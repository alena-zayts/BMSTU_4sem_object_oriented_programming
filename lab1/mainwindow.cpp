#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    QGraphicsScene* scene = new QGraphicsScene(this);
    ui->graphicsView->setScene(scene);
    ui->graphicsView->setAlignment(Qt::AlignTop | Qt::AlignLeft);
    scene->setSceneRect(0, 0, SCENE_WIDTH, SCENE_HEIGHT);
}


MainWindow::~MainWindow(void)
{
    command_t command;
    command.com_number = COM_QUIT;
    command_run(command);

    delete ui;
}

int MainWindow::draw_actions(void)
{
    canvas_t canvas;
    canvas.scene = ui->graphicsView->scene();
    canvas.width = canvas.scene->width();
    canvas.height = canvas.scene->height();

    command_t command;
    command.com_number = COM_DRAW;
    command.canvas = canvas;

    int rc = command_run(command);

    return rc;
}

void MainWindow::on_download_button_clicked()
{
    const char *file_name = ui->en_file_name->toPlainText().toStdString().c_str();
    command_t command;

    command.com_number = COM_DOWNLOAD;
    command.file_name = file_name;

    int rc = command_run(command);
    if (rc != OK)
    {
        show_error(rc);
        return;
    }

    rc = draw_actions();
    printf("draw %d\n", rc);
    if (rc)
    {
        show_error(rc);
    }
}

void MainWindow::on_upload_button_clicked()
{
    const char *file_name = ui->en_file_name->toPlainText().toStdString().c_str();
    command_t command;

    command.com_number = COM_UPLOAD;
    command.file_name = file_name;

    int rc = command_run(command);
    if (rc != OK)
    {
        show_error(rc);
    }
}

void MainWindow::on_shift_button_clicked(void)
{
    shift_params_t shifts;
    shifts.dx = ui->en_dx->value();
    shifts.dy = ui->en_dy->value();
    shifts.dz = ui->en_dz->value();

    command_t command;
    command.com_number = COM_SHIFT;
    command.shift_params = shifts;

    int rc = command_run(command);
    if (rc != OK)
    {
        show_error(rc);
        return;
    }

    rc = draw_actions();
    if (rc != OK)
    {
        show_error(rc);
    }
}

void MainWindow::on_scale_button_clicked(void)
{
    scale_params_t coeffs;
    coeffs.kx = ui->en_kx->value();
    coeffs.ky = ui->en_ky->value();
    coeffs.kz = ui->en_kz->value();

    command_t command;
    command.com_number = COM_SCALE;
    command.scale_params = coeffs;

    int rc = command_run(command);
    if (rc != OK)
    {
        show_error(rc);
        return;
    }

    rc = draw_actions();
    if (rc != OK)
    {
        show_error(rc);
    }
}

void MainWindow::on_turn_button_clicked(void)
{
    turn_params_t angles;
    angles.teta_x = ui->en_tetax->value();
    angles.teta_y = ui->en_tetay->value();
    angles.teta_z = ui->en_tetaz->value();

    command_t command;
    command.com_number = COM_TURN;
    command.turn_params = angles;

    int rc = command_run(command);
    if (rc != OK)
    {
        show_error(rc);
        return;
    }

    rc = draw_actions();
    if (rc != OK)
    {
        show_error(rc);
    }
}
