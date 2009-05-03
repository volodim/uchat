/*
 * global.h
 *
 * Copyright (C) volodim - 2009
 * <benjamin.burget@gmail.com>
 *
 */

#ifndef _GLOBAL_H
#define _GLOBAL_H

#include <stdlib.h>
#include <unistd.h>
#include <ncurses.h>
#include <string.h>
#include <regex.h>
#include <netdb.h>
#include <sys/utsname.h>
#include <sys/types.h>
#include <sys/select.h>
#include <sys/socket.h>
#include <netinet/in.h>

#define IRC_NICK  "uchat_test"
#define IRC_NAME  "Uchat test"
#define IRC_SERV  "irc.freenode.net"
#define IRC_CHAN  "#uchat"
#define IRC_PORT  6667

#define BUFMAX    4064
#define LEN(x)    (sizeof(x) / sizeof((x)[0]))

/*
 * Prototypes
 */

/* gui.c */
void init_screen(void);
void init_mainwin(void);

/* irc.c */
void init_connection(void);

/* util.c */
void send_msg(int sock, char* format, ...);

/* input.c */
void input_help(const char *arg);
void input_setnick(const char *arg);
void input_join(const char *arg);
void input_quit(const char *arg);

/*
 * Structs
 */
typedef struct
{
     char *cmd;
     void (*func)(const char *arg);
} InputStruct;

/*
 * Variables
 */
int Socket;
int running;
WINDOW *mainwin;

#endif /* GLOBAL_H */
