#include <ncurses.h>
#include <iostream>

using namespace std;

void draw_line(WINDOW *w)
{
    box(w, 0, 0);
}

int main()
{
    initscr();
    
    WINDOW *board = newwin(LINES, COLS, 0, 0); 
    WINDOW *typing = newwin(LINES / 10 * 2, COLS / 2, LINES / 10 * 9, COLS / 4);
    WINDOW *right_grid = newwin(LINES, COLS / 4, 0, 0);
    WINDOW *left_grid = newwin(LINES, COLS / 4, 0, COLS - (COLS / 4 * 1));

    draw_line(board);
    draw_line(typing);
    draw_line(right_grid);
    draw_line(left_grid);

    wrefresh(board);
    wrefresh(typing);
    wrefresh(right_grid);
    wrefresh(left_grid);

    wgetch(board);
    endwin();
    return 0;
}