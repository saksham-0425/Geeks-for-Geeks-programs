#include <stdio.h>
#include <stdlib.h>

// Ques- find the row number with max number of 1s :-

int rowwithmax1(int **a,int n,int m){
    int temp = 0;
	    int ans = -1;
	    for(int i = 0; i < n; i++)
	    {
            int cnt = 0;
            for(int j = 0; j < m; j++)
            {
                if(a[i][j] == 1)
                {
                    cnt++;
                }
            }
            if(temp < cnt)
            {
                temp = cnt;
                ans = i;
            }
	    }
	    return ans;
}

int main()
{
    printf("enter the row and column number of the 2d array:\n");
    int rows, col;
    scanf("%d %d", &rows, &col);

    int **a;
    a = (int **)malloc(rows * sizeof(int));
    

    for (int i = 0; i < rows; i++)
    {
        a[i] = (int *)malloc(col * sizeof(int));
    }
    

    printf("enter the elements for 2d array");
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < col; j++)
        {
            scanf("%d", &a[i][j]);
        }
    }

    printf("output :-");
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < col; j++)
        {
            printf("%d  ", a[i][j]);
        }
        printf("\n");
    }

    int b=rowwithmax1(a,rows,col);
    printf("%d",b);
   
    return 0;
}