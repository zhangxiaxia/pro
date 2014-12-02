#include "area3.h"
#include <QtOpenGL/QtOpenGL>

Area3::Area3(QWidget *parent)
	: QGLWidget(QGLFormat(QGL::SampleBuffers), parent)
{
	height = width = cHeight = cWidth = 0; 
	maxY = 650;
	numData = 1;
	query = sqlHelper.getQuery();
}

Area3::~Area3()
{

}

void Area3::initializeGL()
{
	qglClearColor(Qt::lightGray);
	glShadeModel(GL_SMOOTH);							// Enable Smooth Shading
	glClearDepth(1.0f);									// Depth Buffer Setup
	glEnable(GL_DEPTH_TEST);							// Enables Depth Testing
	glDepthFunc(GL_LEQUAL);								// The Type Of Depth Testing To Do
	glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);	// Really Nice Perspective Calculations
}

void Area3::resizeGL(int width, int height)
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

void Area3::paintGL()
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

void Area3::drawData()
{
	query.first();
	do									//query.next()指向查找到的第一条记录，然后每次后移一条记录
	{
		int ele0 = query.value(0).toInt();				//query.value(0)是id的值，将其转换为int 型
		QString ele1 =query.value(1).toString();
		//qDebug() << ele0 <<ele1 ;						//输出两个值
	}while(query.next());
	query.first();
	do{
		glBegin(GL_LINE_LOOP);
			glVertex2f(xPoint[0],changeY(query.value(0).toDouble()));
		for (int j = 1; j < NUM; ++j)
		{
			glVertex2f(xPoint[j], changeY(query.value(j).toDouble()));
		}
			glVertex2f(xPoint[NUM],changeY(query.value(0).toDouble()));
		glEnd();
	}while (query.next());
}

void Area3::readData()
{

}

double Area3::changeY(double y)
{
	return (y * cHeight) / maxY;
}

void Area3::drawLabel()
{
	//显示文字
	QFont fontnew;
	fontnew.setPointSize(10);
	fontnew.setBold(true);
	glTranslated(0.0,0.0,0.15);
	glColor3f(1.0,0.0,0.0);

	for(int i = 0; i <= NUM; ++i){
		renderText(xPoint[i] - 15, -15, -5, "data", fontnew);
		renderText(xPoint[i] - 15, cHeight - 15, -5, "data1", fontnew);
	}
	
}

void Area3::initializeAxis()
{
	glBegin(GL_LINES);
	glVertex2f(0, 0);
	glVertex2f(cWidth, 0);//draw x axis
	glEnd();

	//draw y axises
	double xOffset = cWidth / NUM;

	for (int i = 0; i <= NUM; ++i)
	{
		xPoint[i] = xOffset * i;
		glBegin(GL_LINES);
		glVertex2f(xPoint[i], 0);
		glVertex2f(xPoint[i], cHeight - DISFONT);
		glEnd();
	}
}
