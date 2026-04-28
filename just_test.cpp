#include <iostream>
using namespace std;


//this is fibonachi code
const int MAX = 1000;
long long F[MAX];

long long fib(int n)
{
    if (F[n] != 0)
        return F[n];

    if (n <= 1)
        return F[n] = 1;

    return F[n] = fib(n - 1) + fib(n - 2);
}

int main()
{
    cout << fib(50) << endl;
}