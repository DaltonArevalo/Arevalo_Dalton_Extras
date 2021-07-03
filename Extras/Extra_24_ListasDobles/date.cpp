#include "date.h"
#include <date/date.h>
#include <iostream>
#include <regex>
#include <limits>

Date::Date() {
    Date current = Date::current();
    day = current.getDay();
    month = current.getMonth();
    year =current.getYear();
}

Date::Date(int day, int month, int year){
    this->day = day;
    this->month = month;
    this->year = year;
}

std::chrono::system_clock::time_point Date::system_now() {
    auto now = std::chrono::system_clock::now();
    auto sinceEpoch = now.time_since_epoch();
    sinceEpoch -= std::chrono::hours{5}; // para ajustar a la hora local

    std::chrono::system_clock::time_point utcNow{sinceEpoch};
    return utcNow;
}
//implementa un current para la hora
Date Date::current() {
    auto now = Date::system_now();
    auto dp = date::floor<date::days>(now);
    date::year_month_day ymd{dp};
    
    int day = unsigned(ymd.day());
    int month = unsigned(ymd.month());
    int year = int(ymd.year());

    return Date(day, month, year);
}

Date Date::read(std::string aux) {
    // Date currentAux = Date::current();
    bool valid;
    int day;
    int month;
    int year;
    do {
        valid = true;
        std::string dateSTR;
        std::cout << (aux.empty() ? "Ingrese la fecha (dd/MM/YYYY): " : aux);
        std::cin >> dateSTR;
        //std::getline(std::cin, dateSTR);

        std::regex pattern("^(0?[1-9]|[12][0-9]|3[01])[\\/\\-](0?[1-9]|1[012])[\\/\\-](\\d{4})$");
        std::smatch matches;

        if ( ! std::regex_match(dateSTR, matches, pattern)){
            std::cout << std::endl << "[Formato incorrecto, intenta: (dd/mm/yyyy)]" << std::endl;
            valid = false;
        }else{
            day = std::stoi(matches[1]);
            month = std::stoi(matches[2]);
            year = std::stoi(matches[3]);

            if(day < 1 || day > 31) {
                std::cout <<std::endl <<"[dia incorrecto]" << std::endl;
                valid = false;
            }else if(month < 1 || month > 12) {
                std::cout <<std::endl<< "[mes incorrecto]" <<std::endl;
                valid = false;
            }else if(year < 1990) {
                std::cout <<std::endl<< "[Año incorrecto]" << std::endl;
                valid = false;
            }

            if (! Date::isValid(day,month,year)) {
                std::cout << std::endl<< "[Fecha incorrecta]" << std::endl;
                valid = false;
            }
        }
        
        if(!valid) {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits < std::streamsize>::max(), '\n');
        }
    } while (!valid);
    return Date(day, month, year);
}

bool Date::isValid(int day, int month, int year) {
    if (day < 1 || day > 31){
        return false;
    }else if (month < 1 || month > 12) {
        return false;
    }

    if ((month ==4 || month == 6 || month == 9 || month ==11) && day ==31) {
        return false;
    }else if ((month == 2) && (year % 4 == 0) && day > 29) {
        return false;
    }else if ((month == 2) && (year % 4 != 0) && day > 28) {
        return false;
    }
    return true;
}

std::chrono::system_clock::time_point Date::toTimePoint() {
    std::tm tm = {
        0,
        0,
        0,
        day,
        month -1,
        year - 1900,
    };
    tm.tm_isdst = -1;

    auto utcDate = std::chrono::system_clock::from_time_t(std::mktime(&tm));
    auto sinceEpoch = utcDate.time_since_epoch();
    sinceEpoch -= std::chrono::hours{5}; //horario de ecuador

    std::chrono::system_clock::time_point utcNow{sinceEpoch};

    return utcNow;
}

Day Date::getWeekday(){
    auto dp = date::floor<date::days> (toTimePoint());
    date::weekday weekday{dp};
    return static_cast<Day>(weekday.iso_encoding());
}

void Date::update(std::chrono::system_clock::time_point timePoint) {
    auto dp = date::floor<date::days> (timePoint);
    date::year_month_day ymd{dp};

    day = unsigned (ymd.day());
    month = unsigned (ymd.month());
    year = int(ymd.year());
}

void Date::addDays (int days) {
    auto timePoint = toTimePoint();
    auto date = date::floor<date::days>(timePoint);

    date::year_month_day future = date + date::days{days};

    update(date::sys_days{future});
}

int Date::lastMonthDay() {
    auto timePoint = toTimePoint();
    auto date = date::floor<date::days> (timePoint);
    date::year_month_day ymd{date};
    date::year_month_day_last lastDay{ymd.year(), date::month_day_last{ymd.month()}};
    return unsigned(lastDay.day());
}

bool Date::isHoliday() {
    std::vector<std::pair<int,int>> holidays = {std::make_pair(1, 1), std::make_pair(1, 2), std::make_pair(5, 1),
        std::make_pair(5, 24), std::make_pair(7, 25), std::make_pair(8, 10), std::make_pair(10, 9),
        std::make_pair(11, 2), std::make_pair(11, 3), std::make_pair(12, 25), std::make_pair(12, 31)};
    bool isHoliday = false;

    for(std::pair<int,int> holiday : holidays) {
        if (holiday.first == getMonth() && holiday.second == getDay()) {
            isHoliday = true;
            break;
        }
    }
    return isHoliday;
}

int Date::getDay(){
    return day;
}

int Date::getMonth(){
    return month;
}

int Date::getYear() {
    return year;
}