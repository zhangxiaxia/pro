#include "sqlHelper.h"
#include <QtGui/QMessageBox>
#include <QtSql/QSqlDatabase>
#include <QtSql>
#include <QSqlError> 
#include <QSqlQuery> 
#include <QDebug>

SqlHelper::SqlHelper()
{
	/*query.exec("select * from data");
	query.record.indexof("Kor");
	query.record.indexof("CFRTai");
	query.record.indexof("SEAsia");
	query.record.indexof("CFRJap");
	query.record.indexof("CFRInd");
	query.record.indexof("CFRChi");
	query.record.indexof("ChiDom");
	query.record.indexof("CoalPri");
	query.record.indexof("TankPri");
	query.record.indexof("OriPri");
	query.record.indexof("ImPri");
	query.record.indexof("ImVol");
	*/
}

void SqlHelper::initial()
{
	db = QSqlDatabase::addDatabase("QMYSQL");
	db.setHostName("localhost");	
	db.setDatabaseName("pro");
	db.setUserName("root");
	db.setPassword("123");
	if (!db.open())
	{
		succees = false;
	}
	else
	{
		succees = true;
	}
}

bool SqlHelper::getSuccees()
{
	return succees;
}

QSqlQuery SqlHelper::getQuery()
{
	QSqlQuery query;
	query.exec("select `Kor`,`CFRTai`,`SEAsia`, `CFRJap`,`CFRInd`, `CFRChi`, `TankPri` from `data` ");
	query.first();
	do									//query.next()ָ����ҵ��ĵ�һ����¼��Ȼ��ÿ�κ���һ����¼
	{
		int ele0 = query.value(0).toInt();				//query.value(0)��id��ֵ������ת��Ϊint ��
		QString ele1 =query.value(1).toString();
		//qDebug() << ele0 <<ele1 ;						//�������ֵ
	}while(query.next());
	return query;
}

