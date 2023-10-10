#include "Converter.h"

const float Converter::GetAverageWindSpeed(float sum, unsigned count)
{
    float convertInAverage((sum / count) * 3.6);
    return convertInAverage;
}
const float Converter::GetAverageAirTemperature(float sum, unsigned count)
{
    return sum / count;
}

const float Converter::GetSolarRadiationTotal(float sum)
{
    float convertInSum(sum / 6000);
    return convertInSum;
}
