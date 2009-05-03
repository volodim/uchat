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
     char buffer[BUFMAX] = { 0 };
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

   init_connection();
   init_screen();

   while(running)
   {
        memset(buffer, 0, BUFMAX);

        if((n = recv(Socket, buffer, BUFMAX, 0) > 0))
        {
             wprintw(mainwin, buffer);
             wrefresh(mainwin);
	     wmove(inputwin, 0, 0);
	     wrefresh(inputwin);
	     wgetnstr(inputwin, buffer, BUFMAX);
	     input_manage(buffer);
        }
   }


   close(Socket);
   endwin();

   return 0;
}
