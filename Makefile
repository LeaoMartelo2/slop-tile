.PHONY: clear 
CC = g++


DISABLED_WARNINGS = -Wno-missing-field-initializers

FLAGS = -Wall -Wextra -lm -ggdb $(DISABLED_WARNINGS)

POSIX_FLAGS = -L ./raylib/linux/ -lraylib

SRCDIR = src
OBJDIR = build/posix

SRC = $(wildcard $(SRCDIR)/*.cpp)

OBJ = $(patsubst $(SRCDIR)/%.cpp, $(OBJDIR)/%.o, $(SRC))

sloptile: $(OBJ)
	$(CC) $^ $(FLAGS) $(POSIX_FLAGS) -o sloptile


$(OBJDIR)/%.o: $(SRCDIR)/%.cpp
	@mkdir -p $(OBJDIR)
	$(CC) $(FLAGS) $(POSIX_FLAGS) -c $< -o $@

clear: 
	@rm -f $(OBJDIR)/*.o sloptile
