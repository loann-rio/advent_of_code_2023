#include "Day4.h"

void Day4::Part1()
{
    vector<string> inputs = readData();
    int result = 0;

    for (string val : inputs)
    {
        int numberValidNumber = getValCard(val);
        if (numberValidNumber != 0) result += pow(2, numberValidNumber - 1);
    }
    cout << result << endl;
}

void Day4::Part2()
{
    vector<string> inputs = readData();
    int resultPerCard[300] = { 0 };
    int result = 0;

    for (int i = inputs.size() -1 ; i>-1 ; i--)
    {
        int val = getValCard(inputs[i]);
        resultPerCard[i] += 1;
        for (unsigned int n = 1; n <= val; n++)
            resultPerCard[i] += resultPerCard[i + n];
        result += resultPerCard[i];
    }
    cout << result << endl;
}

int Day4::getValCard(string card)
{
    card.erase(0, card.find(":") + 1);

    vector<int> winningNumbers = {};
    int numberValidNumber = 0;
    string currentNumber = "";
    bool winnigNum = true;

    for (char c : card)
    {
        if (numbers.find(c) != std::string::npos)
        {
            currentNumber += c;
        }
        else if (c == '|')
        {
            winnigNum = false;
        }
        else if (currentNumber != "")
        {
            if (winnigNum)
            {
                winningNumbers.push_back(stoi(currentNumber));
                currentNumber = "";
            }
            else
            {
                if (find(winningNumbers.begin(), winningNumbers.end(), stoi(currentNumber)) != winningNumbers.end())
                {
                    numberValidNumber++;
                }
                currentNumber = "";
            }
        }
    }

    return numberValidNumber;

}























vector<string> Day4::readData()
{
    fstream inputs;
    vector<string> result;

    inputs.open("Day4.txt", ios::in);
    if (inputs.is_open())
    {
        string tp;
        while (getline(inputs, tp)) { //read data from file object and put it into string.
            result.push_back(tp+" ");
        }
        inputs.close(); //close the file object.
    }
    return result;
}
