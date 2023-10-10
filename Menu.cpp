#include "Menu.h"

void Menu::RunMenu(Vector<WindLogType>& windLogVector)
{
    unsigned choice;

    cout << "[ System ] : Allocated Spaces: " << windLogVector.GetCapacity() << '\n'
         << "[ System ] : Used Spaces: " << windLogVector.GetUsed() << '\n';

    do
    {
        cout << "Below are the options available: " << endl;
        cout << "[ 1 ] : The average wind speed and average ambient air temperature for a specified month and year." << '\n'
             << "[ 2 ] : Average wind speed and average ambient air temperature for each month of a specified year." << '\n'
             << "[ 3 ] : Total solar radiation in kWh/m2 for each month of a specified year." << '\n'
             << "[ 4 ] : Output the average wind speed (km/h), average ambient air temperature, and total solar radiation in kWh/m2 for each month of a specified year." << '\n'
             << "[ 5 ] : Exit the program." << endl;

        cout << "\n[ ENTRY ] --> ";
        cin >> choice;
        cout << endl;

        switch (choice)
        {
        case 1:
            cout << "[ SELECTED ] : ==== OPTION ONE ====" << endl;
            OptionOne(windLogVector);
            break;
        case 2:
            cout << "[ SELECTED ] : ==== OPTION TWO ====" << endl;
            OptionTwo(windLogVector);
            break;
        case 3:
            cout << "[ SELECTED ] : ==== OPTION THREE ====" << endl;
            OptionThree(windLogVector);
            break;
        case 4:
            cout << "[ SELECTED ] : ==== OPTION FOUR ====" << endl;
            OptionFour(windLogVector);
            break;
        case 5:
            cout << "[ SELECTED ] : ==== OPTION FIVE ====" << endl;
            cout << "Exit the program" << endl;
            break;
        default:
            cout << "Invalid option. Please choose a valid option." << endl;
            break;
        }
    }
    while (choice != 5);
}

void Menu::OptionOne(Vector<WindLogType>& windLogVector)
{
    Utils utils;
    Converter converter;
    cout << "[Option 1] : Enter the specified month (e.g., 1 , 12): ";
    unsigned inputMonth;
    cin >> inputMonth;

    if (inputMonth < 1 || inputMonth > 12)
    {
        cout << "Invalid month. Please enter a month between 1 and 12." << endl;
        return;
    }

    cout << "[Option 1] : Enter the specified year (e.g., 2014, 2015): ";
    unsigned inputYear;
    cin >> inputYear;

    if (inputYear < 2014 || inputYear > 2016)
    {
        cout << "Invalid year. Please enter a year between 2014 and 2016." << endl;
        return;
    }

    float sumWindSpeed = 0.0;
    float sumTemperature = 0.0;
    unsigned count = 0;

    for (unsigned i = 0; i < windLogVector.GetUsed(); ++i)
    {
        WindLogType entry = windLogVector.GetValueByIndex(i);
        if (entry.GetDate().GetMonth() == inputMonth && entry.GetDate().GetYear() == inputYear)
        {
            sumWindSpeed += entry.GetWindSpeed();
            sumTemperature += entry.GetAirTemperature();
            count++;
        }
    }

    if (count > 0)
    {
        float averageWindSpeed = floorf(converter.GetAverageWindSpeed(sumWindSpeed, count) * 10 ) / 10;
        float averageTemperature = floorf(converter.GetAverageAirTemperature(sumTemperature, count) * 10) / 10;

        cout    << '\n' << "[ OUTPUT ] : " << utils.GetMonthInStr(inputMonth) << " " << inputYear << ": "
                << averageWindSpeed << " km/h, " << averageTemperature << " degrees C" << '\n' << endl;
    }
    else
    {
        cout << "No Data" << endl;
    }
}

void Menu::OptionTwo(Vector<WindLogType>& windLogVector)
{
    Utils utils;
    Converter converter;
    cout << "Option 2: Enter the specified year (e.g., 2014, 2015): ";
    unsigned inputYear;
    cin >> inputYear;

    if (inputYear < 2014 || inputYear > 2016)
    {
        cout << "Invalid year. Please enter a year between 2014 and 2016." << endl;
        return;
    }

    float monthlySumWindSpeed[12] = {0.0};
    float monthlySumTemperature[12] = {0.0};
    unsigned monthlyCount[12] = {0};

    for (unsigned i = 0; i < windLogVector.GetUsed(); ++i)
    {
        WindLogType entry = windLogVector.GetValueByIndex(i);
        if (entry.GetDate().GetYear() == inputYear)
        {
            unsigned month = entry.GetDate().GetMonth() - 1;
            monthlySumWindSpeed[month] += entry.GetWindSpeed();
            monthlySumTemperature[month] += entry.GetAirTemperature();
            monthlyCount[month]++;
        }
    }

    cout << '\n' << "[OUTPUT]" << '\n' << inputYear << endl;
    for (unsigned month = 0; month < 12; ++month)
    {
        if (monthlyCount[month] > 0)
        {
            float windSpeedSum = monthlySumWindSpeed[month];
            float temperatureSum = monthlySumTemperature[month];
            unsigned monthlyCountSum = monthlyCount[month];

            cout << (utils.GetMonthInStr(month + 1)) << ": " << floorf(converter.GetAverageWindSpeed(windSpeedSum, monthlyCountSum) * 10) / 10 << " km/h, "
                 << floorf(converter.GetAverageAirTemperature(temperatureSum, monthlyCountSum) * 10) / 10 << " degrees C" << endl;
        }
        else
        {
            cout << utils.GetMonthInStr(month + 1) << ": No Data" << endl;
        }
    }
    cout << endl;
}

