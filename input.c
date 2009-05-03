/*
 * input.c
 *
 * Copyright (C) volodim - 2009
 * <benjamin.burget@gmail.com>
 *
 */

#include "global.h"

const char struct socket_commands[] = {
  { "/join",    input_join },
  { "/nick",    input_setnick },
  { "/quit",    input_quit },
  { "/help",    input_help }
};


void
input_help(char *arg) {

}

void
input_setnick(char *arg) {

}

void
input_join(char *arg) {

}

void
input_quit(char *arg) {
}
