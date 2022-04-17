#include <stdbool.h>
#pragma once
#ifndef COMMON_INCL
#define COMMON_INCL 1
extern char* wordles[];
extern char* validGuesses[];
bool guessValid();
bool isOutOfGuesses();
int scoreLetter(char *letter, int pos);
void updateWordle();
void updateGuessArray();
void upGuessCount();
bool checkWin();
extern char *guessa[];
extern char *guess;
extern char *todaysWordle;
void resetGuess();
#endif