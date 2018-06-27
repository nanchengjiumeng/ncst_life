<%@ WebHandler Language="C#" Class="GeStudent" %>

using System;
using System.Web;
using System.Data;
using System.Data.Sql;
using System.Data.SqlClient;
using System.Collections.Generic;
using System.Collections.Concurrent;
using System.Web.Script.Serialization;
using System.Web.SessionState;

public class GeStudent : IHttpHandler, IRequiresSessionState
{

    public void ProcessRequest(HttpContext context)
    {
        SqlHelper helper = null;
        try
        {
            helper = new SqlHelper();
            String sql = "select * from student";
            DataTable dt = helper.Query(sql, null);
            List<Student> data = new List<Student>();
            foreach (DataRow dr in dt.Rows)
            {
                Student s = new Student();
                s.Id = dr["id"].ToString();
                s.StudentName = dr["student_name"].ToString();
                s.PhoneNumber = dr["phonenumber"].ToString();
                s.Address = dr["address"].ToString();
                s.AccountId = dr["account_id"].ToString();
              
                data.Add(s);
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