<%@ Page Language="C#" AutoEventWireup="true" CodeFile="Poster.aspx.cs" Inherits="Poster" %>

<!DOCTYPE html>

<html xmlns="http://www.w3.org/1999/xhtml">
<head runat="server">
    <meta http-equiv="Content-Type" content="text/html; charset=utf-8" />
    <title></title>
    <style>
        table
        {
            width: 80%;
            border-collapse: collapse;
        }

        td
        {
            border: 1px solid #666666;
            text-align: center;
            vertical-align: central;
        }
    </style>
    <script type="text/javascript" src="Scripts/jquery-1.7.1.js"></script>
    <script type="text/javascript">
        $(function () {
            load();
        });

        function load() {
            $.ajax({
                url: "GetExpress.ashx",
                type: "get",
                dataType: "json",
                success: function (response) {
                    //alert("Reced: " + response.length);
                    var s = "<table>";
                    s += "<tr><td>快递名称</td><td>收件人姓名</td><td>收件人地址</td><td>收件人电话</td><td>寄送人名称</td><td>邮递时间</td><td>签收时间</td><td>快递状态</td><td>操作</td></tr>";
                    for (var i = 0; i < response.length; i++) {
                        s += "<tr>";
                        s += "<td>" + response[i].ExpressName + "</td>";
                        s += "<td>" + response[i].ExpressStudentName + "</td>";
                        s += "<td>" + response[i].Address + "</td>";
                        s += "<td>" + response[i].PhoneNumber + "</td>";
                        s += "<td>" + response[i].SenderName + "</td>";

                        var dtime = response[i].DispatchTime + " ";
                        s += "<td>" + new Date(Number(dtime.substring(6, 19))).Format("yyyy-MM-dd hh:mm:ss") + "</td>";
                        var rtime = response[i].ReceiveTime + " ";
                        s += "<td>" + new Date(Number(rtime.substring(6, 19))).Format("yyyy-MM-dd hh:mm:ss") + "</td>";

                        var status = IsStatus(response[i].Status);
                        s += "<td>" + status + "</td>";

                        s += "<td><a href ='UpdateExpressStatus.ashx?id=" + response[i].ExpressId + "&status=2'>完成</a></td>";

                        s += "</tr>";
                    }
                    s += "</table>";
                    $("#content").html(s);
                }
            });
        }

        function IsStatus(status) {
            if (status == 0) {
                status = "待签收";
            }
            if (status == 1) {
                status = "已签收";
            }
            if (status == 2) {
                status = "已完成";
            }
            return status;
        }

        Date.prototype.Format = function (fmt) {
            var o = {
                "M+": this.getMonth() + 1,
                "d+": this.getDate(),
                "h+": this.getHours(),
                "m+": this.getMinutes(),
                "s+": this.getSeconds(),
                "q+": Math.floor((this.getMonth() + 3) / 3),
                "S": this.getMilliseconds()
            };
            if (/(y+)/.test(fmt))
                fmt = fmt.replace(RegExp.$1, (this.getFullYear() + "").substr(4 - RegExp.$1.length));
            for (var k in o)
                if (new RegExp("(" + k + ")").test(fmt))
                    fmt = fmt.replace(RegExp.$1, (RegExp.$1.length == 1) ? (o[k]) : (("00" + o[k]).substr(("" + o[k]).length)));
            return fmt;
        }
    </script>

</head>
<body>
    <form id="form1" runat="server">
        <div id="content">
        </div>
    </form>
</body>
</html>
