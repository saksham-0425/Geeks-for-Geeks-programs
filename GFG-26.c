#include <stdio.h>
#include <stdlib.h>

// Ques- check if the pythagorean triplet exists or not in an array :- 

int main()
{
    printf("enter size : ");
    int n;
    scanf("%d", &n);

    int(*p) = (int *)malloc(n * sizeof(int));
    printf("enter the elements");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &p[i]);
    }

    for (int i = 0; i < n; i++)
    {
        p[i] = p[i] * p[i];
    }


    for(int i=0;i<n-1;i++){
        for(int j=i+1;j<n;j++){
            if(p[j]<p[i]){
              int temp=p[j];
              p[j]=p[i];
              p[i]=temp;
            }
        }
    }

    for (int i = n - 1; i >= 2; i--)
    {

        int l = 0;
        int r = i - 1;
        while (l < r)
        {

            if (p[l] + p[r] == p[i])
                printf("found the triplet");

            (p[l] + p[r] < p[i]) ? l++ : r--;
        }
    }
    return 0;
}
