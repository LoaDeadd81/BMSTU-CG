#include "form.h"
#include "ui_form.h"

form::form(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::form)
{
    ui->setupUi(this);
}

form::~form()
{
    delete ui;
}
