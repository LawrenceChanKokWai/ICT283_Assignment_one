#include<iostream>
#include<fstream>
#include<typeinfo>
#include<string>

#include "Vector.h"
#include "Date.h"
#include "Time.h"
#include "WindLogType.h"
#include "Utils.h"

using namespace std;

int main()
{
    unsigned totalTest(0);
    unsigned testPassed(0);
    unsigned testFailed(0);

    string filename("report/VectorTest.txt");
    ofstream ofs(filename);

    if(!ofs)
    {
        cerr << "Failed to open " << filename << " for writing time test report." << endl;
        return -1;
    }

    Utils utils;
    Vector<unsigned> unsignedVec;
    Vector<string> stringVec;
    Vector<Date> dateVec;
    Vector<Time> timeVec;
    Vector<WindLogType> windLogVec;


    ofs << "Test on Vector Class" << '\n'
        << "1. Test on Default Constructor <unsigned data type>" << endl;
    cout << "Test on Vector Class" << '\n'
         << "1. Test on Default Constructor <unsigned data type>" << endl;
    utils.assert(typeid(unsignedVec).name() == typeid(Vector<unsigned>).name(),
                 "unsignedVec is of type Vector<unsigned>", "unsignedVec should be of type Vector<unsigned>",
                 ofs, totalTest, testPassed, testFailed);
    cout << endl;
    ofs << endl;

    ofs << "2. Test on Default Constructor <string data type>" << endl;
    cout << "2. Test on Default Constructor <string data type>" << endl;
    utils.assert(typeid(stringVec).name() == typeid(Vector<string>).name(),
                 "stringVec is of type Vector<string>", "stringVec should be of type Vector<string>",
                 ofs, totalTest, testPassed, testFailed);
    cout << endl;
    ofs << endl;

    ofs << "3. Test on Default Constructor <Date object type>" << endl;
    cout << "3. Test on Default Constructor <Date object type>" << endl;
    utils.assert(typeid(dateVec).name() == typeid(Vector<Date>).name(),
                 "dateVec is of type Vector<Date>", "dateVec should be of type Vector<Date>",
                 ofs, totalTest, testPassed, testFailed);
    cout << endl;
    ofs << endl;

    ofs << "4. Test on Default Constructor <Time object type>" << endl;
    cout << "4. Test on Default Constructor <Time object type>" << endl;
    utils.assert(typeid(timeVec).name() == typeid(Vector<Time>).name(),
                 "timeVec is of type Vector<Time>", "timeVec should be of type Vector<Time>",
                 ofs, totalTest, testPassed, testFailed);
    cout << endl;
    ofs << endl;

    ofs << "5. Test on Default Constructor <WindLogType object type>" << endl;
    cout << "5. Test on Default Constructor <WindLogType object type>" << endl;
    utils.assert(typeid(windLogVec).name() == typeid(Vector<WindLogType>).name(),
                 "windLogVec is of type Vector<Date>", "windLogVec should be of type Vector<WindLogType>",
                 ofs, totalTest, testPassed, testFailed);
    cout << endl;
    ofs << endl;

    ofs << "6. Test on Default Constructor member variables (Capacity)" << endl;
    cout << "6. Test on Default Constructor member variables (Capacity)"  << endl;
    utils.assert(unsignedVec.GetCapacity() == 2,
                 "Default constructed vector capacity at 2", "Default constructed vector capacity should be at 2",
                 ofs, totalTest, testPassed, testFailed);
    cout << endl;
    ofs << endl;

    ofs << "7. Test on Default Constructor member variables (Used Slot)" << endl;
    cout << "7. Test on Default Constructor member variables (Used Slot)"  << endl;
    utils.assert(unsignedVec.GetUsed() == 0,
                 "Default constructed vector used slot at 0", "Default constructed vector used slot should be at 0",
                 ofs, totalTest, testPassed, testFailed);
    cout << endl;
    ofs << endl;

    ofs << "8. Test on Default Constructor member variables (array pointer)" << endl;
    cout << "8. Test on Default Constructor member variables (array pointer)"  << endl;
    utils.assert(unsignedVec.GetArray() != nullptr,
                 "Default constructed vector array pointer not pointing to nullptr", "Default constructed vector array pointer should not be at nullptr",
                 ofs, totalTest, testPassed, testFailed);
    cout << endl;
    ofs << endl;

    ofs << "9. Test on Adding unsigned value to unsignedVec" << endl;
    cout <<"9. Test on Adding unsigned value to unsignedVec"  << endl;
    utils.assert(unsignedVec.Append(12) == true,
                 "unsigned Vector return true after added value 12", "unsigned Vector should be returning true after added value 12",
                 ofs, totalTest, testPassed, testFailed);
    cout << endl;
    ofs << endl;

    ofs << "10. Test on Getting value by index on unsignedVec" << endl;
    cout <<"10. Test on Getting value by index on unsignedVec"  << endl;
    utils.assert(unsignedVec.GetValueByIndex(0) == 12,
                 "unsigned Vector contains value 12 at index 0", "unsigned Vector should contain value 12 at index 0",
                 ofs, totalTest, testPassed, testFailed);
    cout << endl;
    ofs << endl;

    Vector<unsigned> anotherUnsignedVec(unsignedVec);
    ofs << "11. Test on passing unsignedVec into a Copy Constructor" << endl;
    cout << "11. Test on passing unsignedVec into a Copy Constructor"  << endl;
    utils.assert(anotherUnsignedVec.GetCapacity() == unsignedVec.GetCapacity(),
                 "anotherUnsignedVec's capacity has been deep copied from referencing unsignedVec",
                 "anotherUnsignedVec's capacity should have been deep copied from referencing unsignedVec",
                 ofs, totalTest, testPassed, testFailed);
    utils.assert(anotherUnsignedVec.GetUsed() == unsignedVec.GetUsed(),
                 "anotherUnsignedVec's used slot has been deep copied from referencing unsignedVec",
                 "anotherUnsignedVec's used slot should have been deep copied from referencing unsignedVec",
                 ofs, totalTest, testPassed, testFailed);
    utils.assert(anotherUnsignedVec.GetArray() != unsignedVec.GetArray(),
                 "anotherUnsignedVec's has a different address pointer as unsignedVec",
                 "anotherUnsignedVec's should have a different address pointer as unsignedVec",
                 ofs, totalTest, testPassed, testFailed);
    utils.assert(anotherUnsignedVec.GetValueByIndex(0) == unsignedVec.GetValueByIndex(0),
                 "anotherUnsignedVec's has the same value at index 0 been copied from unsignedVec",
                 "anotherUnsignedVec's should have the same value at index 0 been copied from unsignedVec",
                 ofs, totalTest, testPassed, testFailed);
    utils.assert(&anotherUnsignedVec.GetValueByIndex(0) != &unsignedVec.GetValueByIndex(0),
                 "anotherUnsignedVec's has the same value at index 0  as unsignedVec, with a different address storing the value",
                 "anotherUnsignedVec's should have the same value at index 0 as unsignedVecm with a different address storing the value",
                 ofs, totalTest, testPassed, testFailed);
    cout << endl;
    ofs << endl;

    Vector<unsigned> thirdUnsignedVec;
    thirdUnsignedVec = unsignedVec;
    ofs << "12. Test on Overload equals operator with unsignedVector been set equals to thirdUnsignedVector" << endl;
    cout << "12. Test on Overload equals operator with unsignedVector been set equals to thirdUnsignedVector"  << endl;
    utils.assert(thirdUnsignedVec.GetCapacity() == unsignedVec.GetCapacity(),
                 "thirdUnsignedVector's capacity has been deep copied by using overload equals operator been set with unsignedVec",
                 "thirdUnsignedVector's capacity should have been deep copied by using overload equals operator been set with unsignedVec",
                 ofs, totalTest, testPassed, testFailed);
    utils.assert(thirdUnsignedVec.GetUsed() == unsignedVec.GetUsed(),
                 "thirdUnsignedVector's used slot has been deep copied by using overload equals operator been set with unsignedVec",
                 "thirdUnsignedVector's used slot should have been deep copied by using overload equals operator been set with unsignedVec",
                 ofs, totalTest, testPassed, testFailed);
    utils.assert(thirdUnsignedVec.GetArray() != unsignedVec.GetArray(),
                 "thirdUnsignedVec's has a different address pointer as unsignedVec",
                 "thirdUnsignedVec's should have a different address pointer as unsignedVec",
                 ofs, totalTest, testPassed, testFailed);
    utils.assert(thirdUnsignedVec.GetValueByIndex(0) == unsignedVec.GetValueByIndex(0),
                 "thirdUnsignedVector's value at index 0 has been deep copied with unsignedVec",
                 "thirdUnsignedVector's value at index 0 should have been deep copied with unsignedVec",
                 ofs, totalTest, testPassed, testFailed);
    utils.assert(&thirdUnsignedVec.GetValueByIndex(0) != &unsignedVec.GetValueByIndex(0),
                 "thirdUnsignedVector's has the same value at index 0  as unsignedVec, with a different address storing the value",
                 "thirdUnsignedVector's should have the same value at index 0  as unsignedVec, with a different address storing the value",
                 ofs, totalTest, testPassed, testFailed);
    cout << endl;
    ofs << endl;

    Vector<unsigned>scenarioVec;
    cout << "13: Scenario Test, [Adding 2 elements into the dynamic array]" << endl;
    ofs << "13: Scenario Test, [Adding 2 elements into the dynamic array]" << endl;
    scenarioVec.Append(1);
    scenarioVec.Append(2);
    utils.assert(scenarioVec.GetCapacity() == 4, "Space has been allocated to 4 spaces after adding 2 elements", "Space should have been allocated to 4 spaces after adding 2 elements", ofs, totalTest, testPassed, testFailed);
    utils.assert(scenarioVec.GetUsed() == 2, "Space used is 2 after adding 2 elements", "Space should have used is 2 after adding 2 elements", ofs, totalTest, testPassed, testFailed);
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
