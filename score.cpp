#include "typeshoot.hpp"

void scoreup(int &score) {
    score += 10;
    mvaddstr(LINES/6, 11*COLS/12-3, to_string(score).c_str());
}