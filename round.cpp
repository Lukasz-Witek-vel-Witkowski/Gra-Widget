#include "round.h"

Round::Round(int Opponent)
{
opponent = Opponent;
number = 0;
Tab.reserve(opponent);
}
void
Round::setUser(int value, QString Name) {
    if(value>=0&&value<opponent)
        Tab[value] = Name;
}
QString
Round::getUser(int value) {
     if(value>0&&value<opponent)
        return Tab[value];
     return nullptr;
}
int
Round::getOpponent() {
    return number%2;
}
void
Round::next() {
    number++;
}
void
Round::reset() {
    number = 0;
}
