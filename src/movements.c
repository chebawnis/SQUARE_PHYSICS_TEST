#include "../include/square_physics.h"

void    add_x_square(t_square *c, int v)
{
    c->middle[0] += v;
}

void    add_y_square(t_square *c, int v)
{
    c->middle[1] += v;
}

