# Définitions des variables
CC      = gcc
CFLAGS  = -Wall -Wextra -O2
LIBS    = -lglfw -lGL -ldl
SRC     = src/main.c
OUT     = square_physics

# Cible par défaut
all: $(OUT)

# Règle de compilation
$(OUT): $(SRC)
	$(CC) $(CFLAGS) $(SRC) -o $(OUT) $(LIBS)

# Nettoyage des fichiers générés
clean:
	rm -f $(OUT)

.PHONY: all clean
