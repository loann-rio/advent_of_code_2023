#include "Day6.h"

void Day6::Part1()
{
    int result = 1;
    for (unsigned int race = 0; race < 4; race++)
    {
        int possible = 0;
        for (unsigned int i = 0; i < time[race]; i++)
        {
            if ((time[race] - i) * i > distance[race])
            {
                possible++;
            }
        }
        cout << possible << endl;
        result *= possible;
    }
    cout << result << endl;
}

void Day6::Part2()
{
    int possible = 0;
    for (unsigned int i = 0; i < time1; i++)
    {
        if ((time1 - i) * i > distance1)
        {
            possible++;
        }
        if (i % 1000000 == 0)
            cout << i << endl;
    }
    cout << possible << endl;

}
















