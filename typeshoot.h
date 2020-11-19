#pragma once
#include <curses.h>
#include <string>
#include <unistd.h>

using namespace std;

struct codeline {
    string code;
    int x, y;
    int length;
    bool is_alive;
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


