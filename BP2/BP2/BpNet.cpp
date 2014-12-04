#include <stdlib.h>
#include <iostream>
#include <cmath>
using namespace std;
#define  innode 3
#define  hidenode 10
#define  outnode 1
#define  trainsample 3
#define  MAXNUM 5000
#define  Minerror 0.000001
//��������
double XX[trainsample][innode]= {{0.0125,0.0097,0.0139},{0.012,0.0097,0.0144},{0.012,0.0093,0.014}};
double YY[trainsample][outnode]={{0.0119},{0.0116},{0.0116}};

//�������
class BpNet{
public:
	double p[trainsample][innode];
	double t[trainsample][outnode];
	void train(double p[trainsample][innode],double t[trainsample][outnode]);
	double *recongnize(double *p);

	BpNet();
	virtual ~BpNet();
public:
	void init();//��ʼ��Ȩֵ
	double w[innode][hidenode];//���������ز�֮���Ȩֵ
	double w1[hidenode][outnode];//���ز�������֮���Ȩֵ
	double b1[hidenode];//���ز��ƫ��ֵ
	double b2[outnode];//������ƫ��ֵ

	double rate_w;//Ȩֵѧϰ�ʣ������������㣩
	double rate_w1;
	double rate_b1;
	double rate_b2;

	double error;
	double e;
	double result[outnode];

};

BpNet::BpNet()
{
	error = 1.0;
	e=0;
	rate_b2=0.9;
	rate_b1=0.9;
	rate_w=0.9;
	rate_w1=0.9;
}

BpNet::~BpNet()
{
}
void winit(double w[],double n){
	for (int i = 0 ;i<n;i++)
		w[i]=(2*(double)rand()/RAND_MAX)-1;
}
void BpNet::init()
{
	winit((double*)w,innode*hidenode);	
	winit((double*)w1,hidenode*outnode);
	winit(b1,hidenode);
	winit(b2,outnode);
}

void BpNet::train(double p[trainsample][innode],double t[trainsample][outnode])
{
	//for (double (*i)[innode]=p;i!=p+trainsample;i++)
	//	for (double *j= *i;j!=*i+innode;j++)
	//		cout<<*j<<endl;
	double x[innode];//��������
	double x1[hidenode];//�����ڵ�״ֵ̬
	double x2[outnode];//����ڵ�״ֵ̬
	double o1[hidenode];//���ز�ļ���ֵ
	double o2[hidenode];//�����ļ���ֵ
	double yd[outnode];//�������ֵ
	double qq[outnode];//���������ʵ����Ҫ���֮������
	double pp[hidenode];//���ؽڵ��У�����

	for (int isamp=0;isamp<trainsample;isamp++)//ѭ��ѵ������
	{
		for (int i = 0 ;i<innode;i++)
			x[i]=p[isamp][i];//��������
		for (int i = 0;i<outnode;i++)
			yd[i] = t[isamp][i];//�����������


		//����ÿ���������������׼
		for (int i= 0;i<hidenode;i++)
		{
			o1[i]=0;
			for (int j=0;j<innode;j++)
				o1[i]=x[j]*w[j][i]+o1[i];
			x1[i] = 1.0/(1+exp(-o1[i]-b1[i]));
		}
		for (int k =0;k<outnode;k++)
		{
			o2[k]=0;
			for (int j= 0;j<hidenode;j++)
				o2[k]=x1[j]*w1[j][k]+o2[k];
			x2[k] = 1.0/(1+exp(-o2[k]-b2[k]));
		}
		//�����������ֵ��ʵ����Ҫ���ֵ��ƫ��
		for (int k=0;k<outnode;k++)
		{
			qq[k]=(yd[k]-x2[k])*x2[k]*(1-x2[k]);
			for (int j = 0 ;j<hidenode;j++)
				w1[j][k]+=qq[k]*x2[k]*rate_w1;//��һ�����ز�������֮���Ȩֵ

		}
		//�������������ز�֮���ƫ��
		for (int k = 0 ;k<hidenode ;k++)
		{
			pp[k] = 0;
			for (int j= 0 ;j<outnode;j++)
				pp[k] =pp[k]+qq[k] * w1[k][j];
			pp[k]=pp[k]*x1[k]*(1-x1[k]);//���ز��У�����

			for(int i =0;i<innode;i++)
				w[i][k] +=pp[i]* rate_w *x[i];
		}
		//���������
		for (int k = 0;k<outnode;k++)
			e+=fabs(yd[k]-x2[k])*fabs(yd[k]-x2[k]);
		error = e/2;
		
		//��������ֵ
		for (int i= 0;i<outnode;i++)
			b2[i]= b2[i]+rate_b2*qq[i];
		for (int i =0;i<hidenode;i++)
			b1[i] = b1[i]+rate_b1*pp[i];
	}
}

double * BpNet::recongnize( double *p )
{
	double x[innode];
	double x1[hidenode];
	double x2[outnode];
	double o1[hidenode];
	double o2[hidenode];

	for (int i =0;i<innode;i++)
		x[i] = p[i];
	for (int j=0;j<hidenode;j++)
	{
		o1[j]= 0.0;
		for (int i =0;i<innode;i++)
			o1[j]=o1[j]+w[i][j]*x[i];
		x1[j]=1/(1.0+exp(-o1[j]-b1[j]));
	}
	for (int k =0;k<outnode;k++)
	{
		o2[k]=0.0;
		for (int j=0;j<hidenode;j++)
			o2[k]=o2[k]+w1[j][k]*x1[j];
		x2[k]=1/(1.0+exp(-o2[k]-b2[k]));
	}
	for (int k=0;k<outnode;k++)
		result[k]=x2[k];
	return result;

}
int main(){
	BpNet bp;
	int times=0;
	bp.init();
	while (bp.error>Minerror)
	{
		bp.e=0.0;
		times++;
		bp.train(XX,YY);
		//bp.error--;
		if (times>MAXNUM)//���ѵ����������һ���ķ�Χ��ֹͣ
			break;
		cout<<"times="<<times<<"errors="<<bp.error<<endl;
	}
	cout<<"training complete..."<<endl;
	//double m[innode]={0.203,-1.375,0.212};
	double m[innode]={0.0124,0.0089,0.013};
	double *r=bp.recongnize(m);
	//for (int i =0;i<outnode;i++)
	//	cout<<*r++<<endl;
	for (int i =0;i<outnode;i++)
		cout<<bp.result[i]<<endl;
	system("pause");
	return 0;
}