#include <stdio.h>

typedef struct bst
{
    int data;
    struct bst *left;
    struct bst *right;
} node;
node *create()
{
    node *temp;
    printf("enter data:");
    temp = (node *)malloc(sizeof(node));
    scanf("%d", &temp->data);
    temp->left = temp->right = NULL;
    return temp;
}
void insert(node *root, node *temp)
{
    if (temp->data < root->data)
    {
        if (root->left != NULL)
            insert(root->left, temp);
        else
            root->left = temp;
    }
    else if(temp->data > root->data)
    {

        if (temp->data > root->data)
        {
            if (root->right != NULL)
                insert(root->right, temp);
        }
        else
            root->right = temp;
    }
}
void postorder(node *root)
{
    if (root != NULL)
    {
        postorder(root->left);
        postorder(root->right);
        printf("%d", root->data);
    }
}
void inorder(node *root)
{
    if (root != NULL)
    {
        inorder(root->left);
        printf("%d", root->data);
        inorder(root->right);
    }
}
void preorder(node *root)
{
    if (root != NULL)
    {
        printf("%d", root->data);
        preorder(root->left);
        preorder(root->right);
    }
}
int main()
{
    int choice;
    node *root = NULL, *temp;

    while (1)
    {
        printf("\n--- BST MENU ---\n");
        printf("1. Insert\n");
        printf("2. Inorder Traversal\n");
        printf("3. Preorder Traversal\n");
        printf("4. Postorder Traversal\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            temp = create();
            if (root == NULL)
                root = temp;
            else
                insert(root, temp);
            break;

        case 2:
            printf("Inorder: ");
            inorder(root);
            printf("\n");
            break;

        case 3:
            printf("Preorder: ");
            preorder(root);
            printf("\n");
            break;

        case 4:
            printf("Postorder: ");
            postorder(root);
            printf("\n");
            break;

        case 5:
            printf("Exiting...\n");
            return 0;

        default:
            printf("Invalid choice! Try again.\n");
        }
    }
}
