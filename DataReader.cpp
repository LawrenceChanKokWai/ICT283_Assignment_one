#include "DataReader.h"

DataReader::DataReader(const string &filename)
{
    m_filename = filename;
}

bool DataReader::ReadAppendData(Vector<WindLogType> &windlogVector)
{
    WindLogType windlogType;
    ifstream inFile(m_filename);
    if(!inFile)
    {
        cerr << "ERROR: Opening File" << endl;
        return false;
    }
    string skipHeader;
    getline(inFile, skipHeader);
    while(inFile.peek() != EOF)
    {
        inFile >> windlogType;
        windlogVector.Append(windlogType);
    }
    return true;
}
