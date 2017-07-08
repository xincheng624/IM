#include "widget.h"
#include <qlayout.h>
#include <QtCore/QtCore>
#include <QtNetwork\QtNetwork>
#include <Qt\qstring.h>

widget::widget(QWidget *parent, Qt::WFlags flags)
	: QWidget(parent, flags)
{
	//�޸����ƣ����ӿؼ�
	setWindowTitle(QString::fromLocal8Bit("����������"));
	resize(300,200);
	IPLabel = new QLabel(this); //ָ��������Ϊwidget�������ڴ�й©
	PortLabel = new QLabel(this);
	QuitPushButton = new QPushButton(this);
	QuitPushButton->setText(QString::fromLocal8Bit("�˳�"));
	QuitPushButton->resize(200,60);

	//�޸Ĳ���
	QVBoxLayout* layout = new QVBoxLayout(this);
	layout->addWidget(IPLabel);
	layout->addWidget(PortLabel);
	layout->addWidget(QuitPushButton);
	setLayout(layout);

	QString ipAddress = GetIPAddress();
	

	IPLabel->setText(QString::fromLocal8Bit("������IP��ַ��")+ipAddress);
	connect(QuitPushButton,SIGNAL(clicked()),this,SLOT(close()));
}  

widget::~widget()
{

}

QString widget::GetIPAddress()
{
	QString addr;
	//��ȡ��������ӿ��б�
	QList<QHostAddress> addrList = QNetworkInterface::allAddresses();
	for(int i=0; i<addrList.size(); ++i)
	{
		//�����Ϊ�ػ���ַ��ΪIPv4��ַ
		if( addrList.at(i) != QHostAddress::LocalHost && addrList.at(i).toIPv4Address() )
		{
			addr = addrList.at(i).toString();
			break;
		}

	}
	return addr;
}
