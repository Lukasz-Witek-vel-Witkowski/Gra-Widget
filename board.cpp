#include "board.h"

Board::Board(QObject *parent):QObject(parent)
{
    creative();
}
void
Board::creative() {
    V_Tuple.resize(9);
    for(int i=0; i<9; i++){
        V_Tuple[i].setID(i);
    }
    winner = -1;
}
void
Board::clear() {
    V_Tuple.clear();
    creative();
}
void
Board::setValueTuple(int ID, Tuple::Value v) {
     if(isgood(ID))
        V_Tuple[ID].setValue(v);

}
int
Board::getValueTuple(int ID) {
    if(isgood(ID))
        return V_Tuple[ID].getValue();
    return -1; // zwraca blad
}
bool
Board::findWinner() {
    int i=0;
    bool what = false;
    Tuple::Value v;
        for(i=0; i<3; i++) {
            if(V_Tuple[i*3]==V_Tuple[i*3+1]&&V_Tuple[i*3]==V_Tuple[i*3+2]){
                if(Tuple::Value::wheel==V_Tuple[i*3].getValue())  v = Tuple::Value::wheel_win;
                else  v = Tuple::Value::cross_win;
                V_Tuple[3*i].setValue(v);
                V_Tuple[3*i+1].setValue(v);
                V_Tuple[3*i+2].setValue(v);
                winner = i;
                what =  true;
            }
            else if(V_Tuple[i]==V_Tuple[i+3]&&V_Tuple[i]==V_Tuple[i+6]){
                if(Tuple::Value::wheel==V_Tuple[i].getValue())  v = Tuple::Value::wheel_win;
                else  v = Tuple::Value::cross_win;
                V_Tuple[i].setValue(v);
                V_Tuple[i+3].setValue(v);
                V_Tuple[i+6].setValue(v);
                 winner = i+3;
                what = true;
            }
        }
        if(V_Tuple[0]==V_Tuple[4]&&V_Tuple[0]==V_Tuple[8]) {
            if(Tuple::Value::wheel==V_Tuple[0].getValue())  v = Tuple::Value::wheel_win;
            else  v = Tuple::Value::cross_win;
            V_Tuple[0].setValue(v);
            V_Tuple[4].setValue(v);
            V_Tuple[8].setValue(v);
            winner = 6;
            what = true;
        }
        else if(V_Tuple[2]==V_Tuple[4]&&V_Tuple[2]==V_Tuple[6]) {
            if(Tuple::Value::wheel==V_Tuple[2].getValue())  v = Tuple::Value::wheel_win;
            else  v = Tuple::Value::cross_win;
            V_Tuple[2].setValue(v);
            V_Tuple[4].setValue(v);
            V_Tuple[6].setValue(v);
            winner = 7;
            what = true;
        }
        else{
            int j=1;
            for(i=0; i<9;i++) {
                j *=V_Tuple[i].isActive();
            }
            if(j == 1) {
                winner = 8;
                what = true;
            }
        }
    if(what){

          emit finishGame(v,winner);

        return true;
    }
    return false;
}
bool
Board::isgood(int value) {
    return (value >= 0 && value < 9);
}
bool
Board::isEmpty(int value) {
    return !V_Tuple[value].isActive();
}
int
Board::getWinner() {
    return winner;
}
const QString
Board::tostring(int id) {
    if(isgood(id)) {
        return V_Tuple[id].toString();
  }
    return "";
}

// 0 1 2 dla 0
// 3 4 5
// 6 7 8
