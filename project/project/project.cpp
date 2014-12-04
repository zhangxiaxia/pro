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
	QObject::connect(ui.pushButton,SIGNAL(clicked()),this,SLOT(dozhishu()));
	QObject::connect(ui.pushButton_3,SIGNAL(clicked()),this,SLOT(doseason()));
	QObject::connect(ui.pushButton_4,SIGNAL(clicked()),this,SLOT(doBp()));
	QObject::connect(ui.pushButton_5,SIGNAL(clicked()),this,SLOT(doxiaobo()));
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
	//数据库的查询
	int kk= 0;
	query.first();
	do 
	{
		QDate time = query.value(0).toDate();
		int year = time.year();
		int month = time.month();
		timejia[kk].timess = getString(year)+getString(month);
		jiachun[kk] = query.value(1).toDouble();
		timejia[kk].jiac = jiachun[kk];
		qDebug() << timejia[kk].timess<<jiachun[kk] ;
		kk++;
	} while (query.next());
	lenjiachun = kk;
	//指数平滑法预测
	//zhishu();
	//季节指数法
	season();
	//bp神经网络
	//BP();
	//小波神经网络
	//xiaobo();

}
void Project::dozhishu()
{
	ui.label1_data->setText(QString::number(labelData[0]));
	ui.label2_data->setText(QString::number(labelData[1]));
	ui.label3_data->setText(QString::number(labelData[2]));

}
void Project::doseason()
{
	ui.label1_data->setText(QString::number(labelData[0]));
	ui.label2_data->setText(QString::number(labelData[1]));
	ui.label3_data->setText(QString::number(labelData[2]));

}
void Project::doxiaobo()
{

}
void Project::doBp()
{

}

QString Project::getString( int n )
{
	QString str = QString::number(n,10);
	return str;

}

void Project::zhishu()
{
	double a = 0.4;
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

}

void Project::season()
{
	//year 数值统计
	TimeJia yearjia[NN];
	double aveall=0;
	int numyear = lenjiachun/12;
	for (int i = 0;i<numyear ;i++)
	{
		int m = 12*i;
		yearjia[i].timess = timejia[m].timess.left(4);
		double sum = 0;
		for (int j = m;j< (m+12) ; j++)
		{
			sum += timejia[j].jiac;
			aveall += timejia[j].jiac;
		}
		yearjia[i].jiac =  sum;
	}
	aveall = aveall/(numyear*12);//计算所有年的平均数值
	//year指数预测
	double a = 0.3;
	int k = 0;
	double smo[NN];
	smo[0]= (yearjia[0].jiac+yearjia[1].jiac+yearjia[2].jiac)/3;
	while (k<numyear)
	{
		smo[k+1]= a*yearjia[k].jiac+(1-a)*smo[k];
		k++;
	}
	double YuceYear = smo[k];
	double YuceYear2 = a*yearjia[k-1].jiac+(1-a)*smo[k];
	//qDebug() <<numyear<< YuceYear ;
	//季节预测
	double smotha[12];
	for (int k1 = 0;k1<12;k1++)
	{
		double avemouth = 0;
		for (int k2 = k1;k2<lenjiachun;)
		{
			avemouth +=timejia[k2].jiac;
			k2+=12;	
		}
		avemouth = avemouth/numyear;
		smotha[k1] = avemouth/aveall;
	}
	//输出预测的24个月的值
	double Yucemonth[24];
	for (int k3=0 ; k3<12;k3++)
	{
		Yucemonth[k3] = smotha[k3]*YuceYear/12;
	}
	double Yucemonth1[12];
	for (int k3=12; k3<24;k3++)
	{
		Yucemonth[k3] = smotha[k3]*YuceYear2/12;
	}
	//输出
	labelData[0]=Yucemonth[lenjiachun%12];
	labelData[1]=Yucemonth[lenjiachun%12+1];
	labelData[2]=Yucemonth[lenjiachun%12+2];
	qDebug() << labelData[0]<<labelData[1]<<labelData[2] ;
}

void Project::xiaobo()
{

}

void Project::BP()
{

}