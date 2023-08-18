// ques- Leaders in an array

#include<iostream>
using namespace std;

int main(){
    int a[6]={1,2,8,9,5,3};

    int right_most=a[6-1];
    cout<<right_most<<" ";
    for(int i=6-2;i>=0;i--){
        if(right_most<a[i]){
            right_most=a[i];
            cout<<right_most<<" ";
        }
    }

    
    return 0;
}