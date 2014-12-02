#include "project.h"

Project::Project(QWidget *parent, Qt::WFlags flags)
	: QMainWindow(parent, flags)
{
	ui.setupUi(this);
	query.exec("Select Date, TankPri from data");
	setData();
	timer = new QTimer(this);
	connect(timer,SIGNAL(timeout()),ui.area2,SLOT(updateGL()));
	connect(timer,SIGNAL(timeout()),ui.area3,SLOT(updateGL()));
	QObject::connect(ui.pushButton,SIGNAL(clicked()),this,SLOT(dodata()));
	QObject::connect(ui.pushButton_3,SIGNAL(clicked()),this,SLOT(doseason()));
	QObject::connect(ui.pushButton_4,SIGNAL(clicked()),this,SLOT(doBp()));
	QObject::connect(ui.pushButton_5,SIGNAL(clicked()),this,SLOT(xiaobo()));
	timer->start(10);
}

Project::~Project()
{
	
}

void Project::setData()
{
	/*labelData[0] = ui.label1_data->text().toDouble();
	labelData[1] = ui.label2_data->text().toDouble();
	labelData[2] = ui.label3_data->text().toDouble();
	ui.area2->getData(labelData);*/
	labelData[0] = 100;
	labelData[1] = 30;
	labelData[2] = 50;
	int i= 0;
	query.first();
	do 
	{

		//QDate time = query.value(0).toDate();
		//int year = time.year();
		//int month = time.month();
		//timejia[i].timesall = getString(year)+getString(mouth);
		jiachun[i] = query.value(1).toDouble();
		//timejia[i].jiac = jiachun[i];
		//qDebug() << timejia[i].timesall<<jiachun[i] ;
		i++;
	} while (query.next());
	lenjiachun = i;

	//ָ��ƽ����Ԥ��
	double a = 0.3;
	int j = 0;
	smo1[0] = (jiachun[0]+jiachun[1]+jiachun[2])/3;
	smo3[0] = smo2[0] = smo1[0];
	while (j<lenjiachun)
	{
		smo1[j+1] = a * jiachun[j] + (1-a) * smo1[j];
		smo2[j+1] = a * smo1[j+1] + (1-a) * smo2[j];
		smo3[j+1] = a * smo2[j+1] + (1-a) * smo3[j];
		j++;
	}
	double a1 = 3 *smo1[j] - 3 * smo2[j] + smo3[j];
	double b1 = (a/(2*(1-a)*(1-a))) * ((6-5*a)*smo1[j]- 2*(5-4*a)*smo2[j]+(4-3*a)*smo3[j]);
	double c1 = (a*a)/(2*(1-a)*(1-a))*(smo1[j]-2*smo2[j]+smo3[j]);
	labelData[0] = a1+b1+c1;
	labelData[1] = a1+2*b1+2*c1;
	labelData[2] = a1+3*b1+3*c1;
	qDebug() << labelData[0]<<labelData[1]<<labelData[2] ;
	//����ָ����
	//bp������
	//С��������

}

void Project::dodata()
{
	ui.label1_data->setText(QString::number(labelData[0]));
	ui.label2_data->setText(QString::number(labelData[1]));
	ui.label3_data->setText(QString::number(labelData[2]));
}

void Project::doseason()
{

}

void Project::xiaobo()
{

}

void Project::doBp()
{

}
//����string
String Project::getString( int n )
{
	/*stringstream str;
	str<<n;
	return str;*/
}