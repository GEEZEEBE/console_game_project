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
    WINDOW *deadline = newwin(LINES / 40 * 1, COLS, LINES / 10 * 5, COLS / 4.2);
    WINDOW *typing = newwin(LINES / 10 * 2.2, COLS / 6*4, LINES / 10 * 9, COLS / 4.2);
    WINDOW *right_grid = newwin(LINES, COLS / 4, 0, 0);
    WINDOW *left_grid = newwin(LINES, COLS / 4, 0, COLS - (COLS / 4 * 1));
    
    mvprintw(COLS = 2, LINES = 2, "Middle Hello Ncurse!");

    draw_line(board);
    // move(35, 45);
    // attron(A_BOLD);
    // printw("%s", "===== A_BOLD attribute =====");
    // attroff(A_BOLD);
    // refresh();
    
    
    draw_line(deadline);
    draw_line(typing);
    draw_line(right_grid);
    draw_line(left_grid);
    

    wrefresh(board);
    wrefresh(deadline);
    wrefresh(typing);
    wrefresh(right_grid);
    wrefresh(left_grid);
    
    //#define mvaddch
    //mvaddch(LINES, COLS, board); 
    
    
    wgetch(board);
    endwin();
    return 0;
}