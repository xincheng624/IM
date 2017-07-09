#ifndef SERVER_H
#define SERVER_H

#include <QtNetwork\QtNetWork>

#include "clientSocket.h"
#include "serverDatabase.h"

class server: public QTcpServer
{
	Q_OBJECT
private:
	//数据库信息
	serverDatabase ServerData;
	//客户端信息
	QMap<QString, clientSocket*> UserMap;
	//临时信息
	TranssionInfo  TempInfo;
	//用户信息
	UserLoginInfo UserInfo;
	//网络状态描述子
	int descriptor;
public:
	server(QObject* parent=0);
	~server();
	//改变clientId客户端朋友的状态
	void ChangeStatus(const QString& clientId, qint32 status);
	//重新定义QTcpServer的virtual incomingConnection();
	void incomingConnection(int descriptor);
private slots:
	//客户端登录
	//void ClientLogin(const UserLoginInfo& UserInfo);
	//处理信息
	void SendMessage(const TranssionInfo& Info);
	//客户端断开
	void ClientDisconnection(const QString& clientId);

};

#endif
