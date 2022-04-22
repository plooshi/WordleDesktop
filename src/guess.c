#include "guess.h"
#include "wordles.h"
#include "words.h"
#include <time.h>
#ifndef __APPLE__
#include <malloc.h>
#else
#include <stdlib.h>
#endif
#include <string.h>
#include <ctype.h>
#ifdef _MSC_VER
char *guess = "";
#else
char guess[6] = "";
#endif
char *guessa[5] = {" ", " ", " ", " ", " "};

void lowerGuess() {
    for(int i = 0; guess[i]; i++){
        guess[i] = tolower(guess[i]);
    }
}

void resetGuess() {
    #ifdef _MSC_VER
    memset(guess, 0, sizeof(guess));
    #else
    guess[0] = '\0';
    #endif
}

void updateGuessArray() {
    lowerGuess();
    char *v1 = malloc(2*sizeof(char));
    char *v2 = malloc(2*sizeof(char));
    char *v3 = malloc(2*sizeof(char));
    char *v4 = malloc(2*sizeof(char));
    char *v5 = malloc(2*sizeof(char));
    if (strlen(guess) >= 0) {
        v1[0] = guess[0];
        v1[1] = '\0';
    } else {
        v1 = (char*)" ";
    }
    if (strlen(guess) >= 2) {
        v2[0] = guess[1];
        v2[1] = '\0';
    } else {
        v2 = (char*)" ";
    }
    if (strlen(guess) >= 3) {
        v3[0] = guess[2];
        v3[1] = '\0';
    } else {
        v3 = (char*)" ";
    }
    if (strlen(guess) >= 4) {
        v4[0] = guess[3];
        v4[1] = '\0';
    } else {
        v4 = (char*)" ";
    }
    if (strlen(guess) == 5) {
        v5[0] = guess[4];
        v5[1] = '\0';
    } else {
        v5 = (char*)" ";
    }
    guessa[0] = v1;
    guessa[1] = v2;
    guessa[2] = v3;
    guessa[3] = v4;
    guessa[4] = v5;
}

bool guessValid() {
    lowerGuess();
    bool valid = false;
    for ( int i = 0; i < 2309; i++ ) {
        if (strcmp(wordles[i], guess) == 0) valid = true;
    }
    for ( int i = 0; i < 10665; i++ ) {
        if (strcmp(validGuesses[i], guess) == 0) valid = true;
    }
    return valid;
}
