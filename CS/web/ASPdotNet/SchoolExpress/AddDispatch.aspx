<%@ Page Language="C#" AutoEventWireup="true" CodeFile="AddDispatch.aspx.cs" Inherits="AddDispatch" %>

<!DOCTYPE html>

<html xmlns="http://www.w3.org/1999/xhtml">
<head id="Head1" runat="server">
    <meta http-equiv="Content-Type" content="text/html; charset=utf-8" />
    <title></title>
    <style type="text/css">
        input
        {
            width: 200px;
        }

        select
        {
            width: 200px;
        }
    </style>
    <script type="text/javascript" src="Scripts/jquery-1.7.1.js"></script>
    <script type="text/javascript">
        $(function () {
            loadStudent();
            loadSend();
        });
        function loadStudent() {
            $.ajax({
                url: "GeStudent.ashx",
                type: "post",
                dataType: "json",
                success: function (response) {
                    var s = "";
                    for (var i = 0; i < response.length; i++) {
                        s += "<option value ='" + response[i].Id + "'>" + response[i].StudentName + "</option>";
                    }
                    $("#student_id").html(s);
                }
            });
        }

        function loadSend() {
            $.ajax({
                url: "GetSend.ashx",
                type: "post",
                dataType: "json",
                success: function (response) {
                    var s = "";
                    for (var i = 0; i < response.length; i++) {
                        s += "<option value ='" + response[i].Id + "'>" + response[i].UserName + "</option>";
                    }
                    $("#send_id").html(s);
                }
            });
        }
    </script>
</head>
<body>
    <form id="form1" action="SaveExpress.ashx" method="post">
        <div>
            快递编号：<input type="text" name="code" value="" /><br />
            快递名称：<input type="text" name="expressname" value="" /><br />
            收件人：<select id="student_id" name="student_id"></select><br />
            派件人：<select id="send_id" name="send_id"></select><br />
            <input type="submit" value="添加" />
        </div>
    </form>
</body>
</html>
