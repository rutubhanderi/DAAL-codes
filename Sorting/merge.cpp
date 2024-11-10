#include <iostream>
using namespace std;

void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

void merge(int arr[], int l, int mid, int r, int n) {
    int n1 = mid - l + 1;
    int n2 = r - mid;

    int a[n1], b[n2]; // Temporary arrays

    for (int i = 0; i < n1; i++) {
        a[i] = arr[l + i];
    }
    for (int i = 0; i < n2; i++) {
        b[i] = arr[mid + 1 + i];
    }

    int i = 0, j = 0, k = l;
    while (i < n1 && j < n2) {
        if (a[i] < b[j]) {
            arr[k] = a[i];
            i++;
        } else {
            arr[k] = b[j];
            j++;
        }
        k++;
    }

    while (i < n1) {
        arr[k] = a[i];
        i++;
        k++;
    }
    while (j < n2) {
        arr[k] = b[j];
        j++;
        k++;
    }

    // Print array after each merge operation
    cout << "Array after merging from index " << l << " to " << r << ": ";
    printArray(arr, n);
}

void mergeSort(int arr[], int l, int r, int n) {
    if (l < r) {
        int mid = (l + r) / 2;
        mergeSort(arr, l, mid, n);
        mergeSort(arr, mid + 1, r, n);
        merge(arr, l, mid, r, n);
    }
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

    cout << "Starting merge sort...\n";
    mergeSort(arr, 0, n - 1, n);

    cout << "Sorted array: ";
    printArray(arr, n);

    return 0;
}
