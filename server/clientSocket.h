#ifndef CLIENTSOCKET_H
#define CLIENTSOCKET_H

#include <QtNetwork\qtcpsocket.h>

#include "information.h"

class clientSocket:public QTcpSocket
{
	Q_OBJECT
private:
	//传递信息
	TranssionInfo  TransInfo;
	//阻塞信息大小
	qint16 blockSize;
public:
	clientSocket(QObject* parent=0);
	~clientSocket();

signals:
	//发送登录信号
	//void sendLoginInfo(const UserLoginInfo& Info);
	//发送信息信号
	void sendSignals(const TranssionInfo& Info);
	//断开客户端
	void disconnectClient(const QString& clientId);

public slots:
	void sendMessage(const TranssionInfo& Info);
	void receiveMessage();
	void deleteClientSocket();


};

#endif