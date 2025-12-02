#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *next;
    struct node *prev;
};
struct node *head = NULL;
struct node *createnode(int value)
{
    struct node *newnode = (struct node *)malloc(sizeof(struct node));
    newnode->data = value;
    newnode->prev = NULL;
    newnode->next = NULL;
    return newnode;
}
void insertatbegining(int value)
{
    struct node *newnode = (struct node *)malloc(sizeof(struct node));
    newnode->data = value;
    newnode->prev = NULL;
    newnode->next = NULL;

    if (head == NULL)
    {
        head = newnode;
        return;
    }

    newnode->next = head;
    head->prev = newnode;
    head = newnode;

    printf("%d inserted", value);
}

void deleteatposition(int key)
{
    if (head == NULL)
    {
        printf("empty list!!");
        return;
    }
    struct node *temp = head;
    while (temp != NULL && temp->data != key)
        temp = temp->next;
    if (temp == NULL)
    {
        printf("%d not found", key);
        return;
    }
    if (temp->prev != NULL)
        temp->prev->next = temp->next;
    else
        head = temp->next;
    if (temp->next != NULL)
        temp->next->prev = temp->prev;
    printf("deleted node with %d", key);
    free(temp);
}

void display()
{
    struct node *temp = head;
    printf("list:");
    while (temp != NULL)
    {
        printf("%d\t", temp->data);
        temp=temp->next;
    }
    printf("\n");
}
int main()
{
    int choice, data, key;
    while (1)
    {
        printf("_____linked lis__");
        printf("\n1.insertatbeginning\n2.deleteatposition\n3.display\n4.exit\n");
        printf("enter choice");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            printf("enter value");
            scanf("%d", &data);
            insertatbegining(data);
            break;
        case 2:
            printf("enter key");
            scanf("%d", &key);
            deleteatposition(key);
            break;
        case 3:
            display();
            break;
        case 4:
            exit(0);
            break;
        default:
            printf("enter valid choice!");
        }
    }
}