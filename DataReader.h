/**
 * @file DataReader.h
 * @brief DataReader class definition.
 *
 * This file contains the definition of the DataReader class.
 * The class allows reading the data from a csv file.
 * It also append the read data into a vector.
 *
 * @author Chan Kok Wai ( Student Number: 33924804 )
 * @version 1.0
 */

#ifndef DATAREADER_H_INCLUDED
#define DATAREADER_H_INCLUDED

#include<fstream>

#include "Vector.h"
#include "WindLogType.h"

using namespace std;

class DataReader
{
public:

    /**
    * @brief Parameterized constructor for DataReader class.
    *
    * @param filename The filename or path of the file that will be used to be read.
    */
    DataReader(const string &filename);

    /**
    * @brief Reads and append the data into the WindLogType data type.
    *
    * This member function allows reading the data from a csv file and append the data into the WindLogType vector.
    *
    * @return A boolean of true or false if the data has been successfully appended into the WindLogType vector.
    */
    bool ReadAppendData(Vector<WindLogType> &windlogVector);

private:
    string m_filename;
};

#endif // DATAREADER_H_INCLUDED
