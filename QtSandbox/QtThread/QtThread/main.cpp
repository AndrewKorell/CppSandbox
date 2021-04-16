#include <QCoreApplication>
#include "mythread.h"

//deadlock: two threads lockup
//collision: two threads write the same value at the same time
int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    MyThread mThread1;
    MyThread mThread2;
    MyThread mThread3;

    mThread1.name = "Thread1";
    mThread2.name = "Thread2";
    mThread3.name = "Thread3";

    mThread1.start(QThread::HighestPriority);
    mThread2.start(QThread::NormalPriority);
    mThread3.start(QThread::LowPriority);

    mThread1.Stop = true;

    return a.exec();
}
