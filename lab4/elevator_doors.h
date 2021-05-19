#ifndef ELEVATOR_DOORS_H
#define ELEVATOR_DOORS_H

#include <QObject>
#include "constants.h"

class ElevatorDoors : public QObject
{
    Q_OBJECT
    enum DoorsState{ DOpened, DClosed, DOpening, DClosing };

public:
    explicit ElevatorDoors(QObject *parent = nullptr);

signals:
    void newInfo(QString);
    void ClosedDoors();
    void OpenedDoors();

public slots:
    void Opening();
    void Closing();

private slots:
    void Open();
    void Close();

private:
    DoorsState cur_state_;
    QTimer doors_open_timer_;
    QTimer doors_close_timer_;
    QTimer doors_wait_timer_;

    QString info;
};

#endif
