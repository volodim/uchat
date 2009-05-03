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

/*
 * Prototypes
 */

/* gui.c */
int init_screen(void);

/* irc.c */
void init_connection(void);

/* util.c */
void send_msg(int sock, char* format, ...);


/*
 * Variables
 */
int Socket;

#endif /* GLOBAL_H */
