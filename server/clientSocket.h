#ifndef CLIENTSOCKET_H
#define CLIENTSOCKET_H

#include <QtNetwork\qtcpsocket.h>

#include "information.h"

class clientSocket:public QTcpSocket
{
	Q_OBJECT
private:
	//�û���Ϣ
	UserLoginInfo  UserInfo;
	//������Ϣ
	TranssionInfo  TransInfo;

public:
	clientSocket(QObject* parent=0);
	~clientSocket();

signals:
	//���͵�¼�ź�
	void sendLoginInfo(const UserLoginInfo& Info);
	//sendInfo(const TranssionInfo& TransInfo);

	//�Ͽ��ͻ���
	void disconnectClient(const QString& clientId);

public slots:
	void sendMessage(const TemporaryInfo& Info);
	void receiveMessage(const TranssionInfo& Info);
	void deleteClientSocket();


};

#endif