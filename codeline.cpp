#include "typeshoot.hpp"
#include "non_blocking_typing.hpp"
#include <cstring>


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

void code_display(codeline *c) {
    mvaddstr(1, c->x, c->code.c_str());
}

void code_destroy(codeline *c) {
  free(c);
}



