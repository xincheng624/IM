#ifndef INFORMATION_H
#define INFORMATION_H

#include <qstring.h>
#include <QtCore/QtCore>
#include <QtGui/QtGui>


class clientSocket;

//�û���¼״̬��Ϣ
struct UserLoginInfo
{
	QString UserName;
	QString Password;
};

//������Ϣ
struct FriendInformation
{
	QString Account;							//�ʺ�
	QString Name;								//����
	int PhotoNumber;							//ͷ����
	int Status;									//״̬
	int AboutSelf;								//���ҽ���
	int FriendKind;								//��������
	int Remark;									//��ע
};

//������Ϣ
struct TranssionInfo
{
	qint32 RequestCommand;						//��������
	qint32 ReplyCommand;						//�ظ�����

	clientSocket* ClientSocket;					//�ͻ����׽���

	qint32 Status;								//�û�״̬
	QVector<FriendInformation> FriendVec;	    //�����б�
	QVector<QString> AccountVec;				//�˻��б�
	QString ClientId;							//�û�ID	
	QString Password;							//�û�����
};




//�û�״̬
enum UserStatus
{
	ONLINE = 1,									//����
	OFFLINE = 2,								//����
	BUSY = 3									//æµ
};

//��������
enum RequestKind
{
	LOGIN = 1,									//��¼
	DISCONNECT = 2,								//�Ͽ�
	REGISTRER = 3,								//ע��
	CHECK_CONNECTION = 12						//����ܷ�����
};

//������
enum ProcessResult
{
	LOGIN_SUCCESS = 11,							//��¼�ɹ�
	LOGIN_NO_ACCOUNT = 12,						//û���ʺ�
	LOGIN_WRONG_PASSWORD = 13,					//�������
	LOGIN_REPEAT = 14							//�ظ���¼
};

//���ݿ��ֶ�
enum SqlWord
{
	ACCOUNT = 0,								//�˻�
	PASSWORD = 1,								//����
	NICKNAME = 2,								//�ǳ�
	PHOTONUMBER = 3,							//ͷ����
	STATUS = 4,									//״̬
	ABOUTSELF = 5								//���ҽ���
};



#endif