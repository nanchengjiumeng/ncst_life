using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;
using System.Data;
using System.Data.Sql;
using System.Data.SqlClient;

/// <summary>
/// SqlHelper 的摘要说明
/// </summary>
public class SqlHelper
{
    private String connStr = @"server=(local);database=SchoolExpress;integrated security=true";
    private SqlConnection conn;

    public SqlHelper()
    {
        conn = new SqlConnection(connStr);
        Connet();
    }

    //连接数据库
    private void Connet()
    {
        if (conn != null && conn.State != ConnectionState.Open)
        {
            conn.Open();
        }
        else
        {
            return;
        }
    }

    //关闭数据库
    public void Disconnet()
    {
        if (conn != null && conn.State == ConnectionState.Open)
        {
            conn.Close();
        }
    }

    //修改数据库方法
    public void Save(String sql, SqlParameter[] parameters)
    {
        SqlCommand cmd = new SqlCommand(sql, conn);
        if (parameters != null && parameters.Length > 0)
        {
            cmd.Parameters.AddRange(parameters);
        }
        cmd.ExecuteNonQuery();
    }

    //查询数据方法
    public DataTable Query(String sql, SqlParameter[] parameters)
    {
        SqlCommand cmd = new SqlCommand(sql, conn);
        if (parameters != null && parameters.Length > 0)
        {
            cmd.Parameters.AddRange(parameters);
        }
        SqlDataAdapter adp = new SqlDataAdapter(cmd);//执行查询，填充到页面
        DataTable dt = new DataTable();//存放结果
        adp.Fill(dt);//刷新，填充数据
        return dt;
    }

}