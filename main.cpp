#include "typeshoot.hpp"
#include "non_blocking_typing.hpp"
#include <stdlib.h>
#include <random>
#include <iostream>
#include <fstream>

int main(int argc, char **argv) {
    int total = 0;
    string code_array[100];
    if (argc >= 2) {
        string line;
        ifstream file;
        file.open(argv[1]);
        if (file.is_open()) {
            while (!file.eof() || !total>100) {
                getline(file, line);
                if (line == "") continue;
                code_array[total] = line;
                total++;
            }
            file.close();
        }
        else {
            perror("can't open the file");
            exit(EXIT_FAILURE);
        }
    } else {
        perror("give me source code file.");
        exit(EXIT_FAILURE);
    }

    initscr();
    cbreak();             // Immediate key input
    nonl();               // Get return key
    timeout(0);           // Non-blocking input
    keypad(stdscr, 1);    // Fix keypad
    noecho();             // No automatic printing
    curs_set(0);          // Hide real cursor
    intrflush(stdscr, 0); // Avoid potential graphical issues
    leaveok(stdscr, 1);   // Don't care where cursor is left

    background();

    struct input_line lnbuffer;
    make_buffer(&lnbuffer);

    codeline *c = NULL;
    codeline *stop_code[100];
    char **matrix = matrix_init();

    char ln[100];
    int len = 0, lines_read = 0;
    int stopcode_cnt = 0;
    int score = 0;

    while(1) {

        if (c == nullptr) {
            c = code_create(code_array, total);
            code_display(c);
        }
        else {
            descend(c);
            sleep_milli(500);
            // sleep_milli(20);
        }


        if (is_overline(c) && matrix_check(matrix, c)) {
            if (set_matrix(matrix, c) == -1) break;
            else {
                stopdescend(stop_code[stopcode_cnt], c);
                c = code_create(code_array, total);
            }
        }


        if (is_bottom(c)) {
            c->is_down = false;
            set_matrix(matrix, c);
            stopdescend(stop_code[stopcode_cnt], c);
            c = code_create(code_array, total);
        }

        len = get_line_non_blocking(&lnbuffer, ln, sizeof(ln));
        move(7*LINES/8, COLS/4-5);
        render_line(&lnbuffer);
        if(len > 0) {
            if(strcmp(ln, c->code.c_str()) == 0) {
                shoot(c->y, c->x+c->length/2);
                scoreup(score);
                code_destroy(c, 0);
                destroy_buffer(&lnbuffer);
                c = code_create(code_array, total);
                stopcode_display(stop_code, stopcode_cnt);
            }
            // mvaddstr(2 + lines_read, COLS-17, ln);
            // lines_read ++;
        }

        stopcode_display(stop_code, stopcode_cnt);

    }

    gameover();
    getch();
    delwin(stdscr);
    endwin();
    refresh();

    return 0;
}