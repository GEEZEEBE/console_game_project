#include "typeshoot.h"

#define BULLET '^'
#define E_TRACE ' '
#define DELAY 200

using namespace std;

void shoot(int y, int x) {
    int target, ch;
    timeout(DELAY);
    target = LINES;
    while (--target != y) {
        mvaddch(target, x, BULLET);
    }
    ch = getch();
    target = LINES;
    while (--target != y) {
        mvaddch(target, x, E_TRACE);
    }
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
    curs_set(0);
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