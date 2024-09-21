#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node *next;
};
struct node *start=0;   //Global Declaration 
struct node *createNode()
{
    struct node *h1;
    h1=(struct node *)malloc(sizeof(struct node));
    printf("Enter the data: ");
    scanf("%d", &h1-> data);
    h1 -> next=0;
    return h1;
}
 void insertStart() // Seudo Code
{
    struct node *k1;
    k1 = createNode();
    if(start==0)
    {
        start=k1;
    }
    else 
    {
        k1 -> next=start;
        start=k1;
    }
}
void insertEnd()
{
    struct node *j1,*g1;
    j1=createNode();
    if(start==0)
    {
        start=j1;
    }
    else
    {
        g1=start;
        while(g1->next!=0)
        {
            g1=g1->next;
        }
        g1->next=j1;
    }
}
void insertMiddle()
{
    struct node *h1,*j,*f;
    h1=createNode();
    if(start==0)
    {
        start=h1;
    }
    else
    {
        int d;
        printf("Enter the data after which you want to insert: ");
        scanf("%d",&d);
        f=start;
        while(f->next->data!=d)
        {
            f=f->next;
        }
        j=f->next;
        f->next=h1;
        h1->next=j;
    }
}
void deleteStart()
{
    struct node *y1;
    if(start==0)
    {
        printf("There is no node to delete");
    }
    else
    {
        y1=start;
        start=start->next;
        y1->next=0;
        free(y1);
    }
}
void deleteEnd()
{
    struct node *h1, *a1;
    if(start==0)
    {
        printf("There is no any node to delete.");
    }
    else
    {
        h1=start;
        while(h1->next->next!=0)
        {
            h1=h1->next;
        }
        a1=h1->next;
        h1->next=0;
        free(a1);
    }
}
void deleteMiddle()
{
    struct node *g,*p,*h;
    if(start==0)
    {
        printf("There is no any node to delete");
    }
    else
    {
        int d,ch;
        g=start;
        printf("Enter a data that you want to delete: ");
        scanf("%d ",&d);
        while(g->next->data!=d)
        {
            g=g->next;
        }
        p=g->next->next;
        g->next->next=0;
        h=g->next;
        printf("Deleted node value: %d\n",h->data);
        printf("\n\nEnter your choice: ");
        scanf("%d",&ch);
        g->next->next=0;
        g->next=p;
        free(h);
    }
}
void display()
{
   struct node *j1;
   j1=start;

   while(j1 != 0)
   {
    printf("%d ", j1 -> data);
    j1=j1->next;
   } 
}

int main()
{

        int ch;
        printf("\n1. Insertion from start");
        printf("\n2. Insertion from end");
        printf("\n3. Insertion from middle");
        printf("\n4. Deletion frrom start");
        printf("\n5. Deletion from end");
        printf("\n6. Deletion from middle");
        printf("\n7. Display");
        printf("\n8. Exit");
    while(1)
    {
        printf("\n\nEnter your choice: ");
        scanf("%d",&ch);

        switch(ch)
        {
            case 1:
            {
                insertStart();
                break;
            }
            case 2:
            {
                insertEnd();
                break;
            }
            case 3:
            {
                insertMiddle();
                break;
            }
            case 4:
            {
                deleteStart();
                break;
            }
            case 5:
            {
                deleteEnd();
                break;
            }
            case 6:
            {
                deleteMiddle();
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