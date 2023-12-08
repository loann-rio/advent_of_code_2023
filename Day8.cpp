#include "Day8.h"

void Day8::Part1()
{
    vector<string> inputs = readData();

    string nextPos = "AAA";
    int NBstep = 0;
    string dir = "LRRRLRRLRRLRLRRLRRRLLRRLLRRLRRRLRLRRLLRRLRRLRLRRRLRRRLRLRLRLRRRLRRLRRRLRLRRLLLRLRLLRLRRRLRLRRRLRRRLLLRRLRLRRLRRRLLRRLRRLRRLRRRLRRLRRLRRLRLRRLRLRLRLRLRLRRRLRRLRLLLRRRLRLRRRLRRRLLRRLRRRLRRLRRRLRRRLRLRRRLRRLRLLRRLLRLRRLRLRLLRRLLRRLLRRLRRLRRRLRLRRLRLRRRLRRRLLRLRRLLLLRRRLLRLLLRRLRRRLRRRLRRRLRLRRRLRRRLRRRLRLRRRR";
    int maxIdDir = dir.size();


    while (nextPos != "ZZZ")
    {
        for (string val : inputs)
        {
            if (val.substr(0, 3) == nextPos)
            {
                if (dir[NBstep % maxIdDir] == 'L')
                    nextPos = val.substr(7, 3);
                else
                    nextPos = val.substr(12, 3);
                NBstep++;

                break;
            }
        }
    }
    cout << NBstep << endl;
}

void Day8::Part2()
{
    vector<string> inputs = readData();

    string startVal[] = { "GQA", "AAA", "XCA", "HBA", "GVA", "NVA" };
    string dir = "LRRRLRRLRRLRLRRLRRRLLRRLLRRLRRRLRLRRLLRRLRRLRLRRRLRRRLRLRLRLRRRLRRLRRRLRLRRLLLRLRLLRLRRRLRLRRRLRRRLLLRRLRLRRLRRRLLRRLRRLRRLRRRLRRLRRLRRLRLRRLRLRLRLRLRLRRRLRRLRLLLRRRLRLRRRLRRRLLRRLRRRLRRLRRRLRRRLRLRRRLRRLRLLRRLLRLRRLRLRLLRRLLRRLLRRLRRLRRRLRLRRLRLRRRLRRRLLRLRRLLLLRRRLLRLLLRRLRRRLRRRLRRRLRLRRRLRRRLRRRLRLRRRR";
    int maxIdDir = dir.size();

    for (string nextPos : startVal)
    {
        int NBstep = 0;
        


        while (nextPos[2] != 'Z')
        {
            for (string val : inputs)
            {
                if (val.substr(0, 3) == nextPos)
                {
                    if (dir[NBstep % maxIdDir] == 'L')
                        nextPos = val.substr(7, 3);
                    else
                        nextPos = val.substr(12, 3);
                    NBstep++;

                    break;
                }
            }
        }
        cout << NBstep << endl;
    }

    // then find LCD of results

















    /*vector<string> inputs = readData();

    vector<string> nextPos;
    vector<string> newPos;

    int NBstep = 0;
    //string dir = "LR";
    string dir = "LRRRLRRLRRLRLRRLRRRLLRRLLRRLRRRLRLRRLLRRLRRLRLRRRLRRRLRLRLRLRRRLRRLRRRLRLRRLLLRLRLLRLRRRLRLRRRLRRRLLLRRLRLRRLRRRLLRRLRRLRRLRRRLRRLRRLRRLRLRRLRLRLRLRLRLRRRLRRLRLLLRRRLRLRRRLRRRLLRRLRRRLRRLRRRLRRRLRLRRRLRRLRLLRRLLRLRRLRLRLLRRLLRRLLRRLRRLRRRLRLRRLRLRRRLRRRLLRLRRLLLLRRRLLRLLLRRLRRRLRRRLRRRLRLRRRLRRRLRRRLRLRRRR";
    int maxIdDir = dir.size();

    for (string val : inputs) {
        if (val[2] == 'A')
        {
            nextPos.push_back(val.substr(0, 3));
            cout << val << endl;

        }
    }

    int nbZ = 0;
    while (nbZ != nextPos.size())
    {
        nbZ = 0;
        //cout << "____" << endl;
        for (string val : inputs)
        {
            
            for (string pos : nextPos)
            {
                if (val.substr(0, 3) == pos)
                {
                    string nPos;
                    //cout << "from : " << pos << endl;
                    if (dir[NBstep % maxIdDir] == 'L')
                        nPos = val.substr(7, 3);
                    else
                        nPos = val.substr(12, 3);

                    //cout << "to : " << nPos << endl;
                    nbZ += (nPos[2] == 'Z');
                    newPos.push_back(nPos);
                }
            }
           

        }
        nextPos = newPos;
        newPos.clear();
        NBstep++;
    }

    cout << NBstep << endl;*/
}























vector<string> Day8::readData()
{
    fstream inputs;
    vector<string> result;

    inputs.open("Day8.txt", ios::in);
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
