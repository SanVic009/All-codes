#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct tbtnode
{
    int data;
    int lbit, rbit;
    struct tbtnode *right;
    struct tbtnode *left;
};

void create(struct tbtnode *head)
{
    int ch;
    char choice;
    struct tbtnode *root;
    root = (struct tbtnode *)malloc(sizeof(struct tbtnode));

    printf("Enter the Root Data: ");
    scanf("%d", &root->data);
    head->lbit = 1;
    head->left = root;
    root->left = head;
    root->lbit = 0;
    root->rbit = 0;
    root->right = head;

    do
    {
        int flag = 0;
        struct tbtnode *temp = root;
        struct tbtnode *curr;
        curr = (struct tbtnode *)malloc(sizeof(struct tbtnode));
        curr->lbit = 0;
        curr->rbit = 0;
        printf("Enter data for new node: ");
        scanf("%d", &curr->data);

        while (flag == 0)
        {
            printf("Do you want to add as a left or right child of %d? (l: left, r: right): ", temp->data);
            scanf(" %c", &choice);

            if (choice == 'l' || choice == 'L')
            {
                if (temp->lbit == 0)
                {
                    curr->right = temp;
                    curr->left = temp->left;
                    temp->left = curr;
                    temp->lbit = 1;
                    flag = 1;
                }
                else
                {
                    temp = temp->left;
                }
            }
            else if (choice == 'r' || choice == 'R')
            {
                if (temp->rbit == 0)
                {
                    curr->left = temp;
                    curr->right = temp->right;
                    temp->right = curr;
                    temp->rbit = 1;
                    flag = 1;
                }
                else
                {
                    temp = temp->right;
                }
            }
        }
        printf("Do you want to continue ? (1: Yes, 2: No): ");
        scanf("%d", &ch);
    } while (ch == 1);
}

struct tbtnode *inordersucc(struct tbtnode *temp)
{
    if (temp->rbit == 0)
    {
        return temp->right;
    }
    struct tbtnode *x = temp->right;
    while (x->lbit == 1)
    {
        x = x->left;
    }
    return x;
}

void inorder(struct tbtnode *head)
{
    struct tbtnode *temp = head;
    printf("\nInorder Traversal: ");
    while (1)
    {
        temp = inordersucc(temp);
        if (temp == head)
        {
            break;
        }
        printf("%d ", temp->data);
    }
    printf("\n");
}

int main()
{
    struct tbtnode *head;
    head = (struct tbtnode *)malloc(sizeof(struct tbtnode));
    head->lbit = 0;
    head->rbit = 1;
    head->left = head;
    head->right = head;

    create(head);
    inorder(head);

    return 0;
}