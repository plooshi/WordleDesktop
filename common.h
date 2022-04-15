#include <stdbool.h>
#pragma once
#ifndef COMMON_INCL
#define COMMON_INCL 1
extern char* wordles[];
extern char* validGuesses[];
bool guessValid(char *guess);
int scoreLetter(char *letter, int pos);
void updateWordle();
void updateGuessArray();
extern char *guessa[];
extern char *guess;
extern char *todaysWordle;
extern int guesses;
#endif