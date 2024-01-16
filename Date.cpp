#include <iostream>
#include <string>
#include "Date.h"

bool Date::setDay(int d) 
{
// checks if user entered a valid day of the month
    if (month == 4 || month == 6 || month == 9 || month == 11)  // for april, june, september & november
    {
        if (d >= 1 && d <= 30)
        {
            day = d;      // sets user-initialized value
            return true;
        }
        else
            { return false; }
    }

    else if (month != 2)                            // for january, march, may, july, august, october, & december
    {
        if (d >= 1 && d <= 31)
        {
            day = d;      // sets user-initialized value
            return true;
        }
        else
            { return false; }
    }

    else /*(m == 2)*/                            // for february
    {
        if (d >= 1 && d <= 28) 
        {
            day = d;      // sets user-initialized value
            return true;
        }
        else
            { return false; }
    }
}

bool Date::setMonth(int m) 
{
    if (m >= 1 && m <= 12)      // checks if user entered numbers 1-12 for month
    {
        month = m;      // sets user-initialized value
        return true;
    }
    else
        { return false; }
}

bool Date::setYear(int y)     // checks if user entered either 2021 or 2022 for year
{
    if (y == 2021 || y == 2022) 
    {
        year = y;      // sets user-initialized value
        return true;
    }
    else
        { return false; }
}

int Date::getDay() const        // getter function definitions
    { return day; }
int Date::getMonth() const
    { return month; }
int Date::getYear() const
    { return year; }

std::string Date::showDate(int m, int d, int y)     // showDate() definition (converts integers to strings)
{
    std::string strMonth, strDay, strYear;

    if (m < 10)     // for single digit numbers
    {
        strMonth = std::to_string(m);
        std::cout << "0" << strMonth << "/";
    }

    else 
    {
        strMonth = std::to_string(m);
        std::cout << strMonth << "/";
    }

    if (d < 10)     // for single digit numbers
    {
        strDay = std::to_string(d);
        std::cout << "0" << strDay << "/";
    }

    else 
    {
        strDay = std::to_string(d);
        std::cout << strDay << "/";
    }

    strYear = std::to_string(y);

    return strYear;     // returns the date in the format of MM/DD/YYYY as a string
}