.PHONY: clear 
CC = clang++

DISABLED_WARNINGS = -Wno-missing-field-initializers -Wno-format-overflow -Wno-unused-command-line-argument -Wno-missing-braces

FLAGS = -std=c++23 -Wall -Wextra $(DISABLED_WARNINGS) -pedantic -lm -ggdb

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
	@rm -f $(OBJDIR)/*.o $(WINOBJDIR)/*.o wireframe wireframe.exe
