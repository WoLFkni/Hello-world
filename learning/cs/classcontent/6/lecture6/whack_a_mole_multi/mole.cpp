#include "mole.h"

int getScore(const Mole *m)
{
    if (m->big)
        return 300;
    else
        return 100;
}
