EXEC     = uchat
SRCS     = main.c gui.c irc.c util.c input.c
CFLAGS   = -Wall -Werror -g -I/usr/include -I/usr/pkg/include
include  Makefile.rules

OBJS     = $(SRCS:%.c=%.o)

all: $(EXEC)

$(EXEC): $(OBJS)
	$(CC) $(OBJS) -o $(EXEC) $(LDFLAGS)
clean:
	$(RM) *.o $(EXEC)
clean-all: clean
	$(RM) Makefile.rules