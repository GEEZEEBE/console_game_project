#include "typeshoot.hpp"
#include "non_blocking_typing.hpp"
#include <cstring>


void descend(codeline *c) {
    // for (int i = 0; i < LINES - 3; ++i) {

        // if (is_correct(c, input)) {
        //     shoot(c->y, c->x+c->length/2);
        //     c->is_alive = false;
        // }

        // if (c->is_alive) {
            mvaddstr(++c->y, c->x, c->code.c_str());
            mvaddstr(c->y - 1, c->x, c->e_tracer.c_str());
        // } else {
        //     mvaddstr(c->y, c->x, c->e_tracer.c_str());
        //     code_destroy(c);
        //     return;
        // }
        sleep_milli(500);
        refresh();
    // }
}


