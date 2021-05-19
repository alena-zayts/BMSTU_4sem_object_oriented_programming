#include "elevator_doors.h"

ElevatorDoors::ElevatorDoors(QObject *parent) : QObject(parent),
                                                cur_state_(DClosed)
{
    doors_open_timer_.setSingleShot(true);
    QObject::connect(&doors_open_timer_, SIGNAL(timeout()), this, SLOT(Open()));

    doors_close_timer_.setSingleShot(true);
    QObject::connect(&doors_close_timer_, SIGNAL(timeout()), this, SLOT(Close()));

    doors_wait_timer_.setInterval(ELEVATOR_WAITING_TIME);
    doors_wait_timer_.setSingleShot(true);
    QObject::connect(this, SIGNAL(OpenedDoors()), &doors_wait_timer_, SLOT(start()));
    QObject::connect(&doors_wait_timer_, SIGNAL(timeout()), this, SLOT(Closing()));
}

void ElevatorDoors::Opening()
{
    if (cur_state_ == DClosed)
    {
        cur_state_ = DOpening;
        info = "Двери открываются";
        emit newInfo(info);
        doors_open_timer_.start(DOORS_OPENING_TIME);
    }
}

void ElevatorDoors::Closing()
{
    if (cur_state_ == DOpened)
    {
        cur_state_ = DClosing;
        info = "Двери закрываются";
        emit newInfo(info);
        doors_close_timer_.start(DOORS_CLOSING_TIME);
    }
    else if (cur_state_ == DClosed)
    {
        emit ClosedDoors();
    }
}

void ElevatorDoors::Open()
{
    if (cur_state_ == DOpening)
    {
        cur_state_ = DOpened;
        info = "Двери открыты. Время на вход и выход пассажиров";
        emit newInfo(info);
        emit OpenedDoors();
    }
}

void ElevatorDoors::Close()
{
    if (cur_state_ == DClosing)
    {
        cur_state_ = DClosed;
        info = "Двери закрыты";
        emit newInfo(info);
        emit ClosedDoors();
    }
}
