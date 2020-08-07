#ifndef BYCOVID_H
#define BYCOVID_H

#include <QDialog>

namespace Ui {
class bycovid;
}

class bycovid : public QDialog
{
    Q_OBJECT

public:
    explicit bycovid(QWidget *parent = nullptr);
    ~bycovid();

private slots:
    void on_pushButton_clicked();

private:
    Ui::bycovid *ui;
};

#endif // BYCOVID_H
