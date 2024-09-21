#include<stdio.h>

struct node
{
    int data;
    struct node *next;
};
struct node *start=0;   //Global Declaration
struct node *createNode()
{
    struct node *h1;
    h1=(struct noode *)malloc(sizeof(struct node));
    printf("Enter the data: ");
    scanf("%d", &h1-> data);
    h1 -> next=0;
    return h1;
}
 void insertStart() // Pseudo Code
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

}
void insertMiddle()
{

}
void deleteStart()
{

}
void deleteEnd()
{

}
void deleteMiddle()
{

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
    while(1)
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
