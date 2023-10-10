#include "Utils.h"

string Utils::GetMonthInStr(const unsigned &month) const
{
    string monthInStr;
    switch(month)
    {
    case 1:
        monthInStr = "January";
        break;
        case 2:
        monthInStr = "February";
        break;
        case 3:
        monthInStr = "March";
        break;
        case 4:
        monthInStr = "April";
        break;
        case 5:
        monthInStr = "May";
        break;
        case 6:
        monthInStr = "June";
        break;
        case 7:
        monthInStr = "July";
        break;
        case 8:
        monthInStr = "August";
        break;
        case 9:
        monthInStr = "September";
        break;
        case 10:
        monthInStr = "October";
        break;
        case 11:
        monthInStr = "November";
        break;
        case 12:
        monthInStr = "December";
        break;
        default:
            monthInStr = "";
            break;
    }
    return monthInStr;
}

/* Use for tests */
void Utils::assert(bool condition, string passMsg, string failMsg, ostream& output, unsigned &totalTest, unsigned &testPassed, unsigned &testFailed)
{
    if(condition)
    {
        cout << "[ PASS ] : " << passMsg << endl;
        output << "[ PASS ] : " << passMsg << endl;
        testPassed ++;
    }
    else
    {
        cout << "[ FAIL ] : " << failMsg << endl;
        output << "[ FAIL ] : " << failMsg << endl;
        testFailed ++;
    }
}
