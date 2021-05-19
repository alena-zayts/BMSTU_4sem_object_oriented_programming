#ifndef ELEVATOR_CONTROLLER_H
#define ELEVATOR_CONTROLLER_H

#include <QObject>
#include <QVector>

#include "constants.h"

class ElevatorController : public QObject
{
    Q_OBJECT
    enum ControllerState { ConFree, ConBusy };

public:
    explicit ElevatorController(QObject *parent = nullptr);
    void SetNewTarget(int floor);

signals:
    void newInfo(QString);
    void SetTarget(int floor);

public slots:
    void ReachedFloor(int floor);
    void TraversedFloor(int floor);

private:
    QString info;
    int cur_floor_;
    int cur_target_;
    QVector<bool> is_target_;
    ControllerState cur_state_;
    Direction cur_direction_;
    bool NextTarget(int &floor);
    void FindNewTarget();
};

#endif
