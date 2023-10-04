#include<stdio.h>

void pushzeroes(int arr[],int n){
    int count = 0; 
    for (int i = 0; i < n; i++) {
        if (arr[i] != 0) {
            arr[count] = arr[i]; 
            count++;
        }
    }
    
    
    while (count < n) {
        arr[count] = 0;
        count++;
	}

    for(int i=0;i<n;i++){
        printf("%d ",arr[i]);
    }
}

int main(){
    int n;
    scanf("%d",&n);
    int arr[n];
    for(int i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }
    pushzeroes(arr,n);
}