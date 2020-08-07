#ifndef AJUDA_H
#define AJUDA_H

#include <QDialog>
#include "Paciente.h"
namespace Ui {
class Ajuda;
}

class Ajuda : public QDialog
{
    Q_OBJECT
    QString help,cidade;


public:
    explicit Ajuda(QWidget *parent = nullptr);
    ~Ajuda();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_7_clicked();

    void on_pushButton_8_clicked();

    void on_pushButton_5_clicked();

    void on_pushButton_6_clicked();

    void on_pushButton_4_clicked();

public:
    int Analise(Paciente_t *Pecas[], bool *c)
    {
        int a = Pecas[0]->Syntoms(c);
        return a;
    }

    int Analise2(Paciente_t *Pecas[], bool *p)
    {
        int a = Pecas[0]->Questoes(p);
        return a;
    }
    void Indicar(Paciente_t *Pecas[])
    {
        Pecas[0]->locale();
    }
private:
    Ui::Ajuda *ui;
};

#endif // AJUDA_H
