USE [master]
GO
/****** Object:  Database [SchoolExpress]    Script Date: 05/09/2018 08:31:34 ******/
CREATE DATABASE [SchoolExpress] ON  PRIMARY 
( NAME = N'SchoolExpress', FILENAME = N'C:\Program Files\Microsoft SQL Server\MSSQL10_50.SQLSERVER\MSSQL\DATA\SchoolExpress.mdf' , SIZE = 3072KB , MAXSIZE = UNLIMITED, FILEGROWTH = 1024KB )
 LOG ON 
( NAME = N'SchoolExpress_log', FILENAME = N'C:\Program Files\Microsoft SQL Server\MSSQL10_50.SQLSERVER\MSSQL\DATA\SchoolExpress_log.ldf' , SIZE = 1024KB , MAXSIZE = 2048GB , FILEGROWTH = 10%)
GO
ALTER DATABASE [SchoolExpress] SET COMPATIBILITY_LEVEL = 100
GO
IF (1 = FULLTEXTSERVICEPROPERTY('IsFullTextInstalled'))
begin
EXEC [SchoolExpress].[dbo].[sp_fulltext_database] @action = 'enable'
end
GO
ALTER DATABASE [SchoolExpress] SET ANSI_NULL_DEFAULT OFF
GO
ALTER DATABASE [SchoolExpress] SET ANSI_NULLS OFF
GO
ALTER DATABASE [SchoolExpress] SET ANSI_PADDING OFF
GO
ALTER DATABASE [SchoolExpress] SET ANSI_WARNINGS OFF
GO
ALTER DATABASE [SchoolExpress] SET ARITHABORT OFF
GO
ALTER DATABASE [SchoolExpress] SET AUTO_CLOSE OFF
GO
ALTER DATABASE [SchoolExpress] SET AUTO_CREATE_STATISTICS ON
GO
ALTER DATABASE [SchoolExpress] SET AUTO_SHRINK OFF
GO
ALTER DATABASE [SchoolExpress] SET AUTO_UPDATE_STATISTICS ON
GO
ALTER DATABASE [SchoolExpress] SET CURSOR_CLOSE_ON_COMMIT OFF
GO
ALTER DATABASE [SchoolExpress] SET CURSOR_DEFAULT  GLOBAL
GO
ALTER DATABASE [SchoolExpress] SET CONCAT_NULL_YIELDS_NULL OFF
GO
ALTER DATABASE [SchoolExpress] SET NUMERIC_ROUNDABORT OFF
GO
ALTER DATABASE [SchoolExpress] SET QUOTED_IDENTIFIER OFF
GO
ALTER DATABASE [SchoolExpress] SET RECURSIVE_TRIGGERS OFF
GO
ALTER DATABASE [SchoolExpress] SET  DISABLE_BROKER
GO
ALTER DATABASE [SchoolExpress] SET AUTO_UPDATE_STATISTICS_ASYNC OFF
GO
ALTER DATABASE [SchoolExpress] SET DATE_CORRELATION_OPTIMIZATION OFF
GO
ALTER DATABASE [SchoolExpress] SET TRUSTWORTHY OFF
GO
ALTER DATABASE [SchoolExpress] SET ALLOW_SNAPSHOT_ISOLATION OFF
GO
ALTER DATABASE [SchoolExpress] SET PARAMETERIZATION SIMPLE
GO
ALTER DATABASE [SchoolExpress] SET READ_COMMITTED_SNAPSHOT OFF
GO
ALTER DATABASE [SchoolExpress] SET HONOR_BROKER_PRIORITY OFF
GO
ALTER DATABASE [SchoolExpress] SET  READ_WRITE
GO
ALTER DATABASE [SchoolExpress] SET RECOVERY FULL
GO
ALTER DATABASE [SchoolExpress] SET  MULTI_USER
GO
ALTER DATABASE [SchoolExpress] SET PAGE_VERIFY CHECKSUM
GO
ALTER DATABASE [SchoolExpress] SET DB_CHAINING OFF
GO
EXEC sys.sp_db_vardecimal_storage_format N'SchoolExpress', N'ON'
GO
USE [SchoolExpress]
GO
/****** Object:  Table [dbo].[student]    Script Date: 05/09/2018 08:31:34 ******/
SET ANSI_NULLS ON
GO
SET QUOTED_IDENTIFIER ON
GO
SET ANSI_PADDING ON
GO
CREATE TABLE [dbo].[student](
	[id] [varchar](50) NOT NULL,
	[student_name] [varchar](50) NULL,
	[phonenumber] [varchar](50) NULL,
	[address] [varchar](150) NULL,
	[account_id] [varchar](50) NULL,
 CONSTRAINT [PK_Student] PRIMARY KEY CLUSTERED 
(
	[id] ASC
)WITH (PAD_INDEX  = OFF, STATISTICS_NORECOMPUTE  = OFF, IGNORE_DUP_KEY = OFF, ALLOW_ROW_LOCKS  = ON, ALLOW_PAGE_LOCKS  = ON) ON [PRIMARY]
) ON [PRIMARY]
GO
SET ANSI_PADDING OFF
GO
INSERT [dbo].[student] ([id], [student_name], [phonenumber], [address], [account_id]) VALUES (N'1', N'猪八戒', N'18712344321', N'高家庄十三胡同', N'3')
INSERT [dbo].[student] ([id], [student_name], [phonenumber], [address], [account_id]) VALUES (N'2', N'孙悟空', N'12345678911', N'花果山水帘洞山大王', N'3')
/****** Object:  Table [dbo].[rule]    Script Date: 05/09/2018 08:31:34 ******/
SET ANSI_NULLS ON
GO
SET QUOTED_IDENTIFIER ON
GO
SET ANSI_PADDING ON
GO
CREATE TABLE [dbo].[rule](
	[id] [varchar](50) NOT NULL,
	[rulename] [varchar](50) NULL,
 CONSTRAINT [PK_rule] PRIMARY KEY CLUSTERED 
(
	[id] ASC
)WITH (PAD_INDEX  = OFF, STATISTICS_NORECOMPUTE  = OFF, IGNORE_DUP_KEY = OFF, ALLOW_ROW_LOCKS  = ON, ALLOW_PAGE_LOCKS  = ON) ON [PRIMARY]
) ON [PRIMARY]
GO
SET ANSI_PADDING OFF
GO
INSERT [dbo].[rule] ([id], [rulename]) VALUES (N'1', N'管理员')
INSERT [dbo].[rule] ([id], [rulename]) VALUES (N'2', N'投递员')
INSERT [dbo].[rule] ([id], [rulename]) VALUES (N'3', N'学生')
/****** Object:  Table [dbo].[express]    Script Date: 05/09/2018 08:31:34 ******/
SET ANSI_NULLS ON
GO
SET QUOTED_IDENTIFIER ON
GO
SET ANSI_PADDING ON
GO
CREATE TABLE [dbo].[express](
	[id] [varchar](50) NOT NULL,
	[code] [varchar](50) NULL,
	[name] [varchar](50) NULL,
	[student_id] [varchar](50) NULL,
	[sender_id] [varchar](50) NULL,
	[dispatch_time] [datetime] NULL,
	[receive_time] [datetime] NULL,
	[status] [int] NULL,
 CONSTRAINT [PK_Express] PRIMARY KEY CLUSTERED 
(
	[id] ASC
)WITH (PAD_INDEX  = OFF, STATISTICS_NORECOMPUTE  = OFF, IGNORE_DUP_KEY = OFF, ALLOW_ROW_LOCKS  = ON, ALLOW_PAGE_LOCKS  = ON) ON [PRIMARY]
) ON [PRIMARY]
GO
SET ANSI_PADDING OFF
GO
INSERT [dbo].[express] ([id], [code], [name], [student_id], [sender_id], [dispatch_time], [receive_time], [status]) VALUES (N'1', N'2018-04-04-1023', N'蟠桃', N'2', N'2', CAST(0x0000A8B800EA4890 AS DateTime), NULL, 2)
INSERT [dbo].[express] ([id], [code], [name], [student_id], [sender_id], [dispatch_time], [receive_time], [status]) VALUES (N'2', N'2018-04-04-0819', N'大肉包子', N'1', N'2', CAST(0x0000A8B8011BDBF8 AS DateTime), NULL, 2)
INSERT [dbo].[express] ([id], [code], [name], [student_id], [sender_id], [dispatch_time], [receive_time], [status]) VALUES (N'3', N'2018-04-11-0307', N'真经', N'2', N'5', CAST(0x0000A8B8011BDBF8 AS DateTime), NULL, 2)
INSERT [dbo].[express] ([id], [code], [name], [student_id], [sender_id], [dispatch_time], [receive_time], [status]) VALUES (N'4', N'2018-04-11-1105', N'金箍棒', N'1', N'1', CAST(0x0000A8B8011BDBF8 AS DateTime), NULL, 0)
INSERT [dbo].[express] ([id], [code], [name], [student_id], [sender_id], [dispatch_time], [receive_time], [status]) VALUES (N'b543a8e0-cfb7-4776-ad4f-6cddea38f88d', N'2018-04-18-9043', N'三只松鼠', N'1', N'2', CAST(0x0000A8C600F38AE4 AS DateTime), NULL, 0)
INSERT [dbo].[express] ([id], [code], [name], [student_id], [sender_id], [dispatch_time], [receive_time], [status]) VALUES (N'e06c67b6-50e4-4259-92f7-4f25a3f66eee', N'2018-04-17-0003', N'《Windows操作系统原理》', N'2', N'5', CAST(0x0000A8C600F3F578 AS DateTime), NULL, 0)
/****** Object:  Table [dbo].[account]    Script Date: 05/09/2018 08:31:34 ******/
SET ANSI_NULLS ON
GO
SET QUOTED_IDENTIFIER ON
GO
SET ANSI_PADDING ON
GO
CREATE TABLE [dbo].[account](
	[id] [varchar](50) NOT NULL,
	[username] [varchar](50) NULL,
	[password] [varchar](50) NULL,
	[rule_id] [varchar](50) NULL,
 CONSTRAINT [PK_account] PRIMARY KEY CLUSTERED 
(
	[id] ASC
)WITH (PAD_INDEX  = OFF, STATISTICS_NORECOMPUTE  = OFF, IGNORE_DUP_KEY = OFF, ALLOW_ROW_LOCKS  = ON, ALLOW_PAGE_LOCKS  = ON) ON [PRIMARY]
) ON [PRIMARY]
GO
SET ANSI_PADDING OFF
GO
INSERT [dbo].[account] ([id], [username], [password], [rule_id]) VALUES (N'1', N'admin', N'123456', N'1')
INSERT [dbo].[account] ([id], [username], [password], [rule_id]) VALUES (N'2', N'postman', N'123456', N'2')
INSERT [dbo].[account] ([id], [username], [password], [rule_id]) VALUES (N'3', N'0123', N'123456', N'3')
INSERT [dbo].[account] ([id], [username], [password], [rule_id]) VALUES (N'4', N'a', N'123456', N'3')
INSERT [dbo].[account] ([id], [username], [password], [rule_id]) VALUES (N'5', N'postman2', N'123456', N'2')
/****** Object:  ForeignKey [FK_account_rule]    Script Date: 05/09/2018 08:31:34 ******/
ALTER TABLE [dbo].[account]  WITH CHECK ADD  CONSTRAINT [FK_account_rule] FOREIGN KEY([rule_id])
REFERENCES [dbo].[rule] ([id])
GO
ALTER TABLE [dbo].[account] CHECK CONSTRAINT [FK_account_rule]
GO
