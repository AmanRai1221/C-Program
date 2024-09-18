#include<stdio.h>
int main()
{
    int a[]={67,34,18,5,29,2};
    int p,s,index,temp,min;
    for(p=0; p<5; p++)
    {
        min=a[p];
        index=p;
        for(s=p+1; s<6; s++)
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
    for(p=0; p<6; p++)
    {
        printf("%d ", a[p]);
    } 
    return 0;
} 