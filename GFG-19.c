#include<stdio.h>
#include<stdlib.h>

int main(){
    int A[6]={1,-2,4,10,5,-7};
    int max=A[0];
    int min=A[0];
    	
    	for(int i=0;i<6;i++){
    	    if(A[i]>max){
    	        max=A[i];
    	    }
    	    if(A[i]<min){
    	        min=A[i];
    	    }
    	}
    int sum=max+min;
    printf("sum is: %d",sum);
    return 0;
}