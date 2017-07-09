#include "server.h"
#include <qmessagebox.h>

server::server(QObject* parent):QTcpServer(parent)
{
	if( !listen() )//�������ʧ�ܣ���ʾ����
	{
		QMessageBox::about(NULL, QString::fromLocal8Bit("����"),QString::fromLocal8Bit("�޷����ӣ�"));
		exit(-1);
	}
	//��ʼ�����ݿ�
	ServerData.initDatabase();
}

server::~server()
{
}

void server::ChangeStatus(const QString& clientId, qint32 status)
{
	//��¼����
	TempInfo.Status = status;
	TempInfo.ClientId = clientId;

	//�ı�clientId�����ѵ���Ϣ
	ServerData.getFriendAccount(clientId,TempInfo.AccountVec);
	QMap<QString, clientSocket*>::iterator iter;
	for(int i=0; i < TempInfo.AccountVec.size(); ++i)
	{
		iter = UserMap.find(TempInfo.AccountVec[i]);
		if( iter != UserMap.end() )
			iter.value()->sendMessage(TempInfo);
	}

}

void server::incomingConnection(int descriptor)
{
	//�½��ͻ��ˣ�����clientSocket��server������
	clientSocket* client = new clientSocket(this);

	//connect(client,SIGNAL(sendLoginInfo(const UserLoginInfo&)),
	//	this,SLOT(ClientLogin(const UserLoginInfo& UserInfo)));

	connect(client,SIGNAL(sendSignals(const TranssionInfo&)),
		this,SLOT(SendMessage(const TranssionInfo& Info)));
	connect(client,SIGNAL(disconnectClient(const QString&)),
		this,SLOT(ClientDisconnection(const QString& clientId)));

	client->setSocketDescriptor(descriptor);
}

/*void server::ClientLogin(const UserLoginInfo& Info)
{
	UserInfo.Password = Info.Password;
	UserInfo.UserName = Info.UserName;
	ServerData.loginRequest(UserInfo);
}
*/

void server::SendMessage(const TranssionInfo& Info)
{
	qint32 RequestCommand = Info.RequestCommand;
	switch( RequestCommand )
	{
	case LOGIN:
		{
			UserInfo.UserName = Info.ClientId;
			UserInfo.Password = Info.Password;
			ServerData.loginRequest(UserInfo);
			break;
		}
	default:
		break;
	}
}

void server::ClientDisconnection(const QString& clientId)
{
	//�Ƴ��ͻ��ˣ��޸�״̬
	UserMap.remove(clientId);
	ServerData.quitRequest(clientId);
	ChangeStatus(clientId, OFFLINE);
}


