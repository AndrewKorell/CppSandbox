#ifndef DIALOG_H
#define DIALOG_H

#include "mythread.h"
#include <QDialog>

QT_BEGIN_NAMESPACE
namespace Ui { class Dialog; }
QT_END_NAMESPACE

class Dialog : public QDialog
{
    Q_OBJECT

public:
    Dialog(QWidget *parent = 0);
    ~Dialog();
    MyThread *mThread;

private:
    Ui::Dialog *ui;

public slots:
    void onNumberChanged(int);
private slots:
    void on_startButton_clicked();
    void on_stopButton_clicked();
};
#endif // DIALOG_H
