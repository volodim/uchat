EXEC     = uchat
SRCS     = main.c gui.c irc.c util.c
CFLAGS   = -Wall -Werror -g -I/usr/include -I/usr/pkg/include
include  Makefile.rules

OBJS     = $(SRCS:%.c=%.o)

all: $(EXEC)

$(EXEC): $(OBJS)
	$(CC) $(OBJS) -o $(EXEC) $(LDFLAGS)
clean:
	$(LD) *.o $(EXEC)
