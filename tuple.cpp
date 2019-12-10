#include "tuple.h"

Tuple::Tuple(QObject *parent) : QObject(parent)
{
    value = Value::empty;
    id = -1;
    active = false;
}
Tuple::Tuple(const Tuple& t) {
    if(this!=&t) *this = t;
}
bool
Tuple::isActive() {
    return active;
}
void
Tuple::used() {
    active = true;
}
void
Tuple::setValue(Value v) {
    value = v;
    used();
}
int
Tuple::getValue() {
    return value;
}
int
Tuple::getID() {
    return id;
}
void
Tuple::setID(int ID) {
    id = ID;
}
Tuple&
Tuple::operator=(const Tuple& t) {
    if(this == &t) return *this;
    if(*this == t) return *this;
    active = t.active;
    id = t.id;
    value = t.value;
    return *this;
}
bool
Tuple::operator==(const Tuple& t) {
    if(active&&t.active&&id!=t.id) {
        if(value==t.value) {
            return true;
        }
    }
    return false;
}
const QString
Tuple::toString() {
    switch (value) {
    case empty:
        return " ";
    case cross:
    case cross_win:
        return "X";
    case wheel:
    case wheel_win:
        return "O";
    }
    return "";
}
