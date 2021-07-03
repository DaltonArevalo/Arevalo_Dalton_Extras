#pragma once
#include <chrono>
#include <string>

enum class Day {Monday = 1, Tuesday = 2, Wednesday = 3, Thursday = 4, Friday = 5, Saturday = 6, Sunday = 7};

class Date {
    private:
        int day;
        int month;
        int year;
    public:
        Date();
        Date(int day, int month, int year);

        static Date current();
        static std::chrono::system_clock::time_point system_now();
        static Date read(std::string aux);
        static bool isValid(int day, int month, int year);

        std::chrono::system_clock::time_point toTimePoint();
        void update(std::chrono::system_clock::time_point timePoint);
        void addDays(int days);
        int lastMonthDay();
        bool isHoliday();
        Day getWeekday();
        int getDay();
        int getMonth();
        int getYear();
};