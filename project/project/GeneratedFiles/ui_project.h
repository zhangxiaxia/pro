/********************************************************************************
** Form generated from reading UI file 'project.ui'
**
** Created: Sat Nov 29 20:47:39 2014
**      by: Qt User Interface Compiler version 4.6.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PROJECT_H
#define UI_PROJECT_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QGroupBox>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QMainWindow>
#include <QtGui/QMenu>
#include <QtGui/QMenuBar>
#include <QtGui/QPushButton>
#include <QtGui/QSplitter>
#include <QtGui/QStatusBar>
#include <QtGui/QToolBar>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>
#include "area1.h"
#include "area2.h"
#include "area3.h"
#include "area4.h"

QT_BEGIN_NAMESPACE

class Ui_ProjectClass
{
public:
    QAction *action11;
    QAction *action12;
    QAction *action13;
    QAction *action21;
    QAction *action22;
    QAction *action23;
    QAction *action31;
    QAction *action32;
    QAction *action33;
    QWidget *centralWidget;
    QSplitter *splitter;
    QGroupBox *groupBox1;
    QLabel *label_title1;
    QWidget *verticalLayoutWidget;
    QVBoxLayout *verticalLayout;
    QPushButton *pushButton;
    QPushButton *pushButton_3;
    QPushButton *pushButton_2;
    QGroupBox *groupBox2;
    QLabel *label_title2;
    QWidget *layoutWidget;
    QVBoxLayout *verticalLayout_2;
    QPushButton *pushButton_4;
    QPushButton *pushButton_5;
    QPushButton *pushButton_6;
    QGroupBox *groupBox3;
    QLabel *label_title3;
    QWidget *verticalLayoutWidget_2;
    QVBoxLayout *verticalLayout_3;
    QPushButton *pushButton_7;
    QPushButton *pushButton_8;
    QPushButton *pushButton_9;
    Area2 *area2;
    Area1 *area1;
    QSplitter *splitter2;
    QLabel *label_2;
    QLabel *label2_data;
    QSplitter *splitter1;
    QLabel *label_1;
    QLabel *label1_data;
    QSplitter *splitter3;
    QLabel *label_3;
    QLabel *label3_data;
    Area3 *area3;
    Area4 *area4;
    QMenuBar *menuBar;
    QMenu *menu;
    QMenu *menu_2;
    QMenu *menu_3;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *ProjectClass)
    {
        if (ProjectClass->objectName().isEmpty())
            ProjectClass->setObjectName(QString::fromUtf8("ProjectClass"));
        ProjectClass->resize(1145, 701);
        action11 = new QAction(ProjectClass);
        action11->setObjectName(QString::fromUtf8("action11"));
        action12 = new QAction(ProjectClass);
        action12->setObjectName(QString::fromUtf8("action12"));
        action13 = new QAction(ProjectClass);
        action13->setObjectName(QString::fromUtf8("action13"));
        action21 = new QAction(ProjectClass);
        action21->setObjectName(QString::fromUtf8("action21"));
        action22 = new QAction(ProjectClass);
        action22->setObjectName(QString::fromUtf8("action22"));
        action23 = new QAction(ProjectClass);
        action23->setObjectName(QString::fromUtf8("action23"));
        action31 = new QAction(ProjectClass);
        action31->setObjectName(QString::fromUtf8("action31"));
        action32 = new QAction(ProjectClass);
        action32->setObjectName(QString::fromUtf8("action32"));
        action33 = new QAction(ProjectClass);
        action33->setObjectName(QString::fromUtf8("action33"));
        centralWidget = new QWidget(ProjectClass);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        splitter = new QSplitter(centralWidget);
        splitter->setObjectName(QString::fromUtf8("splitter"));
        splitter->setGeometry(QRect(10, 30, 301, 571));
        splitter->setOrientation(Qt::Vertical);
        groupBox1 = new QGroupBox(splitter);
        groupBox1->setObjectName(QString::fromUtf8("groupBox1"));
        label_title1 = new QLabel(groupBox1);
        label_title1->setObjectName(QString::fromUtf8("label_title1"));
        label_title1->setGeometry(QRect(20, 10, 21, 121));
        label_title1->setLayoutDirection(Qt::LeftToRight);
        label_title1->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);
        label_title1->setWordWrap(true);
        verticalLayoutWidget = new QWidget(groupBox1);
        verticalLayoutWidget->setObjectName(QString::fromUtf8("verticalLayoutWidget"));
        verticalLayoutWidget->setGeometry(QRect(50, 10, 211, 121));
        verticalLayout = new QVBoxLayout(verticalLayoutWidget);
        verticalLayout->setSpacing(0);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        pushButton = new QPushButton(verticalLayoutWidget);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        QSizePolicy sizePolicy(QSizePolicy::Minimum, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(pushButton->sizePolicy().hasHeightForWidth());
        pushButton->setSizePolicy(sizePolicy);

        verticalLayout->addWidget(pushButton);

        pushButton_3 = new QPushButton(verticalLayoutWidget);
        pushButton_3->setObjectName(QString::fromUtf8("pushButton_3"));
        sizePolicy.setHeightForWidth(pushButton_3->sizePolicy().hasHeightForWidth());
        pushButton_3->setSizePolicy(sizePolicy);

        verticalLayout->addWidget(pushButton_3);

        pushButton_2 = new QPushButton(verticalLayoutWidget);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));
        sizePolicy.setHeightForWidth(pushButton_2->sizePolicy().hasHeightForWidth());
        pushButton_2->setSizePolicy(sizePolicy);

        verticalLayout->addWidget(pushButton_2);

        pushButton_3->raise();
        pushButton_2->raise();
        pushButton->raise();
        splitter->addWidget(groupBox1);
        groupBox2 = new QGroupBox(splitter);
        groupBox2->setObjectName(QString::fromUtf8("groupBox2"));
        label_title2 = new QLabel(groupBox2);
        label_title2->setObjectName(QString::fromUtf8("label_title2"));
        label_title2->setGeometry(QRect(20, 20, 21, 121));
        label_title2->setLayoutDirection(Qt::LeftToRight);
        label_title2->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);
        label_title2->setWordWrap(true);
        layoutWidget = new QWidget(groupBox2);
        layoutWidget->setObjectName(QString::fromUtf8("layoutWidget"));
        layoutWidget->setGeometry(QRect(50, 20, 211, 131));
        verticalLayout_2 = new QVBoxLayout(layoutWidget);
        verticalLayout_2->setSpacing(0);
        verticalLayout_2->setContentsMargins(11, 11, 11, 11);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        verticalLayout_2->setSizeConstraint(QLayout::SetDefaultConstraint);
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        pushButton_4 = new QPushButton(layoutWidget);
        pushButton_4->setObjectName(QString::fromUtf8("pushButton_4"));
        sizePolicy.setHeightForWidth(pushButton_4->sizePolicy().hasHeightForWidth());
        pushButton_4->setSizePolicy(sizePolicy);

        verticalLayout_2->addWidget(pushButton_4);

        pushButton_5 = new QPushButton(layoutWidget);
        pushButton_5->setObjectName(QString::fromUtf8("pushButton_5"));
        sizePolicy.setHeightForWidth(pushButton_5->sizePolicy().hasHeightForWidth());
        pushButton_5->setSizePolicy(sizePolicy);

        verticalLayout_2->addWidget(pushButton_5);

        pushButton_6 = new QPushButton(layoutWidget);
        pushButton_6->setObjectName(QString::fromUtf8("pushButton_6"));
        sizePolicy.setHeightForWidth(pushButton_6->sizePolicy().hasHeightForWidth());
        pushButton_6->setSizePolicy(sizePolicy);

        verticalLayout_2->addWidget(pushButton_6);

        splitter->addWidget(groupBox2);
        groupBox3 = new QGroupBox(splitter);
        groupBox3->setObjectName(QString::fromUtf8("groupBox3"));
        label_title3 = new QLabel(groupBox3);
        label_title3->setObjectName(QString::fromUtf8("label_title3"));
        label_title3->setGeometry(QRect(20, 10, 21, 121));
        label_title3->setLayoutDirection(Qt::LeftToRight);
        label_title3->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);
        label_title3->setWordWrap(true);
        verticalLayoutWidget_2 = new QWidget(groupBox3);
        verticalLayoutWidget_2->setObjectName(QString::fromUtf8("verticalLayoutWidget_2"));
        verticalLayoutWidget_2->setGeometry(QRect(50, 10, 211, 121));
        verticalLayout_3 = new QVBoxLayout(verticalLayoutWidget_2);
        verticalLayout_3->setSpacing(0);
        verticalLayout_3->setContentsMargins(11, 11, 11, 11);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        verticalLayout_3->setContentsMargins(0, 0, 0, 0);
        pushButton_7 = new QPushButton(verticalLayoutWidget_2);
        pushButton_7->setObjectName(QString::fromUtf8("pushButton_7"));
        sizePolicy.setHeightForWidth(pushButton_7->sizePolicy().hasHeightForWidth());
        pushButton_7->setSizePolicy(sizePolicy);

        verticalLayout_3->addWidget(pushButton_7);

        pushButton_8 = new QPushButton(verticalLayoutWidget_2);
        pushButton_8->setObjectName(QString::fromUtf8("pushButton_8"));
        sizePolicy.setHeightForWidth(pushButton_8->sizePolicy().hasHeightForWidth());
        pushButton_8->setSizePolicy(sizePolicy);

        verticalLayout_3->addWidget(pushButton_8);

        pushButton_9 = new QPushButton(verticalLayoutWidget_2);
        pushButton_9->setObjectName(QString::fromUtf8("pushButton_9"));
        sizePolicy.setHeightForWidth(pushButton_9->sizePolicy().hasHeightForWidth());
        pushButton_9->setSizePolicy(sizePolicy);

        verticalLayout_3->addWidget(pushButton_9);

        splitter->addWidget(groupBox3);
        area2 = new Area2(centralWidget);
        area2->setObjectName(QString::fromUtf8("area2"));
        area2->setGeometry(QRect(730, 30, 391, 231));
        area1 = new Area1(centralWidget);
        area1->setObjectName(QString::fromUtf8("area1"));
        area1->setGeometry(QRect(310, 30, 391, 231));
        splitter2 = new QSplitter(area1);
        splitter2->setObjectName(QString::fromUtf8("splitter2"));
        splitter2->setGeometry(QRect(40, 90, 144, 15));
        splitter2->setOrientation(Qt::Horizontal);
        label_2 = new QLabel(splitter2);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setTextFormat(Qt::PlainText);
        splitter2->addWidget(label_2);
        label2_data = new QLabel(splitter2);
        label2_data->setObjectName(QString::fromUtf8("label2_data"));
        label2_data->setTextFormat(Qt::PlainText);
        label2_data->setAlignment(Qt::AlignCenter);
        splitter2->addWidget(label2_data);
        splitter1 = new QSplitter(area1);
        splitter1->setObjectName(QString::fromUtf8("splitter1"));
        splitter1->setGeometry(QRect(41, 31, 144, 15));
        splitter1->setOrientation(Qt::Horizontal);
        label_1 = new QLabel(splitter1);
        label_1->setObjectName(QString::fromUtf8("label_1"));
        label_1->setTextFormat(Qt::PlainText);
        splitter1->addWidget(label_1);
        label1_data = new QLabel(splitter1);
        label1_data->setObjectName(QString::fromUtf8("label1_data"));
        label1_data->setTextFormat(Qt::AutoText);
        label1_data->setAlignment(Qt::AlignCenter);
        splitter1->addWidget(label1_data);
        splitter3 = new QSplitter(area1);
        splitter3->setObjectName(QString::fromUtf8("splitter3"));
        splitter3->setGeometry(QRect(40, 150, 144, 15));
        splitter3->setOrientation(Qt::Horizontal);
        label_3 = new QLabel(splitter3);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setTextFormat(Qt::PlainText);
        splitter3->addWidget(label_3);
        label3_data = new QLabel(splitter3);
        label3_data->setObjectName(QString::fromUtf8("label3_data"));
        label3_data->setTextFormat(Qt::PlainText);
        label3_data->setAlignment(Qt::AlignCenter);
        splitter3->addWidget(label3_data);
        area3 = new Area3(centralWidget);
        area3->setObjectName(QString::fromUtf8("area3"));
        area3->setGeometry(QRect(310, 290, 401, 311));
        area4 = new Area4(centralWidget);
        area4->setObjectName(QString::fromUtf8("area4"));
        area4->setGeometry(QRect(720, 290, 401, 311));
        ProjectClass->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(ProjectClass);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 1145, 23));
        menu = new QMenu(menuBar);
        menu->setObjectName(QString::fromUtf8("menu"));
        menu_2 = new QMenu(menuBar);
        menu_2->setObjectName(QString::fromUtf8("menu_2"));
        menu_3 = new QMenu(menuBar);
        menu_3->setObjectName(QString::fromUtf8("menu_3"));
        ProjectClass->setMenuBar(menuBar);
        mainToolBar = new QToolBar(ProjectClass);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        ProjectClass->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(ProjectClass);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        ProjectClass->setStatusBar(statusBar);

        menuBar->addAction(menu->menuAction());
        menuBar->addAction(menu_2->menuAction());
        menuBar->addAction(menu_3->menuAction());
        menu->addAction(action11);
        menu->addAction(action12);
        menu->addAction(action13);
        menu_2->addAction(action21);
        menu_2->addAction(action22);
        menu_2->addAction(action23);
        menu_3->addAction(action31);
        menu_3->addAction(action32);
        menu_3->addAction(action33);

        retranslateUi(ProjectClass);

        QMetaObject::connectSlotsByName(ProjectClass);
    } // setupUi

    void retranslateUi(QMainWindow *ProjectClass)
    {
        ProjectClass->setWindowTitle(QApplication::translate("ProjectClass", "Project", 0, QApplication::UnicodeUTF8));
        action11->setText(QApplication::translate("ProjectClass", "\346\214\207\346\225\260\345\271\263\346\273\221\346\263\225", 0, QApplication::UnicodeUTF8));
        action12->setText(QApplication::translate("ProjectClass", "\345\255\243\350\212\202\346\214\207\346\225\260\346\263\225", 0, QApplication::UnicodeUTF8));
        action13->setText(QApplication::translate("ProjectClass", "ARMA\346\263\225", 0, QApplication::UnicodeUTF8));
        action21->setText(QApplication::translate("ProjectClass", "BP\347\245\236\347\273\217\347\275\221\347\273\234", 0, QApplication::UnicodeUTF8));
        action22->setText(QApplication::translate("ProjectClass", "\345\260\217\346\263\242\347\245\236\347\273\217\347\275\221\347\273\234", 0, QApplication::UnicodeUTF8));
        action23->setText(QApplication::translate("ProjectClass", "GARCA\346\250\241\345\236\213", 0, QApplication::UnicodeUTF8));
        action31->setText(QApplication::translate("ProjectClass", "BP+\346\214\207\346\225\260\345\271\263\346\273\221", 0, QApplication::UnicodeUTF8));
        action32->setText(QApplication::translate("ProjectClass", "\345\260\217\346\263\242+\345\255\243\350\212\202\346\214\207\346\225\260\345\271\263\346\273\221", 0, QApplication::UnicodeUTF8));
        action33->setText(QApplication::translate("ProjectClass", "GARCA + \346\214\207\346\225\260\345\271\263\346\273\221", 0, QApplication::UnicodeUTF8));
        groupBox1->setTitle(QString());
        label_title1->setText(QApplication::translate("ProjectClass", "\345\215\225\345\217\230\351\207\217\351\242\204\346\265\213", 0, QApplication::UnicodeUTF8));
        pushButton->setText(QApplication::translate("ProjectClass", "\346\214\207\346\225\260\345\271\263\346\273\221\346\263\225", 0, QApplication::UnicodeUTF8));
        pushButton_3->setText(QApplication::translate("ProjectClass", "\345\255\243\350\212\202\346\214\207\346\225\260\346\263\225", 0, QApplication::UnicodeUTF8));
        pushButton_2->setText(QApplication::translate("ProjectClass", "ARMA\346\263\225", 0, QApplication::UnicodeUTF8));
        groupBox2->setTitle(QString());
        label_title2->setText(QApplication::translate("ProjectClass", "\345\233\240\347\264\240\351\242\204\346\265\213", 0, QApplication::UnicodeUTF8));
        pushButton_4->setText(QApplication::translate("ProjectClass", "BP\347\245\236\347\273\217\347\275\221\347\273\234", 0, QApplication::UnicodeUTF8));
        pushButton_5->setText(QApplication::translate("ProjectClass", "\345\260\217\346\263\242\347\245\236\347\273\217\347\275\221\347\273\234", 0, QApplication::UnicodeUTF8));
        pushButton_6->setText(QApplication::translate("ProjectClass", "GARCA\346\250\241\345\236\213", 0, QApplication::UnicodeUTF8));
        groupBox3->setTitle(QString());
        label_title3->setText(QApplication::translate("ProjectClass", "\347\273\204\345\220\210\351\242\204\346\265\213\346\263\225", 0, QApplication::UnicodeUTF8));
        pushButton_7->setText(QApplication::translate("ProjectClass", "BP+\346\214\207\346\225\260\345\271\263\346\273\221", 0, QApplication::UnicodeUTF8));
        pushButton_8->setText(QApplication::translate("ProjectClass", "\345\260\217\346\263\242+\345\255\243\350\212\202\346\214\207\346\225\260\345\271\263\346\273\221", 0, QApplication::UnicodeUTF8));
        pushButton_9->setText(QApplication::translate("ProjectClass", "GARCA+\346\214\207\346\225\260\345\271\263\346\273\221", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("ProjectClass", "\351\242\204\346\265\213\344\272\214\344\270\252\346\234\210", 0, QApplication::UnicodeUTF8));
        label2_data->setText(QApplication::translate("ProjectClass", "300", 0, QApplication::UnicodeUTF8));
        label_1->setText(QApplication::translate("ProjectClass", "\351\242\204\346\265\213\344\270\200\344\270\252\346\234\210", 0, QApplication::UnicodeUTF8));
        label1_data->setText(QApplication::translate("ProjectClass", "50", 0, QApplication::UnicodeUTF8));
        label_3->setText(QApplication::translate("ProjectClass", "\351\242\204\346\265\213\344\270\211\344\270\252\346\234\210", 0, QApplication::UnicodeUTF8));
        label3_data->setText(QApplication::translate("ProjectClass", "400", 0, QApplication::UnicodeUTF8));
        menu->setTitle(QApplication::translate("ProjectClass", "\345\215\225\345\217\230\351\207\217\351\242\204\346\265\213", 0, QApplication::UnicodeUTF8));
        menu_2->setTitle(QApplication::translate("ProjectClass", "\345\233\240\347\264\240\351\242\204\346\265\213", 0, QApplication::UnicodeUTF8));
        menu_3->setTitle(QApplication::translate("ProjectClass", "\347\273\204\345\220\210\351\242\204\346\265\213\346\263\225", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class ProjectClass: public Ui_ProjectClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PROJECT_H
