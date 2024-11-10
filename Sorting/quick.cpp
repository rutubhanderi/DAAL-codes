#include <iostream>
using namespace std;

void swapElements(int arr[], int i, int j) {
    int temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;
}

int partition(int arr[], int l, int r, int pass) {
    int pivot = arr[r];
    int i = l - 1;
    cout << "Pass " << pass << ": Pivot = " << pivot << endl;

    for (int j = l; j < r; j++) {
        if (arr[j] < pivot) {
            i++;
            swapElements(arr, i, j);
        }
    }
    swapElements(arr, i + 1, r);

    // Display the array after each partition operation
    cout << "Array after pass " << pass << ": ";
    for (int k = l; k <= r; k++) {
        cout << arr[k] << " ";
    }
    cout << endl;

    return i + 1;
}

void quickSort(int arr[], int l, int r, int &pass) {
    if (l < r) {
        pass++;
        int pi = partition(arr, l, r, pass);
        quickSort(arr, l, pi - 1, pass);
        quickSort(arr, pi + 1, r, pass);
    }
}

void displayArray(int a[], int size) {
    for (int i = 0; i < size; i++) {
        cout << a[i] << " ";
    }
    cout << endl;
}

int main() {
    int n, pass = 0;
    cout << "Enter the number of elements: ";
    cin >> n;
    int arr[n];
    cout << "Enter elements: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    quickSort(arr, 0, n - 1, pass);
    cout << "Sorted array: ";
    displayArray(arr, n);

    return 0;
}
