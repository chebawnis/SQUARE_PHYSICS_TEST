#include "../include/square_physics.h"

void    draw_triangle(float p1[2], float p2[2], float p3[2])
{
    glBegin(GL_TRIANGLES);
    glVertex2f(p1[0], p1[1]);
    glVertex2f(p2[0], p2[1]);
    glVertex2f(p3[0], p3[1]);
    glEnd();
}

void    draw_rectangle(float p1[2], float p2[2])
{
    float p3[2] = {p2[0], p1[1]};
    float p4[2] = {p1[0], p2[1]};

    glColor3f(1.0f, 0.0f, 0.0f);
    draw_triangle(p1, p3, p2);
    glColor3f(1.0f, 0.0f, 0.0f);
    draw_triangle(p1, p4, p2);
}

void    draw_square(t_square c)
{
    float p1[2] = {c.middle[0] - c.size, c.middle[1] - c.size};
    float p2[2] = {c.middle[0] + c.size, c.middle[1] + c.size};
    draw_rectangle(p1, p2);
}