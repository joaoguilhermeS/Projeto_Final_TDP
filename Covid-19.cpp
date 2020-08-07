#include "Covid-19.h"
#include "jpcovid.h"
#include "srcovid.h"
#include "bycovid.h"
#include "cbcovid.h"
int Covid_19::Syntoms(bool *c)
{
    int n=0;
    QFile arquivo(local+name);
    arquivo.open(QFile::Append|QFile::Text);
    QTextStream saida(&arquivo);//Gravar no Arquivo
    for(int i=0;i<8;++i)
    {
        if(c[i])
        {
            n++;
            saida<<"Sim  ";
        }
        else
        {
            saida<<"Nao  ";
        }
        if(c[4] || c[5])
        {
            n=5;
        }
    }
        if(n>2 && n<5)
        {
            saida<<"Ficar em isolamento  ";
        }
        else
        {
            if(n>=5)
            {
                saida<<"Necessita urgentemente ";
            }
            else
            {
                saida<<"Nao  ";
            }
            }
arquivo.close();

    return n;
}

int Covid_19::Questoes(bool *p)
{
    QFile arquivo(local+name);
    arquivo.open(QFile::Append|QFile::Text);
    QTextStream saida(&arquivo);
    for(int i=0;i<7;i++)
    {
        if(p[i])
        {

            saida<<"Sim  ";
        }
        else
        {
            saida<<"Nao  ";
        }
    }
    saida<<"\n";
    arquivo.close();
    return 0;
}

void Covid_19::locale()//Mostrar os locais de recomendaçao dependendo de cada cidade
{
    if(cidade == "João Pessoa")
    {
       JPCovid E; E.exec();
    }
    else
    {
        if(cidade == "Santa Rita")
        {
            srcovid E;
            E.exec();
        }
        else
        {
            if(cidade == "Bayeux")
            {
                bycovid E;
                E.exec();
            }
            else
            {
                JPCovid E;
                E.exec();
            }
        }
    }
}
