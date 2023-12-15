#include "Day14.h"

void Day14::Part1()
{
    vector<string> inputs = readData();
    bool done = false;
    while (!done)
    {
        done = true;
        for (size_t indexY = 1; indexY < inputs.size(); indexY++)
        {
            for (size_t indexX = 0; indexX < inputs[0].size(); indexX++)
            {
                if (inputs[indexY][indexX] == 'O' && inputs[indexY - 1][indexX] == '.')
                {
                    inputs[indexY][indexX] = '.';
                    inputs[indexY - 1][indexX] = 'O';
                    done = false;
                }
            }
        }
    }

    int result = 0;

    for (size_t indexY = 0; indexY < inputs.size(); indexY++)
    {
        //cout << inputs[indexY] << endl;
        for (size_t indexX = 0; indexX < inputs[0].size(); indexX++)
        {
            //cout << inputs[indexY][indexX] << endl;
            if (inputs[indexY][indexX] == 'O')
            {
                result += inputs.size() - indexY;
                //cout << result << "\n";
            }
        }
    }

    cout << result << endl;
    
}

void Day14::Part2()
{
    vector<string> inputs = readData();

    for (string val : inputs)
    {
        cout << val << endl;
    }
}























vector<string> Day14::readData()
{
    fstream inputs;
    vector<string> result;

    inputs.open("Day14.txt", ios::in);
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

vector<string> Day14::parseString(const string val, const char delimitation)
{
    vector<string> result;
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
