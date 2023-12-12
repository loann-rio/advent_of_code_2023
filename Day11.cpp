#include "Day11.h"

void Day11::Part1()
{
    vector<vector<int>> inputs = readData();

    sort(inputs.begin(), inputs.end(), [](const vector<int>& lhs, const vector<int>& rhs)
        {     return lhs[0] < rhs[0];    });
    int space = 0;
    for (size_t i = 1; i < inputs.size(); i++)
    {
        if (inputs[i][0] - inputs[i - 1][0] + space > 1)
            space++;
        inputs[i][0] += space;
    }

    sort(inputs.begin(), inputs.end(), [](const vector<int>& lhs, const vector<int>& rhs)
        {     return lhs[1] < rhs[1];    });
    space = 0;
    for (size_t i = 1; i < inputs.size(); i++)
    {
        if (inputs[i][1] - inputs[i - 1][1] + space > 1)
            space++;
        inputs[i][1] += space;
    }
    
    int results = 0;
    for (size_t i = 0; i < inputs.size(); i++)
    {
        for (size_t j = i; j < inputs.size(); j++)
        {
            int dist = abs(inputs[j][0] - inputs[i][0]) + abs(inputs[j][1] - inputs[i][1]);
            results += dist;        }
    }

    cout << results << endl;
}

void Day11::Part2()
{
    vector<vector<int>> inputs1 = readData();
    std::vector<std::vector<__int64>> inputs;

    for (const auto& innerVec : inputs1) {
        vector<__int64> convertedInnerVec(innerVec.begin(), innerVec.end());
        inputs.push_back(convertedInnerVec);
    }

    sort(inputs.begin(), inputs.end(), [](const vector<__int64>& lhs, const vector<__int64>& rhs)
        {     return lhs[0] < rhs[0];    });
    __int64 space = 0;
    for (size_t i = 1; i < inputs.size(); i++)
    {
        if (inputs[i][0] - inputs[i - 1][0] + space > 1)
            space += 1000000-1 ;
        inputs[i][0] += space;
    }

    sort(inputs.begin(), inputs.end(), [](const vector<__int64>& lhs, const vector<__int64>& rhs)
        {     return lhs[1] < rhs[1];    });
    space = 0;
    for (size_t i = 1; i < inputs.size(); i++)
    {
        if (inputs[i][1] - inputs[i - 1][1] + space > 1)
            space += 1000000-1;
        inputs[i][1] += space;
    }

    __int64 results = 0;
    for (size_t i = 0; i < inputs.size(); i++)
    {
        for (size_t j = i; j < inputs.size(); j++)
        {
            __int64 dist = abs(inputs[j][0] - inputs[i][0]) + abs(inputs[j][1] - inputs[i][1]);
            results += dist;
        }
    }

    cout << results << endl;
}




















vector<vector<int>> Day11::readData()
{
    fstream inputs;
    vector<vector<int>> result;

    inputs.open("Day11.txt", ios::in);
    if (inputs.is_open())
    {
        string tp;
        int x = 0;
        while (getline(inputs, tp)) { //read data from file object and put it into string.
            int y = 0;
            for (const char& element : tp)
            {
                if (element == '#')
                {
                    result.push_back({ x, y });
                }
                y++;
            }
            x++;
        }
        inputs.close(); //close the file object.
    }
    return result;
}

vector<string> Day11::parseString(const string val, const char delimitation)
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
