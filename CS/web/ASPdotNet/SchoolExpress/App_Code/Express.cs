using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;

/// <summary>
/// Express 的摘要说明
/// </summary>
public class Express
{
    public String ExpressId { get; set; }
    public String ExpressCode { get; set; }
    public String ExpressName { get; set; }
    public String ExpressStudentId { get; set; }
    public String ExpressStudentName { get; set; }
    public String Address { get; set; }
    public String PhoneNumber { get; set; }
    public String SenderId { get; set; }
    public String SenderName { get; set; }
    public DateTime? DispatchTime { get; set; }
    public DateTime? ReceiveTime { get; set; }
    public int Status { get; set; }
    public Express()
    {
        //
        // TODO: 在此处添加构造函数逻辑
        //
    }
}