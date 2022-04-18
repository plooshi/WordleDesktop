#include <stdbool.h>
#pragma once
#ifndef SCORE_INCL
#define SCORE_INCL 1
bool shouldRepeat(int pos, char ltr);
int scoreLetter(char *letter, int pos);
bool checkWin();
#endif