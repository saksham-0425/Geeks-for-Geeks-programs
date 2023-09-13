#include<iostream>
#include<algorithm>
using namespace std;


int main(){

    int n;
    cout<<"enter the size of first array : ";
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
    sort(c,c+n+m);

    for(int i=0;i<n+m;i++){
        cout<<c[i]<<" ";
    }
    cout<<endl;
    int x=(n+m)/2;

    cout<<"middle elements are: "<<c[x]<<"and"<<c[x-1]<<endl;
    cout<<"the sum of middle elements of the merged array is : "<<c[x]+c[x-1]<<endl;

    return 0;
}


    
    
