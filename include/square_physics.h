#ifndef WINDOW_H
# define WINDOW_H

# include <GLFW/glfw3.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/time.h>
# include <unistd.h>
#include <time.h>

#define G 0.00000000006674
#define EARTH_MASS  5972000000000000000000000000
#define G_FORCE 10
#define WINDOW_X_SIZE 1000
#define WINDOW_Y_SIZE 750
#define ENERGY_LOSS 0.999
#define HEAVINESS 0.0001
#define SPEED_MULTIPLICATOR 1

typedef struct s_square
{
    float 			middle[2];
	int				size;
	float			mass;

	float			x_v;
	float			y_v;
} t_square;

// Fonctions linked lists
t_square			*init_square_struct(void);

// Fonctions de dessin
void    			draw_triangle(float p1[2], float p2[2], float p3[2]);
void    			draw_rectangle(float p1[2], float p2[2]);
void    			draw_square(t_square c);
void 				draw_unit(t_square *c, double delta_time);

// Fonctions de manipulation de carre
void    			square_init(t_square *c, int mid_x, int mid_y, int rayon, float x_speed, float y_speed);
void    			add_x_square(t_square *c, int v);
void    			add_y_square(t_square *c, int v);

// Fonctions GLFW
GLFWwindow* 		create_window(int width, int height, const char *title);
void        		setup_projection(int width, int height);
void        		window_init(void);

#endif