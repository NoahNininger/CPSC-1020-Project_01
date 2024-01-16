#ifndef CALC_DAYS_H_
#define CALC_DAYS_H_
#include "Date.h"

const int monthDays[12] = {31, 59, 90, 120, 151, 181, 212, 243, 273, 304, 334, 365};    // number of days in a year via array

int calcDays(const Date&, const Date&);         // function prototype for calcDays()

#endif