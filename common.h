#include <stdbool.h>
#pragma once
#ifndef COMMON_INCL
#define COMMON_INCL 1
extern char* wordles[];
extern char* validGuesses[];
bool guessValid(char *guess);
int *score(char *guess);
extern char *guess;
extern char *todaysWordle;
#endif