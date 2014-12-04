//����λ��������תΪһλʮ������

#include <iostream>
#include <cmath>
#include <stdlib.h>
using namespace std;

#define  innode 3  //��������
#define  hidenode 10//���������
#define  outnode 1 //��������
#define  trainsample 8//BPѵ��������

class BpNet
{
public:
    void train(double p[trainsample][innode],double t[trainsample][outnode]);//Bpѵ��
    double p[trainsample][innode];     //���������
    double t[trainsample][outnode];    //����Ҫ�����

    double *recognize(double *p);//Bpʶ��
    BpNet();
    virtual ~BpNet();

public:
    void init();
    double w[innode][hidenode];//�������Ȩֵ
    double w1[hidenode][outnode];//������Ȩֵ
    double b1[hidenode];//������㷧ֵ
    double b2[outnode];//�����㷧ֵ

    double rate_w; //Ȩֵѧϰ�ʣ������-������)
    double rate_w1;//Ȩֵѧϰ�� (������-�����)
    double rate_b1;//�����㷧ֵѧϰ��
    double rate_b2;//����㷧ֵѧϰ��

    double e;//������
    double error;//������������
    double result[outnode];// Bp���
};

BpNet::BpNet()
{
    error=1.0;
    e=0.0;
    rate_w=0.9;  //Ȩֵѧϰ�ʣ������--������)
    rate_w1=0.9; //Ȩֵѧϰ�� (������--�����)
    rate_b1=0.9; //�����㷧ֵѧϰ��
    rate_b2=0.9; //����㷧ֵѧϰ��
}

BpNet::~BpNet()
{

}

void winit(double w[],int n) //Ȩֵ��ʼ��
{
  for(int i=0;i<n;i++)
    w[i]=(2.0*(double)rand()/RAND_MAX)-1;
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
    double pp[hidenode];//��������У�����
    double qq[outnode];//ϣ�����ֵ��ʵ�����ֵ��ƫ��
    double yd[outnode];//ϣ�����ֵ

    double x[innode]; //��������
    double x1[hidenode];//�������״ֵ̬
    double x2[outnode];//������״ֵ̬
    double o1[hidenode];//�����㼤��ֵ
    double o2[hidenode];//����㼤��ֵ

    for(int isamp=0;isamp<trainsample;isamp++)//ѭ��ѵ��һ����Ʒ
    {
        for(int i=0;i<innode;i++)
            x[i]=p[isamp][i]; //���������
        for(int i=0;i<outnode;i++)
            yd[i]=t[isamp][i]; //�������������

        //����ÿ����Ʒ������������׼
        for(int j=0;j<hidenode;j++)
        {
            o1[j]=0.0;
            for(int i=0;i<innode;i++)
                o1[j]=o1[j]+w[i][j]*x[i];//���������Ԫ���뼤��ֵ
            x1[j]=1.0/(1+exp(-o1[j]-b1[j]));//���������Ԫ�����
            //    if(o1[j]+b1[j]>0) x1[j]=1;
            //else x1[j]=0;
        }

        for(int k=0;k<outnode;k++)
        {
            o2[k]=0.0;
            for(int j=0;j<hidenode;j++)
                o2[k]=o2[k]+w1[j][k]*x1[j]; //��������Ԫ���뼤��ֵ
            x2[k]=1.0/(1.0+exp(-o2[k]-b2[k])); //��������Ԫ���
            //    if(o2[k]+b2[k]>0) x2[k]=1;
            //    else x2[k]=0;
        }

        for(int k=0;k<outnode;k++)
        {
            qq[k]=(yd[k]-x2[k])*x2[k]*(1-x2[k]); //ϣ�������ʵ�������ƫ��
            for(int j=0;j<hidenode;j++)
                w1[j][k]+=rate_w1*qq[k]*x1[j];  //��һ�ε�������������֮���������Ȩ
        }

        for(int j=0;j<hidenode;j++)
        {
            pp[j]=0.0;
            for(int k=0;k<outnode;k++)
                pp[j]=pp[j]+qq[k]*w1[j][k];
            pp[j]=pp[j]*x1[j]*(1-x1[j]); //�������У�����

            for(int i=0;i<innode;i++)
                w[i][j]+=rate_w*pp[j]*x[i]; //��һ�ε�������������֮���������Ȩ
        }

        for(int k=0;k<outnode;k++)
        {
            e+=fabs(yd[k]-x2[k])*fabs(yd[k]-x2[k]); //���������
        }
        error=e/2.0;

        for(int k=0;k<outnode;k++)
            b2[k]=b2[k]+rate_b2*qq[k]; //��һ�ε�������������֮�������ֵ
        for(int j=0;j<hidenode;j++)
            b1[j]=b1[j]+rate_b1*pp[j]; //��һ�ε�������������֮�������ֵ
    }
}

