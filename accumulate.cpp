#include <iostream>
#include "typeshoot.hpp"

using namespace std;

char **matrix_init() {
    int line, column;

    line = (LINES-1)/2 - (LINES-1)/4 + 1;
    column = 5*(COLS-1)/3 - (COLS-1)/6 + 1;

    char **matrix = new char*[line];
    for (int i=0; i<line; i++)
        matrix[i] = new char[column];

    for (int i=0; i<line; i++)
        for (int j=0; j<column; j++)
            matrix[i][j] = 0;

    return matrix;
}

bool matrix_check(char **matrix, codeline *c) {
    int y = c->y+1;
    int x = c->x;
    int line = y - (LINES-1)/2;
    int column = x - (COLS-1)/6;
    for (int i=column; i<(column+c->length); i++) {
        if (matrix[line][i] == 1) return true;
    }
    return false;
}

int set_matrix(char **matrix, codeline *c) {
    int y = c->y;
    int x = c->x;
    int line = y - (LINES-1)/2;
    int column = x - (COLS-1)/6;
    if (line < 0) {
        return -1;
    } else {
        for (int i=column; i<(column+c->length); i++) {
            matrix[line][i] = 1;
        }
    }
    return 0;
}

bool is_overline(codeline *c) {
    return (c->y > (LINES-1)-(LINES-1)/2-2 ? true : false);
}

bool is_bottom(codeline *c) {
    return (c->y > (LINES-1)-(LINES-1)/4-2 ? true : false);
}
