#ifndef ROUND_H
#define ROUND_H
#include <QStringList>

class Round
{
    int number;
    int opponent;
    QStringList Tab;
public:
    Round(int Opponent = 2);
    void setUser(int value, QString Name);
    QString getUser(int value);
    void next();
    int getOpponent();
    void reset();
};

#endif // ROUND_H
