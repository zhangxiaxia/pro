#ifndef AREA2_H
#define AREA2_H

#include <QSqlQuery>
#include <QGLWidget>
#include "para.h"
const int Num = 7;
const int MaxData = 100;

struct Data
{
	double label[3];
};
struct POI
{
	double x;
	double y;	
};
//POI poi1;
class Area2 : public QGLWidget
{
    Q_OBJECT
public:
    explicit Area2(QWidget *parent = 0);
	void getData(double[]);
private:
	void initializeAxis();
	double changeY(double);
	void drawData();

    Data data[MaxData];
	POI  poi1;
	double xPoint[Num + 1];//x axis point
	double xOffset;
	double yOffset;
	double tinyxOffset;
	QString xLabel[Num + 1];
	QString yLabel[Num + 1];
	int xLabelN;
	int yLabelN;
	int numData;
	int width;//windows width
	int height;
	int cWidth;//canvas width
	int cHeight;
	int MaxY;
	QSqlQuery query;
protected:
	void initializeGL();
	void paintGL();
	void resizeGL(int width, int height);
signals:

public slots:

};

#endif // AREA2_H
