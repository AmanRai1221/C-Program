#include <stdio.h>
int main()
{
    int i,a[100],search;
    int k=0, r;
    printf("Enter the range: ");
    scanf("%d", &r);

    printf("Enter %d Numbers: ",r);
    for(i=0; i<r; i++)
    {
        scanf("%d",&a[i]);
    }
    printf("Enter the number that you want to search: ");
    scanf("%d", &search);
    
    for(i=0; i<r; i++)
    {
        if(a[i]==search)
        {
            printf("Number is found at position %d",i+1);
            k=1;
            break;
        }
    }
    if(k==0)
        {
            printf("Number is not found");
        }
    
    // if(a[1]==search)
    // {
    //     printf("Number is found");
    // }
    // if(a[2]==search)
    // {
    //     printf("Number is found");
    // }
    // if(a[3]==search)
    // {
    //     printf("Number is found");
    // }
    // if(a[4]==search)
    // {
    //     printf("Number is found");
    // }
    // if(a[5]==search)
    // {
    //     printf("Number is found");
    // }
    // if(a[6]==search)
    // {
    //     printf("Number is found");
    // }
    return 0;
}