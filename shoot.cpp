#include "typeshoot.hpp"

#define BULLET '^'
#define E_TRACE ' '
#define DELAY 200

using namespace std;

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

/*
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

    mvaddch(10, 10, '*');
    int ch;
    while ((ch = getch()) != 'q') {
        if (ch == 'a') {
            shoot(10, 10);
        }
    }

    // end main
    endwin();

    return 0;
}
*/