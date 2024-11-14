#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct node
{
    int prn;
    char name[24];
    int year;
    struct node *next;
};

struct node *createNode(int prn, char name[], int year)
{
    struct node *newNode = (struct node *)malloc(sizeof(struct node));

    newNode->prn = prn;
    strcpy(newNode->name, name);
    newNode->year = year;
    newNode->next = NULL;

    return newNode;
}

struct node *addMember(struct node *head, int prn, char name[], int year, int position)
{
    struct node *newNode = createNode(prn, name, year);
    struct node *temp = head;

    if (position == 1)
    { 
        newNode->next = head;
        head = newNode;
        return head;
    }

    int count = 1;
    while (temp != NULL && count < position - 1)
    {
        temp = temp->next;
        count++;
    }

    if (temp == NULL)
    {
        printf("Position not valid.\n");
        return head;
    }

    newNode->next = temp->next;
    temp->next = newNode;
    return head;
}

struct node *deleteMember(struct node *head, int position)
{
    struct node *temp = head, *prev;

    if (position == 1)
    { 
        head = head->next;
        free(temp);
        return head;
    }

    int count = 1;
    while (temp != NULL && count < position)
    {
        prev = temp;
        temp = temp->next;
        count++;
    }

    if (temp == NULL)
    {
        printf("Position not valid.\n");
        return head;
    }

    prev->next = temp->next;
    free(temp);
    return head;
}

int countMembers(struct node *head)
{
    struct node *temp = head;
    int count = 0;

    while (temp != NULL)
    {
        count++;
        temp = temp->next;
    }
    return count;
}

void displayMembers(struct node *head)
{
    if (head == NULL)
    {
        printf("The list is empty.\n");
        return;
    }

    struct node *temp = head;
    printf("Club Members:\n");
    while (temp != NULL)
    {
        printf("PRN: %d, Name: %s, Year: %d\n", temp->prn, temp->name, temp->year);
        temp = temp->next;
    }
}

struct node *mergeLists(struct node *head1, struct node *head2)
{
    if (!head1)
        return head2;
    if (!head2)
        return head1;

    struct node *mergedHead = NULL, *temp;

    if (head1->prn < head2->prn)
    {
        mergedHead = head1;
        head1 = head1->next;
    }
    else
    {
        mergedHead = head2;
        head2 = head2->next;
    }

    temp = mergedHead;
    while (head1 && head2)
    {
        if (head1->prn < head2->prn)
        {
            temp->next = head1;
            head1 = head1->next;
        }
        else
        {
            temp->next = head2;
            head2 = head2->next;
        }
        temp = temp->next;
    }

    if (head1)
        temp->next = head1;
    if (head2)
        temp->next = head2;

    return mergedHead;
}

struct node *reverseList(struct node *head)
{
    struct node *prev = NULL, *curr = head, *next = NULL;

    while (curr != NULL)
    {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }

    head = prev;
    return head;
}

void sortList(struct node *head)
{
    struct node *i, *j;
    int tempPrn;
    char tempName[24];
    int tempYear;

    for (i = head; i != NULL; i = i->next)
    {
        for (j = i->next; j != NULL; j = j->next)
        {
            if (i->prn > j->prn)
            {
                tempPrn = i->prn;
                i->prn = j->prn;
                j->prn = tempPrn;

                strcpy(tempName, i->name);
                strcpy(i->name, j->name);
                strcpy(j->name, tempName);

                tempYear = i->year;
                i->year = j->year;
                j->year = tempYear;
            }
        }
    }
}

int main()
{
    struct node *head = NULL;
    
    int choice, prn, year, position;
    char name[24];

    while (1)
    {
        printf("\nPinnacle Club Menu\n");
        printf("1. Add Member\n2. Delete Member\n3. Display Members\n4. Count Members\n5. Reverse List\n6. Sort List\n7. Merge Lists\n8. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("Enter PRN: ");
            scanf("%d", &prn);
            printf("Enter Name: ");
            scanf("%s", name);
            printf("Enter Year: ");
            scanf("%d", &year);
            printf("Enter position (1 for President, last for Secretary, in-between for member): ");
            scanf("%d", &position);
            head = addMember(head, prn, name, year, position);
            break;

        case 2:
            printf("Enter position to delete (1 for President, last for Secretary, in-between for member): ");
            scanf("%d", &position);
            head = deleteMember(head, position);
            break;

        case 3:
            displayMembers(head);
            break;

        case 4:
            printf("Total members: %d\n", countMembers(head));
            break;

        case 5:
            head = reverseList(head);
            printf("List reversed.\n");
            break;

        case 6:
            sortList(head);
            printf("List sorted by PRN.\n");
            break;

        case 7:
        {
            struct node *head2 = NULL;
            printf("Enter details of the second list to merge.\n");
            printf("Enter PRN, Name, Year for 3 members:\n");
            for (int i = 0; i < 3; i++)
            {
                printf("Member %d: ", i + 1);
                scanf("%d %s %d", &prn, name, &year);
                head2 = addMember(head2, prn, name, year, countMembers(head2) + 1); // Add to head2
            }
            head = mergeLists(head, head2);
            printf("Lists merged.\n");
            break;
        }

        case 8:
            exit(0);

        default:
            printf("Invalid choice!\n");
        }
    }

    return 0;
}
