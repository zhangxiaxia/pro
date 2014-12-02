#include "area4.h"
#include <QtOpenGL/QtOpenGL>

Area4::Area4(QWidget *parent)
: QGLWidget(QGLFormat(QGL::SampleBuffers), parent)
{
	height = width = cHeight = cWidth = 0; 

	query = sqlHelper.getQuery();
}

Area4::~Area4()
{
	
}

void Area4::initializeGL()
{
	qglClearColor(Qt::lightGray);
	glShadeModel(GL_SMOOTH);							// Enable Smooth Shading
	glClearDepth(1.0f);									// Depth Buffer Setup
	glEnable(GL_DEPTH_TEST);							// Enables Depth Testing
	glDepthFunc(GL_LEQUAL);								// The Type Of Depth Testing To Do
	glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);	// Really Nice Perspective Calculations
}

void Area4::resizeGL(int width, int height)
{
	this->width = width;
	this->height = height;
	cWidth = width - DISFONT;
	cHeight = height - DISFONT;

	glViewport(0,0,width,height);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();

	glOrtho(0, width, 0, height, -10, 10.0);
	glMatrixMode(GL_MODELVIEW);
}

void Area4::paintGL()
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

	//draw labels in x and y axises
	drawLabel();

	//draw data
	drawData();

	glFlush();
}

void Area4::drawData()
{
	for(int i = 0; i < NUMLINE; ++i){
		for(int j = 0; j < NUMLINE; ++j)
		{
			glLoadIdentity();
			glTranslatef(xPoint[i] + DISFONT, yPoint[j] + DISFONT, -5);//重置观察矩阵

			//draw data
			glPointSize(2);
			glBegin(GL_POINTS);
			query.first();
			do{
				glVertex2f(changeX(query.value(i).toDouble()), changeY(query.value(j).toDouble()));
			}while(query.next());

			glEnd();
		}
	}
}

void Area4::readData()
{

}

double Area4::changeY(double y)
{
	return  (y * yOffset) / 650 ;//(y * cHeight) / maxY;
}

double Area4::changeX(double x)
{
	return (x * yOffset) / 650;//(x * cHeight) / maxY;
}

void Area4::drawLabel()
{
	//显示文字
	QFont fontnew;
	fontnew.setPointSize(10);
	fontnew.setBold(true);
	glColor3f(1.0,0.0,0.0);

	for(int i = 0; i < NUMLINE; ++i){
		renderText(xPoint[i], -15, -5, "data", fontnew);
		renderText(-25, yPoint[NUMLINE - i] - 14, -5, "da", fontnew);
		//renderText(-15, yPoint[NUMLINE - i] - 12, -5, "a", fontnew);
		//renderText(-15, yPoint[NUMLINE - i] - 20, -5, "t", fontnew);
	}

}

void Area4::initializeAxis()
{
	//draw x axises
	yOffset = cHeight / NUMLINE;

	for (int i = 0; i <= NUMLINE; ++i)
	{
		yPoint[i] = yOffset * i;
		glBegin(GL_LINES);
		glVertex2f(0, yPoint[i]);
		glVertex2f(cWidth, yPoint[i]);
		glEnd();
	}

	//draw y axises
	xOffset = cWidth / NUMLINE;

	for (int i = 0; i <= NUMLINE; ++i)
	{
		xPoint[i] = xOffset * i;
		glBegin(GL_LINES);
		glVertex2f(xPoint[i], 0);
		glVertex2f(xPoint[i], cHeight);
		glEnd();
	}
}
