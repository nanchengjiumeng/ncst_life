using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;

/// <summary>
/// ExpressService 的摘要说明
/// </summary>
public class ExpressService
{
    private ExpressDAL expressDAL;

    public ExpressService()
    {
        expressDAL = new ExpressDAL();

    }

    public void Create(Express express)
    {
        expressDAL.Insert(express);
    }

    public void Uptate(Express express)
    {
        expressDAL.Update(express);
    }

    public void Delete(String id)
    {
        expressDAL.Delete(id);
    }

    /// <summary>
    /// 更改快递状态  为签收
    /// </summary>
    /// <param name="id"></param>
    public void Receive(String id)
    {
        Express express = expressDAL.FindOne(id);
        if (express == null)
        {
            throw new Exception("未找到快递：" + id);
        }
        express.Status = 1;
        expressDAL.Update(express);
    }

    /// <summary>
    /// 更改快递为  完成
    /// </summary>
    /// <param name="id"></param>
    public void Finish(String id)
    {
        Express express = expressDAL.FindOne(id);
        if (express == null)
        {
            throw new Exception("未找到快递：" + id);
        }
        express.Status = 2;
        expressDAL.Update(express);
    }

    public Express FindOne(String id)
    {
        return expressDAL.FindOne(id);
    }

    public List<Express> Find(String userid, String ruleid)
    {
        String s = "";
        if (ruleid == "2")
        {
            s = " p.sender_id='" + userid + "'";
        }
        else if (ruleid == "3")
        {
            s = " c.id='" + userid + "'";
        }
        return expressDAL.Find(s);
    }
}