#include "typeshoot.hpp"
#include "non_blocking_typing.hpp"

/*
int main() {

    // CURSES initialization:
    // initscr();             // initialize curses
    // cbreak();              // pass key presses to program, but not signals
    // noecho();              // don't echo key presses to screen
    // keypad(stdscr, TRUE);  // allow arrow keys
    // nodelay(stdscr, TRUE);
    // timeout(0);            // no blocking on getch()
    // curs_set(0);           // set the cursor to invisible

    initscr();

    cbreak();             // Immediate key input
    nonl();               // Get return key
    timeout(0);           // Non-blocking input
    keypad(stdscr, 1);    // Fix keypad
    noecho();             // No automatic printing
    curs_set(0);          // Hide real cursor
    intrflush(stdscr, 0); // Avoid potential graphical issues
    leaveok(stdscr, 1);   // Don't care where cursor is left


    // start main

    struct input_line lnbuffer;
    make_buffer(&lnbuffer);


    // codeline *c;
    // c = code_create(1, 1);
    // descend(c);

    int lines_read = 0;
    while(1) {
        char ln[1024];
        int len = get_line_non_blocking(&lnbuffer, ln, sizeof(ln));
        if(len > 0) {
            if(strcmp(ln, "exit") == 0) {
                break;
            }
            mvaddstr(7 + lines_read, 5, ln);
            lines_read ++;
        }
        move(5, 5);
        render_line(&lnbuffer);

        // Show that we are active

        sleep(1);
        // end main
        clear();
        // (probably a good idea to sleep here)
    }

    destroy_buffer(&lnbuffer);
    delwin(stdscr);

    endwin();
    refresh();

    return 0;

}
*/

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

    codeline *c;
    c = code_create(1, 1);
    code_display(c);

    int lines_read = 0;
    while(1) {
        char ln[100];
        int len = get_line_non_blocking(&lnbuffer, ln, sizeof(ln));

        descend(c);

        if(len > 0) {
            if(strcmp(ln, "exit") == 0) {
                break;
            }
            mvaddstr(7 + lines_read, 5, ln);
            lines_read ++;
        }
        move(5, 5);
        render_line(&lnbuffer);

        // Show that we are active
        // mvaddch(2, 2, '0' + (rand() % 10));
        // (probably a good idea to sleep here)
    }

    destroy_buffer(&lnbuffer);
    delwin(stdscr);
    endwin();
    refresh();

    return 0;
}