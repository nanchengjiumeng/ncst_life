<%@ WebHandler Language="C#" Class="SaveExpress" %>

using System;
using System.Web;
using System.Data;
using System.Data.Sql;
using System.Data.SqlClient;
using System.Collections.Generic;
using System.Collections.Concurrent;
using System.Web.Script.Serialization;
using System.Web.SessionState;

public class SaveExpress : IHttpHandler, IRequiresSessionState
{

    public void ProcessRequest(HttpContext context)
    {
        SqlHelper helper = null;
        String code = context.Request["code"];
        String expressname = context.Request["expressname"];
        String student_id = context.Request["student_id"];
        String send_id = context.Request["send_id"];

        try
        {
            helper = new SqlHelper();
            String sql = @"insert into express 
                        (id,code,name,student_id,sender_id,dispatch_time,status) 
                        values(@id,@code,@expressname,@student_id,@send_id,@dispatch_time,0)";
            SqlParameter[] p = new SqlParameter[6];
            p[0] = new SqlParameter("@id", Guid.NewGuid().ToString());
            p[1] = new SqlParameter("@code", code);
            p[2] = new SqlParameter("@expressname",expressname);
            p[3] = new SqlParameter("@student_id", student_id);
            p[4] = new SqlParameter("@send_id", send_id);
            p[5] = new SqlParameter("@dispatch_time", DateTime.Now);

            helper.Save(sql,p);
            context.Response.Redirect("Dispatch.aspx");           
        }
        catch (Exception e)
        {
            context.Response.ContentType = "text/plain";
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