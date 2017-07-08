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
	//初始化数据库
	void initDatabase();
	//创建数据库表
	void createTables();
	//检测sql语句是否合法
	void checkQSqlQuery(const QSqlQuery& query, const QString& mark);
	//获取朋友账户
	void getFriendAccount(const QString& clientId, QVector<QString>& AccountVec);
	//结束请求
	void quitRequest(const QString& clientId);
	//用户登录请求
	qint32 loginRequest(const UserLoginInfo& Info);
};


#endif