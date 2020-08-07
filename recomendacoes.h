#ifndef RECOMENDACOES_H
#define RECOMENDACOES_H

#include <QDialog>
#include "saude_mental.h"
#include "Covid-19.h"

namespace Ui {
class Recomendacoes;
}

class Recomendacoes : public QDialog : public Saude_Mental
{
    Q_OBJECT
QString a = (Saude_Mental::getcity());
public:
    explicit Recomendacoes(QWidget *parent = nullptr);
    ~Recomendacoes();

private slots:
    void on_pushButton_clicked();

private:
    Ui::Recomendacoes *ui;
};

#endif // RECOMENDACOES_H
