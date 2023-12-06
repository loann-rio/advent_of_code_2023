#include "Day5.h"

vector<vector<vector<__int64>>> Day5::parseInput(vector<string> inputs)
{
    vector<vector<vector<__int64>>> results;
    results.push_back(vector<vector<__int64>>());
    bool inTable = true;
    int tableId = 0;
    for (string row : inputs)
    {

        if (numbers.find(row[0]) != std::string::npos)
        {
            vector<__int64> r;
            for (string va : parseString(row, ' ')) 
            { 
                stringstream strm(va);
                __int64 x;
                strm >> x;
                r.push_back(x); 
            } // non
            results[tableId].push_back(r);
            inTable = true;
            
            
        }
        else if (inTable){
            results.push_back(vector<vector<__int64>>());
            tableId++;
            inTable = false;
        }
    }

    return results;
}

void Day5::Part1()
{
    vector<string> inputs = readData();
    vector<vector<vector<__int64>>> tables = parseInput(inputs);
    for (__int64& val : newInputVal)
    {
        for (vector<vector<__int64>> table : tables)
        {
            for (vector<__int64> row : table)
            {
                if (val >= row[1] && val < row[1] + row[2])
                {
                    val = row[0] + val - row[1];
                    break;
                }
            }

        }
    }
    int minNb = 100000000000;
    for (__int64 val : newInputVal)
    {
        if (val < minNb)    
            minNb = (int) val;
    }

    cout << minNb << endl;
}
















void Day5::Part2()
{
    vector<string> inputs = readData();

    for (string val : inputs)
    {
        cout << val << endl;
    }
}

vector<string> Day5::parseString(const string val, const char delimitation)
{
    vector<string> result;
    cout << val << endl;
    string currentVal = "";
    for (char c : val) {
        if (c == delimitation) {
            if (currentVal != "") {
                result.push_back(currentVal);
            }
            currentVal = "";
        }
        else {
            currentVal += c;
        }
    }
    result.push_back(currentVal);
    return result;
}























vector<string> Day5::readData()
{
    fstream inputs;
    vector<string> result;

    inputs.open("Day5.txt", ios::in);
    if (inputs.is_open())
    {
        string tp;
        while (getline(inputs, tp)) { //read data from file object and put it into string.
            result.push_back(tp);
        }
        inputs.close(); //close the file object.
    }
    return result;
}
