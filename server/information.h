#ifndef INFORMATION_H
#define INFORMATION_H

#include <qstring.h>
#include <QtCore/QtCore>
#include <QtGui/QtGui>


class clientSocket;

//用户登录状态信息
struct UserLoginInfo
{
	QString UserName;
	QString Password;
};

//朋友信息
struct FriendInformation
{
	QString Account;							//帐号
	QString Name;								//名称
	int PhotoNumber;							//头像编号
	int Status;									//状态
	int AboutSelf;								//自我介绍
	int FriendKind;								//朋友类型
	int Remark;									//备注
};

//传输信息
struct TranssionInfo
{
	qint32 RequestCommand;						//请求命令
	qint32 ReplyCommand;						//回复命令

	clientSocket* ClientSocket;					//客户端套接字

	qint32 Status;								//用户状态
	QVector<FriendInformation> FriendVec;	    //朋友列表
	QVector<QString> AccountVec;				//账户列表
	QString ClientId;							//用户ID	
	QString Password;							//用户密码
};




//用户状态
enum UserStatus
{
	ONLINE = 1,									//在线
	OFFLINE = 2,								//离线
	BUSY = 3									//忙碌
};

//请求类型
enum RequestKind
{
	LOGIN = 1,									//登录
	DISCONNECT = 2,								//断开
	REGISTRER = 3,								//注册
	CHECK_CONNECTION = 12						//检查能否连接
};

//处理结果
enum ProcessResult
{
	LOGIN_SUCCESS = 11,							//登录成功
	LOGIN_NO_ACCOUNT = 12,						//没有帐号
	LOGIN_WRONG_PASSWORD = 13,					//密码错误
	LOGIN_REPEAT = 14							//重复登录
};

//数据库字段
enum SqlWord
{
	ACCOUNT = 0,								//账户
	PASSWORD = 1,								//密码
	NICKNAME = 2,								//昵称
	PHOTONUMBER = 3,							//头像编号
	STATUS = 4,									//状态
	ABOUTSELF = 5								//自我介绍
};



#endif