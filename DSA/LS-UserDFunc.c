#include <stdio.h>
int LinearSearch(int a[], int r, int search)
{
   int k=0,i;
   for(i=0;i<r;i++){
    if(a[i]==search){
        printf("Number is found at position %d\n",i+1);
        k++;
        break;
    }
   }
   if(k==0)
        {
            printf("Number is not found");
        }
}

int main()
{
   int i,a[100],search;
    int r;
    printf("Enter the range: ");
    scanf("%d", &r);

    printf("Enter %d Numbers: ",r);
    for(i=0; i<r; i++)
    {
        scanf("%d",&a[i]);
    }
    printf("Enter the number that you want to search: ");
    scanf("%d", &search);
    LinearSearch(a,r,search);
    return 0;
}
