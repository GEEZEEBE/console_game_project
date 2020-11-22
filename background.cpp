#include <ncurses.h>
#include <iostream>


void background() {

    for (int i=0; i<COLS; i++) {
        mvaddch(0, i, '-');
    }
    for (int i=0; i<COLS; i++) {
        mvaddch(LINES-1, i, '-');
    }
    for (int i=0; i<LINES; i++) {
        mvaddch(i, 0, '|');
    }
    for (int i=0; i<LINES; i++) {
        mvaddch(i, COLS-1, '|');
    }
    for (int i=0; i<LINES; i++) {
        mvaddch(i, COLS/6, '|');
    }
    for (int i=0; i<LINES; i++) {
        mvaddch(i, 5*COLS/6, '|');
    }

    attron(A_BLINK);
    mvaddstr(LINES/2-2, COLS/12-2, "dead");
    mvaddstr(LINES/2, COLS/12-2, "line");
    mvaddstr(LINES/2-2, 11*COLS/12-2, "dead");
    mvaddstr(LINES/2, 11*COLS/12-2, "line");
    attroff(A_BLINK);

    for (int i=0; i<COLS/6; i++) {
        mvaddch(LINES/2-1, i, '-');
    }
    for (int i=5*COLS/6; i<COLS-1; i++) {
        mvaddch(LINES/2-1, i, '-');
    }

    for (int i=COLS/6; i<5*COLS/6; i++) {
        mvaddch(3*LINES/4, i, '-');
    }

    mvaddch(0, 0, '+');
    mvaddch(LINES-1, 0, '+');
    mvaddch(0, COLS-1, '+');
    mvaddch(LINES-1, COLS-1, '+');

    mvaddch(0, COLS/6, '+');
    mvaddch(0, 5*COLS/6, '+');
    mvaddch(LINES-1, COLS/6, '+');
    mvaddch(LINES-1, 5*COLS/6, '+');

    mvaddch(LINES/2-1, 0, '+');
    mvaddch(LINES/2-1, COLS/6, '+');
    mvaddch(LINES/2-1, 5*COLS/6, '+');
    mvaddch(LINES/2-1, COLS-1, '+');

    mvaddch(3*LINES/4, COLS/6, '+');
    mvaddch(3*LINES/4, 5*COLS/6, '+');

    attron(A_STANDOUT);
    mvaddstr(LINES/12+3, COLS/12-5, "TYPING");
    mvaddstr(LINES/12+4, COLS/12-5, "SHOOTING");
    mvaddstr(LINES/12+5, COLS/12-5, "GAME");
    mvaddstr(LINES/12+6, COLS/12-5, "for");
    mvaddstr(LINES/12+7, COLS/12-5, "PROGRAMMERS");
    attroff(A_STANDOUT);

    attron(A_DIM);
    mvaddstr(9*LINES/12+2, COLS/12-6, "Little");
    mvaddstr(9*LINES/12+3, COLS/12-6, "by");
    mvaddstr(9*LINES/12+4, COLS/12-6, "Little");
    mvaddstr(9*LINES/12+5, COLS/12-6, "Team Project");
    mvaddstr(9*LINES/12+7, COLS/12-6, "RAPA");
    mvaddstr(9*LINES/12+8, COLS/12-6, "5G-DRONE");
    attroff(A_DIM);

    attron(A_BOLD);
    mvaddstr(LINES/6-1, 11*COLS/12-3, "SCORE");
    mvaddstr(LINES/6, 11*COLS/12-3, "0");
    attroff(A_BOLD);

    attron(A_DIM);
    mvaddstr(LINES-3, COLS-17, "ctrl+c for quit");
    attroff(A_DIM);

}
