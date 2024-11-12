#include <iostream>
using namespace std;

int binarySearch(int a[], int n, int key)
{

    int low = 0;
    int high = n - 1;
    int mid;
    while (low <= high)
    {
        int mid = (low + high) / 2;
        if (key == a[mid])
        {
            return mid;
        }
        else if (key > a[mid])
        {
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }
    return -1;
}

int main()
{
    int n, key;
    cout << "Enter number of elements in array: ";
    cin >> n;
    int a[n];
    cout << "Enter elements: ";
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    cout << "Enter the element to be searched: ";
    cin >> key;
    int result = binarySearch(a, n, key);
    if (result >= 0)
    {
        cout << "Element found at index: " << result;
    }
    else
    {
        cout << "Element not found";
    }
    return 0;
}