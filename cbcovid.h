#ifndef CBCOVID_H
#define CBCOVID_H

#include <QDialog>

namespace Ui {
class cbcovid;
}

class cbcovid : public QDialog
{
    Q_OBJECT

public:
    explicit cbcovid(QWidget *parent = nullptr);
    ~cbcovid();

private slots:
    void on_pushButton_clicked();

private:
    Ui::cbcovid *ui;
};

#endif // CBCOVID_H
