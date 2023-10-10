#include<iostream>
#include<fstream>

#include "WindLogType.h"
#include "Utils.h"

using namespace std;

int main()
{
    unsigned totalTest(0);
    unsigned testPassed(0);
    unsigned testFailed(0);

    string filename("report/WindLogTypeTest.txt");
    ofstream ofs(filename);

    if(!ofs)
    {
        cerr << "Failed to open " << filename << " for writing windlogtype test report." << endl;
        return -1;
    }

    Utils utils;
    WindLogType defaultWindLogType;
    WindLogType testWindLogType();

    ofs << "Test on WindLogType Class" << '\n'
        << "1. Test on Default Constructor output stream" << endl;
    ofs << "Actual: " << defaultWindLogType << " | " << "Expected: Date: 0/0/0 Time: 0:00 0 0 0" <<  endl;

    cout << "Test on WindLogType Class" << '\n'
         << "1. Test on Default Constructor output stream" << endl;
    cout << "Actual: " << defaultWindLogType << " | " << "Expected: Date: 0/0/0 Time: 0:00 0 0 0" <<  endl;
    utils.assert(defaultWindLogType.GetDate().GetDay() == 0, "Default Constructor Date class Day set as 0", "Default Constructor Date class Day should be set as 0", ofs, totalTest, testPassed, testFailed);
    utils.assert(defaultWindLogType.GetDate().GetMonth() == 0, "Default Constructor Date class Month set as 0", "Default Constructor Date class Month should be set as 0", ofs, totalTest, testPassed, testFailed);
    utils.assert(defaultWindLogType.GetDate().GetYear() == 0, "Default Constructor Date class Year set as 0", "Default Constructor Date class Year should be set as 0", ofs, totalTest, testPassed, testFailed);
    utils.assert(defaultWindLogType.GetTime().GetHour() == "0", "Default Constructor Time class Hour set as 0", "Default Constructor Time class Hour should be set as 0", ofs, totalTest, testPassed, testFailed);
    utils.assert(defaultWindLogType.GetTime().GetMinute() == "00", "Default Constructor Time class Minute set as 00", "Default Constructor Time class Minute should be set as 00", ofs, totalTest, testPassed, testFailed);
    utils.assert(defaultWindLogType.GetWindSpeed() == 0, "Default Constructor wind speed set as 0", "Default Constructor wind speed should be set as 0", ofs, totalTest, testPassed, testFailed);
    utils.assert(defaultWindLogType.GetAirTemperature() == 0, "Default Constructor air temperature set as 0", "Default Constructor air temperature should be set as 0", ofs, totalTest, testPassed, testFailed);
    utils.assert(defaultWindLogType.GetSolarRadiation() == 0, "Default Constructor solar radiation set as 0", "Default Constructor solar radiation should be set as 0", ofs, totalTest, testPassed, testFailed);
    ofs << endl;
    cout << endl;

    unsigned day(11);
    unsigned month(12);
    unsigned year(2020);
    Date setDate(day, month, year);
    defaultWindLogType.SetDate(setDate);
    ofs << "2. Test Setters on Date object" << endl;
    ofs << "Actual: " << setDate  << " | " << "Expected: " << "11/12/2020" << endl;
    cout << "2. Test Setters on Date object" << endl;
    cout << "Actual: " << setDate  << " | " << "Expected: " << "11/12/2020" << endl;
    utils.assert(defaultWindLogType.GetDate().GetDay() == day, "Date day is set to 11", "Date day should be set to 11", ofs, totalTest, testPassed, testFailed);
    utils.assert(defaultWindLogType.GetDate().GetMonth() == month, "Date month is set to 12", "Date month should be set to 12", ofs, totalTest, testPassed, testFailed);
    utils.assert(defaultWindLogType.GetDate().GetYear() == year, "Date year is set to 2020", "Date year should be set to 2020", ofs, totalTest, testPassed, testFailed);
    cout << endl;
    ofs << endl;

    string hours("11");
    string minutes("12");
    Time setTime(hours, minutes);
    defaultWindLogType.SetTime(setTime);
    ofs << "3. Test Setters on Time object" << endl;
    ofs << "Actual: " << setTime  << " | " << "Expected: " << "11:12" << endl;
    cout << "3. Test Setters on Time object" << endl;
    cout << "Actual: " << setTime  << " | " << "Expected: " << "11:12" << endl;
    utils.assert(defaultWindLogType.GetTime().GetHour() == hours, "Time hours is set to 11", "Time hours should be set to 11", ofs, totalTest, testPassed, testFailed);
    utils.assert(defaultWindLogType.GetTime().GetMinute() == minutes, "Time minutes is set to 12", "Time minutes should be set to 12", ofs, totalTest, testPassed, testFailed);
    cout << endl;
    ofs << endl;

    float windSpeed(29.1);
    defaultWindLogType.SetWindSpeed(29.1);
    ofs << "4. Test Setters on Wind Speed" << endl;
    ofs << "Actual: " <<  defaultWindLogType.GetWindSpeed() << " | " << "Expected: " << "29.1" << endl;
    cout << "4. Test Setters on Wind Speed" << endl;
    cout << "Actual: " <<  defaultWindLogType.GetWindSpeed() << " | " << "Expected: " << "29.1" << endl;
    utils.assert(defaultWindLogType.GetWindSpeed() == windSpeed, "Wind Speed is set to 29.1", "Wind Speed should be set to 29.1", ofs, totalTest, testPassed, testFailed);
    cout << endl;
    ofs << endl;

    float airTemp(32.3);
    defaultWindLogType.SetAirTemperature(32.3);
    ofs << "5. Test Setters on Air Temperature" << endl;
    ofs << "Actual: " <<  defaultWindLogType.GetAirTemperature() << " | " << "Expected: " << "32.3" << endl;
    cout << "5. Test Setters on Air Temperature" << endl;
    cout << "Actual: " <<  defaultWindLogType.GetAirTemperature() << " | " << "Expected: " << "32.3" << endl;
    utils.assert(defaultWindLogType.GetAirTemperature() == airTemp, "Air Temperature is set to 32.3", "Air Temperature should be set to 32.3", ofs, totalTest, testPassed, testFailed);
    cout << endl;
    ofs << endl;

    float solarRadiation(43.1);
    defaultWindLogType.SetSolarRadiation(43.1);
    ofs << "6. Test Setters on Solar Radiation" << endl;
    ofs << "Actual: " <<  defaultWindLogType.GetSolarRadiation() << " | " << "Expected: " << "43.1" << endl;
    cout << "6. Test Setters on Solar Radiation" << endl;
    cout << "Actual: " <<  defaultWindLogType.GetSolarRadiation() << " | " << "Expected: " << "43.1" << endl;
    utils.assert(defaultWindLogType.GetSolarRadiation() == solarRadiation, "Solar Radiation is set to 43.1", "Solar Radiation should be set to 43.1", ofs, totalTest, testPassed, testFailed);
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
