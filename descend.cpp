#include "typeshoot.h"
#include <iostream>
#include <string>
#include <curses.h>
#include <unistd.h>

#define descending_word "string"
#define eraser "      " // need length  // (cur_y, cur_x + length/2)
#define makeup "------"

using namespace std;

struct Descending_Item
{
    string value;
    int x_location;
    int y_location;
};

int collision_check(int y, int x)
{
    int campare_ch;
    campare_ch = mvinch(y, x);
    return !((campare_ch == '-'));
}

void draw_deadline(int deadline)
{
    for (int j = 0; j < COLS - 1; ++j)
    {
        mvaddch(deadline, j + 1, '=');
    }
}

void descend(int y, int x)
{
    for (int i = 0; i < LINES - 1; ++i)
    {
        mvaddstr(++y, x, descending_word);
        mvaddstr(y - 1, x, eraser);
        sleep(1);
        refresh();
    }
}

int main()
{
    WINDOW *w;
    w = initscr();
    box(w, 0, 0);
    int x = 1, y = 0, max_x = COLS - 1, max_y = LINES - 1, deadline = LINES - 5;
    draw_deadline(deadline);

    descend(y, x);
    getch();
    endwin();
    return 0;
}