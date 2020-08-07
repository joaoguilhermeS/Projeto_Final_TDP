#include "saude_mental.h"
#include "joaopessoa.h"
#include "santa_rita.h"
#include "bayeux.h"
#include "cabedelo.h"


//Observações iguais a de covid-19
int Saude_Mental::Syntoms(bool *c)
{   int n=0;
    QFile arquivo(local+name);
    if(!arquivo.open(QFile::Append|QFile::Text))
    {
        //Ve o que fazer caso ele não abra;
    }
    QTextStream saida(&arquivo);
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

    }
    arquivo.close();
    return n;
}

int Saude_Mental::Questoes(bool *p)
{
    int n=0;
    QFile arquivo(local+name);
    if(!arquivo.open(QFile::Append|QFile::Text))
    {
        //Ve o que fazer caso ele não abra;
    }
    QTextStream saida(&arquivo);
    for(int i=0;i<7;i++)
    {
        if(p[i])
        {
            n++;
            saida<<"Sim  ";
        }
        else
        {
            saida<<"Nao  ";
        }
    }

    arquivo.close();
    return  n;
}

void Saude_Mental::locale()
{
   if(cidade=="João Pessoa")
    {
    JoaoPessoa E;
    E.exec();
    }
   else
   {
       if(cidade == "Santa Rita")
       {
           Santa_Rita E;
           E.exec();
       }
       else
       {
           if(cidade=="Cabedelo")
           {
               Cabedelo E;
               E.exec();
           }
           else
           {
               Bayeux E;
               E.exec();
           }
       }
   }
}
