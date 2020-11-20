#include "typeshoot.hpp"
#include "non_blocking_typing.hpp"

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
    char ln[100];
    int len = 0, lines_read = 0;
    while(1) {
        len = get_line_non_blocking(&lnbuffer, ln, sizeof(ln));

        if (c != nullptr) descend(c);
        else {
            c = code_create(1, 1);
            code_display(c);
        }

        if(len > 0) {
            if(strcmp(ln, c->code.c_str()) == 0) {
                shoot(c->y, c->x+c->length/2);
                c->is_alive = false;
                code_destroy(c);
                code_init(c);
                destroy_buffer(&lnbuffer);
            }
            mvaddstr(2 + lines_read, 100, ln);
            lines_read ++;
        }
        // move(50, 50);
        // render_line(&lnbuffer);


        // Show that we are active
        // mvaddch(2, 2, '0' + (rand() % 10));
        // (probably a good idea to sleep here)
    }

    free(c);
    delwin(stdscr);
    endwin();
    refresh();

    return 0;
}