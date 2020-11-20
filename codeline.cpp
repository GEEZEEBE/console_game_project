#include "typeshoot.hpp"
#include "non_blocking_typing.hpp"
#include <cstring>
#include <time.h>

#define _POSIX_C_SOURCE 199309L

codeline *code_create(int y, int x) {
    codeline *c = new codeline;
    c->code = "I love you";
    c->y = y;
    c->x = x;
    c->length = c->code.length();
    c->is_alive = true;
    c->make_tracer();

    return c;
}

void code_init(codeline *c) {
    c->code = "kkkkkkk";
    c->y = 1;
    c->x = 20;
    c->length = c->code.length();
    c->is_alive = true;
    c->make_tracer();

}

void code_display(codeline *c) {
    mvaddstr(1, c->x, c->code.c_str());
    refresh();
}

void code_destroy(codeline *c) {
    mvaddstr(c->y, c->x, c->e_tracer.c_str());
    refresh();
}



void sleep_milli(int milliseconds)
{
  struct timespec ts;
  ts.tv_sec = 0;
  ts.tv_nsec = milliseconds * 1000 * 1000;
  nanosleep(&ts, NULL);
}