/*
 * input.c
 *
 * Copyright (C) volodim - 2009
 * <benjamin.burget@gmail.com>
 *
 */

#include "global.h"

const InputStruct input_struct[] =
{
     { "join", input_join },
     { "nick", input_setnick },
     { "quit", input_quit },
     { "help", input_help }
};


void
input_help(const char *arg) {

}

void
input_setnick(const char *arg) {

}

void
input_join(const char *arg) {

}

void
input_quit(const char *arg) {
}
