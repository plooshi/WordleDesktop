#include <stdbool.h>
#pragma once
#ifndef GUESS_INCL
#define GUESS_INCL 1
bool guessValid();
bool isOutOfGuesses();
void updateGuessArray();
void upGuessCount();
void resetGuess();
extern char *guessa[];
extern char *guess;
#endif