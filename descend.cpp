#include "typeshoot.h"
#include <iostream>
#include <string>
#include <curses.h>
#include <unistd.h>
 

#define descending_word "string"
#define eraser "      " // need length
#define makeup "------"

using namespace std;

void descend()
{
    WINDOW *w;
    w = initscr();
    
    int x = 1, y = 0, max_x = COLS - 1, max_y = LINES - 1, deadline = LINES - 5;
    int cur_y, cur_x;
    getyx(stdscr, cur_y, cur_x);

    box(w,0,0);
    for(int j = 0; j < max_x - 1; ++j){
        mvaddch(deadline, j + 1, '-');
    }

    while(y != max_y - 1) {
        mvaddstr(++y, x, descending_word);
        mvaddstr(y - 1, x, eraser);

        sleep(1);
        refresh();
    }

    getch();
    endwin();
}

int main()
{
    descend();
    return 0;
}