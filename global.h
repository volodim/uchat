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
#include <time.h>
#include <regex.h>
#include <netdb.h>
#include <sys/utsname.h>
#include <sys/types.h>
#include <sys/select.h>
#include <sys/socket.h>
#include <netinet/in.h>

#define IRC_NICK  "uchatTEST"
#define IRC_NAME  "pwetuchat."
#define IRC_SERV  "irc.freenode.net"
#define IRC_CHAN  "#uchat"
#define IRC_PORT  6667

#define BUFSIZE          4096
#define UCHAT_KEY_ENTER  10
#define LEN(x)           (sizeof(x) / sizeof((x)[0]))

/*
 * Structs
 */
typedef struct
{
     char *cmd;
     void (*func)(const char *arg);
} InputStruct;

typedef struct
{
     char buffer[BUFSIZE];
     int pos;
} InputBufStruct;

/*
 * Prototypes
 */

/* gui.c */
void init_gui(void);
void gui_update_statuswin(void);
void gui_get_input(InputBufStruct *ib);


/* irc.c */
void init_connection(void);

/* util.c */
void send_msg(int sock, char* format, ...);
void update_date(void);

/* input.c */
void input_help(const char *arg);
void input_setnick(const char *arg);
void input_join(const char *arg);
void input_quit(const char *arg);
void input_manage(const char *input);

/*
 * Variables
 */
int Socket;
int running;
struct tm *tm;
time_t lt;
char global_date[BUFSIZE];
WINDOW *mainwin;
WINDOW *inputwin;
WINDOW *statuswin;

#endif /* GLOBAL_H */
