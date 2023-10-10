#include "Time.h"

    Time::Time()
    {
        m_hour = "0";
        m_minute = "00";
    }
    Time::Time(const string &hour, const string &minute)
    {
        m_hour = hour;
        m_minute = minute;
    }

    string Time::GetHour() const
    {
        return m_hour;
    }

    string Time::GetMinute() const
    {
        return m_minute;
    }

    void Time::SetHour(const string &hour)
    {
        m_hour = hour;
    }

    void Time::SetMinute(const string &minute)
    {
        m_minute = minute;
    }

    ostream &operator << (ostream &outputStream, const Time &T)
    {
        outputStream << "Time: " << T.GetHour() << ":" << T.GetMinute();

        return outputStream;
    }
istream &operator >> (istream &inputStream, Time &T)
{
    string tempHrField;
    string tempMinField;

    getline(inputStream, tempHrField, ':');
    T.SetHour(tempHrField);

    getline(inputStream, tempMinField, ',');
    T.SetMinute(tempMinField);

    return inputStream;
}
