/*
 * util.c
 *
 * Copyright (C) volodim - 2009
 * <benjamin.burget@gmail.com>
 * Copyright (C) xorg62 - 2009
 * <xorg62@gmail.com>
 *
 */

#include "global.h"

/* To send a message to the socket */
void
send_msg(int sock, char* format, ...)
{
     char buf[BUFSIZE];
     va_list ap;

     if(!sock)
          return;

     va_start(ap, format);
     vsprintf(buf, format, ap);
     va_end(ap);

     send(sock, buf, strlen(buf), 0);

     return;
}

void
update_date(void)
{
     tm = localtime(&lt);
     lt = time(NULL);

     strftime(global_date, sizeof(global_date), "%r", tm);

     return;
}

