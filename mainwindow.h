#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QGridLayout>
#include <QTableView>
#include <QLabel>
#include <QGroupBox>
#include <QPushButton>
#include "board.h"
#include <QComboBox>
#include <QSpacerItem>
#include <QTextEdit>
#include <QPainter>
#include <QButtonGroup>
#include <QStringListModel>
#include <QAbstractItemModel>
#include <QMessageBox>
#include <QStandardItemModel>
#include "round.h"
#include <QDebug>
QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT
    int combo_1;
    int combo_2;
    int color_user_1;
    int color_user_2;
    int winner;
    QWidget *widget;
    Round *round;
    QGridLayout *layout;
    QGridLayout *layoutBox;
    QTableView *table;
    QGroupBox *box;
    QStandardItemModel *Table_view;
    QTextEdit *Text_one;
    QTextEdit *Text_two;
    QStringListModel *model;
    QStringList *listmodel;
    QList<QModelIndex> Listindex;
    QStandardItem *baze;
    Board *board;
    QLabel *Name_one;
    QLabel *Name_two;
    QLabel *Color_one;
    QLabel *Color_two;
    QRect *rect;
    QComboBox *combo_one;
    QComboBox *combo_two;
    QPushButton *start;
    QPushButton *restart;
    QPushButton *Color_item_one;
    QPushButton * Color_item_two;
    QSpacerItem *spa_1;
    QSpacerItem *spa_2;
    QSpacerItem *spa_3;
    QSpacerItem *spa_4;
    QMessageBox BOX;
    enum COLOR{
        Black,
        Red,
        Green,
        Blue,
        Grey,
        Yellow
    };
     //Q_PROPERTY(int ID READ _combo_1 WRITE clickCombo_1 NOTIFY _ClickCombo_1)
     //Q_PROPERTY(int ID READ _combo_2 WRITE clickCombo_2 NOTIFY _ClickCombo_2)
     void shiftColor(int type, int value);
     void setText(int type);
     void setLayout();
     void ClickButton(int value);
     QString getWinner(int value);
     QColor setColor(int i);
public:
    MainWindow(QWidget *parent = nullptr);
    void config();
    void ConfigBoard();
    void ConfigComboBox();
    void clickCombo_1(int id) {shiftColor(0,id);}
    void clickCombo_2(int id) {shiftColor(1,id);}
    int _combo_1() {return combo_1;}
    int _combo_2() {return combo_2;}
    ~MainWindow();
public slots:
    void shiftColor_1(int id){shiftColor(0,id);}
    void shiftColor_2(int id){shiftColor(1,id);}
    void SetText_one(){setText(0);}
    void SetText_two(){setText(1);}
    void Click_start(){ClickButton(0);}
    void Click_reset(){ClickButton(1);}
    void Click_board(QModelIndex);
    void Finish(int valu, int win);
signals:
    void _ClickCombo_1();
    void _ClickCombo_2();
private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
