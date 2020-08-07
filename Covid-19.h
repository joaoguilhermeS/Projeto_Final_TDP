#ifndef COVID19_H
#define COVID19_H

#include "Paciente.h"
#include <QDialog>
#include <QFile>
#include <QTextStream>

class Covid_19:public Paciente_t
{
    QString local=("E:/Felipe/Tec-Pro/");
    QString name=("Usuarios_Covid-19.txt");
public:
    Covid_19(QString n, QString s, QString c,QString b,int i):Paciente_t(n,s,c,b,i)
    {
        set_name(n);
        set_sex(s);
        set_city(c);
        set_idad(i);
        set_bair(b);
        QFile arquivo(local+name);
        if(!arquivo.open(QFile::Append|QFile::Text))
        {

        }
        QTextStream saida(&arquivo);
        saida <<nome<<"  "<<sexo<<"  "<<cidade<<"  "<<bairro<<"  "<<idade<<" Anos ";
        arquivo.close();

    }
    int Syntoms(bool *c);
    int Questoes(bool *p);
    void locale();

};
#endif // COVID19_H
