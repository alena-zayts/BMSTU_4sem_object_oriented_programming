#ifndef CONSTANTS_H
#define CONSTANTS_H

#include <QTextEdit>
#include <QTimer>

#define DOORS_OPENING_TIME 2000
#define DOORS_CLOSING_TIME 2000

#define FLOOR_TRAVERSING_TIME 1000
#define START_STATE -1
#define START_FLOOR 1

#define ELEVATOR_WAITING_TIME 2000
#define FLOORS_AMOUNT 10


enum Direction { Down = -1, Stay = 0, Up = 1};

#endif
