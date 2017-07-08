#include "widget.h"
#include <qlayout.h>
#include <QtCore/QtCore>
#include <QtNetwork\QtNetwork>
#include <Qt\qstring.h>

widget::widget(QWidget *parent, Qt::WFlags flags)
	: QWidget(parent, flags)
{
	//修改名称，增加控件
	setWindowTitle(QString::fromLocal8Bit("服务器运行"));
	resize(300,200);
	IPLabel = new QLabel(this); //指定父对象为widget，避免内存泄漏
	PortLabel = new QLabel(this);
	QuitPushButton = new QPushButton(this);
	QuitPushButton->setText(QString::fromLocal8Bit("退出"));
	QuitPushButton->resize(200,60);

	//修改布局
	QVBoxLayout* layout = new QVBoxLayout(this);
	layout->addWidget(IPLabel);
	layout->addWidget(PortLabel);
	layout->addWidget(QuitPushButton);
	setLayout(layout);

	QString ipAddress = GetIPAddress();
	

	IPLabel->setText(QString::fromLocal8Bit("服务器IP地址：")+ipAddress);
	connect(QuitPushButton,SIGNAL(clicked()),this,SLOT(close()));
}  

widget::~widget()
{

}

QString widget::GetIPAddress()
{
	QString addr;
	//获取所有网络接口列表
	QList<QHostAddress> addrList = QNetworkInterface::allAddresses();
	for(int i=0; i<addrList.size(); ++i)
	{
		//如果不为回环地址且为IPv4地址
		if( addrList.at(i) != QHostAddress::LocalHost && addrList.at(i).toIPv4Address() )
		{
			addr = addrList.at(i).toString();
			break;
		}

	}
	return addr;
}
