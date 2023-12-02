#include "Day1.h"

void Day1::Part1()
{
    vector<string> inputs = readData();

    int result = 0;
    for (string val : inputs)
    {
        int i;
        for (i = 0; i < val.size(); ++i) {
            if (int(val[i]) >= 48 && int(val[i]) < 58)
            { 
                result += (val[i] - '0') * 10;
                break;
            }
        }
        for (int j = val.size()-1; j >= i-1; --j) {
            if (int(val[j])>= 48 && int(val[j]) < 58) 
            { 
                result += (val[j] - '0'); 
                break; 
            }
        }
    }

    cout << result << endl;
}

void Day1::Part2()
{
    vector<string> nums = { "one", "two", "three", "four", "five", "six", "seven", "eight", "nine" };

    vector<string> inputs = readData();

    int result = 0;
    for (string val : inputs)
    {
        int i;
        bool done = false;
        for (i = 0; i < val.size(); ++i) {
            if (int(val[i]) >= 48 && int(val[i]) < 58)
            {
                result += (val[i] - '0') * 10;
                break;
            }
            else
            {
                
                for (int posNum = 0; posNum < 9; posNum++)
                {
                    for (int s = 0; (s < 6 && s + i < val.size()); s++)
                    {
                        if (nums[posNum] == val.substr(i, s))
                        {
                            result += (posNum+1) * 10;
                            done = true;
                            break;
                        }
                    }
                    if (done) break;
                }
            }
            if (done) break;
        }
        done = false;
        for (int j = val.size() - 1; j >= i - 1; --j) {
            if (int(val[j]) >= 48 && int(val[j]) < 58)
            {
                result += (val[j] - '0');
                break;
            }
            else
            {
                
                for (int posNum = 0; posNum < 9; posNum++)
                {
                    for (int s = 0; (s < 6 && s + j < val.size() + 1); s++)
                    {
                        if (nums[posNum] == val.substr(j, s))
                        {
                            result += (posNum + 1);
                            done = true;
                            break;
                        }
                    }
                    if (done) break;
                }
            }
            if (done) break;
        }
    }

    cout << result << endl;
}

void Day1::Part2bis()
{
    vector<string> nums = { "one", "two", "three", "four", "five", "six", "seven", "eight", "nine" };

    vector<string> inputs = readData();

    for (string&  val : inputs)
    {
        string newVal = "";
        bool done = false;

        for (int i = 0; i < val.size(); ++i) {
            if (int(val[i]) >= 48 && int(val[i]) < 58)
            {
                newVal += val[i];
            }
            else
            {
                for (int posNum = 0; posNum < 9; posNum++)
                {
                    for (int s = 0; (s < 6 && s + i < val.size() - 1 && i<val.size() - 1); s++)
                    {
                       if (nums[posNum] == val.substr(i, s))
                       {
                            newVal += ""+(posNum + 1);
                            done = true;
                            break;
                        }
                    }
                    if (done) break;
                }
            }
        }
        cout << "new val: " << newVal << endl;
        val = newVal;
    }

    int result = 0;
    for (string val : inputs)
    {
        cout << val << endl;
        int i;
        for (i = 0; i < val.size(); ++i) {
            if (int(val[i]) >= 48 && int(val[i]) < 58)
            {
                result += (val[i] - '0') * 10;
                break;
            }
        }
        for (int j = val.size() - 1; j >= i - 1; --j) {
            if (int(val[j]) >= 48 && int(val[j]) < 58)
            {
                result += (val[j] - '0');
                break;
            }
        }
    }

    cout << result << endl;
    cout << result << endl;
}





















vector<string> Day1::readData()
{
    fstream inputs;
    vector<string> result;

    inputs.open("Day1.txt", ios::in);
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
