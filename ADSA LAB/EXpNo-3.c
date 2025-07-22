#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int key;
    struct Node *left;
    struct Node *right;
};

struct Node *createNode(int key)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->key = key;
    newNode->left = newNode->right = NULL;
    return newNode;
}

struct Node *insert(struct Node *root, int key)
{
    if (root == NULL)
    {
        return createNode(key);
    }
    if (key < root->key)
    {
        root->left = insert(root->left, key);
    }
    else
    {
        root->right = insert(root->right, key);
    }
    return root;
}

struct Node *search(struct Node *root, int key)
{
    if (root == NULL || root->key == key)
    {
        return root;
    }
    if (key < root->key)
    {
        return search(root->left, key);
    }
    return search(root->right, key);
}

struct Node *minValueNode(struct Node *node)
{
    struct Node *current = node;
    while (current && current->left != NULL)
    {
        current = current->left;
    }
    return current;
}

struct Node *maxValueNode(struct Node *node)
{
    struct Node *current = node;
    while (current && current->right != NULL)
    {
        current = current->right;
    }
    return current;
}

struct Node *deleteNode(struct Node *root, int key)
{
    if (root == NULL)
    {
        return root;
    }
    if (key < root->key)
    {
        root->left = deleteNode(root->left, key);
    }
    else if (key > root->key)
    {
        root->right = deleteNode(root->right, key);
    }
    else
    {

        if (root->left == NULL)
        {
            struct Node *temp = root->right;
            free(root);
            return temp;
        }
        else if (root->right == NULL)
        {
            struct Node *temp = root->left;
            free(root);
            return temp;
        }

        struct Node *temp = minValueNode(root->right);
        root->key = temp->key;
        root->right = deleteNode(root->right, temp->key);
    }
    return root;
}

void makeEmpty(struct Node *root)
{
    if (root != NULL)
    {
        makeEmpty(root->left);
        makeEmpty(root->right);
        free(root);
    }
}

void inorder(struct Node *root)
{
    if (root != NULL)
    {
        inorder(root->left);
        printf("%d ", root->key);
        inorder(root->right);
    }
}

void preorder(struct Node *root)
{
    if (root != NULL)
    {
        printf("%d ", root->key);
        preorder(root->left);
        preorder(root->right);
    }
}

void postorder(struct Node *root)
{
    if (root != NULL)
    {
        postorder(root->left);
        postorder(root->right);
        printf("%d ", root->key);
    }
}

void display(struct Node *root, int order)
{
    switch (order)
    {
    case 1:
        printf("In-order: ");
        inorder(root);
        break;
    case 2:
        printf("Pre-order: ");
        preorder(root);
        break;
    case 3:
        printf("Post-order: ");
        postorder(root);
        break;
    default:
        printf("Invalid order!\n");
    }
    printf("\n");
}

int main()
{
    struct Node *root = NULL;
    int choice, key, order;

    printf("Name:Rutuja Dundesh Mane\nPRN:2324000718\nDiv:A\nRoll No:44\n");
    printf("-----------------------------------------");

    while (1)
    {
        printf("\nBST Operations Menu:\n");
        printf("1. Insert\n");
        printf("2. Delete\n");
        printf("3. Find\n");
        printf("4. Find Min\n");
        printf("5. Find Max\n");
        printf("6. Display\n");
        printf("7. Make Empty\n");
        printf("8. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("Enter key to insert: ");
            scanf("%d", &key);
            root = insert(root, key);
            break;
        case 2:
            printf("Enter key to delete: ");
            scanf("%d", &key);
            root = deleteNode(root, key);
            break;
        case 3:
            printf("Enter key to find: ");
            scanf("%d", &key);
            if (search(root, key))
            {
                printf("Key %d found in the BST.\n", key);
            }
            else
            {
                printf("Key %d not found in the BST.\n", key);
            }
            break;
        case 4:
            if (root)
            {
                struct Node *minNode = minValueNode(root);
                printf("Minimum value in the BST: %d\n", minNode->key);
            }
            else
            {
                printf("The BST is empty.\n");
            }
            break;
        case 5:
            if (root)
            {
                struct Node *maxNode = maxValueNode(root);
                printf("Maximum value in the BST: %d\n", maxNode->key);
            }
            else
            {
                printf("The BST is empty.\n");
            }
            break;
        case 6:
            printf("Select display order:\n");
            printf("1. In-order\n");
            printf("2. Pre-order\n");
            printf("3. Post-order\n");
            printf("Enter your choice: ");
            scanf("%d", &order);
            display(root, order);
            break;
        case 7:
            makeEmpty(root);
            root = NULL;
            printf("The BST has been emptied.\n");
            break;
        case 8:
            printf("Exiting...\n");
            exit(0);
        default:
            printf("Invalid choice! Please try again.\n");
        }
    }

    return 0;
}
