#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    config();

    connect(combo_one, SIGNAL(currentIndexChanged(int)), this, SLOT(shiftColor_1(int)));
    connect(combo_two, SIGNAL(currentIndexChanged(int)), this, SLOT(shiftColor_2(int)));
    connect(Text_one, SIGNAL(selectionChanged()),this, SLOT(SetText_one()));
    connect(Text_one, SIGNAL(selectionChanged()),this, SLOT(SetText_two()));
    connect(start, SIGNAL(pressed()), this, SLOT(Click_start()));
    connect(restart, SIGNAL(pressed()), this, SLOT(Click_reset()));
    connect(table, SIGNAL(clicked(QModelIndex)),this, SLOT(Click_board(QModelIndex)));
    connect(board,SIGNAL(finishGame(int,int)),this,SLOT(Finish(int,int)));
}

void
MainWindow::config() {
    round = new Round(2);
    widget = new QWidget();
    table = new QTableView();
    Name_one = new QLabel("Gracz 1:");
    Name_two = new QLabel("Gracz 2:");
    Text_one = new QTextEdit();
    Text_two = new QTextEdit();
    Color_one = new QLabel("Kolor garcza 1:");
    Color_two = new QLabel("Kolor gracza 2:");
    start = new QPushButton("Start");
    restart = new QPushButton("Restart");
    box = new QGroupBox();
    layout = new QGridLayout();
    layoutBox = new QGridLayout();
    Color_item_one = new QPushButton(" ");
    Color_item_two = new QPushButton(" ");
    spa_1 = new QSpacerItem(0,30);
    spa_2 = new QSpacerItem(0,60);
    spa_3 = new QSpacerItem(0,30);
    spa_4 = new QSpacerItem(0,400);
    model = new QStringListModel();
    listmodel = new QStringList();
    board = new Board();

    setLayout();

    combo_1 =0;
    combo_2 =0;

    setWindowTitle(tr("Kółko i krzyżyk"));
    setFixedSize(800,300);
}
void
MainWindow::setLayout() {
    Name_one->setEnabled(true);
    Text_one->setMaximumWidth(300);
    Text_one->setMaximumHeight(25);
    Text_two->setMaximumWidth(300);
    Text_two->setMaximumHeight(25);

    ConfigComboBox();

    layoutBox->addWidget(Name_one,0,0);
    layoutBox->addWidget(Text_one,0,1);
    layoutBox->addItem(spa_1,1,0);
    layoutBox->addWidget(Color_one,2,0);
    layoutBox->addWidget(combo_one,2,1);
    layoutBox->addWidget(Color_item_one,2,2);
    layoutBox->addItem(spa_2,3,0);
    layoutBox->addWidget(Name_two,4,0);
    layoutBox->addWidget(Text_two,4,1);
    layoutBox->addItem(spa_3,5,0);
    layoutBox->addWidget(Color_two,6,0);
    layoutBox->addWidget(combo_two,6,1);
    layoutBox->addWidget(Color_item_two,6,2);
    layoutBox->addItem(spa_4,7,0);
    layoutBox->addWidget(start,8,1);
    layoutBox->addWidget(restart,8,2);

    box->setLayout(layoutBox);

    ConfigBoard();

    Color_item_one->setStyleSheet("* { background-color: Black }");
    Color_item_one->setEnabled(false);
    Color_item_two->setStyleSheet("* { background-color: Black }");
    Color_item_two->setEnabled(false);

    table->setEnabled(false);

    layout->addWidget(table,0,0);
    layout->addWidget(box,0,1);

    widget->setLayout(layout);

    setCentralWidget(widget);
}
void
MainWindow::ConfigBoard() {
    int row = 0;
    int column = 0;

    Table_view = new QStandardItemModel(table);
    table->setModel(Table_view);
    Table_view->setColumnCount(3);
    baze = new QStandardItem[9];

    for (int i=0; i<9; i++) {
        QModelIndex index;
        index.sibling(row,column);

        model->index(row,column,index);

        baze[i].setText(board->tostring(i));
        baze[i].setFont(QFont( "Times",10,QFont::Bold));

        Table_view->setItem(row,column++,&baze[i]);
        if (column>=3) {
            column = 0;
            row++;
        }

        Listindex.push_back(index);
    }

    table->setEditTriggers(QAbstractItemView::NoEditTriggers);
}

