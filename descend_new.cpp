#include "typeshoot.h"


void descend(codeline *c) {
    string eraser;

    for (int i = 0; i < c->code.length(); i++) {
        eraser += ' ';
    }

    for (int i = 0; i < LINES - 1; ++i)
    {
        mvaddstr(++c->y, c->x, c->code.c_str());
        mvaddstr(c->y - 1, c->x, eraser.c_str());
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
    sleep(5);
    c2 = code_create(0, 20);
    descend(c2);

    // end main
    endwin();

    return 0;

}