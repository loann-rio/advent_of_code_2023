#include "Day2.h"

void Day2::Part1()
{
    vector<string> inputs = readData();

    int result = 0;

    for (unsigned int id = 0; id < inputs.size() ; id++)
    {
        if (possible(inputs[id])) result += id + 1;
    }

    cout << result << endl;
}

bool Day2::possible(string val)
{
    size_t pos = 0;
    val.erase(0, val.find(":") + 1);

    while ((pos = val.find(",")) != string::npos) {
        string token = val.substr(1, pos - 1);
        int idSpace = token.find(" ");
        int iDcolor;
        for (iDcolor = 0; iDcolor < 3; ++iDcolor) { if (token.substr(idSpace + 1) == colors[iDcolor]) break; }
        if (stoi(token.substr(0, idSpace)) > maxcubepossible[iDcolor]) return false;
        val.erase(0, pos + 1);
    }
    return true;
}


void Day2::Part2()
{
    vector<string> inputs = readData();
   
    int result = 0;

    for (unsigned int id = 0; id < inputs.size(); id++)
    {

        int minNbCube[] = { 0, 0, 0 };
        size_t pos = 0;
        string token;
        inputs[id].erase(0, inputs[id].find(":") + 1);
        while ((pos = inputs[id].find(",")) != string::npos) {
            token = inputs[id].substr(1, pos - 1);
            int idSpace = token.find(" ");
            int iDcolor;
            for (iDcolor = 0; iDcolor < 3; ++iDcolor) { if (token.substr(idSpace + 1) == colors[iDcolor]) break; }
            minNbCube[iDcolor] = max(minNbCube[iDcolor], stoi(token.substr(0, idSpace)));
            inputs[id].erase(0, pos + 1);
        }
        result += minNbCube[0] * minNbCube[1] * minNbCube[2];
    }

    cout << result << endl;
}























vector<string> Day2::readData()
{
    fstream inputs;
    vector<string> result;

    inputs.open("Day2.txt", ios::in);
    if (inputs.is_open())
    {
        string tp;
        while (getline(inputs, tp)) { //read data from file object and put it into string.
            for (char& v : tp) { if (v == ';') v = ','; }
            result.push_back(tp+',');
        }
        inputs.close(); //close the file object.
    }
    return result;
}
