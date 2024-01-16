#include <iostream>
#include "calcDays.h"

int calcDays(const Date& d1, const Date& d2)
{
    long int daysDiff1;      // variable to hold calculation of days between date of exposure & 01/01/2021

    if (d1.getYear() == 2021)
    {
        if (d1.getMonth() == 1)      // if date of exposure is also in 01/2021
        {
            daysDiff1 = d1.getDay();
            daysDiff1 -= 1;
        }
        else                    // if date of exposure is in months 2-12 in 2021
        {
            daysDiff1 = monthDays[d1.getMonth() - 1];
            daysDiff1 += d1.getDay();
            daysDiff1 -= 2;
        }
    }

    else if (d1.getYear() == 2022)   // if date of exposure was at least a year after 01/01/2021
    {
        daysDiff1 = 365 + monthDays[d1.getMonth() - 1];
        daysDiff1 += d1.getDay();
        daysDiff1 -= 2;
    }

    long int daysDiff2;      // variable to hold calculation of days between date of vaccination & 01/01/2021

    if (d2.getYear() == 2021)
    {
        if (d2.getMonth() == 1)      // if date of vaccination is also in 01/2021
        {
            daysDiff2 = d2.getDay();
            daysDiff2 -= 1;
        }
        else                    // if date of vaccination is in months 2-12 in 2021
        {
            daysDiff2 = monthDays[d2.getMonth() - 1];
            daysDiff2 += d2.getDay();
            daysDiff2 -= 2;
        }
    }

    else if (d2.getYear() == 2022)   // if date of exposure was at least a year after 01/01/2021
    {
        daysDiff2 = 365 + monthDays[d2.getMonth() - 1];
        daysDiff2 += d2.getDay();
        daysDiff2 -= 2;
    }

    return daysDiff1 - daysDiff2;   // returns the difference between the two calculations
}