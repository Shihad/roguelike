#ifndef ROGUELIKEMAP_H
#define ROGUELIKEMAP_H
#include <QObject>



class RoguelikeMap : public QObject
{
    Q_OBJECT
public:
    explicit RoguelikeMap(QObject *parent = 0);
    void generateRandomMap();
    void placeHeroInRandomPlace();
    void returnMap();

    void placePickUpInRandomPlace();
    int currentMapArray[50][50];


    void placeEnemyInRandomPlace();
signals:

public slots:
    void killEnemyInXY(int x, int y);

private:
    int mapArray[50][50];
};

#endif // ROGUELIKEMAP_H
