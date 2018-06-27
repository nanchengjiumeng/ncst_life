<%@ WebHandler Language="C#" Class="GetExpress" %>

using System;
using System.Web;
using System.Data;
using System.Data.Sql;
using System.Data.SqlClient;
using System.Collections.Generic;
using System.Collections.Concurrent;
using System.Web.Script.Serialization;
using System.Web.SessionState;

public class GetExpress : IHttpHandler, IRequiresSessionState
{
    public void ProcessRequest(HttpContext context)
    {
        String uid = context.Session["uid"].ToString();
        String rid = context.Session["rid"].ToString();
        ExpressService expressService = new ExpressService();
        try
        {
            List<Express> data = expressService.Find(uid, rid);
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
    }

    public bool IsReusable
    {
        get
        {
            return false;
        }
    }

}