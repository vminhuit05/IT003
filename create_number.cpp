#include <bits/stdc++.h>

using namespace std;

int main()
{
    freopen("number.inp10.txt","w",stdout);
    srand(time(0));
    for (int i =0;i<1000000;i++)
    {
        double rand1 = rand();
        double rand2 = rand();
        double num = rand1*rand2/10000;
        cout<<num<<' ';
    }


    return 0;
}