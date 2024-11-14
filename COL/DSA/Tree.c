#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define STACK_SIZE 100

typedef struct tree
{
    char data[10];
    struct tree *left;
    struct tree *right;
};

struct tree *stack[STACK_SIZE];
int top = -1;

void push(struct tree *node)
{
    if (top == STACK_SIZE - 1)
    {
        printf("Stack Overflow\n");
        return;
    }

    stack[++top] = node;
}

int is_empty()
{
    return top == -1;
}

struct tree *pop()
{
    if (is_empty())
    {
        printf("\nStack Underflow\n");
        return NULL;
    }

    struct tree *node = stack[top--];
    return node;
}

void create_r(struct tree *root)
{
    struct tree *temp = root;

    char choice;
    printf("Enter y if you want to insert to the LEFT of \"%s\" (y/n) : ", temp->data);
    scanf(" %c", &choice);
    getchar();

    if (choice == 'y')
    {
        struct tree *curr = (struct tree *)malloc(sizeof(struct tree));

        char d[10];
        printf("Enter the value of the current node: ");
        scanf("%s", d);
        getchar();
        strcpy(curr->data, d);
        curr->left = NULL;
        curr->right = NULL;

        temp->left = curr;

        create_r(curr);
    }

    printf("Enter y if you want to insert to the RIGHT of \"%s\" (y/n) : ", temp->data);
    scanf(" %c", &choice);
    getchar();

    if (choice == 'y')
    {
        struct tree *curr = (struct tree *)malloc(sizeof(struct tree));
        char d[10];
        printf("Enter the value of the current node: ");
        scanf("%s", d);
        getchar();
        strcpy(curr->data, d);
        curr->left = NULL;
        curr->right = NULL;

        temp->right = curr;

        create_r(curr);
    }
}

void create_nr(struct tree *root)
{
    char cont;
    do
    {
        struct tree *temp = root;
        int flag = 0;
        struct tree *curr = (struct tree *)malloc(sizeof(struct tree));
        printf("Enter the data for the new node: ");
        scanf("%s", curr->data);
        curr->left = NULL;
        curr->right = NULL;

        while (flag == 0)
        {
            char dir;
            printf("Enter l/r to go left or right: ");
            scanf(" %c", &dir);
            if (dir == 'l')
            {
                if (temp->left == NULL)
                {
                    temp->left = curr;
                    flag = 1;
                }
                temp = temp->left;
            }
            else if (dir == 'r')
            {
                if (!temp->right)
                {
                    temp->right = curr;
                    flag = 1;
                }
                temp = temp->right;
            }
        }
        printf("Press y to continue :");
        scanf(" %c", &cont);
    } while (cont == 'y' || cont == 'Y');
}

void inorder_r(struct tree *root)
{
    struct tree *temp = root;
    if (temp)
    {
        inorder_r(temp->left);
        printf("%s\t", temp->data);
        inorder_r(temp->right);
    }
}

void preorder_r(struct tree *root)
{
    struct tree *temp = root;
    if (temp)
    {
        printf("%s\t", temp->data);
        preorder_r(temp->left);
        preorder_r(temp->right);
    }
}

void postorder_r(struct tree *root)
{
    struct tree *temp = root;
    if (temp)
    {
        postorder_r(temp->left);
        postorder_r(temp->right);
        printf("%s\t", temp->data);
    }
}

void inorder_nr(struct tree *root)
{
    struct tree *temp = root;
    while (1)
    {
        while (temp)
        {
            push(temp);
            temp = temp->left;
        }
        if (is_empty())
            break;

        temp = pop();
        printf("%s\t", temp->data);
        temp = temp->right;
    }
}

void preorder_nr(struct tree *root)
{
    struct tree *temp = root;
    while (1)
    {
        while (temp)
        {
            printf("%s\t", temp->data);
            push(temp);
            temp = temp->left;
        }
        if (is_empty())
            break;
        temp = pop();
        temp = temp->right;
    }
}

void postorder_nr(struct tree *root)
{

    struct tree *temp = root;
    while (1)
    {
        while (temp)
        {
            push(temp);
            temp = temp->left;
        }
        if (stack[top]->right == NULL)
        {
            temp = pop();
            printf("%s\t", temp->data);
        }
        while (!is_empty() && stack[top]->right == temp)
        {
            temp = pop();
            printf("%s\t", temp->data);
        }
        if (is_empty())
            break;
        temp = stack[top]->right;
    }
}

int main()
{

    struct tree *root = (struct tree *)malloc(sizeof(struct tree));

    char val[10];
    printf("Enter the value of the root tree_node: ");
    -scanf("%s", val);
    getchar();
    strcpy(root->data, val);
    root->left = NULL;
    root->right = NULL;

    // create_r(root);
    create_nr(root);

    printf("\n\nIN_ORDER (R)\n");
    inorder_r(root);
    printf("\n\nIN_ORDER (NR)\n");
    inorder_nr(root);
    printf("\n\nPOST_ORDER (R)\n");
    postorder_r(root);
    printf("\n\nPOST_ORDER (NR)\n");
    postorder_nr(root);
    printf("\n\nPRE_ORDER (R)\n");
    preorder_r(root);
    printf("\n\nPRE_ORDER (NR)\n");
    preorder_nr(root);

    return 0;
}

/*
~~~~~~~~~~~~~~ OUTPUT ~~~~~~~~~~~~~~

Enter the value of the root tree_node: ajay
Enter the data for the new node: navin
Enter l/r to go left or right: l
Press y to continue :y
Enter the data for the new node: raveen
Enter l/r to go left or right: l
Enter l/r to go left or right: r
Press y to continue :y
Enter the data for the new node: heena
Enter l/r to go left or right: r
Press y to continue :n


IN_ORDER (R)
navin   raveen  ajay    heena

IN_ORDER (NR)
navin   raveen  ajay    heena

POST_ORDER (R)
raveen  navin   heena   ajay

POST_ORDER (NR)
raveen  navin   heena   ajay

PRE_ORDER (R)
ajay    navin   raveen  heena

PRE_ORDER (NR)
ajay    navin   raveen  heena
*/