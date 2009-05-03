EXEC     = uchat
SRCS     = main.c gui.c irc.c util.c
CFLAGS   = -Wall -Werror -g -I/usr/include -I/usr/pkg/include

OS	 = `uname`

ifeq ($(OS), NetBSD)
	LDFLAGS  = -L/usr/include -L/usr/pkg/include -lcurses
else
	LDFLAGS  = -lncurses
endif

OBJS     = $(SRCS:%.c=%.o)

all: $(EXEC)

$(EXEC): $(OBJS)
	gcc $(OBJS) -o $(EXEC) $(LDFLAGS)
clean:
	rm *.o $(EXEC)
