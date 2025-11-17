#include <stdio.h>
#include <stdlib.h>

// Structure of a node
struct Node {
    int data;
    struct Node *next;
};

// Function to create a new node
struct Node* createNode(int value) {
    struct Node *newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = NULL;
    return newNode;
}

// Insert at end
void insertEnd(struct Node **head, int value) {
    struct Node *newNode = createNode(value);

    if (*head == NULL) {   // if first node
        *head = newNode;
        return;
    }

    struct Node *temp = *head;
    while (temp->next != NULL)
        temp = temp->next;
    temp->next = newNode;
}

// Display List
void display(struct Node *head) {
    if (head == NULL) {
        printf("List is empty\n");
        return;
    }
    struct Node *temp = head;
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

// ----------- OPERATION 1: SORT LINKED LIST ----------------
void sortList(struct Node *head) {
    struct Node *i, *j;
    int temp;

    if (head == NULL) return;

    for (i = head; i->next != NULL; i = i->next) {
        for (j = i->next; j != NULL; j = j->next) {
            if (i->data > j->data) {
                temp = i->data;
                i->data = j->data;
                j->data = temp;
            }
        }
    }
}

// ----------- OPERATION 2: REVERSE LINKED LIST ----------------
struct Node* reverseList(struct Node *head) {
    struct Node *prev = NULL, *curr = head, *next = NULL;

    while (curr != NULL) {
        next = curr->next;     // store next node
        curr->next = prev;     // reverse link
        prev = curr;           // move prev
        curr = next;           // move current
    }

    return prev; // new head
}

// ----------- OPERATION 3: CONCATENATE TWO LISTS ----------------
struct Node* concatenate(struct Node *head1, struct Node *head2) {
    if (head1 == NULL) return head2;
    if (head2 == NULL) return head1;

    struct Node *temp = head1;
    while (temp->next != NULL)
        temp = temp->next;

    temp->next = head2;  // attach list2 at end of list1
    return head1;
}

// --------------------- MAIN PROGRAM --------------------------
int main() {
    struct Node *list1 = NULL;
    struct Node *list2 = NULL;
    int choice, value;

    while (1) {
        printf("\n----- MENU -----\n");
        printf("1. Insert into List 1\n");
        printf("2. Insert into List 2\n");
        printf("3. Display List 1\n");
        printf("4. Display List 2\n");
        printf("5. Sort List 1\n");
        printf("6. Reverse List 1\n");
        printf("7. Concatenate List 1 and List 2\n");
        printf("8. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value: ");
                scanf("%d", &value);
                insertEnd(&list1, value);
                break;
            case 2:
                printf("Enter value: ");
                scanf("%d", &value);
                insertEnd(&list2, value);
                break;
            case 3:
                printf("List 1: ");
                display(list1);
                break;
            case 4:
                printf("List 2: ");
                display(list2);
                break;
            case 5:
                sortList(list1);
                printf("List 1 sorted.\n");
                break;
            case 6:
                list1 = reverseList(list1);
                printf("List 1 reversed.\n");
                break;
            case 7:
                list1 = concatenate(list1, list2);
                printf("Lists concatenated. New List 1:\n");
                display(list1);
                list2 = NULL; // list2 becomes empty
                break;
            case 8:
                exit(0);
            default:
                printf("Invalid choice!\n");
        }
    }

    return 0;
}
