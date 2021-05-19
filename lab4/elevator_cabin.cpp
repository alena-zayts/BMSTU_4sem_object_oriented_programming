#include "elevator_cabin.h"

ElevatorCabin::ElevatorCabin(QObject *parent) : QObject(parent),
                                                cur_floor_(START_FLOOR),
                                                target_(START_STATE),
                                                new_target_(false),
                                                cur_state_(СStop),
                                                cur_direction_(Stay)
{
    QObject::connect(this, SIGNAL(CabinCalled()), &doors_, SLOT(Closing()));
    QObject::connect(this, SIGNAL(CabinStopped(int)), &doors_, SLOT(Opening()));
    QObject::connect(&doors_, SIGNAL(ClosedDoors()), this, SLOT(CabinMove()));

    QObject::connect(this, SIGNAL(CabinReachedTarget(int)), this, SLOT(CabinStop()));

    traversing_floor_timer_.setSingleShot(true);
    QObject::connect(&traversing_floor_timer_, SIGNAL(timeout()), this, SLOT(CabinMove()));
}

void ElevatorCabin::CabinMove()
{
    if (new_target_)
    {
        if (cur_state_ == СWait)
        {
            cur_state_ = СMove;

            if (cur_floor_ == target_)
            {
                emit CabinReachedTarget(cur_floor_);
            }
            else
            {
                traversing_floor_timer_.start(FLOOR_TRAVERSING_TIME);
            }
        }
        else if (cur_state_ == СMove)
        {
            cur_floor_ += cur_direction_;

            if (cur_floor_ == target_)
            {
                emit CabinReachedTarget(cur_floor_);
            }
            else
            {
                emit CabinTraversingFloor(cur_floor_);
                traversing_floor_timer_.start(FLOOR_TRAVERSING_TIME);
            }
        }
    }
}

void ElevatorCabin::CabinStop()
{
    if (cur_state_ == СMove)
    {
        cur_state_ = СStop;
        info = QStringLiteral("Лифт остановился на этаже №%1").arg(cur_floor_);
        emit newInfo(info);
        emit CabinStopped(cur_floor_);
    }
}

void ElevatorCabin::CabinCall(int floor)
{
    if (cur_state_ == СStop)
    {
        new_target_ = true;
        cur_state_ = СWait;
        target_ = floor;

        if (target_ > cur_floor_)
        {
            cur_direction_ = Up;
        }
        else if (target_ < cur_floor_)
        {
            cur_direction_ = Down;
        }
        else
        {
            cur_direction_ = Stay;
        }

        emit CabinCalled();
    }
}

ElevatorDoors *ElevatorCabin::getDoors()
{
    return &doors_;
}
