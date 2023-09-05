#include<iostream>
#include<algorithm>
using namespace std;

// Ques- Kth element of two arrays :-

int main(){

    int n;
    cout<<"ennter the size of first array : ";
    cin>>n;

    int a[n];
    cout<<"enter the array elements"<<endl;
    for(int i=0;i<n;i++){
        cin>>a[i];
    }

    int m;
    cout<<"enter the size of second array : ";
    cin>>m;
    int b[m];
    cout<<"enter the array elements : "<<endl;
    for(int i=0;i<m;i++){
        cin>>b[i];
    }
    
    int c[n+m];
    int k=0;
    for(int i=0;i<n;i++){
        c[k++]=a[i];
    }
    for(int i=0;i<m;i++){
        c[k++]=b[i];
    }
    sort(c,c+13);

    for(int i=0;i<n+m;i++){
        cout<<c[i]<<" ";
    }
    cout<<endl;

    int x;
    cout<<"enter the position : ";
    cin>>x;

    cout<<c[x-1];
    return 0;
}


    
    
