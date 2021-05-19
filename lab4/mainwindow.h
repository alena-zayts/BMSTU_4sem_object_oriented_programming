#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

#include "elevator.h"

namespace Ui
{
    class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void setInfo(QString info);
    void on_button_floor_1_clicked();
    void on_button_floor_2_clicked();
    void on_button_floor_3_clicked();
    void on_button_floor_4_clicked();
    void on_button_floor_5_clicked();
    void on_button_floor_6_clicked();
    void on_button_floor_7_clicked();
    void on_button_floor_8_clicked();
    void on_button_floor_9_clicked();
    void on_button_floor_10_clicked();

private:
    Ui::MainWindow *ui_;
    Elevator elevator_;
};

#endif
