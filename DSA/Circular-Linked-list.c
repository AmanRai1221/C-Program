#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node *next;
};
struct node *start=0;
struct node *createNode()
{   
    struct node *k1;
    k1=(struct node *)malloc(sizeof(struct node));
    printf("Enter a data: ");
    scanf("%d",&k1->data);
    k1->next=0;
    return k1;
}
void insertS()
{
    struct node *s1,*p1;
    s1=createNode();
    if(start==0)
    {
        start=s1;
        s1->next=start; //Up
    }
    else
    {
        // s1->next=start;
        p1=start;
        // if(p1->next==0)
        // {
        //     p1->next=s1;
        //     start=s1;
        // }
        // else
        {
            while(p1->next!=start)
            {
                p1=p1->next;
            }
            p1->next=s1;
            s1->next=start; //Up
            start=s1;
        }
        
    }
}
void insertE()
{
    struct node *s1,*p1;
    s1=createNode();
    if(start==0)
    {
        start=s1;
        s1->next=start; //Up
    }
    else
    {
        p1=start;
        while(p1->next!=start)
        {
            p1=p1->next;
        }
        p1->next=s1;
        s1->next=start;  
    }
}
void insertM()
{

}
void deleteS()
{
    struct node *g1;
    if(start==0)
    {
        printf("There is no any node to delete");
    }
    else
    {
        g1=start;
        while(g1->next!=start)
        {
            g1=g1->next;
        }
        g1->next=start->next;
        g1=start;
        start=start->next;
        g1->next=0;
        free(g1);
    }
}
void deleteE()
{
    struct node *h1,*a1;
    if(start==0)
    {
        printf("There is no any node to delete.");
    }
    else
    {
        h1=start;
        while(h1->next->next!=start)
        {
            h1=h1->next;
        }
        a1=h1->next;
        h1->next=start;
        free(a1);
    }
}
void deleteM()
{

}
void display()
{
    struct node *t1;
    t1=start;
    if(start==0)
    {
        printf("There is no any node to display");
    }
    else
    {
        do
        {
            printf("%d ", t1->data);
            t1=t1->next;
        }
        // while(t1->next!=start);
        while(t1!=start);
        printf("\n");
    }
}

int main()
{
    int ch;
    printf("\n1. Insert from start");
    printf("\n2. Insert from end");
    printf("\n3. Insert from middle");
    printf("\n4. delete from start");
    printf("\n5. delete from end");
    printf("\n6. delete from middle");
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
                insertS();
                break;
            }
            case 2:
            {
                insertE();
                break;
            }
            case 3:
            {
                insertM();
                break;
            }
            case 4:
            {
                deleteS();
                break;
            }
            case 5:
            {
                deleteE();
                break;
            }
            case 6:
            {
                deleteM();
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