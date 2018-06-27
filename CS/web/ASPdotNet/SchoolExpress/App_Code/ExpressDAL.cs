using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;
using System.Data;
using System.Data.Sql;
using System.Data.SqlClient;

/// <summary>
/// ExpressDAL 的摘要说明
/// </summary>
public class ExpressDAL
{
	public ExpressDAL()
	{
		//
		// TODO: 在此处添加构造函数逻辑
		//
	}
    /// <summary>
    /// 查询一组
    /// </summary>
    /// <param name="condition"></param>
    /// <returns></returns>
    public List<Express> Find(String condition)
    {
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
                           left join account a on p.sender_id = a.id 
                           left join account c on s.account_id = c.id ";
            if (!String.IsNullOrEmpty(condition))
            {
                sql += " where " + condition;
            }
            DataTable dt = helper.Query(sql, null);
            List<Express> data = new List<Express>();
            foreach (DataRow dr in dt.Rows)
            {
                Express r = ToExpress(dr);
                data.Add(r);
            }
            return data;
        }
        catch (Exception e)
        {
            throw e;
        }
        finally
        {
            if (helper != null)
            {
                helper.Disconnet();
            }
        }
    }

    /// <summary>
    /// 查询一个 可以调用查询多个，然后返回第一个值
    /// </summary>
    /// <param name="condition"></param>
    /// <returns></returns>
    public Express FindOne(String id)
    {
        String s = "p.id = '" + id + "'";
        List<Express> list = Find(s);
        if (list.Count > 0)
        {
            return list[0];
        }
        else
        {
            return null;
        }
    }

    /// <summary>
    /// 插入一个快递
    /// </summary>
    /// <param name="express"></param>
    public void Insert(Express express)
    {
        SqlHelper helper = null;
        try
        {
            helper = new SqlHelper();
            String sql = @"insert into express 
                        (id,code,name,student_id,sender_id,dispatch_time,status) 
                        values(@id,@code,@expressname,@student_id,@send_id,@dispatch_time,0)";
            SqlParameter[] p = new SqlParameter[6];
            p[0] = new SqlParameter("@id", Guid.NewGuid().ToString());
            p[1] = new SqlParameter("@code", express.ExpressCode);
            p[2] = new SqlParameter("@expressname", express.ExpressName);
            p[3] = new SqlParameter("@student_id", express.ExpressStudentId);
            p[4] = new SqlParameter("@send_id", express.SenderId);
            p[5] = new SqlParameter("@dispatch_time", DateTime.Now);

            helper.Save(sql, p);
        }
        catch (Exception e)
        {
            throw e;

        }
        finally
        {
            if (helper != null) { helper.Disconnet(); }
        }
    }

    public void Update(Express express)
    {
        SqlHelper helper = null;
        try
        {
            helper = new SqlHelper();
            String sql = @"update express set 
                        code@code=,name=@expressname,student_id=@student_id,
                        sender_id=@student_id,dispatch_time=@dispatch_time,status=@status 
                        where id=@id";
            SqlParameter[] p = new SqlParameter[7];
            p[0] = new SqlParameter("@id", express.ExpressId);
            p[1] = new SqlParameter("@code", express.ExpressCode);
            p[2] = new SqlParameter("@expressname", express.ExpressName);
            p[3] = new SqlParameter("@student_id", express.ExpressStudentId);
            p[4] = new SqlParameter("@send_id", express.SenderId);
            p[5] = new SqlParameter("@dispatch_time", DateTime.Now);
            p[6] = new SqlParameter("@status", express.Status);


            helper.Save(sql, p);
        }
        catch (Exception e)
        {
            throw e;
        }
        finally
        {
            if (helper != null) { helper.Disconnet(); }
        }
    }

    public void Delete(String id)
    {
        SqlHelper helper = null;
        try
        {
            helper = new SqlHelper();
            String sql = @"update express where id='" + id + "'";
            helper.Save(sql, null);
        }
        catch (Exception e)
        {
            throw e;
        }
        finally
        {
            if (helper != null) { helper.Disconnet(); }
        }
    }

    /// <summary>
    /// 把数据库查询出来的DateRow 转换为 可用的 Express对象
    /// </summary>
    /// <param name="dr"></param>
    /// <returns></returns>
    private Express ToExpress(DataRow dr)
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
        return p;
    }
}