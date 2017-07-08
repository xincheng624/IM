#ifndef SERVERDATABASE_H
#define SERVERDATABASE_H

#include <QtSql\QtSql>
#include "information.h"

class serverDatabase
{
	QSqlDatabase Data;
public:
	serverDatabase();
	~serverDatabase();
	//��ʼ�����ݿ�
	void initDatabase();
	//�������ݿ��
	void createTables();
	//���sql����Ƿ�Ϸ�
	void checkQSqlQuery(const QSqlQuery& query, const QString& mark);
	//��ȡ�����˻�
	void getFriendAccount(const QString& clientId, QVector<QString>& AccountVec);
	//��������
	void quitRequest(const QString& clientId);
	//�û���¼����
	qint32 loginRequest(const UserLoginInfo& Info);
};


#endif