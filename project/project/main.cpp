#include "project.h"
#include "sqlHelper.h"
#include <QtGui/QApplication>

int main(int argc, char *argv[])
{
	SqlHelper db;
	db.initial();
	QApplication a(argc, argv);
	Project w;
	w.show();
	return a.exec();
}
