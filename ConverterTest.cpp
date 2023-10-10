#include<iostream>
#include<string>
#include<fstream>

#include "Utils.h"
#include "Converter.h"

using namespace std;

int main()
{
    unsigned totalTest(0);
    unsigned testPassed(0);
    unsigned testFailed(0);

    string filename("report/ConverterTest.txt");
    ofstream ofs(filename);

    if(!ofs)
    {
        cerr << "Failed to open " << filename << " for writing windlogtype test report." << endl;
        return -1;
    }

    Utils utils;
    Converter converter;

    float averageWindSpeed(36.9);
    float averageAirTemperature(10.25);
    float totalSolarRadiation(2);

    cout << "Test on Converter Class" << '\n'
         << "1. Test on Converting Average wind speed" << endl;
    cout << "Actual: " << converter.GetAverageWindSpeed(20.5, 2) << " | " << "Expected: 36.9" <<  endl;
    ofs << "Test on Converter Class" << '\n'
        << "1. Test on Converting Average wind speed" << endl;
    ofs << "Actual: " << converter.GetAverageWindSpeed(20.5, 2) << " | " << "Expected: 36.9" <<  endl;
    utils.assert(converter.GetAverageWindSpeed(20.5, 2) == averageWindSpeed, "Average Speed Count as 36.9", "Average Wind Speed should be as 36.9", ofs, totalTest, testPassed, testFailed);
    cout << endl;
    ofs << endl;

    cout << "2. Test on Converting Average Air Temperature" << endl;
    cout << "Actual: " << converter.GetAverageAirTemperature(20.5, 2) << " | " << "Expected: 10.25" <<  endl;
    ofs << "Test on Converter Class" << '\n'
        << "2. Test on Converting Average Air Temperature"<< endl;
    ofs << "Actual: " << converter.GetAverageAirTemperature(20.5, 2) << " | " << "Expected: 10.25" <<  endl;
    utils.assert(converter.GetAverageAirTemperature(20.5, 2) == averageAirTemperature, "Average Air Temperature as 10.25", "Average Air Temperature should be as 10.25", ofs, totalTest, testPassed, testFailed);
    cout << endl;
    ofs << endl;

    cout << "3. Test on Converting Total sum for solar radiation" << endl;
    cout << "Actual: " << converter.GetSolarRadiationTotal(12000) << " | " << "Expected: 2" <<  endl;
    ofs << "Test on Converter Class" << '\n'
        <<  "3. Test on Converting Total sum for solar radiation" << endl;
    ofs << "Actual: " << converter.GetSolarRadiationTotal(12000) << " | " << "Expected: 2" <<  endl;
    utils.assert(converter.GetSolarRadiationTotal(12000) == totalSolarRadiation, "Total Solar Radiation as 2", "Total Solar Radiation should be as 2", ofs, totalTest, testPassed, testFailed);
    cout << endl;
    ofs << endl;

    ofs << endl << "All tests completed." << endl;
    totalTest = testPassed + testFailed;
    ofs   << "Total tests: " << totalTest << " | "
          << " Tests passed: " << testPassed << " | "
          << " Tests failed: " << testFailed << endl;

    ofs.close();

    return 0;
}
