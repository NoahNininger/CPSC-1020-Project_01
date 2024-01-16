// program that calculates a user's isolation periods for COVID-19 within 01/01/2021 - 12/31/2022 for simplicity
// Noah Nininger
#include <iostream>
#include <string>
#include "calcDays.h"
#include "Date.h"
using namespace std;

int main()
{
    int userInput, day, month, year, vaccineDay, vaccineMonth, vaccineYear;        // declared variables

    cout << "Did you test positive or negative for COVID-19?" << endl
         << "1 - Positive" << endl
         << "2 - Negative" << endl;      // user prompt for test results
    cin >> userInput;

    switch (userInput)
    {
        case 1:       // if positive
        {
            Date datePositive;     // creates an instance of class Date for a positive COVID-19 test

            cout << "When did you test positive (MM/DD/YYYY)?" << endl
                 << "Month: ";
            cin >> month;
            if (datePositive.setMonth(month) == false)  // input validation
                { month = datePositive.getMonth(); }

            cout << "Day: ";
            cin >> day;
            if (datePositive.setDay(day) == false)  // input validation 
                { day = datePositive.getDay(); }

            cout << "Year: ";
            cin >> year;
            if (datePositive.setYear(year) == false)  // input validation
                { year = datePositive.getYear(); }

            cout << "Test Result: positive" << endl     // prints results
                 << "Date tested positive: " << datePositive.showDate(month, day, year) << endl
                 << "Length of isolation: 5 days" << endl;
            return 0;       // ends program
        }
        case 2:      // if negative
            cout << "Have you been exposed to anyone who has tested positive?" << endl
                 << "1 - Yes" << endl
                 << "2 - No" << endl;       // prompts user for exposure
            cin >> userInput;

            switch (userInput)
            {
                case 1:      // if exposed
                {
                    Date dateExposed;     // creates an instance of class Date for exposure to COVID-19

                    cout << "When were you exposed to COVID-19 (MM/DD/YYYY)?" << endl
                         << "Month: ";
                    cin >> month;
                    if (dateExposed.setMonth(month) == false)  // input validation
                        { month = dateExposed.getMonth(); }

                    cout << "Day: ";
                    cin >> day;
                    if (dateExposed.setDay(day) == false)  // input validation
                        { day = dateExposed.getDay(); }

                    cout << "Year: ";
                    cin >> year;
                    if (dateExposed.setYear(year) == false)  // input validation
                        { year = dateExposed.getYear(); }

                    cout << "Are you fully vaccinated for COVID-19 (both shots)?" << endl
                         << "1 - Yes" << endl
                         << "2 - No" << endl;       // prompts user for vaccination
                    cin >> userInput;

                    switch (userInput)
                    {
                        case 1:     // if fully vaccinated
                        {
                            Date dateSecondDose;        // creates another instance of class date for the date of vaccination

                            cout << "When did you recieve your second dose (MM/DD/YYY)?" << endl
                                 << "Month: ";
                            cin >> vaccineMonth;
                            if (dateSecondDose.setMonth(vaccineMonth) == false)  // input validation
                                { vaccineMonth = dateSecondDose.getMonth(); }

                            cout << "Day: ";
                            cin >> vaccineDay;
                            if (dateSecondDose.setDay(vaccineDay) == false)  // input validation
                                { vaccineDay = dateSecondDose.getDay(); }

                            cout << "Year: ";
                            cin >> vaccineYear;
                            if (dateSecondDose.setYear(vaccineYear) == false)  // input validation
                                { vaccineYear = dateSecondDose.getYear(); }

                            if (calcDays(dateExposed, dateSecondDose) >= 14)    // if test has been at least 14 days since vaccination
                            {
                                cout << "Test Result: negative" << endl     // prints results
                                     << "Exposed to positive case: Yes" << endl
                                     << "Date exposed to positive case: " << dateExposed.showDate(month, day, year) << endl
                                     << "Second vaccination dose recieved: Yes" << endl
                                     << "Date second vaccination dose recieved: " << dateSecondDose.showDate(vaccineMonth, vaccineDay, vaccineYear) << endl
                                     << "Vaccination status at time of exposure: Fully vaccinated" << endl
                                     << "Length of Isolation: 5 days" << endl;
                            }
                            else if (calcDays(dateExposed, dateSecondDose) < 14)     // if test has been within 14 days of vaccination
                            {
                                cout << "Test Result: negative" << endl     // prints results
                                     << "Exposed to positive case: Yes" << endl
                                     << "Date exposed to positive case: " << dateExposed.showDate(month, day, year) << endl
                                     << "Second vaccination dose recieved: Yes" << endl
                                     << "Date second vaccination dose recieved: " << dateSecondDose.showDate(vaccineMonth, vaccineDay, vaccineYear) << endl
                                     << "Vaccination status at time of exposure: Not fully vaccinated" << endl
                                     << "Length of Isolation: 10 days" << endl;
                            }
                            return 0;       // ends program
                        }
                        case 2:     // if not fully vaccinated
                            cout << "Test Result: negative" << endl     // prints results
                                 << "Exposed to positive case: Yes" << endl
                                 << "Date exposed to positive case: " << dateExposed.showDate(month, day, year) << endl
                                 << "Second vaccination dose recieved: No" << endl
                                 << "Vaccination status at time of exposure: Not fully vaccinated" << endl
                                 << "Length of Isolation: 10 days" << endl;
                            return 0;       // ends program
                    }
                }
                case 2:     // if not exposed
                    cout << "Test Result: negative" << endl     // prints results
                         << "Exposed to positive case: No" << endl
                         << "Length of Isolation: 0 days" << endl;
                    return 0;       // ends program
            }
    }
    return 0;
}