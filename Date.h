#ifndef PATIENT_H_
#define PATIENT_H_

class Date
{
    private:
        int day {1};        // member variables with defualt initialization
        int month {1};
        int year {2021};

    public:
        Date() = default;       // default constructor
        Date(int d, int m, int y) : day{d}, month{m}, year{y} {}        // constructor w/ user-initialized values

        bool setDay(int);       // setter functions
        bool setMonth(int);
        bool setYear(int);

        int getDay() const;     // getter functions
        int getMonth() const;
        int getYear() const;

        std::string showDate(int, int, int);     // showDate() prototype
};

#endif