/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.2.4
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGraphicsView>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QHBoxLayout *horizontalLayout_3;
    QVBoxLayout *ControlLayout;
    QVBoxLayout *CipperColorBox;
    QLabel *TaskLabel;
    QFrame *line_5;
    QLabel *CipperColorLabel;
    QHBoxLayout *CipperColorLay;
    QPushButton *ButtonBlackCipper;
    QPushButton *ButtonWhiteCipper;
    QPushButton *ButtonYellowCipper;
    QPushButton *ButtonRedCipper;
    QPushButton *ButtonOrangeCipper;
    QPushButton *ButtonPurpleCipper;
    QPushButton *ButtonBlueCipper;
    QPushButton *ButtonGreenCipper;
    QVBoxLayout *FragmentColorBox;
    QLabel *LIneColorFragment;
    QHBoxLayout *FragmentColorsLay;
    QPushButton *ButtonBlackFragment;
    QPushButton *ButtonWhiteFragment;
    QPushButton *ButtonYellowFragment;
    QPushButton *ButtonRedFragment;
    QPushButton *ButtonOrangeFragment;
    QPushButton *ButtonPurpleFragment;
    QPushButton *ButtonBlueFragment;
    QPushButton *ButtonGreenFragment;
    QVBoxLayout *LineColorBox;
    QLabel *LIneColorLabel;
    QHBoxLayout *LineColorsLay;
    QPushButton *ButtonBlackLine;
    QPushButton *ButtonWhiteLine;
    QPushButton *ButtonYellowLine;
    QPushButton *ButtonRedLine;
    QPushButton *ButtonOrangeLine;
    QPushButton *ButtonPurpleLine;
    QPushButton *ButtonBlueLine;
    QPushButton *ButtonGreenLine;
    QFrame *line_2;
    QVBoxLayout *verticalLayout_5;
    QLabel *label_6;
    QHBoxLayout *horizontalLayout_2;
    QVBoxLayout *verticalLayout_3;
    QLabel *label_3;
    QFormLayout *Lb_clipper_form_2;
    QLabel *lb_x_clipperLabel_3;
    QLineEdit *start_x_LE;
    QLabel *lb_y_clipperLabel_3;
    QLineEdit *start_y_LE;
    QVBoxLayout *verticalLayout_4;
    QLabel *label_4;
    QFormLayout *RT_clipper_form_2;
    QLabel *rt_x_clipperLabel_2;
    QLineEdit *end_x_LE;
    QLabel *rt_y_clipperLabel_2;
    QLineEdit *end_y_LE;
    QPushButton *DrawSegmentButton;
    QFrame *line;
    QLabel *label_5;
    QHBoxLayout *horizontalLayout;
    QVBoxLayout *verticalLayout;
    QLabel *label;
    QFormLayout *Lt_clipper_form;
    QLabel *lb_x_clipperLabel;
    QLineEdit *lt_x_clipperLineEdit;
    QLabel *lb_y_clipperLabel;
    QLineEdit *lt_y_clipperLineEdit;
    QVBoxLayout *verticalLayout_2;
    QLabel *label_2;
    QFormLayout *RB_clipper_form;
    QLabel *rt_x_clipperLabel;
    QLineEdit *rb_x_clipperLineEdit;
    QLabel *rt_y_clipperLabel;
    QLineEdit *rb_y_clipperLineEdit;
    QPushButton *DrawClipperButton;
    QFrame *line_3;
    QHBoxLayout *ActionLayout;
    QPushButton *CleanButton;
    QPushButton *DrawButton;
    QFrame *line_4;
    QLabel *label_7;
    QTableWidget *PointTableWidget;
    QGraphicsView *ResView;
    QMenuBar *menubar;
    QMenu *menu_7;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(1227, 909);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        horizontalLayout_3 = new QHBoxLayout(centralwidget);
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        ControlLayout = new QVBoxLayout();
        ControlLayout->setObjectName(QString::fromUtf8("ControlLayout"));
        CipperColorBox = new QVBoxLayout();
        CipperColorBox->setObjectName(QString::fromUtf8("CipperColorBox"));
        TaskLabel = new QLabel(centralwidget);
        TaskLabel->setObjectName(QString::fromUtf8("TaskLabel"));
        QFont font;
        font.setPointSize(12);
        TaskLabel->setFont(font);
        TaskLabel->setAlignment(Qt::AlignCenter);

        CipperColorBox->addWidget(TaskLabel);

        line_5 = new QFrame(centralwidget);
        line_5->setObjectName(QString::fromUtf8("line_5"));
        line_5->setFrameShape(QFrame::HLine);
        line_5->setFrameShadow(QFrame::Sunken);

        CipperColorBox->addWidget(line_5);

        CipperColorLabel = new QLabel(centralwidget);
        CipperColorLabel->setObjectName(QString::fromUtf8("CipperColorLabel"));
        QSizePolicy sizePolicy(QSizePolicy::Minimum, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(CipperColorLabel->sizePolicy().hasHeightForWidth());
        CipperColorLabel->setSizePolicy(sizePolicy);
        CipperColorLabel->setFont(font);
        CipperColorLabel->setAlignment(Qt::AlignCenter);

        CipperColorBox->addWidget(CipperColorLabel);

        CipperColorLay = new QHBoxLayout();
        CipperColorLay->setObjectName(QString::fromUtf8("CipperColorLay"));
        ButtonBlackCipper = new QPushButton(centralwidget);
        ButtonBlackCipper->setObjectName(QString::fromUtf8("ButtonBlackCipper"));
        sizePolicy.setHeightForWidth(ButtonBlackCipper->sizePolicy().hasHeightForWidth());
        ButtonBlackCipper->setSizePolicy(sizePolicy);
        ButtonBlackCipper->setStyleSheet(QString::fromUtf8("QPushButton{\n"
"	background-color: rgb(0,0,0);\n"
"}"));

        CipperColorLay->addWidget(ButtonBlackCipper);

        ButtonWhiteCipper = new QPushButton(centralwidget);
        ButtonWhiteCipper->setObjectName(QString::fromUtf8("ButtonWhiteCipper"));
        sizePolicy.setHeightForWidth(ButtonWhiteCipper->sizePolicy().hasHeightForWidth());
        ButtonWhiteCipper->setSizePolicy(sizePolicy);
        ButtonWhiteCipper->setStyleSheet(QString::fromUtf8("QPushButton{\n"
"	background-color: rgb(255,255,255);\n"
"}"));

        CipperColorLay->addWidget(ButtonWhiteCipper);

        ButtonYellowCipper = new QPushButton(centralwidget);
        ButtonYellowCipper->setObjectName(QString::fromUtf8("ButtonYellowCipper"));
        sizePolicy.setHeightForWidth(ButtonYellowCipper->sizePolicy().hasHeightForWidth());
        ButtonYellowCipper->setSizePolicy(sizePolicy);
        ButtonYellowCipper->setStyleSheet(QString::fromUtf8("QPushButton{\n"
"	background-color: rgb(255,255,0);\n"
"}"));

        CipperColorLay->addWidget(ButtonYellowCipper);

        ButtonRedCipper = new QPushButton(centralwidget);
        ButtonRedCipper->setObjectName(QString::fromUtf8("ButtonRedCipper"));
        sizePolicy.setHeightForWidth(ButtonRedCipper->sizePolicy().hasHeightForWidth());
        ButtonRedCipper->setSizePolicy(sizePolicy);
        ButtonRedCipper->setStyleSheet(QString::fromUtf8("QPushButton{\n"
"	background-color: rgb(255,0,0);\n"
"}"));

        CipperColorLay->addWidget(ButtonRedCipper);

        ButtonOrangeCipper = new QPushButton(centralwidget);
        ButtonOrangeCipper->setObjectName(QString::fromUtf8("ButtonOrangeCipper"));
        sizePolicy.setHeightForWidth(ButtonOrangeCipper->sizePolicy().hasHeightForWidth());
        ButtonOrangeCipper->setSizePolicy(sizePolicy);
        ButtonOrangeCipper->setStyleSheet(QString::fromUtf8("QPushButton{\n"
"	background-color: rgb(255,104,0);\n"
"}"));

        CipperColorLay->addWidget(ButtonOrangeCipper);

        ButtonPurpleCipper = new QPushButton(centralwidget);
        ButtonPurpleCipper->setObjectName(QString::fromUtf8("ButtonPurpleCipper"));
        sizePolicy.setHeightForWidth(ButtonPurpleCipper->sizePolicy().hasHeightForWidth());
        ButtonPurpleCipper->setSizePolicy(sizePolicy);
        ButtonPurpleCipper->setStyleSheet(QString::fromUtf8("QPushButton{\n"
"	background-color: rgb(128,0,128);\n"
"}"));

        CipperColorLay->addWidget(ButtonPurpleCipper);

        ButtonBlueCipper = new QPushButton(centralwidget);
        ButtonBlueCipper->setObjectName(QString::fromUtf8("ButtonBlueCipper"));
        sizePolicy.setHeightForWidth(ButtonBlueCipper->sizePolicy().hasHeightForWidth());
        ButtonBlueCipper->setSizePolicy(sizePolicy);
        ButtonBlueCipper->setStyleSheet(QString::fromUtf8("QPushButton{\n"
"	background-color: rgb(0,0,255);\n"
"}"));

        CipperColorLay->addWidget(ButtonBlueCipper);

        ButtonGreenCipper = new QPushButton(centralwidget);
        ButtonGreenCipper->setObjectName(QString::fromUtf8("ButtonGreenCipper"));
        sizePolicy.setHeightForWidth(ButtonGreenCipper->sizePolicy().hasHeightForWidth());
        ButtonGreenCipper->setSizePolicy(sizePolicy);
        ButtonGreenCipper->setStyleSheet(QString::fromUtf8("QPushButton{\n"
"	background-color: rgb(0,255,0);\n"
"}"));

        CipperColorLay->addWidget(ButtonGreenCipper);


        CipperColorBox->addLayout(CipperColorLay);


        ControlLayout->addLayout(CipperColorBox);

        FragmentColorBox = new QVBoxLayout();
        FragmentColorBox->setObjectName(QString::fromUtf8("FragmentColorBox"));
        LIneColorFragment = new QLabel(centralwidget);
        LIneColorFragment->setObjectName(QString::fromUtf8("LIneColorFragment"));
        sizePolicy.setHeightForWidth(LIneColorFragment->sizePolicy().hasHeightForWidth());
        LIneColorFragment->setSizePolicy(sizePolicy);
        LIneColorFragment->setFont(font);
        LIneColorFragment->setAlignment(Qt::AlignCenter);

        FragmentColorBox->addWidget(LIneColorFragment);

        FragmentColorsLay = new QHBoxLayout();
        FragmentColorsLay->setObjectName(QString::fromUtf8("FragmentColorsLay"));
        ButtonBlackFragment = new QPushButton(centralwidget);
        ButtonBlackFragment->setObjectName(QString::fromUtf8("ButtonBlackFragment"));
        sizePolicy.setHeightForWidth(ButtonBlackFragment->sizePolicy().hasHeightForWidth());
        ButtonBlackFragment->setSizePolicy(sizePolicy);
        ButtonBlackFragment->setStyleSheet(QString::fromUtf8("QPushButton{\n"
"	background-color: rgb(0,0,0);\n"
"}"));

        FragmentColorsLay->addWidget(ButtonBlackFragment);

        ButtonWhiteFragment = new QPushButton(centralwidget);
        ButtonWhiteFragment->setObjectName(QString::fromUtf8("ButtonWhiteFragment"));
        sizePolicy.setHeightForWidth(ButtonWhiteFragment->sizePolicy().hasHeightForWidth());
        ButtonWhiteFragment->setSizePolicy(sizePolicy);
        ButtonWhiteFragment->setStyleSheet(QString::fromUtf8("QPushButton{\n"
"	background-color: rgb(255,255,255);\n"
"}"));

        FragmentColorsLay->addWidget(ButtonWhiteFragment);

        ButtonYellowFragment = new QPushButton(centralwidget);
        ButtonYellowFragment->setObjectName(QString::fromUtf8("ButtonYellowFragment"));
        sizePolicy.setHeightForWidth(ButtonYellowFragment->sizePolicy().hasHeightForWidth());
        ButtonYellowFragment->setSizePolicy(sizePolicy);
        ButtonYellowFragment->setStyleSheet(QString::fromUtf8("QPushButton{\n"
"	background-color: rgb(255,255,0);\n"
"}"));

        FragmentColorsLay->addWidget(ButtonYellowFragment);

        ButtonRedFragment = new QPushButton(centralwidget);
        ButtonRedFragment->setObjectName(QString::fromUtf8("ButtonRedFragment"));
        sizePolicy.setHeightForWidth(ButtonRedFragment->sizePolicy().hasHeightForWidth());
        ButtonRedFragment->setSizePolicy(sizePolicy);
        ButtonRedFragment->setStyleSheet(QString::fromUtf8("QPushButton{\n"
"	background-color: rgb(255,0,0);\n"
"}"));

        FragmentColorsLay->addWidget(ButtonRedFragment);

        ButtonOrangeFragment = new QPushButton(centralwidget);
        ButtonOrangeFragment->setObjectName(QString::fromUtf8("ButtonOrangeFragment"));
        sizePolicy.setHeightForWidth(ButtonOrangeFragment->sizePolicy().hasHeightForWidth());
        ButtonOrangeFragment->setSizePolicy(sizePolicy);
        ButtonOrangeFragment->setStyleSheet(QString::fromUtf8("QPushButton{\n"
"	background-color: rgb(255,104,0);\n"
"}"));

        FragmentColorsLay->addWidget(ButtonOrangeFragment);

        ButtonPurpleFragment = new QPushButton(centralwidget);
        ButtonPurpleFragment->setObjectName(QString::fromUtf8("ButtonPurpleFragment"));
        sizePolicy.setHeightForWidth(ButtonPurpleFragment->sizePolicy().hasHeightForWidth());
        ButtonPurpleFragment->setSizePolicy(sizePolicy);
        ButtonPurpleFragment->setStyleSheet(QString::fromUtf8("QPushButton{\n"
"	background-color: rgb(128,0,128);\n"
"}"));

        FragmentColorsLay->addWidget(ButtonPurpleFragment);

        ButtonBlueFragment = new QPushButton(centralwidget);
        ButtonBlueFragment->setObjectName(QString::fromUtf8("ButtonBlueFragment"));
        sizePolicy.setHeightForWidth(ButtonBlueFragment->sizePolicy().hasHeightForWidth());
        ButtonBlueFragment->setSizePolicy(sizePolicy);
        ButtonBlueFragment->setStyleSheet(QString::fromUtf8("QPushButton{\n"
"	background-color: rgb(0,0,255);\n"
"}"));

        FragmentColorsLay->addWidget(ButtonBlueFragment);

        ButtonGreenFragment = new QPushButton(centralwidget);
        ButtonGreenFragment->setObjectName(QString::fromUtf8("ButtonGreenFragment"));
        sizePolicy.setHeightForWidth(ButtonGreenFragment->sizePolicy().hasHeightForWidth());
        ButtonGreenFragment->setSizePolicy(sizePolicy);
        ButtonGreenFragment->setStyleSheet(QString::fromUtf8("QPushButton{\n"
"	background-color: rgb(0,255,0);\n"
"}"));

        FragmentColorsLay->addWidget(ButtonGreenFragment);


        FragmentColorBox->addLayout(FragmentColorsLay);


        ControlLayout->addLayout(FragmentColorBox);

        LineColorBox = new QVBoxLayout();
        LineColorBox->setObjectName(QString::fromUtf8("LineColorBox"));
        LIneColorLabel = new QLabel(centralwidget);
        LIneColorLabel->setObjectName(QString::fromUtf8("LIneColorLabel"));
        sizePolicy.setHeightForWidth(LIneColorLabel->sizePolicy().hasHeightForWidth());
        LIneColorLabel->setSizePolicy(sizePolicy);
        LIneColorLabel->setFont(font);
        LIneColorLabel->setAlignment(Qt::AlignCenter);

        LineColorBox->addWidget(LIneColorLabel);

        LineColorsLay = new QHBoxLayout();
        LineColorsLay->setObjectName(QString::fromUtf8("LineColorsLay"));
        ButtonBlackLine = new QPushButton(centralwidget);
        ButtonBlackLine->setObjectName(QString::fromUtf8("ButtonBlackLine"));
        sizePolicy.setHeightForWidth(ButtonBlackLine->sizePolicy().hasHeightForWidth());
        ButtonBlackLine->setSizePolicy(sizePolicy);
        ButtonBlackLine->setStyleSheet(QString::fromUtf8("QPushButton{\n"
"	background-color: rgb(0,0,0);\n"
"}"));

        LineColorsLay->addWidget(ButtonBlackLine);

        ButtonWhiteLine = new QPushButton(centralwidget);
        ButtonWhiteLine->setObjectName(QString::fromUtf8("ButtonWhiteLine"));
        sizePolicy.setHeightForWidth(ButtonWhiteLine->sizePolicy().hasHeightForWidth());
        ButtonWhiteLine->setSizePolicy(sizePolicy);
        ButtonWhiteLine->setStyleSheet(QString::fromUtf8("QPushButton{\n"
"	background-color: rgb(255,255,255);\n"
"}"));

        LineColorsLay->addWidget(ButtonWhiteLine);

        ButtonYellowLine = new QPushButton(centralwidget);
        ButtonYellowLine->setObjectName(QString::fromUtf8("ButtonYellowLine"));
        sizePolicy.setHeightForWidth(ButtonYellowLine->sizePolicy().hasHeightForWidth());
        ButtonYellowLine->setSizePolicy(sizePolicy);
        ButtonYellowLine->setStyleSheet(QString::fromUtf8("QPushButton{\n"
"	background-color: rgb(255,255,0);\n"
"}"));

        LineColorsLay->addWidget(ButtonYellowLine);

        ButtonRedLine = new QPushButton(centralwidget);
        ButtonRedLine->setObjectName(QString::fromUtf8("ButtonRedLine"));
        sizePolicy.setHeightForWidth(ButtonRedLine->sizePolicy().hasHeightForWidth());
        ButtonRedLine->setSizePolicy(sizePolicy);
        ButtonRedLine->setStyleSheet(QString::fromUtf8("QPushButton{\n"
"	background-color: rgb(255,0,0);\n"
"}"));

        LineColorsLay->addWidget(ButtonRedLine);

        ButtonOrangeLine = new QPushButton(centralwidget);
        ButtonOrangeLine->setObjectName(QString::fromUtf8("ButtonOrangeLine"));
        sizePolicy.setHeightForWidth(ButtonOrangeLine->sizePolicy().hasHeightForWidth());
        ButtonOrangeLine->setSizePolicy(sizePolicy);
        ButtonOrangeLine->setStyleSheet(QString::fromUtf8("QPushButton{\n"
"	background-color: rgb(255,104,0);\n"
"}"));

        LineColorsLay->addWidget(ButtonOrangeLine);

        ButtonPurpleLine = new QPushButton(centralwidget);
        ButtonPurpleLine->setObjectName(QString::fromUtf8("ButtonPurpleLine"));
        sizePolicy.setHeightForWidth(ButtonPurpleLine->sizePolicy().hasHeightForWidth());
        ButtonPurpleLine->setSizePolicy(sizePolicy);
        ButtonPurpleLine->setStyleSheet(QString::fromUtf8("QPushButton{\n"
"	background-color: rgb(128,0,128);\n"
"}"));

        LineColorsLay->addWidget(ButtonPurpleLine);

        ButtonBlueLine = new QPushButton(centralwidget);
        ButtonBlueLine->setObjectName(QString::fromUtf8("ButtonBlueLine"));
        sizePolicy.setHeightForWidth(ButtonBlueLine->sizePolicy().hasHeightForWidth());
        ButtonBlueLine->setSizePolicy(sizePolicy);
        ButtonBlueLine->setStyleSheet(QString::fromUtf8("QPushButton{\n"
"	background-color: rgb(0,0,255);\n"
"}"));

        LineColorsLay->addWidget(ButtonBlueLine);

        ButtonGreenLine = new QPushButton(centralwidget);
        ButtonGreenLine->setObjectName(QString::fromUtf8("ButtonGreenLine"));
        sizePolicy.setHeightForWidth(ButtonGreenLine->sizePolicy().hasHeightForWidth());
        ButtonGreenLine->setSizePolicy(sizePolicy);
        ButtonGreenLine->setStyleSheet(QString::fromUtf8("QPushButton{\n"
"	background-color: rgb(0,255,0);\n"
"}"));

        LineColorsLay->addWidget(ButtonGreenLine);


        LineColorBox->addLayout(LineColorsLay);


        ControlLayout->addLayout(LineColorBox);

        line_2 = new QFrame(centralwidget);
        line_2->setObjectName(QString::fromUtf8("line_2"));
        line_2->setFrameShape(QFrame::HLine);
        line_2->setFrameShadow(QFrame::Sunken);

        ControlLayout->addWidget(line_2);

        verticalLayout_5 = new QVBoxLayout();
        verticalLayout_5->setObjectName(QString::fromUtf8("verticalLayout_5"));
        label_6 = new QLabel(centralwidget);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        QSizePolicy sizePolicy1(QSizePolicy::Minimum, QSizePolicy::Preferred);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(label_6->sizePolicy().hasHeightForWidth());
        label_6->setSizePolicy(sizePolicy1);
        label_6->setFont(font);
        label_6->setAlignment(Qt::AlignCenter);

        verticalLayout_5->addWidget(label_6);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        label_3 = new QLabel(centralwidget);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        sizePolicy1.setHeightForWidth(label_3->sizePolicy().hasHeightForWidth());
        label_3->setSizePolicy(sizePolicy1);
        label_3->setFont(font);
        label_3->setAlignment(Qt::AlignCenter);

        verticalLayout_3->addWidget(label_3);

        Lb_clipper_form_2 = new QFormLayout();
        Lb_clipper_form_2->setObjectName(QString::fromUtf8("Lb_clipper_form_2"));
        lb_x_clipperLabel_3 = new QLabel(centralwidget);
        lb_x_clipperLabel_3->setObjectName(QString::fromUtf8("lb_x_clipperLabel_3"));
        sizePolicy1.setHeightForWidth(lb_x_clipperLabel_3->sizePolicy().hasHeightForWidth());
        lb_x_clipperLabel_3->setSizePolicy(sizePolicy1);
        lb_x_clipperLabel_3->setFont(font);

        Lb_clipper_form_2->setWidget(0, QFormLayout::LabelRole, lb_x_clipperLabel_3);

        start_x_LE = new QLineEdit(centralwidget);
        start_x_LE->setObjectName(QString::fromUtf8("start_x_LE"));
        sizePolicy.setHeightForWidth(start_x_LE->sizePolicy().hasHeightForWidth());
        start_x_LE->setSizePolicy(sizePolicy);
        start_x_LE->setFont(font);

        Lb_clipper_form_2->setWidget(0, QFormLayout::FieldRole, start_x_LE);

        lb_y_clipperLabel_3 = new QLabel(centralwidget);
        lb_y_clipperLabel_3->setObjectName(QString::fromUtf8("lb_y_clipperLabel_3"));
        sizePolicy1.setHeightForWidth(lb_y_clipperLabel_3->sizePolicy().hasHeightForWidth());
        lb_y_clipperLabel_3->setSizePolicy(sizePolicy1);
        lb_y_clipperLabel_3->setFont(font);

        Lb_clipper_form_2->setWidget(1, QFormLayout::LabelRole, lb_y_clipperLabel_3);

        start_y_LE = new QLineEdit(centralwidget);
        start_y_LE->setObjectName(QString::fromUtf8("start_y_LE"));
        sizePolicy.setHeightForWidth(start_y_LE->sizePolicy().hasHeightForWidth());
        start_y_LE->setSizePolicy(sizePolicy);
        start_y_LE->setFont(font);

        Lb_clipper_form_2->setWidget(1, QFormLayout::FieldRole, start_y_LE);


        verticalLayout_3->addLayout(Lb_clipper_form_2);


        horizontalLayout_2->addLayout(verticalLayout_3);

        verticalLayout_4 = new QVBoxLayout();
        verticalLayout_4->setObjectName(QString::fromUtf8("verticalLayout_4"));
        label_4 = new QLabel(centralwidget);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        sizePolicy1.setHeightForWidth(label_4->sizePolicy().hasHeightForWidth());
        label_4->setSizePolicy(sizePolicy1);
        label_4->setFont(font);
        label_4->setAlignment(Qt::AlignCenter);

        verticalLayout_4->addWidget(label_4);

        RT_clipper_form_2 = new QFormLayout();
        RT_clipper_form_2->setObjectName(QString::fromUtf8("RT_clipper_form_2"));
        rt_x_clipperLabel_2 = new QLabel(centralwidget);
        rt_x_clipperLabel_2->setObjectName(QString::fromUtf8("rt_x_clipperLabel_2"));
        sizePolicy1.setHeightForWidth(rt_x_clipperLabel_2->sizePolicy().hasHeightForWidth());
        rt_x_clipperLabel_2->setSizePolicy(sizePolicy1);
        rt_x_clipperLabel_2->setFont(font);

        RT_clipper_form_2->setWidget(0, QFormLayout::LabelRole, rt_x_clipperLabel_2);

        end_x_LE = new QLineEdit(centralwidget);
        end_x_LE->setObjectName(QString::fromUtf8("end_x_LE"));
        sizePolicy.setHeightForWidth(end_x_LE->sizePolicy().hasHeightForWidth());
        end_x_LE->setSizePolicy(sizePolicy);
        end_x_LE->setFont(font);

        RT_clipper_form_2->setWidget(0, QFormLayout::FieldRole, end_x_LE);

        rt_y_clipperLabel_2 = new QLabel(centralwidget);
        rt_y_clipperLabel_2->setObjectName(QString::fromUtf8("rt_y_clipperLabel_2"));
        sizePolicy1.setHeightForWidth(rt_y_clipperLabel_2->sizePolicy().hasHeightForWidth());
        rt_y_clipperLabel_2->setSizePolicy(sizePolicy1);
        rt_y_clipperLabel_2->setFont(font);

        RT_clipper_form_2->setWidget(1, QFormLayout::LabelRole, rt_y_clipperLabel_2);

        end_y_LE = new QLineEdit(centralwidget);
        end_y_LE->setObjectName(QString::fromUtf8("end_y_LE"));
        sizePolicy.setHeightForWidth(end_y_LE->sizePolicy().hasHeightForWidth());
        end_y_LE->setSizePolicy(sizePolicy);
        end_y_LE->setFont(font);

        RT_clipper_form_2->setWidget(1, QFormLayout::FieldRole, end_y_LE);


        verticalLayout_4->addLayout(RT_clipper_form_2);


        horizontalLayout_2->addLayout(verticalLayout_4);


        verticalLayout_5->addLayout(horizontalLayout_2);


        ControlLayout->addLayout(verticalLayout_5);

        DrawSegmentButton = new QPushButton(centralwidget);
        DrawSegmentButton->setObjectName(QString::fromUtf8("DrawSegmentButton"));
        DrawSegmentButton->setFont(font);

        ControlLayout->addWidget(DrawSegmentButton);

        line = new QFrame(centralwidget);
        line->setObjectName(QString::fromUtf8("line"));
        line->setFrameShape(QFrame::HLine);
        line->setFrameShadow(QFrame::Sunken);

        ControlLayout->addWidget(line);

        label_5 = new QLabel(centralwidget);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        sizePolicy1.setHeightForWidth(label_5->sizePolicy().hasHeightForWidth());
        label_5->setSizePolicy(sizePolicy1);
        label_5->setFont(font);
        label_5->setAlignment(Qt::AlignCenter);

        ControlLayout->addWidget(label_5);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        label = new QLabel(centralwidget);
        label->setObjectName(QString::fromUtf8("label"));
        sizePolicy1.setHeightForWidth(label->sizePolicy().hasHeightForWidth());
        label->setSizePolicy(sizePolicy1);
        label->setFont(font);
        label->setAlignment(Qt::AlignCenter);

        verticalLayout->addWidget(label);

        Lt_clipper_form = new QFormLayout();
        Lt_clipper_form->setObjectName(QString::fromUtf8("Lt_clipper_form"));
        lb_x_clipperLabel = new QLabel(centralwidget);
        lb_x_clipperLabel->setObjectName(QString::fromUtf8("lb_x_clipperLabel"));
        sizePolicy1.setHeightForWidth(lb_x_clipperLabel->sizePolicy().hasHeightForWidth());
        lb_x_clipperLabel->setSizePolicy(sizePolicy1);
        lb_x_clipperLabel->setFont(font);

        Lt_clipper_form->setWidget(0, QFormLayout::LabelRole, lb_x_clipperLabel);

        lt_x_clipperLineEdit = new QLineEdit(centralwidget);
        lt_x_clipperLineEdit->setObjectName(QString::fromUtf8("lt_x_clipperLineEdit"));
        sizePolicy.setHeightForWidth(lt_x_clipperLineEdit->sizePolicy().hasHeightForWidth());
        lt_x_clipperLineEdit->setSizePolicy(sizePolicy);
        lt_x_clipperLineEdit->setFont(font);

        Lt_clipper_form->setWidget(0, QFormLayout::FieldRole, lt_x_clipperLineEdit);

        lb_y_clipperLabel = new QLabel(centralwidget);
        lb_y_clipperLabel->setObjectName(QString::fromUtf8("lb_y_clipperLabel"));
        sizePolicy1.setHeightForWidth(lb_y_clipperLabel->sizePolicy().hasHeightForWidth());
        lb_y_clipperLabel->setSizePolicy(sizePolicy1);
        lb_y_clipperLabel->setFont(font);

        Lt_clipper_form->setWidget(1, QFormLayout::LabelRole, lb_y_clipperLabel);

        lt_y_clipperLineEdit = new QLineEdit(centralwidget);
        lt_y_clipperLineEdit->setObjectName(QString::fromUtf8("lt_y_clipperLineEdit"));
        sizePolicy.setHeightForWidth(lt_y_clipperLineEdit->sizePolicy().hasHeightForWidth());
        lt_y_clipperLineEdit->setSizePolicy(sizePolicy);
        lt_y_clipperLineEdit->setFont(font);

        Lt_clipper_form->setWidget(1, QFormLayout::FieldRole, lt_y_clipperLineEdit);


        verticalLayout->addLayout(Lt_clipper_form);


        horizontalLayout->addLayout(verticalLayout);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        label_2 = new QLabel(centralwidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        sizePolicy1.setHeightForWidth(label_2->sizePolicy().hasHeightForWidth());
        label_2->setSizePolicy(sizePolicy1);
        label_2->setFont(font);
        label_2->setAlignment(Qt::AlignCenter);

        verticalLayout_2->addWidget(label_2);

        RB_clipper_form = new QFormLayout();
        RB_clipper_form->setObjectName(QString::fromUtf8("RB_clipper_form"));
        rt_x_clipperLabel = new QLabel(centralwidget);
        rt_x_clipperLabel->setObjectName(QString::fromUtf8("rt_x_clipperLabel"));
        sizePolicy1.setHeightForWidth(rt_x_clipperLabel->sizePolicy().hasHeightForWidth());
        rt_x_clipperLabel->setSizePolicy(sizePolicy1);
        rt_x_clipperLabel->setFont(font);

        RB_clipper_form->setWidget(0, QFormLayout::LabelRole, rt_x_clipperLabel);

        rb_x_clipperLineEdit = new QLineEdit(centralwidget);
        rb_x_clipperLineEdit->setObjectName(QString::fromUtf8("rb_x_clipperLineEdit"));
        sizePolicy.setHeightForWidth(rb_x_clipperLineEdit->sizePolicy().hasHeightForWidth());
        rb_x_clipperLineEdit->setSizePolicy(sizePolicy);
        rb_x_clipperLineEdit->setFont(font);

        RB_clipper_form->setWidget(0, QFormLayout::FieldRole, rb_x_clipperLineEdit);

        rt_y_clipperLabel = new QLabel(centralwidget);
        rt_y_clipperLabel->setObjectName(QString::fromUtf8("rt_y_clipperLabel"));
        sizePolicy1.setHeightForWidth(rt_y_clipperLabel->sizePolicy().hasHeightForWidth());
        rt_y_clipperLabel->setSizePolicy(sizePolicy1);
        rt_y_clipperLabel->setFont(font);

        RB_clipper_form->setWidget(1, QFormLayout::LabelRole, rt_y_clipperLabel);

        rb_y_clipperLineEdit = new QLineEdit(centralwidget);
        rb_y_clipperLineEdit->setObjectName(QString::fromUtf8("rb_y_clipperLineEdit"));
        sizePolicy.setHeightForWidth(rb_y_clipperLineEdit->sizePolicy().hasHeightForWidth());
        rb_y_clipperLineEdit->setSizePolicy(sizePolicy);
        rb_y_clipperLineEdit->setFont(font);

        RB_clipper_form->setWidget(1, QFormLayout::FieldRole, rb_y_clipperLineEdit);


        verticalLayout_2->addLayout(RB_clipper_form);


        horizontalLayout->addLayout(verticalLayout_2);


        ControlLayout->addLayout(horizontalLayout);

        DrawClipperButton = new QPushButton(centralwidget);
        DrawClipperButton->setObjectName(QString::fromUtf8("DrawClipperButton"));
        DrawClipperButton->setFont(font);

        ControlLayout->addWidget(DrawClipperButton);

        line_3 = new QFrame(centralwidget);
        line_3->setObjectName(QString::fromUtf8("line_3"));
        line_3->setFrameShape(QFrame::HLine);
        line_3->setFrameShadow(QFrame::Sunken);

        ControlLayout->addWidget(line_3);

        ActionLayout = new QHBoxLayout();
        ActionLayout->setObjectName(QString::fromUtf8("ActionLayout"));
        CleanButton = new QPushButton(centralwidget);
        CleanButton->setObjectName(QString::fromUtf8("CleanButton"));
        sizePolicy.setHeightForWidth(CleanButton->sizePolicy().hasHeightForWidth());
        CleanButton->setSizePolicy(sizePolicy);
        CleanButton->setFont(font);

        ActionLayout->addWidget(CleanButton);

        DrawButton = new QPushButton(centralwidget);
        DrawButton->setObjectName(QString::fromUtf8("DrawButton"));
        sizePolicy.setHeightForWidth(DrawButton->sizePolicy().hasHeightForWidth());
        DrawButton->setSizePolicy(sizePolicy);
        DrawButton->setFont(font);

        ActionLayout->addWidget(DrawButton);


        ControlLayout->addLayout(ActionLayout);

        line_4 = new QFrame(centralwidget);
        line_4->setObjectName(QString::fromUtf8("line_4"));
        line_4->setFrameShape(QFrame::HLine);
        line_4->setFrameShadow(QFrame::Sunken);

        ControlLayout->addWidget(line_4);

        label_7 = new QLabel(centralwidget);
        label_7->setObjectName(QString::fromUtf8("label_7"));
        label_7->setFont(font);
        label_7->setAlignment(Qt::AlignCenter);

        ControlLayout->addWidget(label_7);

        PointTableWidget = new QTableWidget(centralwidget);
        if (PointTableWidget->columnCount() < 2)
            PointTableWidget->setColumnCount(2);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        PointTableWidget->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        PointTableWidget->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        PointTableWidget->setObjectName(QString::fromUtf8("PointTableWidget"));
        QSizePolicy sizePolicy2(QSizePolicy::Minimum, QSizePolicy::Expanding);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(PointTableWidget->sizePolicy().hasHeightForWidth());
        PointTableWidget->setSizePolicy(sizePolicy2);
        PointTableWidget->setMinimumSize(QSize(100, 0));
        PointTableWidget->setFont(font);
        PointTableWidget->setAutoScroll(false);
        PointTableWidget->horizontalHeader()->setVisible(true);
        PointTableWidget->horizontalHeader()->setCascadingSectionResizes(false);
        PointTableWidget->horizontalHeader()->setMinimumSectionSize(20);
        PointTableWidget->horizontalHeader()->setDefaultSectionSize(150);
        PointTableWidget->horizontalHeader()->setHighlightSections(true);

        ControlLayout->addWidget(PointTableWidget);


        horizontalLayout_3->addLayout(ControlLayout);

        ResView = new QGraphicsView(centralwidget);
        ResView->setObjectName(QString::fromUtf8("ResView"));
        ResView->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignTop);

        horizontalLayout_3->addWidget(ResView);

        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 1227, 21));
        menu_7 = new QMenu(menubar);
        menu_7->setObjectName(QString::fromUtf8("menu_7"));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow->setStatusBar(statusbar);

        menubar->addAction(menu_7->menuAction());

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        TaskLabel->setText(QCoreApplication::translate("MainWindow", "\320\220\320\273\320\263\320\276\321\200\320\270\321\202\320\274 \320\241\320\260\320\267\320\265\321\200\320\273\320\265\320\275\320\264\320\260-\320\232\320\276\321\215\320\275\320\260", nullptr));
        CipperColorLabel->setText(QCoreApplication::translate("MainWindow", "\320\246\320\262\320\265\321\202 \320\276\321\202\321\201\320\265\320\272\320\260\321\202\320\265\320\273\321\217 (\321\207\320\265\321\200\320\275\321\213\320\271)", nullptr));
        ButtonBlackCipper->setText(QString());
        ButtonWhiteCipper->setText(QString());
        ButtonYellowCipper->setText(QString());
        ButtonRedCipper->setText(QString());
        ButtonOrangeCipper->setText(QString());
        ButtonPurpleCipper->setText(QString());
        ButtonBlueCipper->setText(QString());
        ButtonGreenCipper->setText(QString());
        LIneColorFragment->setText(QCoreApplication::translate("MainWindow", "\320\246\320\262\320\265\321\202 \320\276\321\202\321\200\320\265\320\267\320\272\320\276\320\262 (\321\207\320\265\321\200\320\275\321\213\320\271)", nullptr));
        ButtonBlackFragment->setText(QString());
        ButtonWhiteFragment->setText(QString());
        ButtonYellowFragment->setText(QString());
        ButtonRedFragment->setText(QString());
        ButtonOrangeFragment->setText(QString());
        ButtonPurpleFragment->setText(QString());
        ButtonBlueFragment->setText(QString());
        ButtonGreenFragment->setText(QString());
        LIneColorLabel->setText(QCoreApplication::translate("MainWindow", "\320\246\320\262\320\265\321\202 \320\276\321\202\321\201\320\265\321\207\321\221\320\275\320\275\321\213\321\205 \320\276\321\202\321\200\320\265\320\267\320\272\320\276\320\262 (\321\207\320\265\321\200\320\275\321\213\320\271)", nullptr));
        ButtonBlackLine->setText(QString());
        ButtonWhiteLine->setText(QString());
        ButtonYellowLine->setText(QString());
        ButtonRedLine->setText(QString());
        ButtonOrangeLine->setText(QString());
        ButtonPurpleLine->setText(QString());
        ButtonBlueLine->setText(QString());
        ButtonGreenLine->setText(QString());
        label_6->setText(QCoreApplication::translate("MainWindow", "\320\237\321\200\320\260\320\274\320\265\321\202\321\200\321\213 \320\275\320\276\320\262\320\276\320\263\320\276 \320\276\321\202\321\200\320\265\320\267\320\272\320\260", nullptr));
        label_3->setText(QCoreApplication::translate("MainWindow", "\320\235\320\260\321\207\320\260\320\273\320\276", nullptr));
        lb_x_clipperLabel_3->setText(QCoreApplication::translate("MainWindow", "X:", nullptr));
        lb_y_clipperLabel_3->setText(QCoreApplication::translate("MainWindow", "Y:", nullptr));
        label_4->setText(QCoreApplication::translate("MainWindow", "\320\232\320\276\320\275\320\265\321\206", nullptr));
        rt_x_clipperLabel_2->setText(QCoreApplication::translate("MainWindow", "X:", nullptr));
        rt_y_clipperLabel_2->setText(QCoreApplication::translate("MainWindow", "Y:", nullptr));
        DrawSegmentButton->setText(QCoreApplication::translate("MainWindow", "\320\224\320\276\320\261\320\260\320\262\320\270\321\202\321\214 \320\276\321\202\321\200\320\265\320\267\320\276\320\272", nullptr));
        label_5->setText(QCoreApplication::translate("MainWindow", "\320\237\320\260\321\200\320\260\320\274\320\265\321\202\321\200\321\213 \320\276\321\202\321\201\320\265\320\272\320\260\321\202\320\265\320\273\321\217", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "\320\233\320\265\320\262\321\213\320\271 \320\262\320\265\321\200\321\205\320\275\320\270\320\271 \321\203\320\263\320\276\320\273", nullptr));
        lb_x_clipperLabel->setText(QCoreApplication::translate("MainWindow", "X:", nullptr));
        lb_y_clipperLabel->setText(QCoreApplication::translate("MainWindow", "Y:", nullptr));
        label_2->setText(QCoreApplication::translate("MainWindow", "\320\237\321\200\320\260\320\262\321\213\320\271 \320\275\320\270\320\266\320\275\320\270\320\271 \321\203\320\263\320\276\320\273", nullptr));
        rt_x_clipperLabel->setText(QCoreApplication::translate("MainWindow", "X:", nullptr));
        rt_y_clipperLabel->setText(QCoreApplication::translate("MainWindow", "Y:", nullptr));
        DrawClipperButton->setText(QCoreApplication::translate("MainWindow", "\320\237\320\276\321\201\321\202\321\200\320\276\320\270\321\202\321\214 \320\276\321\202\321\201\320\265\320\272\320\260\321\202\320\265\320\273\321\214", nullptr));
        CleanButton->setText(QCoreApplication::translate("MainWindow", "\320\236\321\207\320\270\321\201\321\202\320\270\321\202\321\214 \321\215\320\272\321\200\320\260\320\275", nullptr));
        DrawButton->setText(QCoreApplication::translate("MainWindow", "\320\236\321\202\321\201\320\265\321\207\320\265\320\275\320\270\320\265", nullptr));
        label_7->setText(QCoreApplication::translate("MainWindow", "\320\241\320\277\320\270\321\201\320\276\320\272 \320\276\321\202\321\200\320\265\320\267\320\272\320\276\320\262", nullptr));
        QTableWidgetItem *___qtablewidgetitem = PointTableWidget->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QCoreApplication::translate("MainWindow", "\320\235\320\260\321\207\320\260\320\273\320\276", nullptr));
        QTableWidgetItem *___qtablewidgetitem1 = PointTableWidget->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QCoreApplication::translate("MainWindow", "\320\232\320\276\320\275\320\265\321\206", nullptr));
        menu_7->setTitle(QCoreApplication::translate("MainWindow", "\320\233\320\240 \342\204\2267", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
