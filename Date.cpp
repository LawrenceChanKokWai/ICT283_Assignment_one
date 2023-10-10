#include "Date.h"

Date::Date()
{
    m_day = 0;
    m_month = 0;
    m_year = 0;
}

Date::Date(const unsigned day, const unsigned month, const unsigned year)
{
    m_day = day;
    m_month = month;
    m_year = year;
}

/* Getters */
unsigned Date::GetDay() const
{
    return m_day;
}

unsigned Date::GetMonth() const
{
    return m_month;
}

unsigned Date::GetYear() const
{
    return m_year;
}

/* Setters */
void Date::SetDay(const unsigned day)
{
    m_day = day;
}

void Date::SetMonth(const unsigned month)
{
    m_month = month;
}
void Date::SetYear(const unsigned year)
{
    m_year = year;
}

ostream &operator << (ostream &outputStream, const Date &D)
{
    outputStream << "Date: " << D.GetDay() << "/" << D.GetMonth() << "/" << D.GetYear();

    return outputStream;
}

istream &operator >> (istream &inputStream, Date &D)
{
    string tempDayField;
    string tempMonthField;
    string tempYearField;

    getline(inputStream, tempDayField, '/');
    D.SetDay(stoi(tempDayField));

    getline(inputStream, tempMonthField, '/');
    D.SetMonth(stoi(tempMonthField));

    getline(inputStream, tempYearField, ' ');
    D.SetYear(stoi(tempYearField));

    return inputStream;
}
