#include<stdio.h>
#include<stdlib.h>

struct node
{
    struct node *prev;
    char data[10];
    struct node *next;
};
struct node *start=0;
//Global Declaration
struct node *cn()
{
    struct node *k1;
    k1=(struct node *)malloc(sizeof(struct node));
    printf("Enter a data: ");
    scanf("%s",k1->data);
    k1->next=0;
    k1->prev=0;
    return k1;
}
void is()
{
    struct node *h1;
    h1=cn(); 
    if(start==0)
    {
        start=h1;
    }
    else
    {
        h1->next=start;
        start->prev=h1;
        start=h1;
    }
}
void ie()
{
    struct node *d1,*y1;
    d1=cn();
    if(start==0)
    {
        start=d1;
    }
    else
    {
        y1=start;
        while(y1->next!=0)
        {
            y1=y1->next;
        }
        y1->next=d1;
        d1->prev=y1;
    }
}
void im()
{

}
void ds()
{
    struct node *h1;
    if(start==0)
    {
        printf("There is no any node to delete.");
    }
    else
    {
        h1=start;
        start=start->next;
        start->prev=0;
        h1->next=0;
        free(h1);
    }
}
void de()
{
    struct node *ptr7, *ptr18;
    if(start==0)
    {
        printf("There is no any node to delete");
    }
    else
    {
        ptr7=start;
        while(ptr7->next->next!=0)
            ptr7=ptr7->next;
            ptr18=ptr7->next;
            ptr18->prev=0;
            ptr7->next=0;
            free(ptr18);
    }
}
void dm()
{

}
void display()
{
    struct node *l1;
    l1=start;
    if(start==0)
    {
        printf("There is no any node to display");
    }
    else
    {
        while(l1!=0)
        {
            printf("%s ", l1->data);
            l1=l1->next;
        }
        // while(l1->prev!=0)
        // {
        //     printf("%s ", l1->data);
        //     l1=l1->prev;
        // }
    }
}
int main()
{
    int ch;
    printf("\n1. Insert Start");
    printf("\n2. Insert End");
    printf("\n3. Insert Middle");
    printf("\n4. Delete Start");
    printf("\n5. Delete End");
    printf("\n6. Delete Middle");
    printf("\n7. Display");
    printf("\n8. Exit");

    while(1)
    {

        printf("\nEnter Your Choice: ");
        scanf("%d",&ch);

        switch(ch)
        {
            case 1:
            {
                is();
                break;
            }
            case 2:
            {
                ie();
                break;
            }
            case 3:
            {
                im();
                break;
            }
            case 4:
            {
                ds();
                break;
            }
            case 5:
            {
                de();
                break;
            }
            case 6:
            {
                dm();
                break;
            }
            case 7:
            {
                display();
                break;
            }
            case 8:
            {
                exit(0);
            }
            default:
            {
                printf("Wrong Input");
            }
        }
    }
    return 0;
}