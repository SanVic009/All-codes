#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct Node
{
    char prn[10], name[30];
    int year;
    struct Node *next;
};

void create_list(struct Node *head){
    char choice = 'y';
    struct Node *temp = head;

    while(choice == 'y'){
        char prn[10], name[30];
        int year;

        struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
        newNode->next = NULL;

        printf("Enter the name of the record: ");
        scanf("%s", newNode->name);

        printf("Enter the prn: ");

        scanf("%s", newNode->prn);
        printf("Enter the year: ");
        scanf("%d", &newNode->year);


        if(head->next)
        {
            head = newNode;
            temp = newNode;
        } else {
            temp->next = newNode;
            temp = newNode;
        }
        getchar();
        printf("If you want to continue, press y: ");
        getchar();
        scanf("%c", &choice);
    }
}

void display(struct Node *head)
{
    struct Node *temp = head;

    temp = head;
    while (temp)
    {
        printf("%s\t", temp->prn);
        printf("%s\t", temp->name);
        printf("%d", temp->year);
        printf("\n");
        temp = temp->next;
    }
}

int main(){
    
    struct Node *head = (struct Node*) malloc(sizeof( struct Node));

    head->next = NULL;
    create_list(head);
    display(head);
    return 0;
}