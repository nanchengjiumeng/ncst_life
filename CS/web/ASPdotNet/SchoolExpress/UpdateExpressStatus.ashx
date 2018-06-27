<%@ WebHandler Language="C#" Class="UpdateExpressStatus" %>

using System;
using System.Web;
using System.Data;
using System.Data.Sql;
using System.Data.SqlClient;


public class UpdateExpressStatus : IHttpHandler
{

    public void ProcessRequest(HttpContext context)
    {
        //context.Response.ContentType = "text/plain";
        //context.Response.Write("Hello World");

        String id = context.Request["id"];
        int status = int.Parse(context.Request["status"]);
        SqlHelper helper = null;

        try
        {
            helper = new SqlHelper();
            String sql = "update express set status=@status where id=@id";
            SqlParameter[] p = new SqlParameter[2];
            p[0] = new SqlParameter("@status", status);
            p[1] = new SqlParameter("@id", id);
            helper.Save(sql,p);
            context.Response.Redirect("Poster.aspx");

        }
        catch (Exception e)
        {
            context.Response.ContentType = "text/html";
            context.Response.Write("<html><body>" + " <script type='text/javascript'>alert('" + e.Message + "');");
            context.Response.Write("</script></body></html>");
            //context.Response.Write(e.Message + "错误为：" + e.Source.ToString());
            context.Response.End();
        }
        finally
        {
            if (helper != null)
            {
                helper.Disconnet();
            }
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