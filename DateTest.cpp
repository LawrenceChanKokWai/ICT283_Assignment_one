#include<iostream>

#include "Date.h"
#include "Utils.h"

using namespace std;

int main()
{
    unsigned totalTest(0);
    unsigned testPassed(0);
    unsigned testFailed(0);

    string filename("report/DateTest.txt");
    ofstream ofs(filename);

    if(!ofs)
    {
        cerr << "Failed to open " << filename << " for writing date test report." << endl;
        return -1;
    }

    Utils utils;
    Date defaultDate;
    Date testDataDate(0,0,0);

    ofs << "Test on Date Class" << '\n'
        << "1. Test on Default Constructor output stream" << endl;
    ofs << "Actual: " << defaultDate << " | " << "Expected: " << testDataDate << endl;
    cout << "Test on Date Class" << '\n'
         << "1. Test on Default Constructor output stream" << endl;
    cout << "Actual: " << defaultDate << " | " << "Expected: " << testDataDate << endl;
    utils.assert(defaultDate.GetDay() == 0, "Default Constructor Day set as 0", "Default Constructor Day should be set as 0", ofs, totalTest, testPassed, testFailed);
    utils.assert(defaultDate.GetMonth() == 0, "Default Constructor Month set as 0", "Default Constructor Month should be set as 0", ofs, totalTest, testPassed, testFailed);
    utils.assert(defaultDate.GetYear() == 0, "Default Constructor Year set as 0", "Default Constructor Year should be set as 0", ofs, totalTest, testPassed, testFailed);
    cout << endl;
    ofs << endl;

    defaultDate.SetDay(21);
    defaultDate.SetMonth(7);
    defaultDate.SetYear(2020);
    ofs << "2. Test Setters on Setting day" << endl;
    ofs << "Actual: " << defaultDate.GetDay() << " | " << "Expected: " << "21" << endl;
    cout << "2. Test Setters on Setting day" << endl;
    cout << "Actual: " << defaultDate.GetDay() << " | " << "Expected: " << "21" << endl;
    utils.assert(defaultDate.GetDay() == 21, "Date day has been set to 21", "Date day should be set to 21", ofs, totalTest, testPassed, testFailed);
    cout << endl;
    ofs << endl;

    ofs << "3. Test Setters on Setting month" << endl;
    ofs << "Actual: " << defaultDate.GetMonth() << " | " << "Expected: " << "7" << endl;
    cout << "3. Test Setters on Setting month" << endl;
    cout << "Actual: " << defaultDate.GetMonth() << " | " << "Expected: " << "7" << endl;
    utils.assert(defaultDate.GetMonth() == 7, "Date month has been set to 7", "Date month should be set to 7", ofs, totalTest, testPassed, testFailed);
    cout << endl;
    ofs << endl;

    ofs << "4. Test Setters on Setting year" << endl;
    ofs << "Actual: " << defaultDate.GetYear() << " | " << "Expected: " << "2020" << endl;
    cout << "4. Test Setters on Setting year" << endl;
    cout << "Actual: " << defaultDate.GetYear() << " | " << "Expected: " << "2020" << endl;
    utils.assert(defaultDate.GetYear() == 2020, "Date year has been set to 2020", "Date year should be set to 2020", ofs, totalTest, testPassed, testFailed);
    cout << endl;
    ofs << endl;


    ofs << "5. Test Converting Numeric Month to string in month" << endl;
    ofs << "Actual: " << utils.GetMonthInStr(defaultDate.GetMonth()) << " | " << "Expected: " << "July" << endl;
    cout << "5. Test Converting Numeric Month to string in month" << endl;
    cout << "Actual: " << utils.GetMonthInStr(defaultDate.GetMonth()) << " | " << "Expected: " << "July" << endl;
    utils.assert(utils.GetMonthInStr(defaultDate.GetMonth()) == "July",
                 "Date month in string converted to July",
                 "Date month in string should be set in string converted to July", ofs, totalTest, testPassed, testFailed);
    ofs << endl;


    ofs << endl << "All tests completed." << endl;
    totalTest = testPassed + testFailed;
    ofs   << "Total tests: " << totalTest << " | "
          << " Tests passed: " << testPassed << " | "
          << " Tests failed: " << testFailed << endl;

    ofs.close();

    return 0;
}
