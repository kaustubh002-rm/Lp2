#include<bits/stdc++.h>
using namespace std;

void selection_sort(int arr[], int n){
    for(int i=0; i<n-1; i++){
        int minidx = i;

        for(int j=i+1; j<n; j++){
            if(arr[j]< arr[minidx]){
                minidx = j;
            }
        }

        swap(arr[i], arr[minidx]);
    }
}

int main(){
    int arr[] = {10, 54, 23, 1, 5};
    int n= 5;

    selection_sort(arr,n);

    cout<<"selection sort: ";

    for(int i=0; i<n; i++){
        cout<<arr[i]<<" ";
    }
    return 0;
}