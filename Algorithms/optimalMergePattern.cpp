#include <bits/stdc++.h>
using namespace std;
int optimalMerge(int files[], int n) {
    priority_queue<int, vector<int>, greater<int>> minHeap;
    for (int i = 0; i < n; i++) {
        minHeap.push(files[i]);
    }
    int cost = 0;
    int step = 1;
    while (minHeap.size() > 1) {

        int file1 = minHeap.top();
        minHeap.pop();
        int file2 = minHeap.top();
        minHeap.pop();
        int mergedFileSize = file1 + file2;
        cost += mergedFileSize;
        cout << "Step " << step++ << ": Merging files of size " << file1 << " and " << file2 
             << ", merged file size = " << mergedFileSize 
             << ", total cost so far = " << cost << endl;
        minHeap.push(mergedFileSize);
        cout << "Heap state: ";
        priority_queue<int, vector<int>, greater<int>> tempHeap = minHeap;
        while (!tempHeap.empty()) {
            cout << tempHeap.top() << " ";
            tempHeap.pop();
        }
        cout << endl;
    }   
    return cost;
}
int main() {
    int n;
    cout<<"Enter number of files: ";
    cin>>n;
    int files[n];
    for(int i=0;i<n;i++){
        cout<<"Enter file size: ";
        cin>>files[i];
        cout<<endl;

    }
    int minCost = optimalMerge(files, n);
    cout << "Minimum cost of merging is: " << minCost << endl;
    return 0;
}
