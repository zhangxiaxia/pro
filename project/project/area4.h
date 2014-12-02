#ifndef AREA4_H
#define AREA4_H

#include <QGLWidget>
#include "sqlHelper.h"
#include "para.h"

const int NUMLINE = 6;

class Area4 : public QGLWidget
{
	Q_OBJECT

public:
	Area4(QWidget *parent);
	~Area4();
	void readData();
protected:
	void initializeGL();
	void paintGL();
	void resizeGL(int width, int height);
private:
	void initializeAxis();
	double changeY(double y);
	double changeX(double x);
	void drawLabel();
	void drawData();

	int numData;
	double width;//windows width
	double height;
	double cWidth;//canvas width
	double cHeight;
	double xPoint[NUMLINE + 1];
	double yPoint[NUMLINE + 1];
	double data[NUMLINE + 1][MAXDATA];
	double xOffset;
	double yOffset;
	SqlHelper sqlHelper;
	QSqlQuery query;
};

#endif // AREA4_H
