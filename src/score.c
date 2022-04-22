#include "score.h"
#include "wordles.h"
#include "guess.h"
#include <stddef.h>
#include <string.h>

bool checkWin() {
    if (
        scoreLetter(guessa[0], 0) == 2 && 
        scoreLetter(guessa[1], 1) == 2 && 
        scoreLetter(guessa[2], 2) == 2 && 
        scoreLetter(guessa[3], 3) == 2 && 
        scoreLetter(guessa[4], 4) == 2
    ) return true;
    return false;
}

bool shouldRepeat(int pos, char ltr) {
    int wRptCount = -1, wFirstOcc = -1, wRpt1 = -1, wRpt2 = -1, wRpt3 = -1, wRpt4 = -1, wRpt5 = -1;
    int gRptCount = -1, gFirstOcc = -1, gRpt1 = -1, gRpt2 = -1, gRpt3 = -1, gRpt4 = -1, gRpt5 = -1;
    lowerGuess();
    for (int x = 0; x < 5; x++) {
        if (todaysWordle[x] == ltr) {
            wRptCount++;
            if (wRptCount == 0) {
                wFirstOcc = x;
            } else if (wRptCount == 1) {
                wRpt1 = x;
            } else if (wRptCount == 2) {
                wRpt2 = x;
            } else {
                wRpt3 = x;
            }
        }
    }
    for (int i = 0; i < 5; i++) {
        if (guess[i] == ltr) {
            gRptCount++;
            if (gRptCount == 0) {
                gFirstOcc = i;
            } else if (gRptCount == 1) {
                gRpt1 = i;
            } else if (gRptCount == 2) {
                gRpt2 = i;
            } else {
                gRpt3 = i;
            }
        }
    }
    if (gRptCount == 1 && wRpt1 == -1 && wRptCount < 1) {
        return false;
    }
    if (gRptCount == 2 && wRpt2 == -1 && wRptCount < 2) {
        return false;
    }
    if (gRptCount == 3 && wRpt3 == -1 && wRptCount < 3) {
        return false;
    }
    if (gRptCount >= 4) {
        return false;
    }
    return true;
}

int scoreLetter(char *letter, int pos) {
    if ((char)letter[0] == (char)todaysWordle[pos]) return 2;
    bool repeat = shouldRepeat(pos, (char)letter[0]);
    if (strchr(todaysWordle, (int)(letter[0])) != NULL && repeat == true) return 1;
    return 0;
}