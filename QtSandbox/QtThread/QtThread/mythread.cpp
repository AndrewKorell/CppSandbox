#include "mythread.h"
#include <QtCore>
#include <QDebug>
#include <iostream>

MyThread::MyThread()
{

}


void MyThread::run()
{
    qDebug() << this->name << "Running";

    for(int i = 0; i < 1000; i++) {
        QMutex mutex;
        mutex.lock(); //ensures that only this thread can access the Stop variable
        if(this->Stop) {
            break;
        }
        mutex.unlock();

        qDebug() << this->name << i;
    }

}
