#include <stdio.h>
#include <stdlib.h>

struct node 
{
    int info;
    struct node* left;
    struct node* right;
};

struct node* root = NULL;

struct node* createnode(int data) 
{
    struct node* newnode = (struct node*)malloc(sizeof(struct node));
    newnode->info = data;
    newnode->left = NULL;
    newnode->right = NULL;
    return newnode;
}

struct node* insertion(struct node* node, int value) 
{
    
    if (node == NULL)
        return createnode(value);
    if (value < node->info)
        node->left = insertion(node->left, value);
    else
        node->right = insertion(node->right, value);
    return node;
}

void inorder(struct node* node) 
{
    if (node == NULL)
        return;
    inorder(node->left);
    printf("%d ", node->info);
    inorder(node->right);
}

void postorder(struct node* node) 
{
    if (node == NULL)
        return;
    postorder(node->left);
    postorder(node->right);
    printf("%d ", node->info);
}

void preorder(struct node* node)
{
    if (node == NULL)
        return;
    printf("%d ", node->info);
    preorder(node->left);
    pre10order(node->right);
}
int main() 
{
    int n, value;

    printf("Enter the number of nodes to insert: ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++) 
    {
        printf("Enter value %d: ", i + 1);
        scanf("%d", &value);
        root = insertion(root, value);
    }

    printf("Inorder traversal: ");
    inorder(root);
    printf("\n");
    printf("Preorder traversal: ");
    preorder(root);
    printf("\n");
    printf("Postorder traversal: ");
    postorder(root);
    printf("\n");
    return 0;
}