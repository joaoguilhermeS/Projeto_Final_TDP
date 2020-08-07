#include "recomendacoes.h"
#include "ui_recomendacoes.h"
#include "saude_mental.h"

Recomendacoes::Recomendacoes(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Recomendacoes)
{
    ui->setupUi(this);
}

Recomendacoes::~Recomendacoes()
{
    delete ui;
}

void Recomendacoes::on_pushButton_clicked()
{

}
