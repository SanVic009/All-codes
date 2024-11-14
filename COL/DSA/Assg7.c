#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node
{
    char keyword[100];
    char meaning[100];
    struct Node *left;
    struct Node *right;
} Node;

Node *createNode(const char *keyword, const char *meaning)
{
    Node *newNode = (Node *)malloc(sizeof(Node));
    strcpy(newNode->keyword, keyword);
    strcpy(newNode->meaning, meaning);
    newNode->left = newNode->right = NULL;
    return newNode;
}

Node *insert(Node *root, const char *keyword, const char *meaning)
{
    if (root == NULL)
    {
        return createNode(keyword, meaning);
    }
    if (strcmp(keyword, root->keyword) < 0)
    {
        root->left = insert(root->left, keyword, meaning);
    }
    else if (strcmp(keyword, root->keyword) > 0)
    {
        root->right = insert(root->right, keyword, meaning);
    }
    return root;
}

Node *minValueNode(Node *node)
{
    Node *current = node;
    while (current && current->left != NULL)
    {
        current = current->left;
    }
    return current;
}

void delete(struct Node *root)
{
    struct Node *curr = root;
    struct Node *parent = NULL;
    struct Node *temp;
    struct Node *s;
    char data[100];

    printf("Enter the keyword to delete:\n");
    scanf("%s", data);

    while (curr != NULL && strcmp(curr->keyword, data) != 0)
    {
        parent = curr;
        if (strcmp(data, curr->keyword) < 0)
            curr = curr->left;
        else
            curr = curr->right;
    }

    if (curr == NULL)
    {
        printf("Keyword not found!\n");
        return;
    }

    if (curr->left == NULL && curr->right == NULL)
    {
        if (curr == root)
            root = NULL;
        else if (parent->left == curr)
            parent->left = NULL;
        else
            parent->right = NULL;
        free(curr);
    }
    else if (curr->left == NULL || curr->right == NULL)
    {
        struct Node *child = (curr->left != NULL) ? curr->left : curr->right;
        if (curr == root)
            root = child;
        else if (parent->left == curr)
            parent->left = child;
        else
            parent->right = child;
        free(curr);
    }
    else
    {
        parent = curr;
        s = curr->right;
        while (s->left != NULL)
        {
            parent = s;
            s = s->left;
        }
        strcpy(curr->keyword, s->keyword);
        strcpy(curr->meaning, s->meaning);

        if (parent->left == s)
            parent->left = s->right;
        else
            parent->right = s->right;

        free(s);
    }
}

void levelOrderDisplay(Node *root)
{
    if (root == NULL)
    {
        printf("The dictionary is empty.\n");
        return;
    }
    Node **queue = (Node **)malloc(100 * sizeof(Node));
    int front = 0, rear = 0;
    queue[rear++] = root;
    while (front < rear)
    {
        Node *current = queue[front++];
        printf("%s: %s\n", current->keyword, current->meaning);
        if (current->left)
            queue[rear++] = current->left;
        if (current->right)
            queue[rear++] = current->right;
    }
    free(queue);
}

Node *copy(Node *root)
{
    if (root == NULL)
        return NULL;
    Node *newNode = createNode(root->keyword, root->meaning);
    newNode->left = copy(root->left);
    newNode->right = copy(root->right);
    return newNode;
}

void freeTree(Node *root)
{
    if (root == NULL)
        return;
    freeTree(root->left);
    freeTree(root->right);
    free(root);
}

void createMirror(Node *root)
{
    if (root == NULL)
        return;
    Node *temp = root->left;
    root->left = root->right;
    root->right = temp;
    createMirror(root->left);
    createMirror(root->right);
}

int main()
{
    Node *bst = NULL;
    int choice;
    char keyword[100], meaning[100];

    while (1)
    {
        printf("\nDictionary Menu:\n");
        printf("1. Insert a keyword\n");
        printf("2. Delete a keyword\n");
        printf("3. Create mirror image\n");
        printf("4. Display level-wise\n");
        printf("5. Copy the dictionary\n");
        printf("6. Exit\n");
        printf("Choose an option (1-6): ");
        scanf("%d", &choice);
        getchar();

        switch (choice)
        {
        case 1:
            printf("Enter the keyword: ");
            scanf(" %s", keyword);
            printf("Enter the meaning: ");
            scanf(" %s", meaning);
            bst = insert(bst, keyword, meaning);
            printf("Inserted: %s - %s\n", keyword, meaning);
            break;
        case 2:
            delete (bst);

            break;
        case 3:
            createMirror(bst);
            printf("Created mirror image of the dictionary.\n");
            break;
        case 4:
            printf("Level order display of the dictionary:\n");
            levelOrderDisplay(bst);
            break;
        case 5:
        {
            Node *copiedTree = copy(bst);
            printf("Copied the dictionary.\n");
            printf("Level order display of the copied dictionary:\n");
            levelOrderDisplay(copiedTree);
            freeTree(copiedTree);
            break;
        }
        case 6:
            printf("Exiting the program.\n");
            freeTree(bst);
            return 0;
        default:
            printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}