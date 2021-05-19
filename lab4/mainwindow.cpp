#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent),
                                          ui_(new Ui::MainWindow)
{
    connect(elevator_.getCabin()->getDoors(), SIGNAL(newInfo(QString)), this, SLOT(setInfo(QString)));
    connect(elevator_.getCabin(), SIGNAL(newInfo(QString)), this, SLOT(setInfo(QString)));
    connect(elevator_.getController(), SIGNAL(newInfo(QString)), this, SLOT(setInfo(QString)));

    ui_->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui_;
}

void MainWindow::setInfo(QString info)
{
    ui_->textBrowser->append(info);
}

void MainWindow::on_button_floor_1_clicked()
{
    setInfo("Лифт вызвали с этажа №1");
    elevator_.Click(1);
}

void MainWindow::on_button_floor_2_clicked()
{
    setInfo("Лифт вызвали с этажа №2");
    elevator_.Click(2);
}

void MainWindow::on_button_floor_3_clicked()
{
    setInfo("Лифт вызвали с этажа №3");
    elevator_.Click(3);
}

void MainWindow::on_button_floor_4_clicked()
{
    setInfo("Лифт вызвали с этажа №4");
    elevator_.Click(4);
}

void MainWindow::on_button_floor_5_clicked()
{
    setInfo("Лифт вызвали с этажа №5");
    elevator_.Click(5);
}

void MainWindow::on_button_floor_6_clicked()
{
    setInfo("Лифт вызвали с этажа №6");
    elevator_.Click(6);
}

void MainWindow::on_button_floor_7_clicked()
{
    setInfo("Лифт вызвали с этажа №7");
    elevator_.Click(7);
}

void MainWindow::on_button_floor_8_clicked()
{
    setInfo("Лифт вызвали с этажа №8");
    elevator_.Click(8);
}

void MainWindow::on_button_floor_9_clicked()
{
    setInfo("Лифт вызвали с этажа №9");
    elevator_.Click(9);
}

void MainWindow::on_button_floor_10_clicked()
{
    setInfo("Лифт вызвали с этажа №10");
    elevator_.Click(10);
}
