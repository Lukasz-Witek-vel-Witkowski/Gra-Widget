#ifndef TUPLE_H
#define TUPLE_H
#include <QObject>

class Tuple : public QObject
{
public:
    enum Value{
        wheel,
        cross,
        wheel_win,
        cross_win,
        empty
    };
    explicit Tuple(QObject *parent = nullptr);
    Tuple(const Tuple& t);
    bool isActive();
    void used();
    void setValue(Value v);
    int getValue();
    int getID();
    void setID(int ID);
    const QString toString();
    bool operator==(const Tuple& t);
    Tuple& operator=(const Tuple& t);
private:
    Q_OBJECT
    bool active;
    int id;
    Value value;
};

#endif // TUPLE_H
