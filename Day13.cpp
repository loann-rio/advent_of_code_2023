#include "Day13.h"

void Day13::Part1()
{
    vector<vector<string>> inputs = readData();
    int result = 0;

    for (vector<string> val : inputs)
    {

        vector<int> numValsVert;
        vector<int> numValsHor;
        for (size_t index = 0; index < val.size(); index++)
        {
            numValsVert.push_back(binaryStringToInt(val[index]));
        }

        for (size_t index = 0; index < val[0].size(); index++)
        {
            string newVal = "";
            for (size_t j = 0; j < val.size(); j++)
            {
                newVal += val[j][index];
            }
            numValsHor.push_back(binaryStringToInt(newVal));
        }

        result += 100 * findReflection(numValsVert);
        result += findReflection(numValsHor);

    }
    cout << result << endl;
}

void Day13::Part2()
{
    vector<vector<string>> inputs = readData();

    for (vector<string> val : inputs)
    {
    }
}

// 17232

int Day13::findReflection(vector<int> vals)
{
    for (size_t index = 0; index < vals.size()-1; index++)
    {
        if (vals[index] == vals[index + 1])
        {
            bool valid = true;
            for (size_t i = 1; i < min(index+1, vals.size() - index -1); i++)
            {
                //cout << index << " " << i << "\n ";cout << vals[index - i] << " " << vals[index + 1 + i] << endl;
                if (vals[index - i] != vals[index + 1 + i])
                {
                    valid = false;
                    break;
                }
            }
            if (valid)
            {
                return index + 1;

            }
        }
    }
    return 0;
}


















int Day13::binaryStringToInt(const std::string& binaryString) {
    int result = 0;

    for (char c : binaryString) {
        // Shift the result to the left and add the current bit
        result = (result << 1) | (c == '#' ? 1 : 0);
    }

    return result;
}




vector<vector<string>> Day13::readData()
{
    fstream inputs;
    vector<vector<string>> result;
    vector<string> block;

    inputs.open("Day13.txt", ios::in);
    if (inputs.is_open())
    {
        string tp;
        while (getline(inputs, tp)) { //read data from file object and put it into string.
            if (tp == "")
            {
                result.push_back(vector<string>(block));
                block.clear();
            }
            else
            {
                block.push_back(tp);
            }
                

        }
        result.push_back(vector<string>(block));
        inputs.close(); //close the file object.
    }
    return result;
}

vector<string> Day13::parseString(const string val, const char delimitation)
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
