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
	//Ip��ʾ
	QLabel* IPLabel;
	//�˿���ʾ
	QLabel* PortLabel;
	//�˳���ť
	QPushButton* QuitPushButton;
	//��ȡ������IP��ַ
	QString GetIPAddress();
};

#endif // WIDGET_H
