#include<iostream>
using namespace std;

int peakElement(int arr[], int n)
    {
       if (n == 1)
        return 0;
    if (arr[0] >= arr[1])
        return 0;
    if (arr[n - 1] >= arr[n - 2])
        return n - 1;
 
    // check for every other element
    for (int i = 1; i < n - 1; i++) {
 
        // check if the neighbors are smaller
        if (arr[i] >= arr[i - 1] && arr[i] >= arr[i + 1])
            return i;
    }
}

int main(){
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    peakElement(arr,n);
    return 0;
}