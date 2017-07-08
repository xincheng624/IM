#include "clientSocket.h"

clientSocket::clientSocket(QObject* parent)
	:QTcpSocket(parent)
{
}

clientSocket::~clientSocket()
{
}

void clientSocket::receiveMessage(const TranssionInfo& TransInfo)
{
}

void clientSocket::deleteClientSocket()
{
}



