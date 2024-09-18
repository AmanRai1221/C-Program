#include<iostream>
#include<conio.h>
using namespace std;
int main()
{
    int a[20]={2,3,4,7,9,17,19,36,71,77,82,85,91,99};
    int l=0,r=13,Search,i,m;

    cout<<"Enter a number that you want to search: ";
    cin>>Search;

    while(l<=r)
    {
        m=(l+r)/2;
        if(a[m]==Search)
        {
            cout<<"Number is found";
            break;
        }
        else if(a[m]>Search)
        {
            r=m-1;
        }
        else if(a[m]<Search)
        {
            l=m+1;
        }
    }
    if(l>r)
    {
        cout<<"Number is not found";
    }
    getch();
    return 0;
}
