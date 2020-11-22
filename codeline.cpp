#include "typeshoot.hpp"
#include "non_blocking_typing.hpp"
#include <cstring>
#include <stdlib.h>
#include <random>

// #define _POSIX_C_SOURCE 199309L


string get_str(string *codes, int i) {
    return codes[i];
}


codeline *code_create(string *code_array, int total) {
    codeline *c = new codeline;
    c->code = get_str(code_array, rand_num(0, total));
    c->length = c->code.length();
    c->y = 1;
    c->x = rand_num((COLS-1)/6+2, 5*(COLS-1)/6-c->length);
    c->is_down = true;
    c->make_tracer();

    return c;
}


void code_display(codeline *c) {
    mvaddstr(1, c->x, c->code.c_str());
    refresh();
}

void code_destroy(codeline *c, int check) {
    if (check == 0) mvaddstr(c->y, c->x, c->e_tracer.c_str());

    free(c);
    refresh();
}


void sleep_milli(int milliseconds)
{
  struct timespec ts;
  ts.tv_sec = 0;
  ts.tv_nsec = milliseconds * 1000 * 1000;
  nanosleep(&ts, NULL);
}

int rand_num(int begin, int end) {
    random_device rd;
    mt19937_64 mersenne_twister_engine(rd());
    uniform_int_distribution<> dice(begin, end);

    return dice(mersenne_twister_engine);
}