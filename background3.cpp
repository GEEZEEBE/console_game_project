#include <ncurses.h>
#include <iostream>

using namespace std;
int main()
{
    WINDOW *win;
    initscr();
    start_color();
    init_pair(1, COLOR_WHITE, COLOR_BLACK);
    refresh();
    win = newwin(LINES, COLS, 0, 0);
    
    WINDOW *win1;
    win1 = newwin(LINES, COLS -100, 0, 50);
    
     // LINES: 0,0  기준으로 고정되어 세로길이
     // COLS : 0,0 을 기준으로 고정되어 가로길이                          
    
    WINDOW *win2;
    win2 = newwin(LINES -45, COLS -80, 10, 40);


    wbkgd(win, COLOR_PAIR(1));
    wattron(win, COLOR_PAIR(1));
    
    mvwprintw(win, 10, 10, "Goddamn ~ C++ 1");
    mvwprintw(win, 20, 10, "Goddamn ~ C++ 2");
    mvwprintw(win, 30, 10, "Goddamn ~ C++ 3");

    wborder(win, '*','*','*','*','*','*','*','*');
    wrefresh(win);
    
    wborder(win1, '*','*','*','*','*','*','*','*');
    wrefresh(win1);

    wborder(win2, '#','#','#','#','#','#','#','#');
    wrefresh(win2);
    // #define hline
    // int hline('(LINES -30)', chtype (ch = '-'));
    // int vline(COLES -20, n = 30);
    
    // int mvwvline ((WINDOW *win), int y , int x , chtype ch , int n );
    // ch 는 선을 그리기 위해서 사용할 문자이며, n 은 몇개의 선문자를 사용할것인지 즉, 선의 길이를 얼마만큼 할것인지를 결정하기 위해서 사용

    
    getch();
    delwin(win);
    delwin(win1);
    delwin(win2);
    endwin();
}
