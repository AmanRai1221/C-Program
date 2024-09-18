#include<iostream>
#include<conio.h>
using namespace std;
int main()
{
    int a[20],N;
    int l=0,r,Search,i,m;
    cout<<"Enter the range: ";
    cin>>N;
    r=N-1;
    cout<<"Enter "<<N<< "Numbers: ";
    for(i=0; i<N;i++)
    {
        cin>>a[i];
    }

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