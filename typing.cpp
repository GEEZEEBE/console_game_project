#include <cstdlib>
#include <cstring>
#include <ncurses.h>
#include <iostream>

using namespace std;

/*
int main()
{
    // setting up string
    initscr();

    // setting up true Password
    string pass = "pass";

    // allocating space for input Password
    // char *input = (char *)malloc(100);
    char *input = new char[256];
    // printing
    // LINES means number of rows
    // COLS means number of columns
    mvprintw(LINES / 2, 10, "Enter Password ");
    attron(A_BOLD);
    echo();                               // suppress character echoing
    attroff(A_BOLD);

    wgetnstr(stdscr, input, 100); // used to get user input from specific window (here, stdscr)

    // clearing screen
    clear();
    refresh();

    // comparing Password
    if (strcmp(pass.c_str(), input) == 0)
    {
        // Password is correct
        attron(A_BOLD);
        mvprintw(LINES / 2, COLS / 2 - 6, "Welcome User");
        attroff(A_BOLD);
    }
    else
    {
        // Password is wrong
        attron(A_BLINK);
        mvprintw(LINES / 2, COLS / 2 - 9, "Unauthorized Access");
        attroff(A_BLINK);
    }

    // pausing window
    getch();
    // ending screen
    endwin();
}
*/