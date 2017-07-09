#ifndef CLIENTSOCKET_H
#define CLIENTSOCKET_H

#include <QtNetwork\qtcpsocket.h>

#include "information.h"

class clientSocket:public QTcpSocket
{
	Q_OBJECT
private:
	//������Ϣ
	TranssionInfo  TransInfo;
	//������Ϣ��С
	qint16 blockSize;
public:
	clientSocket(QObject* parent=0);
	~clientSocket();

signals:
	//���͵�¼�ź�
	//void sendLoginInfo(const UserLoginInfo& Info);
	//������Ϣ�ź�
	void sendSignals(const TranssionInfo& Info);
	//�Ͽ��ͻ���
	void disconnectClient(const QString& clientId);

public slots:
	void sendMessage(const TranssionInfo& Info);
	void receiveMessage();
	void deleteClientSocket();


};

#endif