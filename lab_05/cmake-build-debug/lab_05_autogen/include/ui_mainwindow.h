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
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGraphicsView>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QHBoxLayout *horizontalLayout;
    QVBoxLayout *ControlLayout;
    QVBoxLayout *BGColorBox;
    QLabel *label_3;
    QLabel *BGColorLabel;
    QHBoxLayout *BGColorLay;
    QPushButton *ButtonBlackBG;
    QPushButton *ButtonWhiteBG;
    QPushButton *ButtonYellowBG;
    QPushButton *ButtonRedBG;
    QPushButton *ButtonOrangeBG;
    QPushButton *ButtonPurpleBG;
    QPushButton *ButtonBlueBG;
    QPushButton *ButtonGreenBG;
    QVBoxLayout *BorderColorBox;
    QLabel *LIneColorBorder;
    QHBoxLayout *BorderColorsLay;
    QPushButton *ButtonBlackBorder;
    QPushButton *ButtonWhiteBorder;
    QPushButton *ButtonYellowBorder;
    QPushButton *ButtonRedBorder;
    QPushButton *ButtonOrangeBorder;
    QPushButton *ButtonPurpleBorder;
    QPushButton *ButtonBlueBorder;
    QPushButton *ButtonGreenBorder;
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
    QFrame *line;
    QVBoxLayout *InpuLayout;
    QLabel *CenterLabel;
    QFormLayout *formLayout;
    QLabel *xLabel;
    QLineEdit *xLineEdit;
    QLabel *yLabel;
    QLineEdit *yLineEdit;
    QPushButton *AddDotButton;
    QPushButton *CloseFigureButton;
    QFrame *line_2;
    QHBoxLayout *DelayLayout;
    QCheckBox *DelayCJeckBox;
    QFormLayout *DelayForm;
    QLabel *DelayLabel;
    QSpinBox *DelaySpinBox;
    QLabel *label;
    QHBoxLayout *ActionLayout;
    QPushButton *CleanButton;
    QPushButton *DrawButton;
    QLabel *label_2;
    QFrame *line_3;
    QTableWidget *PointTableWidget;
    QGraphicsView *ResView;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(1227, 909);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        horizontalLayout = new QHBoxLayout(centralwidget);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        ControlLayout = new QVBoxLayout();
        ControlLayout->setObjectName(QString::fromUtf8("ControlLayout"));
        BGColorBox = new QVBoxLayout();
        BGColorBox->setObjectName(QString::fromUtf8("BGColorBox"));
        label_3 = new QLabel(centralwidget);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        QFont font;
        font.setPointSize(12);
        label_3->setFont(font);
        label_3->setAlignment(Qt::AlignCenter);

        BGColorBox->addWidget(label_3);

        BGColorLabel = new QLabel(centralwidget);
        BGColorLabel->setObjectName(QString::fromUtf8("BGColorLabel"));
        QSizePolicy sizePolicy(QSizePolicy::Minimum, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(BGColorLabel->sizePolicy().hasHeightForWidth());
        BGColorLabel->setSizePolicy(sizePolicy);
        BGColorLabel->setFont(font);
        BGColorLabel->setAlignment(Qt::AlignCenter);

        BGColorBox->addWidget(BGColorLabel);

        BGColorLay = new QHBoxLayout();
        BGColorLay->setObjectName(QString::fromUtf8("BGColorLay"));
        ButtonBlackBG = new QPushButton(centralwidget);
        ButtonBlackBG->setObjectName(QString::fromUtf8("ButtonBlackBG"));
        sizePolicy.setHeightForWidth(ButtonBlackBG->sizePolicy().hasHeightForWidth());
        ButtonBlackBG->setSizePolicy(sizePolicy);
        ButtonBlackBG->setStyleSheet(QString::fromUtf8("QPushButton{\n"
"	background-color: rgb(0,0,0);\n"
"}"));

        BGColorLay->addWidget(ButtonBlackBG);

        ButtonWhiteBG = new QPushButton(centralwidget);
        ButtonWhiteBG->setObjectName(QString::fromUtf8("ButtonWhiteBG"));
        sizePolicy.setHeightForWidth(ButtonWhiteBG->sizePolicy().hasHeightForWidth());
        ButtonWhiteBG->setSizePolicy(sizePolicy);
        ButtonWhiteBG->setStyleSheet(QString::fromUtf8("QPushButton{\n"
"	background-color: rgb(255,255,255);\n"
"}"));

        BGColorLay->addWidget(ButtonWhiteBG);

        ButtonYellowBG = new QPushButton(centralwidget);
        ButtonYellowBG->setObjectName(QString::fromUtf8("ButtonYellowBG"));
        sizePolicy.setHeightForWidth(ButtonYellowBG->sizePolicy().hasHeightForWidth());
        ButtonYellowBG->setSizePolicy(sizePolicy);
        ButtonYellowBG->setStyleSheet(QString::fromUtf8("QPushButton{\n"
"	background-color: rgb(255,255,0);\n"
"}"));

        BGColorLay->addWidget(ButtonYellowBG);

        ButtonRedBG = new QPushButton(centralwidget);
        ButtonRedBG->setObjectName(QString::fromUtf8("ButtonRedBG"));
        sizePolicy.setHeightForWidth(ButtonRedBG->sizePolicy().hasHeightForWidth());
        ButtonRedBG->setSizePolicy(sizePolicy);
        ButtonRedBG->setStyleSheet(QString::fromUtf8("QPushButton{\n"
"	background-color: rgb(255,0,0);\n"
"}"));

        BGColorLay->addWidget(ButtonRedBG);

        ButtonOrangeBG = new QPushButton(centralwidget);
        ButtonOrangeBG->setObjectName(QString::fromUtf8("ButtonOrangeBG"));
        sizePolicy.setHeightForWidth(ButtonOrangeBG->sizePolicy().hasHeightForWidth());
        ButtonOrangeBG->setSizePolicy(sizePolicy);
        ButtonOrangeBG->setStyleSheet(QString::fromUtf8("QPushButton{\n"
"	background-color: rgb(255,104,0);\n"
"}"));

        BGColorLay->addWidget(ButtonOrangeBG);

        ButtonPurpleBG = new QPushButton(centralwidget);
        ButtonPurpleBG->setObjectName(QString::fromUtf8("ButtonPurpleBG"));
        sizePolicy.setHeightForWidth(ButtonPurpleBG->sizePolicy().hasHeightForWidth());
        ButtonPurpleBG->setSizePolicy(sizePolicy);
        ButtonPurpleBG->setStyleSheet(QString::fromUtf8("QPushButton{\n"
"	background-color: rgb(128,0,128);\n"
"}"));

        BGColorLay->addWidget(ButtonPurpleBG);

        ButtonBlueBG = new QPushButton(centralwidget);
        ButtonBlueBG->setObjectName(QString::fromUtf8("ButtonBlueBG"));
        sizePolicy.setHeightForWidth(ButtonBlueBG->sizePolicy().hasHeightForWidth());
        ButtonBlueBG->setSizePolicy(sizePolicy);
        ButtonBlueBG->setStyleSheet(QString::fromUtf8("QPushButton{\n"
"	background-color: rgb(0,0,255);\n"
"}"));

        BGColorLay->addWidget(ButtonBlueBG);

        ButtonGreenBG = new QPushButton(centralwidget);
        ButtonGreenBG->setObjectName(QString::fromUtf8("ButtonGreenBG"));
        sizePolicy.setHeightForWidth(ButtonGreenBG->sizePolicy().hasHeightForWidth());
        ButtonGreenBG->setSizePolicy(sizePolicy);
        ButtonGreenBG->setStyleSheet(QString::fromUtf8("QPushButton{\n"
"	background-color: rgb(0,255,0);\n"
"}"));

        BGColorLay->addWidget(ButtonGreenBG);


        BGColorBox->addLayout(BGColorLay);


        ControlLayout->addLayout(BGColorBox);

        BorderColorBox = new QVBoxLayout();
        BorderColorBox->setObjectName(QString::fromUtf8("BorderColorBox"));
        LIneColorBorder = new QLabel(centralwidget);
        LIneColorBorder->setObjectName(QString::fromUtf8("LIneColorBorder"));
        sizePolicy.setHeightForWidth(LIneColorBorder->sizePolicy().hasHeightForWidth());
        LIneColorBorder->setSizePolicy(sizePolicy);
        LIneColorBorder->setFont(font);
        LIneColorBorder->setAlignment(Qt::AlignCenter);

        BorderColorBox->addWidget(LIneColorBorder);

        BorderColorsLay = new QHBoxLayout();
        BorderColorsLay->setObjectName(QString::fromUtf8("BorderColorsLay"));
        ButtonBlackBorder = new QPushButton(centralwidget);
        ButtonBlackBorder->setObjectName(QString::fromUtf8("ButtonBlackBorder"));
        sizePolicy.setHeightForWidth(ButtonBlackBorder->sizePolicy().hasHeightForWidth());
        ButtonBlackBorder->setSizePolicy(sizePolicy);
        ButtonBlackBorder->setStyleSheet(QString::fromUtf8("QPushButton{\n"
"	background-color: rgb(0,0,0);\n"
"}"));

        BorderColorsLay->addWidget(ButtonBlackBorder);

        ButtonWhiteBorder = new QPushButton(centralwidget);
        ButtonWhiteBorder->setObjectName(QString::fromUtf8("ButtonWhiteBorder"));
        sizePolicy.setHeightForWidth(ButtonWhiteBorder->sizePolicy().hasHeightForWidth());
        ButtonWhiteBorder->setSizePolicy(sizePolicy);
        ButtonWhiteBorder->setStyleSheet(QString::fromUtf8("QPushButton{\n"
"	background-color: rgb(255,255,255);\n"
"}"));

        BorderColorsLay->addWidget(ButtonWhiteBorder);

        ButtonYellowBorder = new QPushButton(centralwidget);
        ButtonYellowBorder->setObjectName(QString::fromUtf8("ButtonYellowBorder"));
        sizePolicy.setHeightForWidth(ButtonYellowBorder->sizePolicy().hasHeightForWidth());
        ButtonYellowBorder->setSizePolicy(sizePolicy);
        ButtonYellowBorder->setStyleSheet(QString::fromUtf8("QPushButton{\n"
"	background-color: rgb(255,255,0);\n"
"}"));

        BorderColorsLay->addWidget(ButtonYellowBorder);

        ButtonRedBorder = new QPushButton(centralwidget);
        ButtonRedBorder->setObjectName(QString::fromUtf8("ButtonRedBorder"));
        sizePolicy.setHeightForWidth(ButtonRedBorder->sizePolicy().hasHeightForWidth());
        ButtonRedBorder->setSizePolicy(sizePolicy);
        ButtonRedBorder->setStyleSheet(QString::fromUtf8("QPushButton{\n"
"	background-color: rgb(255,0,0);\n"
"}"));

        BorderColorsLay->addWidget(ButtonRedBorder);

        ButtonOrangeBorder = new QPushButton(centralwidget);
        ButtonOrangeBorder->setObjectName(QString::fromUtf8("ButtonOrangeBorder"));
        sizePolicy.setHeightForWidth(ButtonOrangeBorder->sizePolicy().hasHeightForWidth());
        ButtonOrangeBorder->setSizePolicy(sizePolicy);
        ButtonOrangeBorder->setStyleSheet(QString::fromUtf8("QPushButton{\n"
"	background-color: rgb(255,104,0);\n"
"}"));

        BorderColorsLay->addWidget(ButtonOrangeBorder);

        ButtonPurpleBorder = new QPushButton(centralwidget);
        ButtonPurpleBorder->setObjectName(QString::fromUtf8("ButtonPurpleBorder"));
        sizePolicy.setHeightForWidth(ButtonPurpleBorder->sizePolicy().hasHeightForWidth());
        ButtonPurpleBorder->setSizePolicy(sizePolicy);
        ButtonPurpleBorder->setStyleSheet(QString::fromUtf8("QPushButton{\n"
"	background-color: rgb(128,0,128);\n"
"}"));

        BorderColorsLay->addWidget(ButtonPurpleBorder);

        ButtonBlueBorder = new QPushButton(centralwidget);
        ButtonBlueBorder->setObjectName(QString::fromUtf8("ButtonBlueBorder"));
        sizePolicy.setHeightForWidth(ButtonBlueBorder->sizePolicy().hasHeightForWidth());
        ButtonBlueBorder->setSizePolicy(sizePolicy);
        ButtonBlueBorder->setStyleSheet(QString::fromUtf8("QPushButton{\n"
"	background-color: rgb(0,0,255);\n"
"}"));

        BorderColorsLay->addWidget(ButtonBlueBorder);

        ButtonGreenBorder = new QPushButton(centralwidget);
        ButtonGreenBorder->setObjectName(QString::fromUtf8("ButtonGreenBorder"));
        sizePolicy.setHeightForWidth(ButtonGreenBorder->sizePolicy().hasHeightForWidth());
        ButtonGreenBorder->setSizePolicy(sizePolicy);
        ButtonGreenBorder->setStyleSheet(QString::fromUtf8("QPushButton{\n"
"	background-color: rgb(0,255,0);\n"
"}"));

        BorderColorsLay->addWidget(ButtonGreenBorder);


        BorderColorBox->addLayout(BorderColorsLay);


        ControlLayout->addLayout(BorderColorBox);

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

        line = new QFrame(centralwidget);
        line->setObjectName(QString::fromUtf8("line"));
        line->setFrameShape(QFrame::HLine);
        line->setFrameShadow(QFrame::Sunken);

        ControlLayout->addWidget(line);

        InpuLayout = new QVBoxLayout();
        InpuLayout->setObjectName(QString::fromUtf8("InpuLayout"));
        CenterLabel = new QLabel(centralwidget);
        CenterLabel->setObjectName(QString::fromUtf8("CenterLabel"));
        QSizePolicy sizePolicy1(QSizePolicy::Minimum, QSizePolicy::Preferred);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(CenterLabel->sizePolicy().hasHeightForWidth());
        CenterLabel->setSizePolicy(sizePolicy1);
        CenterLabel->setFont(font);
        CenterLabel->setAlignment(Qt::AlignCenter);

        InpuLayout->addWidget(CenterLabel);

        formLayout = new QFormLayout();
        formLayout->setObjectName(QString::fromUtf8("formLayout"));
        xLabel = new QLabel(centralwidget);
        xLabel->setObjectName(QString::fromUtf8("xLabel"));
        sizePolicy1.setHeightForWidth(xLabel->sizePolicy().hasHeightForWidth());
        xLabel->setSizePolicy(sizePolicy1);
        xLabel->setFont(font);

        formLayout->setWidget(0, QFormLayout::LabelRole, xLabel);

        xLineEdit = new QLineEdit(centralwidget);
        xLineEdit->setObjectName(QString::fromUtf8("xLineEdit"));
        sizePolicy.setHeightForWidth(xLineEdit->sizePolicy().hasHeightForWidth());
        xLineEdit->setSizePolicy(sizePolicy);
        xLineEdit->setFont(font);

        formLayout->setWidget(0, QFormLayout::FieldRole, xLineEdit);

        yLabel = new QLabel(centralwidget);
        yLabel->setObjectName(QString::fromUtf8("yLabel"));
        sizePolicy1.setHeightForWidth(yLabel->sizePolicy().hasHeightForWidth());
        yLabel->setSizePolicy(sizePolicy1);
        yLabel->setFont(font);

        formLayout->setWidget(1, QFormLayout::LabelRole, yLabel);

        yLineEdit = new QLineEdit(centralwidget);
        yLineEdit->setObjectName(QString::fromUtf8("yLineEdit"));
        sizePolicy.setHeightForWidth(yLineEdit->sizePolicy().hasHeightForWidth());
        yLineEdit->setSizePolicy(sizePolicy);
        yLineEdit->setFont(font);

        formLayout->setWidget(1, QFormLayout::FieldRole, yLineEdit);


        InpuLayout->addLayout(formLayout);

        AddDotButton = new QPushButton(centralwidget);
        AddDotButton->setObjectName(QString::fromUtf8("AddDotButton"));
        sizePolicy.setHeightForWidth(AddDotButton->sizePolicy().hasHeightForWidth());
        AddDotButton->setSizePolicy(sizePolicy);
        AddDotButton->setFont(font);

        InpuLayout->addWidget(AddDotButton);

        CloseFigureButton = new QPushButton(centralwidget);
        CloseFigureButton->setObjectName(QString::fromUtf8("CloseFigureButton"));
        CloseFigureButton->setFont(font);

        InpuLayout->addWidget(CloseFigureButton);

        line_2 = new QFrame(centralwidget);
        line_2->setObjectName(QString::fromUtf8("line_2"));
        line_2->setFrameShape(QFrame::HLine);
        line_2->setFrameShadow(QFrame::Sunken);

        InpuLayout->addWidget(line_2);

        DelayLayout = new QHBoxLayout();
        DelayLayout->setObjectName(QString::fromUtf8("DelayLayout"));
        DelayCJeckBox = new QCheckBox(centralwidget);
        DelayCJeckBox->setObjectName(QString::fromUtf8("DelayCJeckBox"));
        sizePolicy.setHeightForWidth(DelayCJeckBox->sizePolicy().hasHeightForWidth());
        DelayCJeckBox->setSizePolicy(sizePolicy);
        DelayCJeckBox->setLayoutDirection(Qt::RightToLeft);

        DelayLayout->addWidget(DelayCJeckBox);

        DelayForm = new QFormLayout();
        DelayForm->setObjectName(QString::fromUtf8("DelayForm"));
        DelayLabel = new QLabel(centralwidget);
        DelayLabel->setObjectName(QString::fromUtf8("DelayLabel"));
        sizePolicy1.setHeightForWidth(DelayLabel->sizePolicy().hasHeightForWidth());
        DelayLabel->setSizePolicy(sizePolicy1);
        DelayLabel->setFont(font);

        DelayForm->setWidget(0, QFormLayout::LabelRole, DelayLabel);

        DelaySpinBox = new QSpinBox(centralwidget);
        DelaySpinBox->setObjectName(QString::fromUtf8("DelaySpinBox"));
        sizePolicy.setHeightForWidth(DelaySpinBox->sizePolicy().hasHeightForWidth());
        DelaySpinBox->setSizePolicy(sizePolicy);
        DelaySpinBox->setFont(font);
        DelaySpinBox->setMinimum(5);
        DelaySpinBox->setMaximum(100);
        DelaySpinBox->setSingleStep(5);
        DelaySpinBox->setValue(5);

        DelayForm->setWidget(0, QFormLayout::FieldRole, DelaySpinBox);


        DelayLayout->addLayout(DelayForm);

        label = new QLabel(centralwidget);
        label->setObjectName(QString::fromUtf8("label"));
        sizePolicy1.setHeightForWidth(label->sizePolicy().hasHeightForWidth());
        label->setSizePolicy(sizePolicy1);
        label->setFont(font);

        DelayLayout->addWidget(label);

        DelayLayout->setStretch(0, 1);

        InpuLayout->addLayout(DelayLayout);


        ControlLayout->addLayout(InpuLayout);

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

        label_2 = new QLabel(centralwidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setFont(font);

        ControlLayout->addWidget(label_2);

        line_3 = new QFrame(centralwidget);
        line_3->setObjectName(QString::fromUtf8("line_3"));
        line_3->setFrameShape(QFrame::HLine);
        line_3->setFrameShadow(QFrame::Sunken);

        ControlLayout->addWidget(line_3);

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
        PointTableWidget->setAutoScroll(false);
        PointTableWidget->horizontalHeader()->setVisible(true);
        PointTableWidget->horizontalHeader()->setCascadingSectionResizes(false);
        PointTableWidget->horizontalHeader()->setMinimumSectionSize(20);
        PointTableWidget->horizontalHeader()->setDefaultSectionSize(150);
        PointTableWidget->horizontalHeader()->setHighlightSections(true);

        ControlLayout->addWidget(PointTableWidget);


        horizontalLayout->addLayout(ControlLayout);

        ResView = new QGraphicsView(centralwidget);
        ResView->setObjectName(QString::fromUtf8("ResView"));
        ResView->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignTop);

        horizontalLayout->addWidget(ResView);

        horizontalLayout->setStretch(1, 1);
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 1227, 21));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        label_3->setText(QCoreApplication::translate("MainWindow", "\320\220\320\273\320\263\320\276\321\200\320\270\321\202\320\274 \320\267\320\260\320\277\320\276\320\273\320\275\320\265\320\275\320\270\321\217 \321\201 \321\203\320\277\320\276\321\200\321\217\320\264\320\276\321\207\320\265\320\275\320\275\321\213\320\271\320\274 \n"
" \321\201\320\277\320\270\321\201\320\272\320\276\320\274 \321\200\321\221\320\261\320\265\321\200", nullptr));
        BGColorLabel->setText(QCoreApplication::translate("MainWindow", "\320\246\320\262\320\265\321\202 \321\204\320\276\320\275\320\260", nullptr));
        ButtonBlackBG->setText(QString());
        ButtonWhiteBG->setText(QString());
        ButtonYellowBG->setText(QString());
        ButtonRedBG->setText(QString());
        ButtonOrangeBG->setText(QString());
        ButtonPurpleBG->setText(QString());
        ButtonBlueBG->setText(QString());
        ButtonGreenBG->setText(QString());
        LIneColorBorder->setText(QCoreApplication::translate("MainWindow", "\320\246\320\262\320\265\321\202 \320\263\321\200\320\260\320\275\320\270\321\206(\321\202\320\265\320\272\321\203\321\211\320\270\320\271 \321\206\320\262\320\265\321\202-\321\207\320\265\321\200\320\275\321\213\320\271)", nullptr));
        ButtonBlackBorder->setText(QString());
        ButtonWhiteBorder->setText(QString());
        ButtonYellowBorder->setText(QString());
        ButtonRedBorder->setText(QString());
        ButtonOrangeBorder->setText(QString());
        ButtonPurpleBorder->setText(QString());
        ButtonBlueBorder->setText(QString());
        ButtonGreenBorder->setText(QString());
        LIneColorLabel->setText(QCoreApplication::translate("MainWindow", "\320\246\320\262\320\265\321\202 \320\267\320\260\320\273\320\270\320\262\320\272\320\270(\321\202\320\265\320\272\321\203\321\211\320\270\320\271 \321\206\320\262\320\265\321\202-\321\207\320\265\321\200\320\275\321\213\320\271)", nullptr));
        ButtonBlackLine->setText(QString());
        ButtonWhiteLine->setText(QString());
        ButtonYellowLine->setText(QString());
        ButtonRedLine->setText(QString());
        ButtonOrangeLine->setText(QString());
        ButtonPurpleLine->setText(QString());
        ButtonBlueLine->setText(QString());
        ButtonGreenLine->setText(QString());
        CenterLabel->setText(QCoreApplication::translate("MainWindow", "\320\232\320\276\320\276\321\200\320\264\320\270\320\275\320\260\321\202\321\213 \320\275\320\276\320\262\320\276\320\271 \321\202\320\276\321\207\320\272\320\270", nullptr));
        xLabel->setText(QCoreApplication::translate("MainWindow", "x:", nullptr));
        yLabel->setText(QCoreApplication::translate("MainWindow", "y:", nullptr));
        AddDotButton->setText(QCoreApplication::translate("MainWindow", "\320\224\320\276\320\261\320\260\320\262\320\270\321\202\321\214 \321\202\320\276\321\207\320\272\321\203", nullptr));
        CloseFigureButton->setText(QCoreApplication::translate("MainWindow", "\320\227\320\260\320\274\320\272\320\275\321\203\321\202\321\214 \321\204\320\270\320\263\321\203\321\200\321\203", nullptr));
        DelayCJeckBox->setText(QString());
        DelayLabel->setText(QCoreApplication::translate("MainWindow", "\320\227\320\260\320\264\320\265\321\200\320\266\320\272\320\260", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "\320\274\321\201", nullptr));
        CleanButton->setText(QCoreApplication::translate("MainWindow", "\320\236\321\207\320\270\321\201\321\202\320\270\321\202\321\214 \321\215\320\272\321\200\320\260\320\275", nullptr));
        DrawButton->setText(QCoreApplication::translate("MainWindow", "\320\240\320\260\320\267\320\262\321\221\321\200\321\202\320\272\320\260", nullptr));
        label_2->setText(QCoreApplication::translate("MainWindow", "\320\222\321\200\320\265\320\274\321\217 \321\200\320\260\320\261\320\276\321\202\321\213 \320\260\320\273\320\263\320\276\321\200\320\270\321\202\320\274\320\260: ", nullptr));
        QTableWidgetItem *___qtablewidgetitem = PointTableWidget->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QCoreApplication::translate("MainWindow", "x", nullptr));
        QTableWidgetItem *___qtablewidgetitem1 = PointTableWidget->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QCoreApplication::translate("MainWindow", "y", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
