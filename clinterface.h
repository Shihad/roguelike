#ifndef CLINTERFACE_H
#define CLINTERFACE_H
#include <QObject>
#include <QDebug>

class CLInterface : public QObject
{
    Q_OBJECT
public:
    explicit CLInterface(QObject *parent = 0);
    void showMap(int* arr,int m,int n);

signals:

public slots:
};

#endif // CLINTERFACE_H
