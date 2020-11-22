#include "typeshoot.hpp"
#include "non_blocking_typing.hpp"
#include <cstring>


void descend(codeline *c) {
    if (c->is_down) {
        mvaddstr(++c->y, c->x, c->code.c_str());
        mvaddstr(c->y - 1, c->x, c->e_tracer.c_str());
    }
    refresh();
}

void stopdescend(codeline *stop_code, codeline *c) {
    if (!c->is_down) {
        stop_code = copy_codeline(c);
        code_destroy(c, 1);
    }
}

codeline *copy_codeline(codeline *src) {
    codeline *target = new codeline;
    target->code = src->code;
    target->y = src->y;
    target->x = src->x;
    target->is_down = false;

    return target;
}

void stopcode_display(codeline **stop_code, int cnt) {
    for (int i=0; i<cnt; i++) {
        mvaddstr(stop_code[i]->y, stop_code[i]->x, stop_code[i]->code.c_str());
    }
    refresh();
}