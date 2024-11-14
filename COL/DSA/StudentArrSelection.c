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

void rollSelectionSort(struct Students arr[], int size)
{
    for (int i = 0; i < size; i++)
    {
        int minIndex = i;
        for (int j = i; j < size; j++)
        {
            if (arr[j].rollNumber < arr[minIndex].rollNumber)
                minIndex = j;
        }
        if (minIndex != i)
            swap(&arr[minIndex], &arr[i]);
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

void input(struct Students arr[], int size){


}

int main()
{
    FILE *file = fopen("input.txt", "r");
    if (file == NULL) {
        printf("Error opening file!\n");
        return 1;
    }
    int size;
    fscanf(file, "%d", &size);
    struct Students arr[50];

    // printf("Enter the number of records to enter: ");
    // scanf("%d", &size);

    for (int i = 0; i < size; i++)
    {
        // printf("\nEnter the name of student %d :", i + 1);
        // scanf("%s", arr[i].name);
        // getchar();

        // printf("\nEnter the roll number :");
        // scanf("%d", &arr[i].rollNumber);
        // getchar();

        // printf("\nEnter the division of the student :");
        // scanf("%d", &arr[i].division);
        // getchar();

        // printf("\nEnter the percentage :");
        // scanf("%f", &arr[i].percentage);
        // getchar();

        // printf("\nEnter the address: ");
        // scanf("%[^\n]%*c", arr[i].address);
        // getchar();
        fscanf(file, "%9s", arr[i].name);
        fscanf(file, "%d", &arr[i].rollNumber);
        fscanf(file, "%d", &arr[i].division);
        fscanf(file, "%f", &arr[i].percentage);
        fscanf(file, " %[^\n]%*c", arr[i].address);
    }

    displayRecord(arr, size);
    rollSelectionSort(arr, size);
    displayRecord(arr, size);

    return 0;
}