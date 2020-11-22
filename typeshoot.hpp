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
    bool is_down;

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
void background(void);
string *inputfile(string, int &);
codeline *code_create(string *, int);
void code_destroy(codeline *, int);
bool is_correct(codeline *, char *);
char *typecode();
void code_display(codeline *);
void code_init(codeline *);
bool is_overline(codeline *);
void stopdescend(codeline *, codeline *);
void stopcode_display(codeline **, int);
string get_str(int);
int rand_num(int, int);
codeline *copy_codeline(codeline *);
char **matrix_init();
bool matrix_check(char **, codeline *);
int set_matrix(char **, codeline *);
void gameover();
void scoreup(int &);

bool is_bottom(codeline *);
void sleep_milli(int);



