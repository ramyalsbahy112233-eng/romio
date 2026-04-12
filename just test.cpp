#include <iostream>
#include <cmath>
using namespace std;

int power_num(int a, int b)
{

    if (b == 1)
        return a;
    if (b == 0)
        return 0;
    int m = floor(b / 2);
    int p = power_num(a, m);
    if (b % 2 == 0)
        return p * p;
    else
        return p * p * a;
}

int main()
{

    cout << power_num(4, 3) << endl;
}
