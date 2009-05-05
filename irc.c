/*
 * irc.c
 *
 * Copyright (C) volodim - 2009
 * <benjamin.burget@gmail.com>
 * Copyright (C) xorg62 - 2009
 * <xorg62@gmail.com>
 *
 */

#include "global.h"

void
init_connection(void)
{
     struct hostent *server;
     struct sockaddr_in addr;

     server = gethostbyname(IRC_SERV);

     if(server->h_addrtype != AF_INET)
     {
          fprintf(stderr, "Fatal: Sorry but we dont support this server (Probably IPV6 IP)\n");
          return;
     }

     addr.sin_family = AF_INET;
     addr.sin_port = htons(IRC_PORT);
     memcpy(&addr.sin_addr.s_addr, server->h_addr_list[0], server->h_length);

     if((Socket = socket(AF_INET, SOCK_STREAM, 0)) < 0)
     {
          fprintf(stderr, "Fatal: Unable to create the socket\n");
          return;
     }

     if(connect(Socket, (struct sockaddr*) &addr, sizeof(addr)) != 0)
     {
          fprintf(stderr,"Fatal: Unable to connect socket\n");
          return;
     }

     /* Send nick/name to the serv */
     send_msg(Socket, "NICK "IRC_NICK" :\r\n");
     send_msg(Socket, "USER %s %s %s :%s\r\n", IRC_NAME, IRC_NAME, IRC_SERV, IRC_NICK);

     /* Join IRC_CHAN */
     send_msg(Socket, "JOIN "IRC_CHAN" :\r\n");

     return;
}
