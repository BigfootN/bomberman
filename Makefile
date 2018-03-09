CC = gcc
NAME = bomberman
SRCDIR1 = 01_main
SRCDIR2 = 02_noyeau
SRCDIR3 = 03_introduction
SRCDIR4 = 04_ipchoice
SRCDIR5 = 05_game
SRCDIR6 = 07_network
SRCDIR7 = 08_IA
SRCDIR8 = 09_pictures
SRCDIR9 = 10_lib
SRCDIR10 = 06_score
LIBDIR = tmp
HEADDIR = 00_headers
GLLIBS = -lSDL2 -lSDL2_image -lSDL2_ttf -pthread
CFLAGS =  -pg -I $(HEADDIR) -W -Wall -Wextra -Werror

SRC1 = $(wildcard $(SRCDIR1)/*.c)
SRC2 = $(wildcard $(SRCDIR2)/*.c)
SRC3 = $(wildcard $(SRCDIR3)/*.c)
SRC4 = $(wildcard $(SRCDIR4)/*.c)
SRC5 = $(wildcard $(SRCDIR5)/*.c)
SRC6 = $(wildcard $(SRCDIR6)/*.c)
SRC7 = $(wildcard $(SRCDIR7)/*.c)
SRC8 = $(wildcard $(SRCDIR8)/*.c)
SRC9 = $(wildcard $(SRCDIR9)/*.c)
SRC10 = $(wildcard $(SRCDIR10)/*.c)

OBJ1 = $(SRC1:$(SRCDIR1)/%.c=$(LIBDIR)/%.o)
OBJ2 = $(SRC2:$(SRCDIR2)/%.c=$(LIBDIR)/%.o)
OBJ3 = $(SRC3:$(SRCDIR3)/%.c=$(LIBDIR)/%.o)
OBJ4 = $(SRC4:$(SRCDIR4)/%.c=$(LIBDIR)/%.o)
OBJ5 = $(SRC5:$(SRCDIR5)/%.c=$(LIBDIR)/%.o)
OBJ6 = $(SRC6:$(SRCDIR6)/%.c=$(LIBDIR)/%.o)
OBJ7 = $(SRC7:$(SRCDIR7)/%.c=$(LIBDIR)/%.o)
OBJ8 = $(SRC8:$(SRCDIR8)/%.c=$(LIBDIR)/%.o)
OBJ9 = $(SRC9:$(SRCDIR9)/%.c=$(LIBDIR)/%.o)
OBJ10 = $(SRC10:$(SRCDIR10)/%.c=$(LIBDIR)/%.o)

all: $(NAME)
$(NAME): $(OBJ1) $(OBJ2) $(OBJ3) $(OBJ4) $(OBJ5) $(OBJ6) $(OBJ7) $(OBJ8) $(OBJ9) $(OBJ10)
	$(CC) -o $@ $^ $(CFLAGS) $(GLLIBS)
$(LIBDIR)/%.o: $(SRCDIR1)/%.c
	$(CC) -o $@ -c $< $(CFLAGS)
$(LIBDIR)/%.o: $(SRCDIR2)/%.c
	$(CC) -o $@ -c $< $(CFLAGS)
$(LIBDIR)/%.o: $(SRCDIR3)/%.c
	$(CC) -o $@ -c $< $(CFLAGS)
$(LIBDIR)/%.o: $(SRCDIR4)/%.c
	$(CC) -o $@ -c $< $(CFLAGS)
$(LIBDIR)/%.o: $(SRCDIR5)/%.c
	$(CC) -o $@ -c $< $(CFLAGS)
$(LIBDIR)/%.o: $(SRCDIR6)/%.c
	$(CC) -o $@ -c $< $(CFLAGS)
$(LIBDIR)/%.o: $(SRCDIR7)/%.c
	$(CC) -o $@ -c $< $(CFLAGS)
$(LIBDIR)/%.o: $(SRCDIR8)/%.c
	$(CC) -o $@ -c $< $(CFLAGS)
$(LIBDIR)/%.o: $(SRCDIR9)/%.c
	$(CC) -o $@ -c $< $(CFLAGS)
$(LIBDIR)/%.o: $(SRCDIR10)/%.c
	$(CC) -o $@ -c $< $(CFLAGS)

.PHONY: clean fclean

clean:
	rm $(LIBDIR)/*.o

fclean: clean
	rm $(BINDIR)/*
