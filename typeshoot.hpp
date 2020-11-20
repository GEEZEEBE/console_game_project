#pragma once
#include <curses.h>
#include <string>
#include <unistd.h>

using namespace std;

struct codeline {
    string code;
    int x, y;
    int length;
    string e_tracer;
    bool is_alive;

    void make_tracer() {
        for (int i = 0; i < code.length(); i++) {
            e_tracer += ' ';
        }
    }
};

void descend(codeline *);
void typing(void);
void shoot(int, int);
void collision(void);
void accumulate(void);
void score(void);
void backgroud(void);
void inputfile(void);
codeline *code_create(int, int);
void code_destroy(codeline *);
bool is_correct(codeline *, char *);
char *typecode();
void code_display(codeline *);
void code_init(codeline *);

void sleep_milli(int milliseconds);


