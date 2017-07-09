#include "clientSocket.h"

clientSocket::clientSocket(QObject* parent)
	:QTcpSocket(parent)
{
	TransInfo.ClientSocket = this;
	connect(this,SIGNAL(readyRead()),this,SLOT(receiveMessage()));
	connect(this,SIGNAL(disconnected()),this,SLOT(deleteClientSocket()));

}

clientSocket::~clientSocket()
{
}

void clientSocket::receiveMessage()
{
	QDataStream in(this);
	in.setVersion(QDataStream::Qt_4_8);

	if( blockSize == 0 )
	{
		if( bytesAvailable() < sizeof(quint16) )
			return;
		in >> blockSize;
	}
	//超过blockSize的数据则开始读取
	if( bytesAvailable() < blockSize )
	{
		return;
	}

	in >> TransInfo.RequestCommand;

	switch(TransInfo.RequestCommand)
	{
	case CHECK_CONNECTION:
		{
			TransInfo.ReplyCommand = CHECK_CONNECTION;
			sendMessage(TransInfo);
			blockSize = 0;
			return;
		}
	default:
		break;
	}

	blockSize = 0;
	emit sendSignals(TransInfo);
}

void clientSocket::sendMessage(const TranssionInfo& Info)
{
	QByteArray block;
	QDataStream out(&block, QIODevice::WriteOnly);
	out.setVersion(QDataStream::Qt_4_8);

	out<<Info.ReplyCommand;

	out.device()->seek(0);
	write(block);
}

void clientSocket::deleteClientSocket()
{
	if( !TransInfo.ClientId.isEmpty() )
	{
		emit disconnectClient(TransInfo.ClientId);
	}
	//注意这个
	deleteLater();
}



