#ifndef LOCAL_DE_AJUDA_H
#define LOCAL_DE_AJUDA_H

#include <QDialog>

class Local_de_Ajuda
{   QString lcity;
public:
    Local_de_Ajuda(QString n)
    {
        lcity = n;
    }
    QString pegarcidade(){return lcity;};
};

#endif // LOCAL_DE_AJUDA_H
