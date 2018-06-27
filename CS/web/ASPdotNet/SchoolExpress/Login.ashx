<%@ WebHandler Language="C#" Class="Login" %>

using System;
using System.Web;
using System.Data;
using System.Data.Sql;
using System.Data.SqlClient;
using System.Web.SessionState;

public class Login : IHttpHandler,IRequiresSessionState
{

    public void ProcessRequest(HttpContext context)
    {
        context.Response.ContentType = "text/plain";

        String username = context.Request["username"];
        String password = context.Request["password"];
        SqlHelper helper = null;

        try
        {
            helper = new SqlHelper();
            String sql = "select * from account where username=@username";
            SqlParameter[] p = new SqlParameter[1];
            p[0] = new SqlParameter("@username", username);
            DataTable dt = helper.Query(sql, p);

            if (dt.Rows.Count == 0)   //判账号
            {
                throw new Exception("用户不存在！");
            }
            else if (dt.Rows[0]["password"].ToString() != password)   //判密码
            {
                throw new Exception("密码错误！");
            }
            //根据权限跳到不同的页面
            String ruleId = dt.Rows[0]["rule_id"].ToString();
            String uid = dt.Rows[0]["id"].ToString();
            String uname = dt.Rows[0]["username"].ToString();
            context.Session["uid"] = uid;
            context.Session["uname"] = uname;
            context.Session["rid"] = ruleId;
            
            if (ruleId == "1")
            {
                context.Response.Redirect("Dispatch.aspx");
            }
            else if (ruleId == "2")
            {
                context.Response.Redirect("Poster.aspx");
            }

        }
        catch (Exception e)
        {
            context.Response.ContentType = "text/html";
            context.Response.Write("<html><body>" + " <script type='text/javascript'>alert('" + e.Message + "');");
            context.Response.Write("window.location.href='Login.aspx';");
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