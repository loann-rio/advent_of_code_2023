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
        {
            ValResult = ((ValResult + int(c)) * 17) % 256;
        }
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

        cout << "val : " << val << endl;
        // split inputs
        int ID = min(val.find('='), val.find('-'));
        bool isEqual = (val.find('=') == ID);

        int HashVal = 0;

        for (const char& c : val.substr(0, ID)) { HashVal = ((HashVal + int(c)) * 17) % 256; }

        cout << "is equal = " << isEqual << endl;
        if (isEqual)
        {
            cout << "add " << val << " to box " << HashVal << endl;
            //boxes[ValResult][val.substr(0, ID)] = stoi(val.substr(ID + 1));
            if (boxes.find(HashVal) == boxes.end())
            {
                cout << "vect does not exist \n";
                boxes[HashVal] = vector<tuple<string, int>>();
            }

            auto it = boxes[HashVal].begin();
            while (it != boxes[HashVal].end())
            {
                if (get<0>(*it) == val.substr(0, ID))
                {
                    cout << "modify the value\n";
                    (*it) = tuple<string, int>{ get<0>(*it), stoi(val.substr(ID+1)) };
                    break;
                }

                it++;
            }
            if (it == boxes[HashVal].end())
            {
                cout << "add the value\n";
                cout << val.substr(0, ID) << endl;
                cout << stoi(val.substr(ID+1)) << endl;
                boxes[HashVal].push_back(tuple<string, int>{ val.substr(0, ID), stoi(val.substr(ID+1)) });
            }
        }
        else
        {
            cout << "remove : " << val << " from box " << HashVal << endl;
            if (boxes.find(HashVal) != boxes.end())
            {
                auto it = boxes[HashVal].begin();
                while (it != boxes[HashVal].end())
                {
                    if (get<0>(*it) == val.substr(0, ID))
                    {
                        cout << "remove\n";
                        boxes[HashVal].erase(it);
                        break;
                    }
                    it++;
                }

            }
            cout << "done removing\n";
        }

        cout << "boxes : \n" << endl;

        for (map<int, vector<tuple<string, int>>>::iterator iter = boxes.begin(); iter != boxes.end(); ++iter)
        {
            for (tuple<string, int> vals : iter->second)
            {
                cout << "boxe : " << iter->first << " , val = " << get<0>(vals) << " " << get<1>(vals) << endl;
            }
        }

        cout << " " << endl;

    }


}


/*void Day15::Part2()
{
    vector<string> inputs = readData();
    int result = 0;
    map<int, map<string, int>> boxes;

    for (string val : inputs)
    {
        int ValResult = 0;
        int ID = min(val.find('='), val.find('-'));
        bool isEqual = (val.find('=') == ID);
       
        std::cout << val.substr(0, ID) << endl;
        for (const char& c : val.substr(0, ID))
        {
            ValResult = ((ValResult + int(c)) * 17) % 256;
        }

        if (isEqual)
        {
            cout << "add " << val << " to box " << ValResult << endl;
            boxes[ValResult][val.substr(0, ID)]=stoi(val.substr(ID+1));
        }
        else
        {
            if (boxes.find(ValResult) != boxes.end())
            {
                if (boxes[ValResult].find(val.substr(0, ID)) != boxes[ValResult].end()) {
                    boxes[ValResult].erase(val.substr(0, ID));
                }
                cout << "remove " << val << " to box " << ValResult << endl;
            }
        }
        cout << "_______\n";
        for (std::map<int, map<string, int>>::iterator iter = boxes.begin(); iter != boxes.end(); ++iter)
        {
            int k = iter->first;
            cout << k << endl;
            map<string, int> v = iter->second;

            for (map<string, int>::iterator VectIt = v.begin(); VectIt != v.end(); VectIt++)
            {
                cout << "key second = " << VectIt->first;
                cout << " val second  " << VectIt->second << endl;
            }
        }
        cout << "_______\n";
        cout <<  ValResult << "\n";
    }

    for (std::map<int, map<string, int>>::iterator iter = boxes.begin(); iter != boxes.end(); ++iter)
    {
        int k = iter->first;
        cout << k << endl;
        map<string, int> v = iter->second;

        for (map<string, int>::iterator VectIt = v.begin(); VectIt != v.end(); VectIt++)
        {
            cout << "key second = " << VectIt->first << endl;
            result += (k+1) * distance(VectIt, v.begin()) * VectIt->second;
            //cout << "re = " << (k + 1) << " " << distance(VectIt, v.begin()) << " " << VectIt->second << endl;
        }
        cout << "hh\n";
    }
    cout << result << "\n";
}*/























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
