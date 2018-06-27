<%@ Page Language="C#" AutoEventWireup="true" CodeFile="Dispatch.aspx.cs" Inherits="Dispatch" %>

<!DOCTYPE html>

<html xmlns="http://www.w3.org/1999/xhtml">
<head runat="server">
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
            //loadStudent();
            //loadSend();
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
            <a href="AddDispatch.aspx">添加快递</a>
        </div>
    </form>
</body>
</html>
