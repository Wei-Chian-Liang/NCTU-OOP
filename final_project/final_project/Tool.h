#include "player.h"

using namespace std;

#ifndef TOOL_H
#define TOOL_H

void Tool_IncreaseHp(Player A)
{
    A.HP += 30;
}
void Tool_IncreaseHit(Player A)
{
    A.weapon.hit += 5;
}
void Tool_Aim(Player A, Player B)
{
    if (A.weapon.picture[1].x >= 275 && A.weapon.picture[1].x <= 325 && A.weapon.picture[1].y >= 200 && A.weapon.picture[1].y <= 400) {}
    else {
        if (A.weapon.picture[1].x == B.x) {
            A.weapon.picture[1].y = B.y;
        }
        else if (A.weapon.picture[1].y == B.y) {
            A.weapon.picture[1].x = B.x;
        }
    }
}

#endif
