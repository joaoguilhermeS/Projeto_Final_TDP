#include "santa_rita.h"
#include "ui_santa_rita.h"

Santa_Rita::Santa_Rita(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Santa_Rita)
{
    ui->setupUi(this);
}

Santa_Rita::~Santa_Rita()
{
    delete ui;
}

void Santa_Rita::on_pushButton_clicked()
{
    this->close();
}
