#include <time.h>
#include "words.h"

char *todaysWordle = "";

void updateWordle() {
    struct tm startDay = {0};
    startDay.tm_year = 121;
    startDay.tm_mon = 5;
    startDay.tm_mday = 19;
    startDay.tm_hour = 0;
    startDay.tm_min = 0;
    startDay.tm_sec = 0;
    time_t startEpoch = mktime(&startDay);
    time_t nowEpoch = time(NULL);
    time_t timeDiff = (time_t)difftime(nowEpoch, startEpoch);
    int dayCount = (int)timeDiff / (60 * 60 * 24);
    todaysWordle = wordles[dayCount];
}