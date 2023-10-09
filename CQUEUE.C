#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#define max 10

int cqueue_arr[max];
int front=-1;
int rear=-1;
void display();
void insert(int item) ;
int del();
int peek();
int isEmpty();
int isFull();
int main()
{
    int choice,item;
    while(1)
    {
        printf(" 1.INSERT\n 2.DELETE\n 3.PEEK\n 4.DISPLAY\n 5.QUIT");
        printf("\n\nENTER THE CHOICE:");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1: printf("ENTER THE ELEMENT FOR INSERTION:");
                    scanf("%d",&item);
                    insert(item);
                    break;
            case 2: printf("ElEMENT DELETED is %d\n",del());
                    break;
            case 3: printf(" ELEMENT AT THE FRONT:%d",peek());
                    break;
            case 4:  display();
                     break;
            case 5: exit(1);
                    break;
            default:printf("WRONG CHOICE");
        }
    }
}
void insert(int item)
{
    if(isFull())
    {
        printf("OVERFLOW");
        return ;
    }
    if(front == -1)
        front=0;
    if(rear==max-1)
        rear=0;
    else
        rear = rear+1;
    cqueue_arr[rear]=item;
}
int del()
{
    int item;
    if(isEmpty())
    {
        printf("UNDERFLOW");
    }
    item=cqueue_arr[front];
    if(front==rear)
    {
        front=rear=-1;
    }
    else if(front==max-1)
        front =0;
    else
        front=front+1;
    return item;
}
int isEmpty()
{
    if(front==-1)
        return 1;
    else
        return 0;
}
int isFull()
{
    if((front==0&&rear==max-1)||(front==rear+1))
        return 1;
    else
        return 0;
}
int peek()
{
    if(isEmpty())
    {
        printf("UNDERFLOW");
        exit(1) ;
    }
    return cqueue_arr[front];
}
void display()
{
    int i;
    if(isEmpty())
    {
        printf("QUEUE IS EMPTY");
        return ;
    }
    printf("QUEUE ELEMENTS:\n");
    i=front;
    if(front<=rear)
    {
        while(i<=rear)
            printf("%d",cqueue_arr[i++]);
    }
    else
    {
        while(i<=max-1)
            printf("%d",cqueue_arr[i++]);
        i=0;
        while(i<=rear)
            printf("%d",cqueue_arr[i++]);
    }
}



