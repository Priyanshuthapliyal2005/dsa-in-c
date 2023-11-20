#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define MAX_HEIGHT 100000

// Tree Node structure
struct Node
{
    int data;
    struct Node *left;
    struct Node *right;
};

// Utility function to create a new Tree Node
struct Node *newNode(int val)
{
    struct Node *temp = (struct Node *)malloc(sizeof(struct Node));
    temp->data = val;
    temp->left = NULL;
    temp->right = NULL;

    return temp;
}

// Function to build a binary tree from the input string
struct Node *buildTree(char str[])
{
    // Corner Case
    if (str[0] == '\0' || str[0] == 'N')
        return NULL;

    // Creating vector of strings from input
    // string after splitting by space
    char *token = strtok(str, " ");

    // Create the root of the tree
    struct Node *root = newNode(atoi(token));
    token = strtok(NULL, " ");

    // Push the root to the queue
    struct Node *queue[MAX_HEIGHT];
    int front = -1;
    int rear = -1;
    queue[++rear] = root;

    // Starting from the second element
    int i = 1;
    while (rear != front)
    {
        struct Node *currNode = queue[++front];
        if (token != NULL)
        {
            currNode->left = newNode(atoi(token));
            queue[++rear] = currNode->left;
            token = strtok(NULL, " ");
        }

        if (token != NULL)
        {
            currNode->right = newNode(atoi(token));
            queue[++rear] = currNode->right;
            token = strtok(NULL, " ");
        }
    }

    return root;
}

// Function to print leaves of the binary tree
void printLeaves(struct Node *root)
{
    if (root != NULL)
    {
        printLeaves(root->left);

        if (root->left == NULL && root->right == NULL)
            printf("%d ", root->data);

        printLeaves(root->right);
    }
}

// Function to perform boundary order traversal
void boundaryOrderTraversal(struct Node *root)
{
    if (root != NULL)
    {
        printf("Processing node: %d\n", root->data);

        printf("Left Boundary: ");
        // Traverse left boundary (excluding root and leaves)
        if (root->left != NULL)
        {
            struct Node *node = root->left;
            while (node != NULL && (node->left != NULL || node->right != NULL))
            {
                printf("%d ", node->data);

                if (node->left != NULL)
                    node = node->left;
                else
                    node = node->right;
            }
        }
        printf("\n");

        printf("Leaves: ");
        // Traverse leaves from left to right
        printLeaves(root);
        printf("\n");

        printf("Right Boundary: ");
        // Traverse right boundary (excluding root and leaves)
        if (root->right != NULL)
        {
            struct Node *node = root->right;
            int stack[MAX_HEIGHT];
            int top = 0;

            while (node != NULL && (node->left != NULL || node->right != NULL))
            {
                stack[top++] = node->data;

                if (node->right != NULL)
                    node = node->right;
                else
                    node = node->left;
            }

            // Print the right boundary in reverse order
            while (top > 0)
            {
                printf("%d ", stack[--top]);
            }
        }
        printf("\n");
    }
}

int main()
{
    char input[] = "1 2 3 N N 4 5 N N N N";
    struct Node *root = buildTree(input);

    printf("Boundary Order Traversal: ");
    boundaryOrderTraversal(root);

    return 0;
}
