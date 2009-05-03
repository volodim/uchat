/*
 * main.c
 *
 * Copyright (C) volodim - 2009
 * <benjamin.burget@gmail.com>
 *
 */

#include "global.h"

void
usage(void) {
   fprintf(stderr, "uchat: must writting some help, heh :)\n");
   exit(1);
}

int
main(int argc, char *argv[]) {

     int n;
     char buffer[1024] = { 0 };

  /*   int ch;

   while ((ch = getopt(argc, argv, "c:n:")) != 1) {
      switch (ch) {
         case 'c':
               break;
	 case 'n':
               break;
         case '?':
               usage();
      }
   }*/

   running = 1;
   printf("uchat starting\n");

   init_screen();
   init_mainwin();
   init_connection();
   while(running)
   {
        memset(buffer, 0, 1024);

        if((n = recv(Socket, buffer, 1024, 0) > 0))
        {
             printw(buffer);

             refresh();
        }
   }


   close(Socket);
   endwin();

   return 0;
}
