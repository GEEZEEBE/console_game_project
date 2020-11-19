#include "typeshoot.h"

#define BULLET '^'
#define E_TRACE ' '
#define DELAY 200

void shoot(int y, int x) {
    int to_target, ch;
    timeout(DELAY);
    to_target = LINES;
    while (--to_target != y) {
        mvaddch(to_target, x, BULLET);
    }
    ch = getch();
    to_target = LINES;
    while (--to_target != y) {
        mvaddch(to_target, x, E_TRACE);
    }
}

void descend(codeline *c) {
    int ch;
    string eraser;

    for (int i = 0; i < c->code.length(); i++) {
        eraser += ' ';
    }

    for (int i = 0; i < LINES - 1; ++i) {
        ch = getch();
        if (ch == 'a') {
            c->is_alive = false;
            shoot(c->y, c->x+c->length/2);
        }

        if (c->is_alive) {
            mvaddstr(++c->y, c->x, c->code.c_str());
            mvaddstr(c->y - 1, c->x, eraser.c_str());
        } else {
            mvaddstr(c->y, c->x, eraser.c_str());
            code_destroy(c);
            return;
        }
        sleep(1);
        refresh();
    }
}

codeline *code_create(int y, int x) {
    codeline *c = new codeline;
    c->code = "I love you!!";
    c->y = y;
    c->x = x;
    c->length = c->code.length();
    c->is_alive = true;

    return c;
}

void code_destroy(codeline *c) {
  free(c);
}

int main() {

    // CURSES initialization:
    initscr();             // initialize curses
    cbreak();              // pass key presses to program, but not signals
    noecho();              // don't echo key presses to screen
    keypad(stdscr, TRUE);  // allow arrow keys
    timeout(0);            // no blocking on getch()
    curs_set(0);           // set the cursor to invisible

    WINDOW *w;
    w = initscr();
    // start main

    codeline *c, *c2;
    c = code_create(0, 10);
    descend(c);
    // sleep(5);
    c2 = code_create(0, 30);
    descend(c2);

    // end main
    endwin();

    return 0;

}