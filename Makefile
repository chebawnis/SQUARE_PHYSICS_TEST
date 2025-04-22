CC      = gcc
CFLAGS  = -Wall -Wextra -O2
LIBS    = -lglfw -lGL -ldl
SRC     = src/main.c \
          src/movements.c \
          src/draw_shapes_functions.c \
          src/square_init_functions.c \
          src/window_setup.c
OUT     = square_physics

all: $(OUT)

$(OUT): $(SRC)
	$(CC) $(CFLAGS) $(SRC) -o $(OUT) $(LIBS)

clean:
	rm -f $(OUT)

fclean: clean

re: fclean all

.PHONY: all clean fclean re
