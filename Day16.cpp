#include "Day16.h"

void Day16::Part1()
{
    vector<string> inputs = readData();

    const int primes[4] = { 2, 3, 5, 7 };
    const int dir[4][2] = { {1, 0}, {0, 1}, {-1, 0}, {0, -1} };

    // list of light ee pos with dir
    vector<vector<int>> poss = { {0, 1, 0} };

    // Initializing resulting matrix with light
    vector<vector<int>> resultingMat(inputs.size(), vector<int>(inputs[0].size(), 1));


    while (poss.size() > 0)
    {
        vector<vector<int>> newVectPoss;
        for (vector<int> pos : poss)
        {

            
            int newXpos = pos[0] + dir[pos[2]][0];
            int newYpos = pos[1] + dir[pos[2]][1];
            int newDir = pos[2];
            std::cout << "_____ new pos : " << newXpos << " " << newYpos << " " << newDir << endl;

            switch (inputs[newYpos][newXpos])
            {
            case ('.'):
                newVectPoss.push_back(vector<int>{newXpos, newYpos, newDir});
                resultingMat[newYpos][newXpos] *= primes[newDir];
                std::cout << "empty" << endl;

                // Display the contents of the 2D vector
                for (int i = 0; i < inputs.size(); ++i) {
                    for (int j = 0; j < inputs.size(); ++j) {
                        std::cout << resultingMat[i][j] << " ";
                    }
                    std::cout << std::endl;
                }

            case ('/'):
                
                if (pos[2] % 2 == 0)
                    newDir = (pos[2] + 3) % 4;
                else
                    newDir = (pos[2] + 1) % 4;
                if (resultingMat[newYpos][newXpos] % primes[newDir] != 0)
                {
                    newVectPoss.push_back(vector<int>{newXpos, newYpos, newDir});
                    resultingMat[newYpos][newXpos] *= primes[newDir];
                }
                    

                break;

            case ('\\'):
                if (pos[2] % 2 == 0)
                    newDir = (pos[2] + 1) % 4;
                else
                    newDir = (pos[2] + 3) % 4;
                if (resultingMat[newYpos][newXpos] % primes[newDir] != 0)
                {
                    newVectPoss.push_back(vector<int>{newXpos, newYpos, newDir});
                    resultingMat[newYpos][newXpos] *= primes[newDir];
                }
                    
                break;

            case ('|'):
                cout << "|\n";
                if (pos[2] % 2 == 0)
                {
                    cout << "split\n";
                    newDir = (pos[2] + 1) % 4;
                    cout << newDir << " " << resultingMat[newYpos][newXpos] << endl;
                    if (resultingMat[newYpos][newXpos] % primes[newDir] != 0)
                    {
                        cout << "1 " <<  newDir << " " << primes[newDir] <<      "\n";
                        newVectPoss.push_back(vector<int>{newXpos, newYpos, newDir});
                        resultingMat[newYpos][newXpos] *= primes[newDir];
                    }
                    newDir = (pos[2] + 3) % 4;
                    cout << newDir << " " << resultingMat[newYpos][newXpos] << endl;
                    if (resultingMat[newYpos][newXpos] % primes[newDir] != 0)
                    {
                        cout << "2 " << newDir << " " << primes[newDir] << "\n";;
                        newVectPoss.push_back(vector<int>{newXpos, newYpos, newDir});
                        resultingMat[newYpos][newXpos] *= primes[newDir];
                    }
                }
                else if (resultingMat[newYpos][newXpos] % primes[newDir] != 0)
                {
                    cout << "not split\n";
                    newVectPoss.push_back(vector<int>{newXpos, newYpos, newDir});
                    resultingMat[newYpos][newXpos] *= primes[newDir];
                }


                // Display the contents of the 2D vector
                for (int i = 0; i < inputs.size(); ++i) {
                    for (int j = 0; j < inputs.size(); ++j) {
                        std::cout << resultingMat[i][j] << " ";
                    }
                    std::cout << std::endl;
                }
                    
                break;
            case ('-'):
                if (pos[2] % 2 != 0)
                {
                    newDir = (pos[2] + 1) % 4;
                    if (resultingMat[newYpos][newXpos] % primes[newDir] != 0)
                    {
                        newVectPoss.push_back(vector<int>{newXpos, newYpos, newDir});
                        resultingMat[newYpos][newXpos] *= primes[newDir];
                    }
                    newDir = (pos[2] + 3) % 4;
                    if (resultingMat[newYpos][newXpos] % primes[newDir] != 0)
                    {
                        newVectPoss.push_back(vector<int>{newXpos, newYpos, newDir});
                        resultingMat[newYpos][newXpos] *= primes[newDir];
                    }
                }
                else if (resultingMat[newYpos][newXpos] % primes[newDir] != 0)
                {
                    newVectPoss.push_back(vector<int>{newXpos, newYpos, newDir});
                    resultingMat[newYpos][newXpos] *= primes[newDir];
                }

                break;
                    
            }
        }

        poss = newVectPoss;
        cout << "size vector poss : " << newVectPoss.size() << endl;
    }

    for (vector<int> row : resultingMat)
    {
        for (int e : row)
        {
            cout << e << " ";
        }
        cout << endl;
    }


}

void Day16::Part2()
{
    vector<string> inputs = readData();

    for (string val : inputs)
    {
        cout << val << endl;
    }
}























vector<string> Day16::readData()
{
    fstream inputs;
    vector<string> result;


    inputs.open("Day16.txt", ios::in);
    if (inputs.is_open())
    {
        string tp;
        while (getline(inputs, tp)) { //read data from file object and put it into string.
            result.push_back("x" + tp + "x");
        }
        inputs.close(); //close the file object.
    }

    result.insert(result.begin(), string(result[0].size(), 'x'));
    result.push_back(string(result[0].size(), 'x'));
    return result;
}

vector<string> Day16::parseString(const string val, const char delimitation)
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
