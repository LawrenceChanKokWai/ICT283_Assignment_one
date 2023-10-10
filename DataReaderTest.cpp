#include<iostream>
#include<string>
#include<fstream>

#include "Utils.h"
#include "WindLogType.h"
#include "Vector.h"
#include "DataReader.h"

using namespace std;

int main()
{
    unsigned totalTest(0);
    unsigned testPassed(0);
    unsigned testFailed(0);

    string filename("report/DataReaderTest.txt");
    ofstream ofs(filename);

    if(!ofs)
    {
        cerr << "Failed to open " << filename << " for writing windlogtype test report." << endl;
        return -1;
    }

    Utils utils;
    Vector<WindLogType>windlogVec;
    const string WRONG_FILENAME("abc.csv");
    const string RIGHT_FILENAME("data/MetData_Mar01-2014-Mar01-2015-ALL.csv");
    DataReader wrongDataReader(WRONG_FILENAME);
    DataReader rightDataReader(RIGHT_FILENAME);

    cout << "Test on DataReader Class" << '\n'
         << "1. Test on Failure loading and reading CSV with the wrong filename" << endl;
    ofs << "Test on DataReader Class" << '\n'
        << "1. Test on Failure loading and reading CSV with the wrong filename" << endl;
    utils.assert(wrongDataReader.ReadAppendData(windlogVec) == false, "File returns false on opening file", "File should returns false on opening file", ofs, totalTest, testPassed, testFailed);
    cout << endl;
    ofs << endl;


    cout << "2. Test on loading and reading CSV with the right filename" << endl;
    ofs << "2. Test on loading and reading CSV with the right filename" << endl;
    utils.assert(rightDataReader.ReadAppendData(windlogVec) == true, "File returns true on opening file", "File should returns true on opening file", ofs, totalTest, testPassed, testFailed);
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
