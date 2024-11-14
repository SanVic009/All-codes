#include <stdio.h>

struct Students
{
    int rollNumber, division;
    char name[10], address[100];
    float percentage;
};

void swap(struct Students *a, struct Students *b)
{
    struct Students temp = *a;
    *a = *b;
    *b = temp;
}

void rollBubbleSort(struct Students arr[50], int size)
{
    for (int i = size - 1; i > 0; i--)
    {
        for (int j = 0; j < i; j++)
        {
            if (arr[j].rollNumber > arr[j + 1].rollNumber)
                swap(&arr[j], &arr[j + 1]);
        }
    }
}

void displayRecord(struct Students arr[50], int size)
{
    for (int i = 0; i < size; i++)
    {
        printf("Here are the records of %s", arr[i].name);
        printf("\nRoll number: %d", arr[i].rollNumber);
        printf("\nDivison: %d", arr[i].division);
        printf("\nPercentage: %.3f", arr[i].percentage);
        printf("\nAddress: %s", arr[i].address);
        
        printf("\n");
        printf("\n");
    }
}

int main()
{

    int size;
    struct Students arr[50];

    printf("Enter the number of records to enter: ");
    scanf("%d", &size);

    for (int i = 0; i < size; i++)
    {
        printf("\nEnter the name of student %d :", i + 1);
        scanf("%s", arr[i].name);
        getchar();

        printf("\nEnter the roll number :");
        scanf("%d", &arr[i].rollNumber);
        getchar();

        printf("\nEnter the division of the student :");
        scanf("%d", &arr[i].division);
        getchar();

        printf("\nEnter the percentage :");
        scanf("%f", &arr[i].percentage);
        getchar();

        printf("\nEnter the address: ");
        scanf("%[^\n]%*c", arr[i].address);
        getchar();
    }

    displayRecord(arr, size);
    rollBubbleSort(arr, size);
    displayRecord(arr, size);

    return 0;
}   