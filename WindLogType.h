/**
 * @file WindLogType.h
 * @brief WindLogType class definition.
 *
 * This file contains the definition of the WindLogType class.
 * The class allows setting and retrieving the date , time, wind speed, solar radiation, and air temperature associated with the WindLogType.
 * It also overloads stream operators for input and output to facilitate I/O operations.
 *
 * @author Chan Kok Wai ( Student Number: 33924804 )
 * @version 1.0
 */

#ifndef WINDLOGTYPE_H_INCLUDED
#define WINDLOGTYPE_H_INCLUDED

#include<iostream>

#include "Date.h"
#include "Time.h"

using namespace std;

class WindLogType
{
public:

    /**
    * @brief Default constructor for WindLogType class.
    *
    * This constructor creates a WindLogType object with default values for date object, time object, wind speed, solar radiation, and air temperature that is set as 0.
    */
    WindLogType();

    /**
    * @brief Parameterized constructor for WindLogType class.
    *
    * @param date The date associated with the Date class object containing day, month, and year.
    * @param time The time associated with the Time class object containing hours, and minutes.
    * @param windspeed The wind speed associated with the WindLogType containing unsigned wind speed value.
    * @param airTemperature The air temperature associated with the WindLogType containing float air temperature value.
    * @param solarRadiation The solar radiation associated with the WindLogType containing unsigned solar radiation value.
    *
    */
    WindLogType(const Date &date, const Time &time, const float windspeed, const float airTemperature, const float solarRadiation);

    /**
    * @brief Get the date class object associated with the Date class for WindLogType class.
    *
    * This member function allows retrieving the date that is associated with the Date class object.
    *
    * @return A Date object data type of the day representing a date.
    */
    const Date GetDate() const;

    /**
    * @brief Get the time class object associated with the Time class for WindLogType class.
    *
    * This member function allows retrieving the date that is associated with the Time class object.
    *
    * @return A Time object data type of the time representing a time.
    */
    const Time GetTime() const;

    /**
    * @brief Get the wind speed associated with the WindLogType.
    *
    * This member function allows retrieving the wind speed that is associated with the WindLogType object.
    *
    * @return A unsigned data type of the wind speed representing the wind speed of a particular date.
    */
    const float GetWindSpeed() const;

    /**
    * @brief Get the air temperature associated with the WindLogType.
    *
    * This member function allows retrieving the air temperature that is associated with the WindLogType object.
    *
    * @return A float data type of the air temperature representing the air temperature of a particular date.
    */
    const float GetAirTemperature() const;

    /**
    * @brief Get the solar radiation associated with the WindLogType.
    *
    * This member function allows retrieving the solar radiation that is associated with the WindLogType object.
    *
    * @return A unsigned data type of the solar radiation representing the solar radiation of a particular date.
    */
    const float GetSolarRadiation() const;


    /**
    * @brief Set the date class object that contains the day, month, and year associated with the date.
    *
    * This member function allows setting the date class object that are associated with the WindLogType.
    *
    * @param date The date to be set as an date class object data type by reference.
    */
    void SetDate(const Date &date);

    /**
    * @brief Set the time class object that contains the hours, and minutes associated with the time.
    *
    * This member function allows setting the time class object that are associated with the WindLogType.
    *
    * @param time The time to be set as an time class object data type by reference.
    */
    void SetTime(const Time &time);

    /**
    * @brief Set the wind speed associated with the WindLogType.
    *
    * This member function allows setting the wind speed that are associated with the WindLogType.
    *
    * @param windspeed The wind speed to be set as an unsigned data type by reference.
    */
    void SetWindSpeed(const float windspeed);

    /**
    * @brief Set the air temperature associated with the WindLogType.
    *
    * This member function allows setting the air temperature that are associated with the WindLogType.
    *
    * @param airTemperature The air temperature to be set as an float data type by reference.
    */
    void SetAirTemperature(const float airTemperature);

    /**
    * @brief Set the solar radiation associated with the WindLogType.
    *
    * This member function allows setting the solar radiation that are associated with the WindLogType.
    *
    * @param solarRadiation The solar radiation to be set as an float data type by reference.
    */
    void SetSolarRadiation(const float solarRadiation);

private:
    Date m_date;
    Time m_time;
    float m_windspeed;
    float m_airTemperature;
    float m_solarRadiation;
};

/**
* @brief Overloaded stream insertion operator for WindLogType class.
*
* This allows a WindLogType object to be printed to an output stream using the standard output format.
* The date (Date object data type), time (Time object data type), wind speed (float data type), air temperature (float data type), and solar temperature (float data type) will be printed.
*
* @param output The output stream where the WindLogType object will be printed.
* @param W The WindLogType object to be printed.
* @return A reference to the output stream after printing the WindLogType object.
*/
ostream &operator << (ostream &outputStream, const WindLogType &W);

/**
* @brief Overloaded stream extraction operator for WindLogType class.
*
* This allows a WindLogType object to be read from an input stream using the standard input format.
* The input should contain date (Date object data type), time (Time object data type), wind speed (float data type), air temperature (float data type), and solar temperature (float data type)).
*
* @param input The input stream from which the WindLogType object will be read.
* @param W The WindLogType object where the read information will be stored.
* @return A reference to the input stream after setting the WindLogType object.
*/
istream &operator >> (istream &inputStream, WindLogType &W);

#endif // WINDLOGTYPE_H_INCLUDED