void Menu::OptionThree(Vector<WindLogType>& windLogVector)
{
    Utils utils;
    Converter converter;
    cout << "Option 3: Enter the specified year (e.g., 2014, 2015): ";
    unsigned inputYear;
    cin >> inputYear;

    if (inputYear < 2014 || inputYear > 2016)
    {
        cout << "Invalid year. Please enter a year between 2014 and 2016." << endl;
        return;
    }

    float monthlyTotalSolarRadiation[12] = {0.0};
    unsigned monthlyCount[12] = {0};

    for (unsigned i = 0; i < windLogVector.GetUsed(); ++i)
    {
        WindLogType entry = windLogVector.GetValueByIndex(i);
        if (entry.GetDate().GetYear() == inputYear)
        {
            float solarRadiation = entry.GetSolarRadiation();
            unsigned month = entry.GetDate().GetMonth() -1;
            monthlyTotalSolarRadiation[month - 1] += solarRadiation;
            monthlyCount[month]++;
        }
    }

    cout << '\n' << "[OUTPUT]" << '\n' << inputYear << endl;
    for (unsigned month = 0; month < 12; ++month)
    {
        if (monthlyCount[month] > 0)
        {
            cout << utils.GetMonthInStr(month + 1) << ": "
                 << floorf(converter.GetSolarRadiationTotal(monthlyTotalSolarRadiation[month - 1]) * 10) / 10 << " kWh/m2" << endl;
        }
        else
        {
            cout << utils.GetMonthInStr(month + 1) << ": No Data" << endl;
        }
    }
    cout << endl;


}

void Menu::OptionFour(Vector<WindLogType>& windLogVector)
{
    // Prompt the user for the year
    cout << "Option 4: Enter the specified year (e.g., 2014, 2015): ";
    unsigned inputYear;
    cin >> inputYear;

    if (inputYear < 2014 || inputYear > 2016)
    {
        cout << "Invalid year. Please enter a year between 2014 and 2016." << endl;
        return;
    }

    // Create and open the CSV file for writing
    string filename = "WindTempSolar.csv"; // Specify the file name
    ofstream outputFile(filename); // Create an output file stream

    if (!outputFile)
    {
        cerr << "Failed to open " << filename << " for writing." << endl;
        return;
    }
    outputFile << "Month,Average Wind Speed (km/h),Average Ambient Air Temperature (°C),Total Solar Radiation (kWh/m2)" << endl;

    // Array to store total solar radiation for each month (initialize to zero)
    float monthlyTotalSolarRadiation[12] = {0.0};
    float monthlySumWindSpeed[12] = {0.0};
    float monthlySumTemperature[12] = {0.0};
    unsigned monthlyCount[12] = {0};
    Utils utils;
    Converter converter;

    for (unsigned i = 0; i < windLogVector.GetUsed(); ++i)
    {
        WindLogType entry = windLogVector.GetValueByIndex(i);
        if (entry.GetDate().GetYear() == inputYear)
        {
            float solarRadiation = entry.GetSolarRadiation();
            float windSpeed = entry.GetWindSpeed();
            float temperature = entry.GetAirTemperature();
            unsigned month = entry.GetDate().GetMonth() - 1;

            monthlySumWindSpeed[month] += windSpeed;
            monthlySumTemperature[month] += temperature;
            monthlyTotalSolarRadiation[month] += solarRadiation;
            monthlyCount[month]++;
        }
    }

    // Iterate through the months and write data to the CSV file
    for (unsigned month = 0; month < 12; ++month)
    {
        outputFile << utils.GetMonthInStr(month + 1) << ","
                   << (monthlyCount[month] > 0 ? (floorf(converter.GetAverageWindSpeed(monthlySumWindSpeed[month], monthlyCount[month]) * 10) / 10) : 0.0) << ","
                   << (monthlyCount[month] > 0 ? (floorf(converter.GetAverageAirTemperature(monthlySumTemperature[month], monthlyCount[month]) * 10) / 10) : 0.0) << ","
                   << floorf(converter.GetSolarRadiationTotal(monthlyTotalSolarRadiation[month]) * 10) / 10 << " kWh/m2" << endl;
    }

    // Close the CSV file
    outputFile.close();

    cout << "Data has been written to " << filename << endl;
    cout << endl;
}

