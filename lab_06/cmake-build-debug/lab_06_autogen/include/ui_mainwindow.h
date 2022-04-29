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
#include <QtWidgets/QSpacerItem>
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
    QVBoxLayout *BorderColorBox;
    QLabel *LIneColorBorder;
    QHBoxLayout *BorderColorsLay;
    QPushButton *ButtonBlackBorder;
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
    QVBoxLayout *ZatravLayout;
    QLabel *ZtravLableLabel;
    QFormLayout *ZatravformLayout;
    QLabel *cxLabel;
    QLineEdit *cxLineEdit;
    QLabel *cyLabel;
    QLineEdit *cyLineEdit;
    QPushButton *AddZatravButton;
    QVBoxLayout *ZatravLayout_2;
    QLabel *ZtravLableLabel_2;
    QFormLayout *ZatravformLayout_2;
    QLabel *cxLabel_2;
    QLineEdit *cxLineEdit_2;
    QLabel *cyLabel_2;
    QLineEdit *cyLineEdit_2;
    QVBoxLayout *ZatravLayout_3;
    QLabel *ZtravLableLabel_3;
    QFormLayout *ZatravformLayout_3;
    QLabel *cxLabel_3;
    QLineEdit *cxLineEdit_3;
    QLabel *cyLabel_3;
    QLineEdit *cyLineEdit_3;
    QPushButton *DrawEllipseButton;
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
    QSpacerItem *verticalSpacer;
    QTableWidget *PointTableWidget;
    QGraphicsView *ResView;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(1868, 1041);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        horizontalLayout = new QHBoxLayout(centralwidget);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        ControlLayout = new QVBoxLayout();
        ControlLayout->setObjectName(QString::fromUtf8("ControlLayout"));
        BorderColorBox = new QVBoxLayout();
        BorderColorBox->setObjectName(QString::fromUtf8("BorderColorBox"));
        LIneColorBorder = new QLabel(centralwidget);
        LIneColorBorder->setObjectName(QString::fromUtf8("LIneColorBorder"));
        QSizePolicy sizePolicy(QSizePolicy::Minimum, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(LIneColorBorder->sizePolicy().hasHeightForWidth());
        LIneColorBorder->setSizePolicy(sizePolicy);
        QFont font;
        font.setPointSize(12);
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

        ZatravLayout = new QVBoxLayout();
        ZatravLayout->setObjectName(QString::fromUtf8("ZatravLayout"));
        ZtravLableLabel = new QLabel(centralwidget);
        ZtravLableLabel->setObjectName(QString::fromUtf8("ZtravLableLabel"));
        sizePolicy1.setHeightForWidth(ZtravLableLabel->sizePolicy().hasHeightForWidth());
        ZtravLableLabel->setSizePolicy(sizePolicy1);
        ZtravLableLabel->setFont(font);
        ZtravLableLabel->setAlignment(Qt::AlignCenter);

        ZatravLayout->addWidget(ZtravLableLabel);

        ZatravformLayout = new QFormLayout();
        ZatravformLayout->setObjectName(QString::fromUtf8("ZatravformLayout"));
        cxLabel = new QLabel(centralwidget);
        cxLabel->setObjectName(QString::fromUtf8("cxLabel"));
        sizePolicy1.setHeightForWidth(cxLabel->sizePolicy().hasHeightForWidth());
        cxLabel->setSizePolicy(sizePolicy1);
        cxLabel->setFont(font);

        ZatravformLayout->setWidget(0, QFormLayout::LabelRole, cxLabel);

        cxLineEdit = new QLineEdit(centralwidget);
        cxLineEdit->setObjectName(QString::fromUtf8("cxLineEdit"));
        sizePolicy.setHeightForWidth(cxLineEdit->sizePolicy().hasHeightForWidth());
        cxLineEdit->setSizePolicy(sizePolicy);
        cxLineEdit->setFont(font);

        ZatravformLayout->setWidget(0, QFormLayout::FieldRole, cxLineEdit);

        cyLabel = new QLabel(centralwidget);
        cyLabel->setObjectName(QString::fromUtf8("cyLabel"));
        sizePolicy1.setHeightForWidth(cyLabel->sizePolicy().hasHeightForWidth());
        cyLabel->setSizePolicy(sizePolicy1);
        cyLabel->setFont(font);

        ZatravformLayout->setWidget(1, QFormLayout::LabelRole, cyLabel);

        cyLineEdit = new QLineEdit(centralwidget);
        cyLineEdit->setObjectName(QString::fromUtf8("cyLineEdit"));
        sizePolicy.setHeightForWidth(cyLineEdit->sizePolicy().hasHeightForWidth());
        cyLineEdit->setSizePolicy(sizePolicy);
        cyLineEdit->setFont(font);

        ZatravformLayout->setWidget(1, QFormLayout::FieldRole, cyLineEdit);


        ZatravLayout->addLayout(ZatravformLayout);

        AddZatravButton = new QPushButton(centralwidget);
        AddZatravButton->setObjectName(QString::fromUtf8("AddZatravButton"));
        sizePolicy.setHeightForWidth(AddZatravButton->sizePolicy().hasHeightForWidth());
        AddZatravButton->setSizePolicy(sizePolicy);
        AddZatravButton->setFont(font);

        ZatravLayout->addWidget(AddZatravButton);


        InpuLayout->addLayout(ZatravLayout);

        ZatravLayout_2 = new QVBoxLayout();
        ZatravLayout_2->setObjectName(QString::fromUtf8("ZatravLayout_2"));
        ZtravLableLabel_2 = new QLabel(centralwidget);
        ZtravLableLabel_2->setObjectName(QString::fromUtf8("ZtravLableLabel_2"));
        sizePolicy1.setHeightForWidth(ZtravLableLabel_2->sizePolicy().hasHeightForWidth());
        ZtravLableLabel_2->setSizePolicy(sizePolicy1);
        ZtravLableLabel_2->setFont(font);
        ZtravLableLabel_2->setAlignment(Qt::AlignCenter);

        ZatravLayout_2->addWidget(ZtravLableLabel_2);

        ZatravformLayout_2 = new QFormLayout();
        ZatravformLayout_2->setObjectName(QString::fromUtf8("ZatravformLayout_2"));
        cxLabel_2 = new QLabel(centralwidget);
        cxLabel_2->setObjectName(QString::fromUtf8("cxLabel_2"));
        sizePolicy1.setHeightForWidth(cxLabel_2->sizePolicy().hasHeightForWidth());
        cxLabel_2->setSizePolicy(sizePolicy1);
        cxLabel_2->setFont(font);

        ZatravformLayout_2->setWidget(0, QFormLayout::LabelRole, cxLabel_2);

        cxLineEdit_2 = new QLineEdit(centralwidget);
        cxLineEdit_2->setObjectName(QString::fromUtf8("cxLineEdit_2"));
        sizePolicy.setHeightForWidth(cxLineEdit_2->sizePolicy().hasHeightForWidth());
        cxLineEdit_2->setSizePolicy(sizePolicy);
        cxLineEdit_2->setFont(font);

        ZatravformLayout_2->setWidget(0, QFormLayout::FieldRole, cxLineEdit_2);

        cyLabel_2 = new QLabel(centralwidget);
        cyLabel_2->setObjectName(QString::fromUtf8("cyLabel_2"));
        sizePolicy1.setHeightForWidth(cyLabel_2->sizePolicy().hasHeightForWidth());
        cyLabel_2->setSizePolicy(sizePolicy1);
        cyLabel_2->setFont(font);

        ZatravformLayout_2->setWidget(1, QFormLayout::LabelRole, cyLabel_2);

        cyLineEdit_2 = new QLineEdit(centralwidget);
        cyLineEdit_2->setObjectName(QString::fromUtf8("cyLineEdit_2"));
        sizePolicy.setHeightForWidth(cyLineEdit_2->sizePolicy().hasHeightForWidth());
        cyLineEdit_2->setSizePolicy(sizePolicy);
        cyLineEdit_2->setFont(font);

        ZatravformLayout_2->setWidget(1, QFormLayout::FieldRole, cyLineEdit_2);


        ZatravLayout_2->addLayout(ZatravformLayout_2);


        InpuLayout->addLayout(ZatravLayout_2);

        ZatravLayout_3 = new QVBoxLayout();
        ZatravLayout_3->setObjectName(QString::fromUtf8("ZatravLayout_3"));
        ZtravLableLabel_3 = new QLabel(centralwidget);
        ZtravLableLabel_3->setObjectName(QString::fromUtf8("ZtravLableLabel_3"));
        sizePolicy1.setHeightForWidth(ZtravLableLabel_3->sizePolicy().hasHeightForWidth());
        ZtravLableLabel_3->setSizePolicy(sizePolicy1);
        ZtravLableLabel_3->setFont(font);
        ZtravLableLabel_3->setAlignment(Qt::AlignCenter);

        ZatravLayout_3->addWidget(ZtravLableLabel_3);

        ZatravformLayout_3 = new QFormLayout();
        ZatravformLayout_3->setObjectName(QString::fromUtf8("ZatravformLayout_3"));
        cxLabel_3 = new QLabel(centralwidget);
        cxLabel_3->setObjectName(QString::fromUtf8("cxLabel_3"));
        sizePolicy1.setHeightForWidth(cxLabel_3->sizePolicy().hasHeightForWidth());
        cxLabel_3->setSizePolicy(sizePolicy1);
        cxLabel_3->setFont(font);

        ZatravformLayout_3->setWidget(0, QFormLayout::LabelRole, cxLabel_3);

        cxLineEdit_3 = new QLineEdit(centralwidget);
        cxLineEdit_3->setObjectName(QString::fromUtf8("cxLineEdit_3"));
        sizePolicy.setHeightForWidth(cxLineEdit_3->sizePolicy().hasHeightForWidth());
        cxLineEdit_3->setSizePolicy(sizePolicy);
        cxLineEdit_3->setFont(font);

        ZatravformLayout_3->setWidget(0, QFormLayout::FieldRole, cxLineEdit_3);

        cyLabel_3 = new QLabel(centralwidget);
        cyLabel_3->setObjectName(QString::fromUtf8("cyLabel_3"));
        sizePolicy1.setHeightForWidth(cyLabel_3->sizePolicy().hasHeightForWidth());
        cyLabel_3->setSizePolicy(sizePolicy1);
        cyLabel_3->setFont(font);

        ZatravformLayout_3->setWidget(1, QFormLayout::LabelRole, cyLabel_3);

        cyLineEdit_3 = new QLineEdit(centralwidget);
        cyLineEdit_3->setObjectName(QString::fromUtf8("cyLineEdit_3"));
        sizePolicy.setHeightForWidth(cyLineEdit_3->sizePolicy().hasHeightForWidth());
        cyLineEdit_3->setSizePolicy(sizePolicy);
        cyLineEdit_3->setFont(font);

        ZatravformLayout_3->setWidget(1, QFormLayout::FieldRole, cyLineEdit_3);


        ZatravLayout_3->addLayout(ZatravformLayout_3);

        DrawEllipseButton = new QPushButton(centralwidget);
        DrawEllipseButton->setObjectName(QString::fromUtf8("DrawEllipseButton"));
        sizePolicy.setHeightForWidth(DrawEllipseButton->sizePolicy().hasHeightForWidth());
        DrawEllipseButton->setSizePolicy(sizePolicy);
        DrawEllipseButton->setFont(font);

        ZatravLayout_3->addWidget(DrawEllipseButton);


        InpuLayout->addLayout(ZatravLayout_3);

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

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        ControlLayout->addItem(verticalSpacer);


        horizontalLayout->addLayout(ControlLayout);

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
        PointTableWidget->horizontalHeader()->setDefaultSectionSize(120);
        PointTableWidget->horizontalHeader()->setHighlightSections(true);

        horizontalLayout->addWidget(PointTableWidget);

        ResView = new QGraphicsView(centralwidget);
        ResView->setObjectName(QString::fromUtf8("ResView"));
        ResView->setEnabled(true);
        QSizePolicy sizePolicy3(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy3.setHorizontalStretch(0);
        sizePolicy3.setVerticalStretch(0);
        sizePolicy3.setHeightForWidth(ResView->sizePolicy().hasHeightForWidth());
        ResView->setSizePolicy(sizePolicy3);
        ResView->setMinimumSize(QSize(1295, 970));
        ResView->setMaximumSize(QSize(1400, 1100));
        ResView->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignTop);

        horizontalLayout->addWidget(ResView);

        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 1868, 21));
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
        LIneColorBorder->setText(QCoreApplication::translate("MainWindow", "\320\246\320\262\320\265\321\202 \320\263\321\200\320\260\320\275\320\270\321\206(\321\202\320\265\320\272\321\203\321\211\320\270\320\271 \321\206\320\262\320\265\321\202-\321\207\320\265\321\200\320\275\321\213\320\271)", nullptr));
        ButtonBlackBorder->setText(QString());
        ButtonYellowBorder->setText(QString());
        ButtonRedBorder->setText(QString());
        ButtonOrangeBorder->setText(QString());
        ButtonPurpleBorder->setText(QString());
        ButtonBlueBorder->setText(QString());
        ButtonGreenBorder->setText(QString());
        LIneColorLabel->setText(QCoreApplication::translate("MainWindow", "\320\246\320\262\320\265\321\202 \320\267\320\260\320\273\320\270\320\262\320\272\320\270(\321\202\320\265\320\272\321\203\321\211\320\270\320\271 \321\206\320\262\320\265\321\202-\321\207\320\265\321\200\320\275\321\213\320\271)", nullptr));
        ButtonBlackLine->setText(QString());
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
        ZtravLableLabel->setText(QCoreApplication::translate("MainWindow", "\320\232\320\276\320\276\321\200\320\264\320\270\320\275\320\260\321\202\321\213 \320\267\320\260\321\202\321\200\320\260\320\262\320\276\321\207\320\275\320\276\320\271 \321\202\320\276\321\207\320\272\320\270", nullptr));
        cxLabel->setText(QCoreApplication::translate("MainWindow", "x:", nullptr));
        cyLabel->setText(QCoreApplication::translate("MainWindow", "y:", nullptr));
        AddZatravButton->setText(QCoreApplication::translate("MainWindow", "\320\222\320\262\320\265\321\201\321\202\320\270 \320\267\320\260\321\202\321\200\320\260\320\262\320\276\321\207\320\275\321\203\321\216 \321\202\320\276\321\207\320\272\321\203", nullptr));
        ZtravLableLabel_2->setText(QCoreApplication::translate("MainWindow", "\320\232\320\276\320\276\321\200\320\264\320\270\320\275\320\260\321\202\321\213 \321\206\320\265\320\275\321\202\321\200\320\260 \321\215\320\273\320\273\320\270\320\277\321\201\320\260", nullptr));
        cxLabel_2->setText(QCoreApplication::translate("MainWindow", "x:", nullptr));
        cxLineEdit_2->setText(QCoreApplication::translate("MainWindow", "650", nullptr));
        cyLabel_2->setText(QCoreApplication::translate("MainWindow", "y:", nullptr));
        cyLineEdit_2->setText(QCoreApplication::translate("MainWindow", "485", nullptr));
        ZtravLableLabel_3->setText(QCoreApplication::translate("MainWindow", "\320\237\320\260\321\200\320\260\320\274\320\265\321\202\321\200 \321\215\320\273\320\273\320\270\320\277\321\201\320\260", nullptr));
        cxLabel_3->setText(QCoreApplication::translate("MainWindow", "\320\223\320\276\321\200\320\270\320\267\320\276\320\275\321\202\320\260\320\273\321\214\320\275\320\260\321\217 \320\277\320\276\320\273\321\203\320\276\321\201\321\214", nullptr));
        cyLabel_3->setText(QCoreApplication::translate("MainWindow", "\320\222\320\265\321\200\321\202\320\270\320\272\320\260\320\273\321\214\320\275\320\260\321\217 \320\277\320\276\320\273\321\203\320\276\321\201\321\214", nullptr));
        DrawEllipseButton->setText(QCoreApplication::translate("MainWindow", "\320\237\320\276\321\201\321\202\321\200\320\276\320\270\321\202\321\214 \321\215\320\273\320\273\320\270\320\277\321\201", nullptr));
        DelayCJeckBox->setText(QString());
        DelayLabel->setText(QCoreApplication::translate("MainWindow", "\320\227\320\260\320\264\320\265\321\200\320\266\320\272\320\260", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "\320\274\321\201", nullptr));
        CleanButton->setText(QCoreApplication::translate("MainWindow", "\320\236\321\207\320\270\321\201\321\202\320\270\321\202\321\214 \321\215\320\272\321\200\320\260\320\275", nullptr));
        DrawButton->setText(QCoreApplication::translate("MainWindow", "\320\227\320\260\321\202\321\200\320\260\320\262\320\272\320\260", nullptr));
        label_2->setText(QCoreApplication::translate("MainWindow", "\320\222\321\200\320\265\320\274\321\217 \321\200\320\260\320\261\320\276\321\202\321\213 \320\260\320\273\320\263\320\276\321\200\320\270\321\202\320\274\320\260:", nullptr));
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
