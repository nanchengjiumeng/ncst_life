<%@ WebHandler Language="C#" Class="GetExpressForSender" %>

using System;
using System.Web;
using System.Data;
using System.Data.Sql;
using System.Data.SqlClient;
using System.Collections.Generic;
using System.Collections.Concurrent;
using System.Web.Script.Serialization;
using System.Web.SessionState;


public class GetExpressForSender : IHttpHandler, IRequiresSessionState
{

    public void ProcessRequest(HttpContext context)
    {
        String uid = context.Session["uid"].ToString();
        
        SqlHelper helper = null;
        try
        {
            helper = new SqlHelper();
            String sql = @"select p.id as ExpressId,
                           p.name as ExpressName, 
                           s.id as ExpressStudentId,
                           s.student_name as ExpressStudentName,
                           s.address as  Address,
                           s.phonenumber as PhoneNumber,
                           p.sender_id as SenderId,
                           a.username as SenderName,
                           p.dispatch_time as DispatchTime,
                           p.receive_time as ReceiveTime,
                           p.status as Status
                           from express p 
                           inner join student s on p.student_id = s.id 
                           left join account a on p.sender_id = a.id where p.sender_id='"+uid+"'";
            DataTable dt = helper.Query(sql, null);
            List<Express> data = new List<Express>();
            foreach (DataRow dr in dt.Rows)
            {
                Express p = new Express();
                p.ExpressId = dr["ExpressId"].ToString();
                p.ExpressName = dr["ExpressName"].ToString();
                p.ExpressStudentId = dr["ExpressStudentId"].ToString();
                p.ExpressStudentName = dr["ExpressStudentName"].ToString();
                p.Address = dr["Address"].ToString();
                p.PhoneNumber = dr["PhoneNumber"].ToString();
                p.SenderId = dr["SenderId"].ToString();
                p.SenderName = dr["SenderName"].ToString();
                if (dr["DispatchTime"] == DBNull.Value)
                {
                    p.DispatchTime = null;
                }
                else
                {
                    p.DispatchTime = DateTime.Parse(dr["DispatchTime"].ToString());

                }
                if (dr["ReceiveTime"] == DBNull.Value)
                {
                    p.ReceiveTime = null;
                }
                else
                {
                    p.ReceiveTime = DateTime.Parse(dr["ReceiveTime"].ToString());

                }
                p.Status = int.Parse(dr["Status"].ToString());
                data.Add(p);
            }
            String result = "";
            JavaScriptSerializer js = new JavaScriptSerializer();
            result = js.Serialize(data);

            context.Response.ContentType = "text/json";
            context.Response.Write(result);
        }
        catch (Exception e)
        {
            context.Response.Write(e.Message);
            context.Response.Write(e.Source.ToString());

        }
        finally
        {
            if (helper != null) { helper.Disconnet(); }
        }
    }

    public bool IsReusable
    {
        get
        {
            return false;
        }
    }

}