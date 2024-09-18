#include<stdio.h>
void quick(int a[], int N, int beg, int end, int *loc)
{
    int left,right,temp;
    left=beg;
    right=end;
    *loc=beg;

    step1: while (a[*loc]<=a[right] && right != *loc)
    {
        right--;
    }
    if(right==*loc)
    {
        return;
    }
    if(a[*loc]>a[right])
    {
        temp=a[*loc];
        a[*loc]=a[right];
        a[right]=temp;
        *loc=right;
    }
    goto step2;
    step2: while(a[*loc]>=a[left] && left != *loc)
    {
        left++;
    }
    if(left==*loc)
    {
        return;
    }
    if(a[*loc]<a[left])
    {
        temp=a[*loc];
        a[*loc]=a[left];
        a[left]=temp;
        *loc=left;
    }
    goto step1;

}
void quick_sort(int a[], int N)
{
    int beg,end,top=-1,loc;
    int lower[10],upper[10];
    if(N>1)
    {
        top++;
        lower[top]=0;
        upper[top]=N-1;
    }
    while(top!=-1)
    {
        beg=lower[top];
        end=upper[top];
        top--;
        quick(a,N,beg,end,&loc);
        if(beg<loc-1)
        {
            top++;
            lower[top]=beg;
            upper[top]=loc-1;
        }
        if(loc+1<end)
        {
            top++;
            lower[top]=loc+1;
            upper[top]=end;
        }
    }
}

int main()
{
    int a[]={78,5,21,90,81,73,59,61,35,20,50,71};
    int N=12,i;
    quick_sort(a,N);
    printf("Sorted Array is: \n");
    for(i=0; i<N; i++)
    {
        printf("%d ",a[i]);
    }
    return 0;
}
