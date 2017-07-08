#include "serverDatabase.h"
#include <QObject>
#include <qmessagebox.h>

serverDatabase::serverDatabase()
{
	bool IsCreated = QFile::exists("IM.db");
	if( !IsCreated )
	{
		createTables();
	}
	Data = QSqlDatabase::addDatabase("QSQLITE");
	Data.setDatabaseName("IM.db");
	if( !Data.open() )
	{
		QMessageBox::warning(NULL,"Database Error","Can not open IM.db");
		exit(2);
	}

}

serverDatabase::~serverDatabase()
{

}

void serverDatabase::initDatabase()
{
	QSqlQuery query;
	//用户状态初始化
	query.exec("updata users set status = 0");
	checkQSqlQuery(query,"initDatabase()");
}

void serverDatabase::createTables()
{
	QSqlQuery query;
	//创建用户表，帐号（主键）、密码、昵称、照片编号、状态和自我描述
	query.exec("create table users(account varchar(21) primary key,"
		"password varchar(21) not null,"
		"nickname varchar(41) not null,"
		"photonumber integer not null,"
		"status integer not null,"
		"aboutSelf varchar(201) not null)");
	checkQSqlQuery(query,"createTableusers()");

	//创建朋友表，好友A（主键）、好友B、好友关系和备注
	query.exec("create table friends(NameA varchar(21) primary key,"
		"NameB varchar(21) not null,"
		"kind varchar(21) not null,"
		"remark varchar(21) not null)");
	checkQSqlQuery(query,"createTablefriends()");
}

void serverDatabase::checkQSqlQuery(const QSqlQuery& query, const QString& mark)
{
	//如果查询失败
	if( !query.isActive() )
	{
		QString err = query.lastError().text() + '\n' + mark;
		QMessageBox::about(NULL,QString::fromLocal8Bit("出错！"),err);
	}
}

void serverDatabase::getFriendAccount(const QString& clientId, QVector<QString>& FriendAcc)
{
	FriendAcc.clear();
	QSqlQuery query;
	//从friends表中查询所有NameA为clientId的项
	query.prepare("select * from friends where NameA = :clientId");
	query.bindValue(":clientId",clientId);
	query.exec();
	checkQSqlQuery(query,"getFriendAccount()");

	while( query.next() )
	{
		//如果是好友
		if( query.value(2).toInt() != 0 )
		{
			FriendAcc.push_back(query.value(1).toString());
		}
	}
}

void serverDatabase::quitRequest(const QString& clientId)
{
	QSqlQuery query;
	query.prepare("updata users set status=0 where acount =:clientId");
	query.bindValue(":clientId",clientId);
	query.exec();
	checkQSqlQuery(query,"quitRequest()");
}

qint32 serverDatabase::loginRequest(const UserLoginInfo& Info)
{
	QSqlQuery query;
	int number = 0;

	query.prepare("select* from users where account =:clientId");
	query.bindValue(":clientId",Info.UserName);
	query.exec();
	checkQSqlQuery(query,"loginRequest()");
	while( query.next() )
		number++;

	if( number == 0 )
	{
		return LOGIN_NO_ACCOUNT;
	}
	else if( query.value(PASSWORD).toString() != Info.Password )
	{
		return LOGIN_WRONG_PASSWORD;
	}
	else if( query.value(STATUS) != OFFLINE )
	{
		return LOGIN_REPEAT;
	}
	else
	{
		//loginSuccess();
		return LOGIN_SUCCESS;
	}
}