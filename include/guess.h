#include <stdbool.h>
#pragma once
#ifndef GUESS_INCL
#define GUESS_INCL 1
bool guessValid();
bool isOutOfGuesses();
void updateGuessArray();
void upGuessCount();
void resetGuess();
void lowerGuess();
extern char *guessa[];
#ifdef _MSC_VER
extern char *guess;
#else
extern char guess[6];
#endif
#endif