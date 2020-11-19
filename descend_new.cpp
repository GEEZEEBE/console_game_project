#include "typeshoot.h"
#include <cstring>

#define BULLET '^'
#define E_TRACE ' '
#define DELAY 200

bool is_correct(codeline *c, char *input) {
    bool flag = false;
    if (strcmp(c->code.c_str(), input) == 0) {
        flag = true;
    }
    return flag;
}


void typecode(char *input) {
    mvaddstr(2, 20, "TYPE CODE : ");
    echo();
    getnstr(input, 100);
    // getstr(input);
    // clear();
    // refresh();
}


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
    string eraser;
    char *input = new char[100];

    for (int i = 0; i < c->code.length(); i++) {
        eraser += ' ';
    }

    for (int i = 0; i < LINES - 3; ++i) {


        if (is_correct(c, input)) {
            shoot(c->y, c->x+c->length/2);
            c->is_alive = false;
        }

        if (c->is_alive) {
            mvaddstr(++c->y, c->x, c->code.c_str());
            mvaddstr(c->y - 1, c->x, eraser.c_str());
        } else {
            mvaddstr(c->y, c->x, eraser.c_str());
            code_destroy(c);
            delete [] input;
            return;
        }
        typecode(input);
        sleep(1);
        refresh();
    }
}

codeline *code_create(int y, int x) {
    codeline *c = new codeline;
    c->code = "I love you";
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
    nodelay(stdscr, TRUE);
    timeout(0);            // no blocking on getch()
    curs_set(0);           // set the cursor to invisible

    // start main

    codeline *c, *c2, *c3;
    c = code_create(1, 1);
    descend(c);
    c2 = code_create(1, 3);
    descend(c2);

    sleep(1);
    // end main
    clear();
    endwin();

    return 0;

}

// https://stackoverflow.com/questions/40319239/get-full-strings-from-getstr-in-ncurses-in-a-non-blocking-way