#ifndef JPCOVID_H
#define JPCOVID_H

#include <QDialog>

namespace Ui {
class JPCovid;
}

class JPCovid : public QDialog
{
    Q_OBJECT

public:
    explicit JPCovid(QWidget *parent = nullptr);
    ~JPCovid();

private slots:
    void on_pushButton_clicked();

private:
    Ui::JPCovid *ui;
};

#endif // JPCOVID_H
