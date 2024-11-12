#include <bits/stdc++.h>
using namespace std;
int partition(int arr[], int l, int r) {
    int pivot = arr[r];
    int i = l - 1;
    cout << "Pivot = " << pivot << endl;

    for (int j = l; j < r; j++) {
        if (arr[j] < pivot) {
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i+1], arr[r]);

    // Display the array after each partition operation
    cout << "Array after pass : ";
    for (int k = l; k <= r; k++) {
        cout << arr[k] << " ";
    }
    cout << endl;

    return i + 1;
}

void quickSort(int arr[], int l, int r) {
    if (l < r) {
        int pi = partition(arr, l, r);
        quickSort(arr, l, pi - 1);
        quickSort(arr, pi + 1, r);
    }
}

void displayArray(int a[], int size) {
    for (int i = 0; i < size; i++) {
        cout << a[i] << " ";
    }
    cout << endl;
}

int main() {
    int n;
    cout << "Enter the number of elements: ";
    cin >> n;
    int arr[n];
    cout << "Enter elements: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    quickSort(arr, 0, n - 1);
    cout << "Sorted array: ";
    displayArray(arr, n);

    return 0;
}