void
MainWindow::ConfigComboBox() {

    combo_one = new QComboBox(this);
    combo_two = new QComboBox(this);

    QStringList list;

    list <<"Black"<<"Red"<<"Green"<<"Blue"<<"Grey"<<"Yellow";

    combo_one->setModel(new QStringListModel(list));
    combo_two->setModel(new QStringListModel(list));
}
MainWindow::~MainWindow()
{
    delete Name_one;
    delete Name_two;
    delete Text_one;
    delete Text_two;
    delete box;
    delete layout;
    delete layoutBox;
    delete Color_one;
    delete Color_two;
    delete start;
    delete restart;
    delete table;
    delete combo_one;
    delete combo_two;
    delete Color_item_one;
    delete Color_item_two;
    delete spa_1;
    delete spa_2;
    delete spa_3;
    delete spa_4;
    delete round;
    delete widget;
    delete model;
    delete listmodel;
    delete board;
    delete ui;
    delete[] baze;
}
void
MainWindow::shiftColor(int type, int value) {
    QString data;
    switch (value) {
    case Black:
        data = "* { background-color: Black }";
        break;
    case Red:
        data = "* { background-color: Red }";
        break;
    case Green:
        data = "* { background-color: Green }";
        break;
    case Blue:
        data = "* { background-color: Blue }";
        break;
    case Grey:
        data = "* { background-color: Grey }";
        break;
    case Yellow:
        data = "* { background-color: Yellow }";
        break;
    default:
        return;
    }
    switch(type){
    case 0:
        Color_item_one->setStyleSheet(data);
        color_user_1 = value;
        break;
    case 1:
        Color_item_two->setStyleSheet(data);
        color_user_2 = value;
        break;
    default:
        break;
    }
}
void
MainWindow::setText(int type) {
    switch(type) {
    case 0:
        qDebug() <<Text_one->toPlainText();
        break;
    case 1:
        qDebug() <<Text_two->toPlainText();
        break;
    }
}
void
MainWindow::ClickButton(int value) {
    switch(value){
    case 0:
        if(Text_one->toPlainText()!="" && Text_two->toPlainText()!="") {
            table->setEnabled(true);
            restart->setEnabled(true);
            Text_one->setEnabled(false);
            Text_two->setEnabled(false);
            combo_one->setEnabled(false);
            combo_two->setEnabled(false);
            start->setEnabled(false);
        }
        break;
    case 1:
        board->clear();
        for(int i=0; i<9; i++) {
            baze[i].setText(board->tostring(i));
            baze[i].setFont(QFont("Times",10,QFont::Bold));

        }
        break;
    }
}
void
MainWindow::Click_board(QModelIndex index){
    int id = index.row()*3+index.column();
    qDebug() <<"klikniecie na plansze! "<<id;
    if(board->isEmpty(id)) {
        round->next();
        if(round->getOpponent()==1) {
            board->setValueTuple(id,Tuple::Value::wheel);
            qDebug() <<id<<"\t\t"<<board->tostring(id);
            baze[id].setForeground(QBrush(setColor(color_user_1)));
        } else {
            board->setValueTuple(id,Tuple::Value::cross);
            qDebug() <<id<<"\t\t"<<board->tostring(id);
            baze[id].setForeground(QBrush(setColor(color_user_2)));
        }
    }
    board->findWinner();
    baze[id].setText(board->tostring(id));
}
void
MainWindow::Finish(int value, int win) {
    switch(win) {
    case 0:
        baze[0].setFont(QFont("Times",20,QFont::Bold));
        baze[1].setFont(QFont("Times",20,QFont::Bold));
        baze[2].setFont(QFont("Times",20,QFont::Bold));
        break;
    case 1:
        baze[3].setFont(QFont("Times",20,QFont::Bold));
        baze[4].setFont(QFont("Times",20,QFont::Bold));
        baze[5].setFont(QFont("Times",20,QFont::Bold));
        winner = board->getValueTuple(3);
        break;
    case 2:
        baze[6].setFont(QFont("Times",20,QFont::Bold));
        baze[7].setFont(QFont("Times",20,QFont::Bold));
        baze[8].setFont(QFont("Times",20,QFont::Bold));
        winner = board->getValueTuple(6);
        break;
    case 3:
        baze[0].setFont(QFont("Times",20,QFont::Bold));
        baze[3].setFont(QFont("Times",20,QFont::Bold));
        baze[6].setFont(QFont("Times",20,QFont::Bold));
        winner = board->getValueTuple(0);
        break;
    case 4:
        baze[1].setFont(QFont("Times",20,QFont::Bold));
        baze[4].setFont(QFont("Times",20,QFont::Bold));
        baze[7].setFont(QFont("Times",20,QFont::Bold));
        winner = board->getValueTuple(1);
        break;
    case 5:
        baze[2].setFont(QFont("Times",20,QFont::Bold));
        baze[5].setFont(QFont("Times",20,QFont::Bold));
        baze[8].setFont(QFont("Times",20,QFont::Bold));
        winner = board->getValueTuple(2);
        break;
    case 6:
        baze[0].setFont(QFont("Times",20,QFont::Bold));
        baze[4].setFont(QFont("Times",20,QFont::Bold));
        baze[8].setFont(QFont("Times",20,QFont::Bold));
        winner = board->getValueTuple(0);
        break;
    case 7:
        baze[2].setFont(QFont("Times",20,QFont::Bold));
        baze[4].setFont(QFont("Times",20,QFont::Bold));
        baze[6].setFont(QFont("Times",20,QFont::Bold));
        winner = board->getValueTuple(2);
        break;
    }
    QString data = getWinner(value);
    BOX.setText("Wygrał gracz " + data);
    BOX.setButtonText(0,"OK");
    BOX.showNormal();
}
QColor
MainWindow::setColor(int i) {
    QString data;
    switch (i) {
    case Black:
        data = "Black";
        break;
    case Red:
        data = "Red";
        break;
    case Green:
        data = "Green";
        break;
    case Blue:
        data = "Blue";
        break;
    case Grey:
        data = "Grey";
        break;
    case Yellow:
        data = "Yellow";
        break;
    default:
        return "";
    }
    return data;
}
QString
MainWindow::getWinner(int value) {
    switch(value) {
    case Tuple::Value::wheel_win:
        return Text_one->toPlainText();
    case Tuple::Value::cross_win:
        return Text_two->toPlainText();
    }
}
