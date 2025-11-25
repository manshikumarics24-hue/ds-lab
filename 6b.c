#include <stdio.h>
#include <stdlib.h>
// ----------for stack--------//
struct node
{
    int data;
    struct node *next;
};
struct node *top = NULL;
struct node *front = NULL;
struct node *rear = NULL;
void push(int val)
{

    struct node *newnode;
    newnode = (struct node *)malloc(sizeof(struct node));
    newnode->data = val;
    newnode->next = top;
    top = newnode;
    printf("item pushed successfully!\n");
}

void pop()
{
    struct node *temp;
    if (top == NULL)
        printf("stack underflow");
    else
    {
        temp = top;
        printf("popped elements is %d\n", temp->data);
        top = top->next;
        free(temp);
    }
}

void displaystack()
{

    if (top == NULL)
    {
        printf("empty list!!!");
        return;
    }
    struct node *temp = top;
    while (temp != NULL)
    {
        printf("%d->", temp->data);
        temp = temp->next;
    }
}

//------for queue------//
void enqueue(int value)
{
    struct node *newnode;
    newnode = (struct node *)malloc(sizeof(struct node));
    newnode->data = value;
    newnode->next = NULL;
    if (rear == NULL)
    {

        front = rear = newnode;
        printf("person %d entered \n", value);
        return;
    }
    rear->next = newnode;
    rear = newnode;
    printf("person %d entered\n", value);
}

void dequeue()
{

    struct node *temp;
    if (front == NULL)
    {
        printf("queue underflow");
        return;
    }
    temp = front;
    printf("person %d left \n", temp->data);
    free(temp);
    if (front == NULL)
        rear = NULL;
}
void displayqueue()
{
    struct node *temp = front;
    printf("!!!Queue!!!");
    while (temp != NULL)
    {
        printf("%d\t", temp->data);
        temp=temp->next;
    }
}

int main()
{
    int choice, data;
    while (1)
    {
        printf("----stack and queue-----");
        printf("\n1.push\n2.pop\n3.enqueue\n4.dequeue\n5.displaystack\n6.displayqueue\n7.exit\n");
        printf("enter choice!");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            printf("enter value");
            scanf("%d", &data);
            push(data);
            break;
        case 2:
            pop();
            break;
        case 3:
            printf("enter value");
            scanf("%d", &data);
            enqueue(data);
            break;
        case 4:
            dequeue();
            break;
        case 5:
            displaystack();
            break;
        case 6:
            displayqueue();
            break;
        case 7:
            exit(0);
            break;
        default:
            printf("enter valid choice!!");
            break;
        }
    }
    return 0;
}
