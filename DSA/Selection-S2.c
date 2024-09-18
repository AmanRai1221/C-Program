#include<stdio.h>
int main()
{
    int a[10],N; 
    int p,s,index,temp,min;
    printf("Enter the range: ");
    scanf("%d",&N);
    printf("Enter %d numbers: ",N);
    for(p=0; p<N; p++)
    {
        scanf("%d",&a[p]);
    }
    for(p=0; p<N-1; p++)
    {
        min=a[p];
        index=p;
        for(s=p+1; s<N; s++)
        {
            if(min>a[s])
            {
                min=a[s];
                index=s;
            }
        }
        temp=a[p];
        a[p]=a[index];
        a[index]=temp;
    }
    printf("After Sorting: \n");
    for(p=0; p<N; p++)
    {
        printf("%d ", a[p]);
    } 
    return 0;
}