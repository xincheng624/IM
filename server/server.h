#ifndef SERVER_H
#define SERVER_H

#include <QtNetwork\QtNetWork>

#include "clientSocket.h"
#include "serverDatabase.h"

class server: public QTcpServer
{
	Q_OBJECT
private:
	//���ݿ���Ϣ
	serverDatabase ServerData;
	//�ͻ�����Ϣ
	QMap<QString, clientSocket*> UserMap;
	//��ʱ��Ϣ
	TranssionInfo  TempInfo;
	//�û���Ϣ
	UserLoginInfo UserInfo;
	//����״̬������
	int descriptor;
public:
	server(QObject* parent=0);
	~server();
	//�ı�clientId�ͻ������ѵ�״̬
	void ChangeStatus(const QString& clientId, qint32 status);
	//���¶���QTcpServer��virtual incomingConnection();
	void incomingConnection(int descriptor);
private slots:
	//�ͻ��˵�¼
	//void ClientLogin(const UserLoginInfo& UserInfo);
	//������Ϣ
	void SendMessage(const TranssionInfo& Info);
	//�ͻ��˶Ͽ�
	void ClientDisconnection(const QString& clientId);

};

#endif
