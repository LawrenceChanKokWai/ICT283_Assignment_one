/**
 * @file Date.h
 * @brief Date class definition.
 *
 * This file contains the definition of the Date class, which represents the date for a specific unit.
 * The class allows setting and retrieving the day, month, and year associated with the date for the unit.
 * It also overloads stream operators for input and output to facilitate I/O operations.
 *
 * @author Chan Kok Wai ( Student Number: 33924804 )
 * @version 1.0
 */

#ifndef DATE_H_INCLUDED
#define DATE_H_INCLUDED

#include<iostream>
#include<string>

using namespace std;

class Date
{
public:

    /**
    * @brief Default constructor for Date class.
    *
    * This constructor creates a Date object with default values for day, month, and year attributes that is set as 0.
    */
    Date();

    /**
    * @brief Parameterized constructor for Date class.
    *
    * @param day The day associated with the date.
    * @param month The month associated with the date.
    * @param year The year associated with the date.
    */
    Date(const unsigned day, const unsigned month, const unsigned year);

    /* Getters */
    /**
    * @brief Get the day associated with the date.
    *
    * This member function allows retrieving the day that is associated with the Date object.
    *
    * @return A constant unsigned data type of the day representing the day of the date.
    */
    unsigned GetDay() const;

    /**
    * @brief Get the month associated with the date.
    *
    * This member function allows retrieving the month that is associated with the Date object.
    *
    * @return A constant unsigned data type of the month representing the month of the date.
    */
    unsigned GetMonth() const;

    /**
    * @brief Get the year associated with the date.
    *
    * This member function allows retrieving the year that is associated with the Date object.
    *
    * @return A constant unsigned data type of the year representing the year of the date.
    */
    unsigned GetYear() const;

    /* Setters */
    /**
    * @brief Set the day associated with the date.
    *
    * This member function allows setting the day that are associated with the date.
    *
    * @param day The day to be set as an unsigned data type.
    */
    void SetDay(const unsigned day);

    /**
    * @brief Set the month associated with the date.
    *
    * This member function allows setting the month that are associated with the date.
    *
    * @param month The month to be set as an unsigned data type.
    */
    void SetMonth(const unsigned month);

    /**
    * @brief Set the year associated with the date.
    *
    * This member function allows setting the year that are associated with the date.
    *
    * @param year The year to be set as an unsigned data type.
    */
    void SetYear(const unsigned year);

private:
    unsigned m_day;
    unsigned m_month;
    unsigned m_year;
};

/**
* @brief Overloaded stream insertion operator for Date class.
*
* This allows a Date object to be printed to an output stream using the standard output format.
* The day (unsigned data type), month (string data type), and year (unsigned data type) will be printed.
*
* @param output The output stream where the Date object will be printed.
* @param D The Date object to be printed.
* @return A reference to the output stream after printing the Date object.
*/
ostream &operator << (ostream &outputStream, const Date &D);

/**
* @brief Overloaded stream extraction operator for Date class.
*
* This allows a Date object to be read from an input stream using the standard input format.
* The input should contain the day (unsigned data type), month (unsigned data type), and year (unsigned data type).
*
* @param input The input stream from which the Date object will be read.
* @param D The Date object where the read information will be stored.
* @return A reference to the input stream after setting the Date object.
*/
istream &operator >> (istream &inputStream, Date &D);

#endif // DATE_H_INCLUDED
