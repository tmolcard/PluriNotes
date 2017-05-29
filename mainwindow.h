#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "notewindow.h"

#include <QMainWindow>
#include <QPushButton>
#include <QWidget>



namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT


public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
};



#endif // MAINWINDOW_H
