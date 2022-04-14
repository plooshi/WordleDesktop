#include <stdbool.h>
#pragma once
#ifndef COMMON_INCL
#define COMMON_INCL 1
extern char* wordles[];
extern char* validGuesses[];
bool guessValid(char* guess);
char *guess;
#endif