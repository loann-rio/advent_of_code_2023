#include "Day15.h"
#include <map> 

void Day15::Part1()
{
    vector<string> inputs = readData();
    int result = 0;

    for (string val : inputs)
    {
        int ValResult = 0;
        for (const char& c : val)
            ValResult = ((ValResult + int(c)) * 17) % 256;
        result += ValResult;
    }
    cout << result << "\n";
}

void Day15::Part2()
{
    vector<string> inputs = readData();
    int result = 0;
    map<int, vector<tuple<string, int>>> boxes;

    for (string val : inputs)
    {

        // split inputs
        int ID = min(val.find('='), val.find('-'));
        bool isEqual = (val.find('=') == ID);

        int HashVal = 0;

        for (const char& c : val.substr(0, ID)) { HashVal = ((HashVal + int(c)) * 17) % 256; }

        if (isEqual)
        {
            if (boxes.find(HashVal) == boxes.end())
                boxes[HashVal] = vector<tuple<string, int>>();

            auto it = boxes[HashVal].begin();
            while (it != boxes[HashVal].end())
            {
                if (get<0>(*it) == val.substr(0, ID))
                {
                    (*it) = tuple<string, int>{ get<0>(*it), stoi(val.substr(ID + 1)) };
                    break;
                }
                it++;
            }
            if (it == boxes[HashVal].end())
                boxes[HashVal].push_back(tuple<string, int>{ val.substr(0, ID), stoi(val.substr(ID+1)) });
        }
        else
        {
            if (boxes.find(HashVal) != boxes.end())
            {
                auto it = boxes[HashVal].begin();
                while (it != boxes[HashVal].end())
                {
                    if (get<0>(*it) == val.substr(0, ID))
                    {
                        boxes[HashVal].erase(it);
                        break;
                    }
                    it++;
                }
            }
        }
    }

    for (map<int, vector<tuple<string, int>>>::iterator iter = boxes.begin(); iter != boxes.end(); ++iter)
    {
        int k = iter->first;
        int index = 0;
        for (tuple<string, int> vals : iter->second)
        {
            index++;
            cout << "boxe : " << iter->first << " , val = " << get<0>(vals) << " " << get<1>(vals) << " result to : " << (k + 1) * index * get<1>(vals) << endl;
            result += (k + 1) * index * get<1>(vals);
        }
    }
    
    cout << "result = " << result << endl;

}






















vector<string> Day15::readData()
{
    fstream inputs;
    vector<string> result;
    string tempResult = "";

    inputs.open("Day15.txt", ios::in);

    if (inputs.is_open())
    {
        string tp;
        while (getline(inputs, tp)) { //read data from file object and put it into string.
            tempResult += tp;
        }
        inputs.close(); //close the file object.
    }

    return parseString(tempResult, ',');
}

vector<string> Day15::parseString(const string val, const char delimitation)
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
