<%@ WebHandler Language="C#" Class="GetSend" %>

using System;
using System.Web;
using System.Data;
using System.Data.Sql;
using System.Data.SqlClient;
using System.Collections.Generic;
using System.Collections.Concurrent;
using System.Web.Script.Serialization;
using System.Web.SessionState;

public class GetSend : IHttpHandler, IRequiresSessionState
{

    public void ProcessRequest(HttpContext context)
    {
        SqlHelper helper = null;
        try
        {
            helper = new SqlHelper();
            String sql = "select * from account where rule_id = '2'";
            DataTable dt = helper.Query(sql, null);
            List<Account> data = new List<Account>();
            foreach (DataRow dr in dt.Rows)
            {
                Account a = new Account();
                a.Id = dr["id"].ToString();
                a.UserName = dr["username"].ToString();
                a.Password = dr["password"].ToString();
                a.RuleId = dr["rule_id"].ToString();

                data.Add(a);
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