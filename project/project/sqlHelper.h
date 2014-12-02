#pragma once

#include <QtSql/QtSql>
#include <QSqlQuery>

class SqlHelper
{
public:
	SqlHelper();
	void initial();
	bool getSuccees();
	QSqlQuery getQuery();
	
private:
	bool succees;
	QSqlDatabase db;
	//QSqlQuery query;
};