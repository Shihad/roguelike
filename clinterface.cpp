#include "clinterface.h"
#include "iostream"

CLInterface::CLInterface(QObject *parent) : QObject(parent)
{
    qDebug()<<"hello";

}

void CLInterface::showMap(int* arr, int m, int n) {
    for(int i = 0; i < m; i++) {
        for(int j = 0; j < n; j++) {
        //    qDebug() << *(arr + i*n + j);
            std::cout<<*(arr + i*n + j);

        }
      //  qDebug() << endl;
        std::cout<<endl;
    }
}
