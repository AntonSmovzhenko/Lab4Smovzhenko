/////muting error
#pragma warning(disable : 4996)

//Smovzhenko Anton
#include "Date.h"
#include <ctime>

Date Date::defaultDate;
bool Date::defaultSet = true;

string Date::monthNames[12] = {
        "Jan",
        "Feb",
        "Mar",
        "Apr",
        "May",
        "Jun",
        "Jul",
        "Aug",
        "Sep", 
        "Oct",
        "Nov",
        "Dec"
};
////constructors
Date::Date(const int d, const Month m, const int y) {
    fillDate(d, m, y);
}
Date::Date(const int d, const int m, const int y) {
    fillDate(d, Month(m), y);
}

//////////////////toString()
ostream& operator<<(ostream& ostr, const Date& d) {
    ostr << d.day() << '/' << d.month() << '/' << d.year() << endl;

    return ostr;
}
ostream& operator<<(ostream& ostr, const Date::BadDate& bd) {
    ostr << bd._day << '/' << bd._month << '/' << bd._year << endl;
    return ostr;
}
/////////////////////////

/////removing
Date::~Date() {
    cout << " removing " << *this << endl;
    return;
}
///coping
Date::Date(const Date& d) :
    _day(d._day),
    _month(d._month),
    _year(d._year) {
    cout << d << " coping " << *this << endl;
    return;
}


/// like setters
void Date::setDay(int d)
{
    _day = d;
}
void Date::setMonth(int m)
{
    _month = m;
}
void Date::setDYear(int y) 
{
    _year = y;
}
/////////////////////////


/////////////////getters
int Date::day() const {
    return _day;
}
Date::Month Date::month() const {
    return Month(_month);
}
int Date::year() const {
    return _year;
}
const std::string Date::getMonthName() const {
    return monthNames[_month];
}
/////////////////////////////



/////////перевірка на високостність
bool leapYear(int y)
{
    bool is_leap_year = false;
    if (y % 4 == 0)
    {
        is_leap_year = true;
    }
    return is_leap_year;
}
////////////////////



/// ////////////////
void Date::fillDate(const int d, const Month m, const int y) {
    if (defaultSet == true)
    {
        setDefault();
    }
    _day = d ? d : defaultDate._day;
    _month = m ? m : defaultDate._month;
    _year = y ? y : defaultDate._year;
    unsigned int numberOfDays = 0;
    switch (_month) 
    {
    case feb: numberOfDays = 28 + leapYear(y);
    break;
    case apr: case jun: case sep: case nov: numberOfDays = 30;
    break;
    case jan: case mar: case may: case jul: case aug: case oct: case dec: numberOfDays = 31;
    break;
    default: throw BadDate(_day, _month, _year);
    }

    if ((_day < 1) || (numberOfDays < _day) || (_year < 0)) {
        throw BadDate(_day, _month, _year);
    }

};
//////////////////////////


/////////////////////////////////all about default
void Date::setDefault(const int d, const Month m, const int y) {
    defaultSet = false;
    defaultDate = Date(d, m, y);
}
void Date::setDefault() {
    time_t timer;
    time(&timer);
    /////mute error here
    struct tm* today = gmtime(&timer);
    defaultDate._day= today->tm_mday;
    defaultDate._month= ++(today->tm_mon);
    defaultDate._year= today->tm_year += 1900;
}
void Date::showDefault() {
    cout << defaultDate;
}
///////////////////////////////////

