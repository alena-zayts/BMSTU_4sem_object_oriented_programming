#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#define SCENE_WIDTH (2100 - 2)
#define SCENE_HEIGHT (1100 - 2)

#include <QMainWindow>
#include "commands.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
private slots:
    int draw_actions(void);

    void on_download_button_clicked();

    void on_upload_button_clicked();

    void on_shift_button_clicked();

    void on_scale_button_clicked();

    void on_turn_button_clicked();

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
