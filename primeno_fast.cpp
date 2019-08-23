#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <cmath>
#include <algorithm>
#include <vector>
#include <limits>
#include <time.h>
using namespace std;

int main(int argc, char **argv)
{
    double start = clock();
    vector<int> prime;
    vector<int>::iterator iter;
    int testNO;
    testNO = atoi(argv[1]);
    cout<< testNO <<endl;
    prime.push_back(2);
    for(int i = 2; i < testNO; i++)
    {
        int curNO = i + 1;
        int root = sqrt(curNO) + 1;
        int flag = 1; 
        for(iter = prime.begin(); iter != prime.end(); iter++)
        {
            int div = *iter;
            if(div > root) break; 
            if((curNO % div) == 0)
            {
                flag = 0;
                break;
            }
        }
        if(flag == 1) prime.push_back(curNO);
    }
    cout<< "prime list: " << endl;
    for(iter = prime.begin(); iter != prime.end(); iter++)
    {
        cout<< *iter << "\n";
    }
    iter = prime.end() - 1;
    int ans = 1;
    if((*iter) != testNO) ans = 0;
    cout<< endl;
    cout<<"Answer: ";
    if(ans == 1) cout<< "YES"<< endl;
    else cout<< "NO"<< endl;
    cout<< "counts of prime number less or equal than " << testNO << " : " << prime.size() << endl;
    double end = clock();
    double runtime = (end - start) / CLOCKS_PER_SEC;
    cout<< "run time: " << runtime <<endl;
}
