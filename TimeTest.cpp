#include<iostream>
#include<fstream>

#include "Time.h"
#include "Utils.h"

using namespace std;

int main()
{
    unsigned totalTest(0);
    unsigned testPassed(0);
    unsigned testFailed(0);

    string filename("report/TimeTest.txt");
    ofstream ofs(filename);

    if(!ofs)
    {
        cerr << "Failed to open " << filename << " for writing time test report." << endl;
        return -1;
    }

    Utils utils;
    Time defaultTime;
    Time testDataTime("0", "00");

    ofs << "Test on Time Class" << '\n'
        << "1. Test on Default Constructor output stream" << endl;
    cout << "Test on Time Class" << '\n'
         << "1. Test on Default Constructor output stream" << endl;
    cout << "Actual: " << defaultTime << " | " << "Expected: " << testDataTime << endl;
    ofs << "Actual: " << defaultTime << " | " << "Expected: " << testDataTime << endl;
    utils.assert(defaultTime.GetHour() == "0", "Default Constructor Time hour set as 0", "Default Constructor Time hour should be set as 0", ofs, totalTest, testPassed, testFailed);
    utils.assert(defaultTime.GetMinute() == "00", "Default Constructor Time minute set as 00", "Default Constructor Time minute should be set as 00", ofs, totalTest, testPassed, testFailed);
    cout << endl;
    ofs << endl;

    defaultTime.SetHour("12");
    defaultTime.SetMinute("22");
    ofs << "2. Test Setters on Setting hour" << endl;
    ofs << "Actual: " << defaultTime.GetHour() << " | " << "Expected: " << "12" << endl;
    cout << "2. Test Setters on Setting hour" << endl;
    cout << "Actual: " << defaultTime.GetHour() << " | " << "Expected: " << "12" << endl;
    utils.assert(defaultTime.GetHour() == "12", "Time hour has been set to 12", "Time hour should be set to 12", ofs, totalTest, testPassed, testFailed);
    cout << endl;
    ofs << endl;

    ofs << "3. Test Setters on Setting minutes" << endl;
    ofs << "Actual: " << defaultTime.GetMinute() << " | " << "Expected: " << "22" << endl;
    cout << "3. Test Setters on Setting minutes" << endl;
    cout << "Actual: " << defaultTime.GetMinute() << " | " << "Expected: " << "22" << endl;
    utils.assert(defaultTime.GetMinute() == "22", "Time minutes has been set to 22", "Time minutes should be set to 22", ofs, totalTest, testPassed, testFailed);
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
