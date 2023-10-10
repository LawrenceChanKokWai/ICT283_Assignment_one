#include "WindLogType.h"

WindLogType::WindLogType()
{
    m_windspeed = 0;
    m_airTemperature = 0;
    m_solarRadiation = 0;
}

WindLogType::WindLogType(const Date &date, const Time &time, const float windspeed, const float airTemperature, const float solarRadiation)
{
    m_date = date;
    m_time = time;
    m_windspeed = windspeed;
    m_airTemperature = airTemperature;
    m_solarRadiation = solarRadiation;
}

const Date WindLogType::GetDate() const
{
    return m_date;
}

const Time WindLogType::GetTime() const
{
    return m_time;
}

const float WindLogType::GetWindSpeed() const
{
    return m_windspeed;
}

const float WindLogType::GetAirTemperature() const
{
    return m_airTemperature;
}

const float WindLogType::GetSolarRadiation() const
{
    return m_solarRadiation;
}

void WindLogType::SetDate(const Date &date)
{
    m_date = date;
}

void WindLogType::SetTime(const Time &time)
{
    m_time = time;
}

void WindLogType::SetWindSpeed(const float windspeed)
{
    m_windspeed = windspeed;
}

void WindLogType::SetAirTemperature(const float airTemperature)
{
    m_airTemperature = airTemperature;
}

void WindLogType::SetSolarRadiation(const float solarRadiation)
{
    m_solarRadiation = solarRadiation;
}

ostream &operator << (ostream &outputStream, const WindLogType &W)
{
    outputStream << W.GetDate() << " " << W.GetTime() << " "
                                << W.GetWindSpeed() << " " << W.GetSolarRadiation() << " " << W.GetAirTemperature();

    return outputStream;
}

istream &operator >> (istream &inputStream, WindLogType &W)
{
    string tempWindspeedField;
    string tempSolarRadiationField;
    string tempAirTemperatureField;
    string tempLine;
    Date date;
    Time time;

    inputStream >> date;
    W.SetDate(date);

    inputStream >> time;
    W.SetTime(time);

    for(unsigned i(0); i < 9; i++)
    {
        getline(inputStream, tempLine, ',');
    }
    getline(inputStream, tempWindspeedField, ',');
    W.SetWindSpeed(stof(tempWindspeedField));

    getline(inputStream, tempSolarRadiationField, ',');
    W.SetSolarRadiation(stof(tempSolarRadiationField));

    for(unsigned i(0); i < 5; i++)
    {
        getline(inputStream, tempLine, ',');
    }
    getline(inputStream, tempAirTemperatureField, '\n');
    W.SetAirTemperature(stof(tempAirTemperatureField));

    return inputStream;
}
