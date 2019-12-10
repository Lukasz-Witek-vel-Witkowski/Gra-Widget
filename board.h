#ifndef BOARD_H
#define BOARD_H
#include "tuple.h"
#include <qvector.h>
#include <QObject>
#include <QDebug>
class Board : public QObject
{
    QVector<Tuple> V_Tuple;
    bool isgood(int value);
    Q_OBJECT
    int winner;
public:
    explicit Board(QObject *parent = nullptr);
    void creative();
    void clear();
    void setValueTuple(int ID, Tuple::Value v);
    int getValueTuple(int ID);
    bool findWinner();
    bool isEmpty(int value);
    int getWinner();
    const QString tostring(int id);

signals:
void finishGame(int,int);
public slots:
};

#endif // BOARD_H
