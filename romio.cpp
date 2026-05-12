#include <iostream>
#include <string>
using namespace std;

int binary_search(int arr[], int n, int target) // O(log n)
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
//---------------------------------------------------
void merge(int arr[], int left, int mid, int right)
{
    int n1 = mid - left + 1;
    int n2 = right - mid;

    int *L = new int[n1];
    int *R = new int[n2];

    for (int i = 0; i < n1; i++)
        L[i] = arr[left + i];

    for (int i = 0; i < n2; i++)
        R[i] = arr[mid + 1 + i];

    int i = 0, j = 0, k = left;

    while (i < n1 && j < n2)
    {
        if (L[i] <= R[j])
            arr[k++] = L[i++];
        else
            arr[k++] = R[j++];
    }

    while (i < n1)
        arr[k++] = L[i++];

    while (j < n2)
        arr[k++] = R[j++];

    delete[] L;
    delete[] R;
}
//---------------------------------------------------
void mergeSort(int arr[], int left, int right) // O(nlogn)
{
    if (left >= right)
        return;

    int mid = left + (right - left) / 2;

    mergeSort(arr, left, mid);
    mergeSort(arr, mid + 1, right);
    merge(arr, left, mid, right);
}
//--------------------------------------------------
int inseertion_sort(int arr[], int n)
{

    for (int j = 1; j <= n; j++)
    {
        int temp = arr[j];
        int i = j - 1;
        while (i >= 0 && arr[i] > temp)
        {
            arr[i + 1] = arr[i];
            i = i - 1;
        }
        arr[i + 1] = temp;
    }

    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << "->";
    }
    cout << endl;
    return 1;
}
//--------------------------------------------------

// this is fibonacci code
const int MAX = 1000;
long long F[MAX]; // here we added a storage for dynamic programming

long long fib(int n) // O(n)
{
    if (F[n] != 0)
        return F[n];

    if (n <= 1)
        return F[n] = 1;

    return F[n] = fib(n - 1) + fib(n - 2);
}

//-------------------------------------------------
int main()
{
    // test for binary search..
    int arr1[5] = {1, 2, 3, 4, 5};

    int n1 = sizeof(arr1) / sizeof(arr1[0]);

    cout << "the number you want is in index: " << binary_search(arr1, n1, 5) << endl;

    cout << string(50, '-') << endl;

    //-------------------------------------------
    // test for merge_sort
    int arr2[] = {38, 27, 43, 3, 9, 82, 10};

    int n2 = sizeof(arr2) / sizeof(arr2[0]);

    mergeSort(arr2, 0, n2 - 1);

    cout << "and this is the sorted array: " << endl;
    for (int i = 0; i < n2; i++)
        cout << arr2[i] << " ";
    cout << endl;
    cout << string(50, '-') << endl;

    //--------------------------------------------
    // test for dynamic programming:

    cout << "this is the fib result" << endl;
    cout << fib(50) << endl; // don't try big numbers because it might cause an overflow, (not over 90)
    cout << string(50, '-') << endl;
    //--------------------------------------------
    // test for insertion sort:
    int arr[] = {1, 4, 3, 7, 4, 9, 3, 9};
    int n = sizeof(arr) / sizeof(arr[0]);
    cout << "this test for insertion sort:" << endl;
    inseertion_sort(arr, n);
    cout << string(50, '-') << endl;
}
