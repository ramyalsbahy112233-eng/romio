#include <iostream>
using namespace std;

int binary_search(int arr[], int n, int target)
{

    int right = n - 1;
    int left = 0;
    int mid = n / 2;

    while (left <= right)
    {
        if (arr[mid] == target)
            return mid;
        else if (arr[mid] < target)
        {
            left = mid + 1;
        }
        else if (arr[mid] > target)
        {
            right = mid - 1;
        }
        mid = (left + right) / 2;
    }
    return -1;
}

int main()
{

    int arr[5] = {1, 2, 3, 4, 5};

    int n = sizeof(arr) / sizeof(arr[0]);

    cout << binary_search(arr, n, 5) << endl;
}