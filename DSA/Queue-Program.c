#include<stdio.h>
#include<stdlib.h>

struct Queue
{
    int rear;
    int front;
    int cap;
    int *arr;
};
struct Queue *createQueue(int s)
{
    struct Queue *G;
    G=(struct Queue *)malloc(sizeof(struct Queue));
    G->rear=-1;
    G->front=-1;
    G->cap=s;
    G->arr=(int *)calloc(G->cap,sizeof(int));
    return G;
}

void enQueue(struct Queue *Q)
{
    int d;
    printf("Enter a data: ");
    scanf("%d", &d);

    if(!isFull(Q))
    {
        Q->rear=(Q->rear+1)%Q->cap;
        Q->arr[Q->rear]=d;
        if(Q->front==-1)
        {
            Q->front=Q->rear;
        }
    }
    else
    {
        printf("Queue is Full");
    }
}
void deQueue(struct Queue *Q)
{
    int d;
    if(!isEmpty(Q))
    {
        d=Q->arr[Q->front];
        if(Q->rear==Q->front)
        {
            Q->rear=-1;
            Q->front=-1;
        }
        else
        {
            Q->front=(Q->front+1)%Q->cap;
        }
        printf("Deleted data is %d\n",d);
    }
    else
    {
        printf("Queue is Empty");
    }
}
void deleteQueue(struct Queue *Q)
{
    if(Q)
    {
        if(Q->arr)
        {
            free(Q->arr);
        }
        free (Q);
        printf("Whole Queue is Deleted.");
    }
}
void queueSize(struct Queue *Q)
{
    int d;
    if(Q->rear==-1 && Q->front==-1)
    {
        printf("Size of Queue is 0");
    }
    else
    {
        d=((Q->cap-(Q->front))+(Q->rear+1))%Q->cap;
        printf("Size of a Queue is %d", d);
    }
}
int isEmpty(struct Queue *Q)
{
    if(Q->front==-1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
int isFull(struct Queue *Q)
{
    if((Q->rear+1)%Q->cap==Q->front)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int main()
{
    struct Queue *Q;
    int s,ch;
    printf("Enter a size of a Queue: ");
    scanf("%d", &s);
    Q=createQueue(s);
    printf("\n1. Insert of a Data");
    printf("\n2. Deletion of Data");
    printf("\n3. Size of a Queue");
    printf("\n4. Delete whole Queue");

    while(1)
    {
        printf("\n\nEnter Your choice: ");
        scanf("%d", &ch);

        switch(ch)
        {
            case 1:
            {
                enQueue(Q);
                break;
            }
            case 2:
            {
                deQueue(Q);
                break;
            }
            case 3:
            {
                queueSize(Q);
                break;
            }
            case 4:
            {
                break;
            }
            case 5:
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