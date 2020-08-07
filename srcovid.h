#ifndef SRCOVID_H
#define SRCOVID_H

#include <QDialog>

namespace Ui {
class srcovid;
}

class srcovid : public QDialog
{
    Q_OBJECT

public:
    explicit srcovid(QWidget *parent = nullptr);
    ~srcovid();

private slots:
    void on_pushButton_clicked();

private:
    Ui::srcovid *ui;
};

#endif // SRCOVID_H
