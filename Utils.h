/**
 * @file Utils.h
 * @brief Utils class definition.
 *
 * This file contains the definition of the Utils class.
 * The class allows returning the string format of a month by passing in a numeric number of a month.
 * It also holds a function that is used in asserting for unit test.
 *
 * @author Chan Kok Wai ( Student Number: 33924804 )
 * @version 1.0
 */

#ifndef UTILS_H_INCLUDED
#define UTILS_H_INCLUDED

#include<iostream>
#include<fstream>
#include<string>

using namespace std;

class Utils
{
public:

    /**
    * @brief Get the month in string format by passing in a numeric number of a month.
    *
    * This member function allows retrieving string format of a month.
    *
    * @return A string data type a month.
    */
    string GetMonthInStr(const unsigned &month) const;

    /**
    * @brief assert a condition and return a message, Outputs the result to a txt file with the totalTest, test passed, and test failed status.
    *
    * This member function allows asserting for unit test.
    *
    * @param condition The condition of the test.
    * @param passMsg a string data type with the user defined pass statement.
     * @param failMsg a string data type with the user defined fail statement.
     * @param output the file output stream.
     * @param totalTest a unsigned data type holding the number of total assertion test.
     * @param testPassed a unsigned data type holding the number of total passed assertion test.
     * @param totalFailed a unsigned data type holding the number of total failed assertion test.
    */
    void assert(bool condition, string passMsg, string failMsg, ostream& output, unsigned &totalTest, unsigned &testPassed, unsigned &testFailed);
};

#endif // UTILS_H_INCLUDED
