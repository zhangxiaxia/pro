#ifndef PROJECT_H
#define PROJECT_H

#include <QtGui/QMainWindow>
#include "ui_project.h"
#include <QtGui/QMessageBox>
#include <QTimer>
#include "para.h"
#include <QString.h>
#include <QMap>
#include "sqlHelper.h"
const int NN = 100;
struct TimeJia{
	QString timess;
	double jiac;
};
class Project : public QMainWindow
{
	Q_OBJECT

public:
	Project(QWidget *parent = 0, Qt::WFlags flags = 0);
	void setData();
	QTimer *timer;
	~Project();
	void zhishu();
	void season();
	void xiaobo();
	void BP();
private:
	Ui::ProjectClass ui;
	QSqlQuery query;
	double jiachun[NN];
	TimeJia timejia[NN];
	double smo1[NN];
	double smo2[NN];
	double smo3[NN];
	int lenjiachun;
	QString getString(int n);
public slots:
	void dozhishu();
	void doseason();
	void doxiaobo();
	void doBp();
};

#endif // PROJECT_H
