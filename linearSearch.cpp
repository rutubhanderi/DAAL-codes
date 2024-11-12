#include<iostream>
using namespace std;

void linearSearch(int a[],int n,int key){
    int isFound=0,i;
    for( i=0;i<n;i++){
        if(a[i]==key){
            isFound=1;
            break;
        }
    }
    if(isFound==1){
        cout<<"Element found at index :"<<i;
    }
    else{
        cout<<"Element not found";
    }
}
int main(){
    int n,key;
    cout<<"Enter number of elements in array: ";
    cin>>n;
    int a[n];
    cout<<"Enter elements: ";
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    cout<<"Enter the element to be searched: ";
    cin>>key;
    linearSearch(a,n,key);
    return 0;
}
