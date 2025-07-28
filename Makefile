.PHONY: clear 
CC = gcc

FLAGS = -Wall -Wextra -lm -ggdb

POSIX_FLAGS = -L ./raylib/linux/ -lraylib

SRCDIR = src
OBJDIR = build/posix

SRC = $(wildcard $(SRCDIR)/*.c)

OBJ = $(patsubst $(SRCDIR)/%.c, $(OBJDIR)/%.o, $(SRC))

sloptile: $(OBJ)
	$(CC) $^ $(FLAGS) $(POSIX_FLAGS) -o sloptile


$(OBJDIR)/%.o: $(SRCDIR)/%.c
	@mkdir -p $(OBJDIR)
	$(CC) $(FLAGS) $(POSIX_FLAGS) -c $< -o $@

clear: 
	@rm -f $(OBJDIR)/*.o sloptile
