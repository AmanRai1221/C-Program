#include<stdio.h>
#include<stdlib.h>

struct stack
{
    int top;
    int cap;
    int *arr;
};
int isFull(struct stack *st)
{
    if(st->top==st->cap-1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
int isEmpty(struct stack *st)
{
    if(st->top==-1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
void push(struct stack *st)
{
    if(!isFull(st))
    {
        st->top++;
        printf("Enter a data: ");
        scanf("%d",&st->arr[st->top]);
    }
    else
    {
        printf("Stack is Full");
    }
}
void pop(struct stack *st)
{
    if(!isEmpty(st))
    {
        int data;
        data=st->arr[st->top];
        st->top--;
        printf("Popped element is %d",data);
    }
    else
    {
        printf("Stack is empty.");
    }
}

int main()
{
    int ch,size;
    struct stack *st;
    printf("\nEnter a size of a stack: ");
    scanf("%d",&size);
    st=(struct stack *)malloc(sizeof(struct stack));
    st->top=-1;
    st->cap=size;
    st->arr=(int *)calloc(st->cap,sizeof(int));

    printf("\n1. Push");
    printf("\n2. Pop");
    printf("\n3. Exit");

    while(1)
    {
        printf("\nEnter your choice: "); 
        scanf("%d",&ch);

        switch(ch)
        {
            case 1:
            {
                push(st);
                break;
            }
            case 2:
            {
                pop(st);
                break;
            }
            case 3:
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