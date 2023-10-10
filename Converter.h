/**
 * @file Converter.h
 * @brief Converter class definition.
 *
 * This file contains the definition of the Converter class.
 * The class allows calculating and converting the average wind speed, average air temperature, and the total solar radiation.
 *
 * @author Chan Kok Wai ( Student Number: 33924804 )
 * @version 1.0
 */

#ifndef CONVERTER_H_INCLUDED
#define CONVERTER_H_INCLUDED

class Converter
{
public:

    /**
    * @brief Get the average wind speed.
    *
    * This member function allows calculating and converting the average wind speed.
    *
    * @return A float data type of the converted average wind speed.
    */
    const float GetAverageWindSpeed(float sum, unsigned count);

    /**
    * @brief Get the average air temperature.
    *
    * This member function allows calculating the average air temperature.
    *
    * @return A float data type of the average air temperature.
    */
    const float GetAverageAirTemperature(float sum, unsigned count);

    /**
    * @brief Get the total sum of solar radiation.
    *
    * This member function allows calculating and converting the total sum of the solar radiation.
    *
    * @return A float data type of the converted total sum of the solar radiation.
    */
    const float GetSolarRadiationTotal(float sum);
};

#endif // CONVERTER_H_INCLUDED
