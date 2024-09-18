#include<stdio.h>
int main()
{
    int a[10]={6,2,19,21,5,4};
    int i,j,temp, N=6;
    for(i=0; i<N; i++)
    {
        for(j=0; j<N-1; j++)
        {
            if(a[j]>a[j+1])
            {
                temp=a[j+1];
                a[j+1]=a[j];
                a[j]=temp;
            }
        }
    }
    printf("After Sorting: \n");
    for(i=0; i<6; i++)
    {
        printf("%d ",a[i]);
    }
    return 0;
}