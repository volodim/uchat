/*
 * util.c
 *
 * Copyright (C) xorg62 - 2009
 * <xorg62@gmail.com>
 *
 */

#include "global.h"

/* To send a message to the socket */
void
send_msg(int sock, char* format, ...)
{
     char buf[1024];
     va_list ap;

     if(!sock)
          return;

     va_start(ap, format);
     vsprintf(buf, format, ap);
     va_end(ap);

     send(sock, buf, strlen(buf), 0);

     return;
}