double *BpNet::recognize(double *p)
{
    double x[innode]; //��������
    double x1[hidenode]; //�������״ֵ̬
    double x2[outnode]; //������״ֵ̬
    double o1[hidenode]; //�����㼤��ֵ
    double o2[hidenode]; //����㼤��ֵ

    for(int i=0;i<innode;i++)
        x[i]=p[i];

    for(int j=0;j<hidenode;j++)
    {
        o1[j]=0.0;
        for(int i=0;i<innode;i++)
            o1[j]=o1[j]+w[i][j]*x[i]; //���������Ԫ����ֵ
        x1[j]=1.0/(1.0+exp(-o1[j]-b1[j])); //���������Ԫ���
        //if(o1[j]+b1[j]>0) x1[j]=1;
        //    else x1[j]=0;
    }

    for(int k=0;k<outnode;k++)
    {
        o2[k]=0.0;
        for(int j=0;j<hidenode;j++)
            o2[k]=o2[k]+w1[j][k]*x1[j];//��������Ԫ����ֵ
        x2[k]=1.0/(1.0+exp(-o2[k]-b2[k]));//��������Ԫ���
        //if(o2[k]+b2[k]>0) x2[k]=1;
        //else x2[k]=0;
    }

    for(int k=0;k<outnode;k++)
    {
        result[k]=x2[k];
    }
    return result;
}
//��������
//double X[trainsample][innode]= {
//	{405,606.56,92.93},{393,660,95.35},{350.625,633.75,105.42},{384.17,400.94,112.46},{468.5,738,125.79},{502.5,885,134.02},{440,1043.5,133.48},{414.5,1071.88,116.69}
//    };
////�����������
//double Y[trainsample][outnode]={
//    {3332.58},{3314.17},{3317.1},{3552.17},{4256.29},{4329.5},{3757.42},{3509.52}
//    };
//��������
double X[trainsample][innode]= {
	{0,0,0},{0,0,1},{0,1,0},{0,1,1},{1,0,0},{1,0,1},{1,1,0},{1,1,1}
};
//�����������
double Y[trainsample][outnode]={
	{0},{0.1429},{0.2857},{0.4286},{0.5714},{0.7143},{0.8571},{1.0000}
};
int main()
{
    BpNet bp;
    bp.init();
    int times=0;
 //   while(bp.error>0.0001)
 //   {
 //       bp.e=0.0;
 //       times++;
 //       bp.train(X,Y);
 //       cout<<"Times="<<times<<" error="<<bp.error<<endl;
	//	//cout<<"*******************************************"<<endl;
 //   }
 //   cout<<"trainning complete..."<<endl;
 //   double m[innode]={1,1,1};
 //   double *r=bp.recognize(m);
 //   for(int i=0;i<outnode;++i)
 //      cout<<bp.result[i]<<" ";
 //   double cha[trainsample][outnode];
 //   double mi=100;
 //   double index;
 //   for(int i=0;i<trainsample;i++)
 //   {
 //       for(int j=0;j<outnode;j++)
 //       {
 //           //�Ҳ�ֵ��С���Ǹ�����
 //           cha[i][j]=(double)(fabs(Y[i][j]-bp.result[j]));
 //           if(cha[i][j]<mi)
 //           {
 //               mi=cha[i][j];
 //               index=i;
 //           }
 //       }
 //   }
 //   for(int i=0;i<innode;++i)
 //      cout<<m[i];
 //   cout<<" is "<<index<<endl;
 //   cout<<endl;
	  system("pause");
    return 0;
}