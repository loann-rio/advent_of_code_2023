#include "Day3.h"

void Day3::Part1()
{
    vector<string> inputs = readData();
    string numbers = "0123456789";
    int results = 0;

    for (unsigned int i = 0; i < inputs.size(); i++)
    {
        string currentNumber = "";
        bool isValid = false;

        for (unsigned int j = 0; j < inputs[0].size(); j++)
        {
            // if the char is a number
            if (numbers.find(inputs[i][j]) != std::string::npos)
            {
                currentNumber += inputs[i][j];
                isValid = isValid || specialSign(inputs, i, j);
            }
            else
            {
                if (isValid)
                {
                    cout << "valid : " << currentNumber << endl;
                    results += stoi(currentNumber);
                }

                isValid = false;
                currentNumber = "";
            }

        }
    }
    cout << results << endl;

}

bool Day3::specialSign(vector<string> inputs, int i, int j)
{
    string numbers = "0123456789";

    for (int x = -1; x < 2; x++)
    {
        for (int y = -1; y < 2; y++)
        {
            if ((i+x >= 0 && i+x < inputs.size() && j+y >= 0 && j+y < inputs[0].size()) && numbers.find(inputs[i+x][j+y]) == std::string::npos && inputs[i + x][j + y] != '.')
            {
                return true;
            }
        }
    }
    return false;
}


void Day3::Part2()
{

    vector<int> pos = {};
    vector<int> val = {};

    vector<string> inputs = readData();
    string numbers = "0123456789";
    int results = 0;

    for (unsigned int i = 0; i < inputs.size(); i++)
    {
        string currentNumber = "";
        int star = -1;

        for (unsigned int j = 0; j < inputs[0].size(); j++)
        {
            // if the char is a number
            if (numbers.find(inputs[i][j]) != std::string::npos)
            {
                currentNumber += inputs[i][j];
                star = max(star, starSign(inputs, i, j));
            }
            else
            {
                if (star != -1)
                {
                    int it = 0;
                    for (int p : pos)
                    {
                        if (p == star) break;
                        else it++;
                    }

                    if (it != pos.size())
                    {
                        results += val[it] * stoi(currentNumber);
                    }
                    else
                    {
                        pos.push_back(star);
                        val.push_back(stoi(currentNumber));
                    }
                }

                star = -1;
                currentNumber = "";
            }

        }
    }
    cout << results << endl;


}


int Day3::starSign(vector<string> inputs, int i, int j)
{
    int nb2 = 1289;
    int r = 0;

    for (int x = -1; x < 2; x++)
    {
        for (int y = -1; y < 2; y++)
        {
            if ((i + x >= 0 && i + x < inputs.size() && j + y >= 0 && j + y < inputs[0].size()))
            {
                if (inputs[i + x][j + y] == '*')
                {
                    return (i + x) + nb2 * (j + y);
                }
               
            }
        }
    }
    return -1;
}






















vector<string> Day3::readData()
{
    fstream inputs;
    vector<string> result;

    inputs.open("Day3.txt", ios::in);
    if (inputs.is_open())
    {
        string tp;
        while (getline(inputs, tp)) { //read data from file object and put it into string.
            result.push_back(tp+".");
        }
        inputs.close(); //close the file object.
    }
    return result;
}
