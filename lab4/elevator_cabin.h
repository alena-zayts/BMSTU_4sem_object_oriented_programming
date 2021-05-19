#ifndef ELEVATOR_CABIN_H
#define ELEVATOR_CABIN_H

#include <QObject>
#include "constants.h"
#include "elevator_doors.h"

class ElevatorCabin : public QObject
{
    Q_OBJECT
    enum CabinState { СMove, СWait, СStop};

public:
    explicit ElevatorCabin(QObject *parent = nullptr);
    ElevatorDoors* getDoors();

signals:
    void newInfo(QString);
    void CabinCalled();
    void CabinTraversingFloor(int floor);
    void CabinReachedTarget(int floor);
    void CabinStopped(int floor);

public slots:
    void CabinMove();
    void CabinStop();
    void CabinCall(int floor);

private:
    QString info;
    int cur_floor_;
    int target_;
    bool new_target_;
    CabinState cur_state_;
    Direction cur_direction_;
    ElevatorDoors doors_;
    QTimer traversing_floor_timer_;
};

#endif
