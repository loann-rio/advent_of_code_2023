#include "Day9.h"

void Day9::Part1()
{
    vector<vector<int>> inputs = readData();
    int result = 0;

    for (vector<int> val : inputs)
    {
        vector<vector<int>> results;
        results.push_back(val);
        int i = 0;

        while (std::adjacent_find(results[i].begin(), results[i].end(), std::not_equal_to<int>()) != results[i].end())
        {
            results.push_back(vector<int>());

            for (size_t ind = 0; ind < results[i].size() - 1; ind++)
            {
                results[i + 1].push_back(results[i][ind + 1] - results[i][ind]);
            }
            i++;
        }


        for (vector<int> e : results)
        {
            result += e[e.size() - 1];
            //cout << e[e.size() - 1] << endl;
        }
        
    }

    cout << result << endl;
}




void Day9::Part2()
{
    vector<vector<int>> inputs = readData();
    int result = 0;

    for (vector<int> val : inputs)
    {
        vector<vector<int>> results;
        results.push_back(val);
        int i = 0;

        while (std::adjacent_find(results[i].begin(), results[i].end(), std::not_equal_to<int>()) != results[i].end())
        {
            results.push_back(vector<int>());

            for (size_t ind = 0; ind < results[i].size() - 1; ind++)
            {
                results[i + 1].push_back(results[i][ind + 1] - results[i][ind]);
            }
            i++;
        }

        i = 0;
        for (vector<int> e : results)
        {
            cout << e[0] << endl;
            if (i % 2 == 0)
            {
                result += e[0];
            }
            else
            {
                result -= e[0];
            }
            i++;
        }

    }

    cout << result << endl;

}























vector<vector<int>> Day9::readData()
{
    fstream inputs;
    vector<vector<int>> result;

    inputs.open("Day9.txt", ios::in);
    if (inputs.is_open())
    {
        string tp;
        while (getline(inputs, tp)) { //read data from file object and put it into string.
            
            result.push_back(parseString(tp, ' '));
        }
        inputs.close(); //close the file object.
    }
    return result;
}


vector<int> Day9::parseString(const string val, const char delimitation)
{
    vector<int> result;
    string currentVal = "";
    for (char c : val) {
        if (c == delimitation) {
            if (currentVal != "") {
                result.push_back(stoi(currentVal));
            }
            currentVal = "";
        }
        else {
            currentVal += c;
        }
    }
    result.push_back(stoi(currentVal));
    return result;
}
