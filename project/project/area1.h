#ifndef AREA1_H
#define AREA1_H

#include <QWidget>
#include <QLabel>

class Area1 : public QWidget
{
    Q_OBJECT
public:
    explicit Area1(QWidget *parent = 0);
private:
	double data[3];
signals:

public slots:

};

#endif // AREA1_H
