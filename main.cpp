#include "typeshoot.hpp"
#include "non_blocking_typing.hpp"
#include <stdlib.h>
#include <random>


int main(void) {

    initscr();
    cbreak();             // Immediate key input
    nonl();               // Get return key
    timeout(0);           // Non-blocking input
    keypad(stdscr, 1);    // Fix keypad
    noecho();             // No automatic printing
    curs_set(0);          // Hide real cursor
    intrflush(stdscr, 0); // Avoid potential graphical issues
    leaveok(stdscr, 1);   // Don't care where cursor is left

    struct input_line lnbuffer;
    make_buffer(&lnbuffer);

    codeline *c = NULL;
    codeline *stop_code[100];
    char **matrix = matrix_init();

    char ln[100];
    int len = 0, lines_read = 0;
    int stopcode_cnt = 0;

    while(1) {

        if (c == nullptr) {
            c = code_create();
            code_display(c);
        }
        else {
            descend(c);
            sleep_milli(100);
        }


        if (is_overline(c) && matrix_check(matrix, c)) {
            if (set_matrix(matrix, c) == -1) break;
            else {
                stopdescend(stop_code[stopcode_cnt], c);
                c = code_create();
            }
        }


        if (is_bottom(c)) {
            c->is_down = false;
            set_matrix(matrix, c);
            stopdescend(stop_code[stopcode_cnt], c);
            c = code_create();
        }

        len = get_line_non_blocking(&lnbuffer, ln, sizeof(ln));
        move(LINES-10, COLS/2);
        render_line(&lnbuffer);
        if(len > 0) {
            if(strcmp(ln, c->code.c_str()) == 0) {
                shoot(c->y, c->x+c->length/2);
                code_destroy(c, 0);
                destroy_buffer(&lnbuffer);
                c = code_create();
            }
            mvaddstr(2 + lines_read, 100, ln);
            lines_read ++;
        }

        stopcode_display(stop_code, stopcode_cnt);

    }

    gameover();
    delwin(stdscr);
    endwin();
    refresh();

    return 0;
}