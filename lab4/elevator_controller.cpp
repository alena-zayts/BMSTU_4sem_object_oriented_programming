#include "elevator_controller.h"

ElevatorController::ElevatorController(QObject *parent) : QObject(parent),
                                                          cur_floor_(START_FLOOR),
                                                          cur_target_(START_STATE),
                                                          is_target_(FLOORS_AMOUNT, false),
                                                          cur_state_(ConFree),
                                                          cur_direction_(Stay) {}
void ElevatorController::FindNewTarget()
{
    bool state = false;

    if (cur_direction_ == Up)
    {
        for (int i = FLOORS_AMOUNT; i >= 1 && !state; i--)
        {
            if (is_target_[i - 1] == true)
            {
                state = true;
                cur_target_ = i;
            }
        }
    }
    else
    {
        for (int i = 1; i <= FLOORS_AMOUNT && !state; i++)
        {
            if (is_target_[i - 1])
            {
                state = true;
                cur_target_ = i;
            }
        }
    }
}

bool ElevatorController::NextTarget(int &floor)
{
    bool state = false;

    if (cur_target_ > cur_floor_)
    {
        for (int i = cur_floor_; i <= FLOORS_AMOUNT && !state; i++)
        {
            if (is_target_[i - 1])
            {
                floor = i;
                state = true;
            }
        }
    }
    else
    {
        for (int i = cur_floor_; i >= 1 && !state; i--)
        {
            if (is_target_[i - 1])
            {
                floor = i;
                state = true;
            }
        }
    }

    return state;
}

void ElevatorController::SetNewTarget(int floor)
{
    cur_state_ = ConBusy;
    is_target_[floor - 1] = true;

    if ((cur_target_ == START_STATE) ||
        (cur_direction_ == Up && floor > cur_target_) ||
        (cur_direction_ == Down && floor < cur_target_))
    {
        cur_target_ = floor;
    }


    if (cur_floor_ > cur_target_)
    {
        cur_direction_ = Down;
    }
    else
    {
        cur_direction_ = Up;
    }

    emit SetTarget(floor);
}

void ElevatorController::ReachedFloor(int floor)
{
    if (cur_state_ == ConBusy)
    {
        cur_floor_ = floor;
        is_target_[floor - 1] = false;

        if (cur_floor_ == cur_target_)
        {
//            info = QStringLiteral("Лифт прибыл на этаж №%1").arg(cur_floor_);
//            emit newInfo(info);
            cur_target_ = START_STATE;
            FindNewTarget();
        }

        if (NextTarget(floor))
        {
            if (cur_floor_ > cur_target_)
            {
                cur_direction_ = Down;
            }
            else
            {
                cur_direction_ = Up;
            }

            emit SetTarget(floor);
        }
        else
        {
            cur_state_ = ConFree;
        }
    }
}

void ElevatorController::TraversedFloor(int floor)
{
    cur_floor_ = floor;
    info = QStringLiteral("Лифт проехал этаж №%1").arg(cur_floor_);
    emit newInfo(info);
}

