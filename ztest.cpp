#include "typeshoot.hpp"
#include "non_blocking_typing.hpp"
#include <cstring>

using namespace std;

struct array{
    int left_top_x;
    int left_top_y;
    int left_bot_x;
    int left_bot_y;
    int right_top_x;
    int right_top_y;
    int right_bot_x;
    int right_bot_y;

    int x = left_bot_y - left_top_y + 1;
    int y = right_bot_x - left_bot_x -1;
};

void get_stack_loc(array *stacked_space) {
    stacked_space->left_top_y = (LINES * 3) / 4;
    stacked_space->left_top_x = 0;
    stacked_space->left_bot_y = LINES -1;
    stacked_space->left_bot_x = 0;
    stacked_space->right_top_y = (LINES * 3) / 4;
    stacked_space->right_top_x = COLS / 4;
    stacked_space->right_bot_y = LINES -1;
    stacked_space->right_bot_x = COLS / 4;
}

void init_arr(array *stacked_space){
     int arr[stacked_space->y][stacked_space->x];
     for (int i = 0; i < stacked_space->y; ++i)
        for (int j = 0; j < stacked_space->x; ++j)
        {
            arr[i][j] = 0;
        }
}

/*
void descend(codeline *c, array *a)
{
    for (int i = 0; i < LINES - 1; ++i)
    {
        mvaddstr(++c->y, c->x, c->code);
        mvaddstr(c->y - 1, c->x, c->e_tracer);
        sleep(1);
        refresh();

        if(a[0][0]= a)
    }
}

int main()
{
    initscr();

    codeline *c1 = code_create(1,1);
    array *stacked_space;
    descend(c1, stacked_space);

    get_stack_loc(stacked_space);
    init_arr(stacked_space);

    getch();
    endwin();
    return 0;
}
*/