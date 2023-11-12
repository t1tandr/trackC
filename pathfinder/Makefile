NAME = pathfinder
CC = clang
CFLAGS = -std=c11 -Wall -Wextra -Werror -Wpedantic

SRCDIR = src
INCDIR = inc
OBJDIR = obj

LMXDIR = libmx
LMXA := $(LMXDIR)/libmx.a
LMXI := $(LMXDIR)/inc

SRC = $(wildcard $(SRCDIR)/*.c)
OBJ = $(patsubst $(SRCDIR)/%.c, $(OBJDIR)/%.o, $(SRC))
INCS = $(wildcard $(INCDIR)/*.h)

all: install

install: $(LMXA) $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -L$(LMXDIR) -lmx -o $@

$(OBJDIR)/%.o: $(SRCDIR)/%.c $(INCS)
	@mkdir -p $(OBJDIR)
	$(CC) $(CFLAGS) -c $< -o $@ -I$(INCDIR) -I$(LMXI)

$(LMXA):
	@make -C $(LMXDIR)

clean:
	@make -C $(LMXDIR) $@
	@rm -rf $(OBJDIR)

uninstall: clean
	@make -C $(LMXDIR) $@
	@rm -f $(NAME)

reinstall: uninstall install

.PHONY: all install clean uninstall reinstall
