#include <stdio.h>
#define SIZE 5  

int queue[SIZE];
int front = -1, rear = -1;


void insert() {
    int value;
    if (rear == SIZE - 1) {
        printf("\nQueue Overflow! Cannot insert element.\n");
    } else {
        printf("Enter the element to insert: ");
        scanf("%d", &value);
        if (front == -1)
            front = 0;  
        rear++;
        queue[rear] = value;
        printf("Inserted %d into the queue.\n", value);
    }
}


void delete() {
    if (front == -1 || front > rear) {
        printf("\nQueue Underflow! No elements to delete.\n");
    } else {
        printf("Deleted element: %d\n", queue[front]);
        front++;
    }
}


void display() {
    if (front == -1 || front > rear) {
        printf("\nQueue is empty!\n");
    } else {
        printf("\nQueue elements are: ");
        for (int i = front; i <= rear; i++) {
            printf("%d ", queue[i]);
        }
        printf("\n");
    }
}


int main() {
    int choice;
    printf("Queue Implementation using Array\n");

    while (1) {
        printf("\n--- Menu ---\n");
        printf("1. Insert\n");
        printf("2. Delete\n");
        printf("3. Display\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                insert();
                break;
            case 2:
                delete();
                break;
            case 3:
                display();
                break;
            case 4:
                printf("Exiting program.\n");
                return 0;
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }
}
