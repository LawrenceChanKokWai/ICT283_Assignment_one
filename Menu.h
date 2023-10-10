/**
 * @file Menu.h
 * @brief Menu class definition.
 *
 * This file contains the definition of the Menu class.
 * The class allows user to place their inputs in retrieving the data from the WindLogType class.
 * This class serves as the main menu for the user.
 *
 * @author Chan Kok Wai ( Student Number: 33924804 )
 * @version 1.0
 */

#ifndef MENU_H_INCLUDED
#define MENU_H_INCLUDED

#include<iostream>
#include<fstream>

#include "Vector.h"
#include "WindLogType.h"
#include "Utils.h"
#include "Converter.h"
#include "cmath"

using namespace std;

class Menu
{
public:

    /**
    * @brief Get the running menu of the options that the user can select.
    *
    * This member function allows retrieving the menu of options that the user can select.
    *
    * @param windLogVector The vector that holds the data from the read csv file.
    */
    static void RunMenu(Vector<WindLogType>& windLogVector);

    /**
    * @brief Get the option one of the menu.
    *
    * This member function allows retrieving the menu of option one from the menu.
    *
    * @param windLogVector The vector that holds the data from the read csv file.
    */
    static void OptionOne(Vector<WindLogType>& windLogVector);

    /**
    * @brief Get the option two of the menu.
    *
    * This member function allows retrieving the menu of option two from the menu.
    *
    * @param windLogVector The vector that holds the data from the read csv file.
    */
    static void OptionTwo(Vector<WindLogType>& windLogVector);

    /**
    * @brief Get the option three of the menu.
    *
    * This member function allows retrieving the menu of option three from the menu.
    *
    * @param windLogVector The vector that holds the data from the read csv file.
    */
    static void OptionThree(Vector<WindLogType>& windLogVector);

    /**
    * @brief Get the option one of the menu.
    *
    * This member function allows retrieving the menu of option four from the menu.
    *
    * @param windLogVector The vector that holds the data from the read csv file.
    */
    static void OptionFour(Vector<WindLogType>& windLogVector);
};

#endif // MENU_H_INCLUDED
