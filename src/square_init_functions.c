#include "../include/square_physics.h"

void    square_init(t_square *c, int mid_x, int mid_y, int rayon, float x_speed, float y_speed)
{
    c->middle[0] = mid_x;
    c->middle[1] = mid_y;
    c->size = rayon;

    c->x_v = x_speed;
    c->y_v = y_speed;
}

t_square *init_square_struct(void)
{
    t_square *c = malloc(sizeof(t_square));
    if (!c)
        return NULL;

    static int seeded = 0;
    if (!seeded)
    {
        srand(time(NULL));
        seeded = 1;
    }

    int rayon = 25;
    int mid_x = rayon + rand() % (WINDOW_X_SIZE - 2 * rayon);
    int mid_y = rayon + rand() % (WINDOW_Y_SIZE - 2 * rayon);

    int x_v = (rand() % 21) - 10;
    int y_v = (rand() % 21) - 10;
    if (x_v == 0) x_v = 1;
    if (y_v == 0) y_v = 1;

    printf("MID_X = %d\n", mid_x);
    printf("MID_Y = %d\n", mid_y);
    printf("X_V = %d\n", x_v);
    printf("Y_V = %d\n", y_v);

    square_init(c, mid_x, mid_y, rayon, x_v, y_v);
    return c;
}



