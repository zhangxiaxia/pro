#ifndef AREA3_H
#define AREA3_H

#include <QGLWidget>
#include "sqlHelper.h"
#include "para.h"

class Area3 : public QGLWidget
{
	Q_OBJECT

public:
	Area3(QWidget *parent);
	~Area3();
	void readData();
protected:
	void initializeGL();
	void paintGL();
	void resizeGL(int width, int height);
private:
	void initializeAxis();
	double changeY(double y);
	void drawLabel();
	void drawData();

	int numData;
	int width;//windows width
	int height;
	int cWidth;//canvas width
	int cHeight;
	int maxY;//the max num in y axis 
	double xPoint[NUM + 1];
	double data[NUM + 1][MAXDATA];
	SqlHelper sqlHelper;
	QSqlQuery query;
};

#endif // AREA3_H
