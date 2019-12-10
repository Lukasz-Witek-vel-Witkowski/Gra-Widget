#include "mainwindow.h"
#include <QGridLayout>
#include <QListView>
#include <QGroupBox>
#include <QAbstractItemModel>
#include <QStringListModel>
#include <QApplication>
#include <QTableView>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    return a.exec();
}
