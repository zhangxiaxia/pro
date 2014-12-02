#include "area2.h"
#include <QtOpenGL/QtOpenGL>
#include <qdatetime.h>

Area2::Area2(QWidget *parent)
	: QGLWidget(QGLFormat(QGL::SampleBuffers), parent)
{
	numData = 0;
	xLabel[0] = "label1";
	xLabel[1] = "label2";
	xLabel[2] = "label3";
	xLabelN = 3;

	yLabel[0] = "120";
	yLabel[1] = "240";
	yLabel[2] = "360";
	yLabel[3] = "480";
	yLabel[4] = "600";
	MaxY = 600;
	yLabelN = 5;

	/*****************************************/
	query.exec("Select Date, Kor from data");
}


void Area2::initializeGL()
{
	qglClearColor(Qt::lightGray);
	glShadeModel(GL_SMOOTH);							// Enable Smooth Shading
	glClearDepth(1.0f);									// Depth Buffer Setup
	glEnable(GL_DEPTH_TEST);							// Enables Depth Testing
	glDepthFunc(GL_LEQUAL);								// The Type Of Depth Testing To Do
	glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);	// Really Nice Perspective Calculations
}

void Area2::resizeGL(int width, int height)
{
	this->width = width;
	this->height = height;
	cWidth = width - DISFONT;
	cHeight = height -DISFONT;

	glViewport(0,0,width,height);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();

	glOrtho(0, width, 0, height, -10, 10.0);
	glMatrixMode(GL_MODELVIEW);
}


void Area2::paintGL()
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glLoadIdentity();	
	glEnable(GL_POLYGON_SMOOTH);
	glEnable(GL_LINE_SMOOTH);
	glHint(GL_POLYGON_SMOOTH_HINT, GL_NICEST); // Make round points, not square points
	glHint(GL_LINE_SMOOTH_HINT, GL_NICEST); // Antialias the lines
	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

	glTranslatef(DISFONT, DISFONT, -5.0);//move (0 , 0) to (disfont, disfont)
	qglColor(Qt::black);

	initializeAxis();

	//draw data
	drawData();

	glFlush();
}

void Area2::getData(double data1[])
{
	data[numData].label[0] = data1[0];
	data[numData].label[1] = data1[1];
	data[numData].label[2] = data1[2];
	numData++;
}

double Area2::changeY(double y)
{
	return (cHeight * y / MaxY);
}

void Area2::drawData()
{	
	glColor3f(1.0,0.0,0.0);
	glPointSize(2);
	query.first();
	glBegin(GL_POINTS);
	do 
	{
			QDate time = query.value(0).toDate();
			int year = time.year();
			int month = time.month();
			glBegin(GL_LINE_LOOP);
			glColor3f(1.0,0.0,0.0);
			glVertex2f(poi1.x,poi1.y);
			glVertex2f(xPoint[year - 2008] + month * tinyxOffset,changeY(query.value(1).toDouble()));
			glEnd();
			poi1.x = xPoint[year - 2008] + month * tinyxOffset;
			poi1.y = changeY(query.value(1).toDouble());
		
	} while (query.next());
	glEnd();
}

void Area2::initializeAxis()
{
	xOffset = cWidth / Num;
	yOffset = (cHeight - DISFONT) / Num;
	tinyxOffset = xOffset / 12;//each month

	for(int i = 0; i < Num; ++i)
		xPoint[i] = xOffset * i;
	glBegin(GL_LINES);
	glVertex2f(0, 0);
	glVertex2f(cWidth, 0);//draw x axis

	glVertex2f(0,0);
	glVertex2f(0,cHeight - DISFONT);
	glEnd();

	//draw x point
	for (int i = 1; i <= Num; ++i)
	{
		glBegin(GL_LINES);
		glVertex2f(0, yOffset * i);
		glVertex2f(DISFONT / 5, yOffset * i);
		glEnd();
	}

	//draw y point
	for (int i = 1; i <= Num; ++i)
	{
		glBegin(GL_LINES);
		glVertex2f(xPoint[i], 0);
		glVertex2f(xPoint[i], DISFONT / 5);
		glEnd();
	}
}
