#ifndef CLIENTSOCKET_H
#define CLIENTSOCKET_H

#include <QtNetwork\qtcpsocket.h>

#include "information.h"

class clientSocket:public QTcpSocket
{
	Q_OBJECT
private:
	//用户信息
	UserLoginInfo  UserInfo;
	//传递信息
	TranssionInfo  TransInfo;

public:
	clientSocket(QObject* parent=0);
	~clientSocket();

signals:
	//发送登录信号
	void sendLoginInfo(const UserLoginInfo& Info);
	//sendInfo(const TranssionInfo& TransInfo);

	//断开客户端
	void disconnectClient(const QString& clientId);

public slots:
	void sendMessage(const TemporaryInfo& Info);
	void receiveMessage(const TranssionInfo& Info);
	void deleteClientSocket();


};

#endif