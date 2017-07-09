#include "server.h"
#include <qmessagebox.h>

server::server(QObject* parent):QTcpServer(parent)
{
	if( !listen() )//如果监听失败，显示出错
	{
		QMessageBox::about(NULL, QString::fromLocal8Bit("出错！"),QString::fromLocal8Bit("无法连接！"));
		exit(-1);
	}
	//初始化数据库
	ServerData.initDatabase();
}

server::~server()
{
}

void server::ChangeStatus(const QString& clientId, qint32 status)
{
	//记录数据
	TempInfo.Status = status;
	TempInfo.ClientId = clientId;

	//改变clientId的朋友的信息
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
	//新建客户端，建立clientSocket和server的连接
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
	//移除客户端，修改状态
	UserMap.remove(clientId);
	ServerData.quitRequest(clientId);
	ChangeStatus(clientId, OFFLINE);
}


