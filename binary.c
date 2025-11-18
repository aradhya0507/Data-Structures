/* Implement binary tree and perform following operations: Creation of binary tree and traversal recursive and 
non-recursive.*/

#include <stdio.h>
#include <stdlib.h>

typedef struct TreeNode 
{
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
} TreeNode;

TreeNode* getnode() 
{
    TreeNode* newnode = (TreeNode*)malloc(sizeof(TreeNode));
    printf("Enter Data: ");
    scanf("%d", &newnode->val);
    newnode->left = NULL;
    newnode->right = NULL;
    return newnode;
}

void create(TreeNode* root) 
{
    char ch;
    TreeNode* temp = root;
    int flag = 0;
    TreeNode* curr = getnode();
    while (flag == 0) 
    {
        char direction;
        printf("\nEnter Direction (left: l / right: r): ");
        scanf(" %c", &direction);
        if (direction == 'l') 
        {
            if (temp->left == NULL) 
            {
                temp->left = curr;
                flag = 1;
            } 
            else 
            {
                temp = temp->left;
            }
        } 
        else if (direction == 'r') 
        {
            if (temp->right == NULL) 
            {
                temp->right = curr;
                flag = 1;
            } 
            else 
            {
                temp = temp->right;
            }
        }
    }
        printf("\nEnter 'y' to continue adding nodes (y/n): ");
        scanf(" %c", &ch);
    if (ch == 'y')
    {
        create(root); //Recurssion
    }
}

void preorder(TreeNode* node) 
{
    if (node == NULL) return;
    printf("%d ", node->val);
    preorder(node->left);
    preorder(node->right);
}

void preorder_nr(TreeNode* root) 
{
    if (root == NULL) return;

    TreeNode* stack[100];
    int top = -1;

    stack[++top] = root;

    while (top >= 0) 
    {
        TreeNode* node = stack[top--];
        printf("%d ", node->val);
        if (node->right) stack[++top] = node->right;
        if (node->left) stack[++top] = node->left;
    }
}

void inorder(TreeNode* node) 
{
    if (node == NULL) return;
    inorder(node->left);
    printf("%d ", node->val);
    inorder(node->right);
}

void inorder_nr(TreeNode* root) 
{
    TreeNode* stack[100];
    int top = -1;
    TreeNode* current = root;

    while (current != NULL || top >= 0) 
    {
        while (current != NULL) 
        {
            stack[++top] = current;
            current = current->left;
        }
        current = stack[top--];
        printf("%d ", current->val);
        current = current->right;
    }
}

void postorder(TreeNode* node) 
{
    if (node == NULL) return;
    postorder(node->left);
    postorder(node->right);
    printf("%d ", node->val);
}

int main() 
{
    TreeNode* root = NULL;
    char choice;

    printf("Create a binary tree:\n");
    root = getnode();
    create(root);

    do 
    {
        printf("\nMenu:\n");
        printf("1. Preorder Traversal (Recursive)\n");
        printf("2. Preorder Traversal (Non-Recursive)\n");
        printf("3. Inorder Traversal (Recursive)\n");
        printf("4. Inorder Traversal (Non-Recursive)\n");
        printf("5. Postorder Traversal\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf(" %c", &choice);

        switch (choice) 
        {
            case '1':
                printf("Preorder Traversal (Recursive): ");
                preorder(root);
                printf("\n");
                break;
            case '2':
                printf("Preorder Traversal (Non-Recursive): ");
                preorder_nr(root);
                printf("\n");
                break;
            case '3':
                printf("Inorder Traversal (Recursive): ");
                inorder(root);
                printf("\n");
                break;
            case '4':
                printf("Inorder Traversal (Non-Recursive): ");
                inorder_nr(root);
                printf("\n");
                break;
            case '5':
                printf("Postorder Traversal: ");
                postorder(root);
                printf("\n");
                break;
            case '6':
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice! Please try again.\n");
        }
    } while (choice != '6');

    return 0;
}
