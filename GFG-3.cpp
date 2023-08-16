#include<iostream>
using namespace std;

// ques-  Given an array of size N containing only 0s, 1s, and 2s; sort the array in ascending order.

int main(){
    int n;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    
    int a0=0,b1=0,c2=0;
    for(int i=0;i<n;i++){

        if(a[i]==0){
            a0++;
            //break;
        }
        else if(a[i]==1){
            b1++;
            //break;
        }
        else{
            c2++;
            //break;
        }
    }
    int i=0;
    while(a0>0){
      a[i++]=0;
      a0--;
    }
    while(b1>0){
      a[i++]=1;
      b1--;
    }
    while(c2>0){
      a[i++]=2;
      c2--;
    }

    for(int i=0;i<n;i++){
        cout<<a[i]<<endl;
    }
}