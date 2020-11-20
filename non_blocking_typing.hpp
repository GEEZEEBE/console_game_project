#pragma once
#include <ncurses.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

struct input_line {
    char *ln;
    int length;
    int capacity;
    int cursor;
    int last_rendered;
};

void make_buffer(struct input_line *);
void destroy_buffer(struct input_line *);
void render_line(struct input_line *);
int retrieve_content(struct input_line *, char *, int);
void add_char(struct input_line *, char);
int handle_input(struct input_line *, char *, int, int);
int get_line_non_blocking(struct input_line *, char *, int);