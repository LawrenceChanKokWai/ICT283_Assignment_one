/**
 * @file Time.h
 * @brief Time class definition.
 *
 * This file contains the definition of the Time class, which represents the time.
 * The class allows setting and retrieving the hour, and minutes associated with the time.
 * It also overloads stream operators for input and output to facilitate I/O operations.
 *
 * @author Chan Kok Wai ( Student Number: 33924804 )
 * @version 1.0
 */

#ifndef TIME_H_INCLUDED
#define TIME_H_INCLUDED

#include<iostream>
#include<string>

using namespace std;

class Time
{
public:

    /**
    * @brief Default constructor for Time class.
    *
    * This constructor creates a Time object with default values for hours, and minutes attributes that is set as 0.
    */
    Time();

    /**
    * @brief Parameterized constructor for Time class.
    *
    * @param day The hours associated with the time.
    * @param month The minutes associated with the time.
    */
    Time(const string &hour, const string &minute);


    /**
    * @brief Get the hours associated with the time.
    *
    * This member function allows retrieving the hours that is associated with the Time object.
    *
    * @return A constant unsigned data type of the hours representing the hours of the time.
    */
    string GetHour() const;

    /**
    * @brief Get the minutes associated with the time.
    *
    * This member function allows retrieving the minutes that is associated with the Time object.
    *
    * @return A constant unsigned data type of the minutes representing the hours of the time.
    */
    string GetMinute() const;

    /**
    * @brief Set the hours associated with the time.
    *
    * This member function allows setting the hours that are associated with the time.
    *
    * @param day The hours to be set as an unsigned data type.
    */
    void SetHour(const string &hour);

    /**
    * @brief Set the minutes associated with the time.
    *
    * This member function allows setting the minutes that are associated with the time.
    *
    * @param day The minutes to be set as an unsigned data type.
    */
    void SetMinute(const string &minute);

private:
    string m_hour;
    string m_minute;
};

/**
* @brief Overloaded stream insertion operator for Time class.
*
* This allows a Time object to be printed to an output stream using the standard output format.
* The hours (unsigned data type), and minutes (unsigned data type) will be printed.
*
* @param output The output stream where the Time object will be printed.
* @param T The Time object to be printed.
* @return A reference to the output stream after printing the Time object.
*/
ostream &operator << (ostream &outputStream, const Time &T);

/**
* @brief Overloaded stream extraction operator for Time class.
*
* This allows a Time object to be read from an input stream using the standard input format.
* The input should contain the hours (unsigned data type), and minutes (unsigned data type).
*
* @param input The input stream from which the Time object will be read.
* @param T The Time object where the read information will be stored.
* @return A reference to the input stream after setting the Time object.
*/
istream &operator >> (istream &inputStream, Time &T);

#endif // TIME_H_INCLUDED
