#include<iostream>
#include<fstream>

using namespace std;

#include "WindLogType.h"
#include "Vector.h"
#include "DataReader.h"
#include "Menu.h"

const string FILENAME("data/MetData_Mar01-2014-Mar01-2015-ALL.csv");
void DisplayItems(unsigned option);

int main()
{
    /* Initialize */
    Vector<WindLogType> windLogVector;
    DataReader dataReader(FILENAME);

    dataReader.ReadAppendData(windLogVector);

//========================================================================

    /* Run Application */
    Menu::RunMenu(windLogVector);

    return 0;
}
