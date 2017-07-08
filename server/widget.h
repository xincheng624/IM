#ifndef WIDGET_H
#define WIDGET_H

#include <QtGui/QWidget>
#include <QtGui\qlabel.h>
#include <qpushbutton.h>


class widget : public QWidget
{
	Q_OBJECT

public:
	widget(QWidget *parent = 0, Qt::WFlags flags = 0);
	~widget();
private:
	//Ip显示
	QLabel* IPLabel;
	//端口显示
	QLabel* PortLabel;
	//退出按钮
	QPushButton* QuitPushButton;
	//获取服务器IP地址
	QString GetIPAddress();
};

#endif // WIDGET_H
