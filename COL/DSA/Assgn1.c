/*
Sanchit Sovale
31
1032230669
*/
#include <stdio.h>
#include <string.h>

struct student
{
    int roll;
    int div;
    float percent;
    char name[20];
    char address[50];
};

void bubbleSort(struct student arr[], int n)
{
    int i, j;
    for (i = 0; i < n - 1; i++)
    {
        int swapped = 0;
        for (j = 0; j < n - i - 1; j++)
        {
            if (arr[j].roll > arr[j + 1].roll)
            {
                struct student temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
                swapped = 1;
            }
        }
        if (!swapped)
        {
            break;
        }
    }
}

void selectionSort(struct student arr[], int n)
{
    int i, j, minIndex;
    for (i = 0; i < n - 1; i++)
    {
        minIndex = i;
        for (j = i + 1; j < n; j++)
        {
            if (arr[j].roll < arr[minIndex].roll)
            {
                minIndex = j;
            }
        }
        if (minIndex != i)
        {
            struct student temp = arr[i];
            arr[i] = arr[minIndex];
            arr[minIndex] = temp;
        }
    }
}

void insertionSort(struct student arr[], int n)
{
    int i, j;
    struct student key;
    for (i = 1; i < n; i++)
    {
        key = arr[i];
        j = i - 1;

        while (j >= 0 && arr[j].roll > key.roll)
        {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}

int main()
{
    int numStudents, z;
    printf("Enter the number of students: ");
    scanf("%d", &numStudents);

    struct student students[numStudents];

    for (int i = 0; i < numStudents; i++)
    {
        printf("\nEnter details for student %d:\n", i + 1);
        printf("Roll No: ");
        scanf("%d", &students[i].roll);

        printf("Div: ");
        scanf("%d", &students[i].div);

        printf("Percentage: ");
        scanf("%f", &students[i].percent);

        printf("Name: ");
        scanf("%s", students[i].name);

        printf("Address: ");
        scanf(" %[^\n]", students[i].address);
    }

    printf("\nStudent data before sorting:\n");
    for (int i = 0; i < numStudents; i++)
    {
        printf("Student %d:\n", i + 1);
        printf("  Roll No: %d\n", students[i].roll);
        printf("  Div: %d\n", students[i].div);
        printf("  Percentage: %.2f\n", students[i].percent);
        printf("  Name: %s\n", students[i].name);
        printf("  Address: %s\n", students[i].address);
    }

    do {
        int choice;
        printf("\nChoose sorting method:\n");
        printf("1. Bubble Sort\n");
        printf("2. Selection Sort\n");
        printf("3. Insertion Sort\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            bubbleSort(students, numStudents);
            break;
        case 2:
            selectionSort(students, numStudents);
            break;
        case 3:
            insertionSort(students, numStudents);
            break;
        default:
            printf("Invalid choice.\n");
            continue; // Skip the rest of the loop if the choice is invalid
        }

        printf("\nStudent data after sorting by roll number:\n");
        for (int i = 0; i < numStudents; i++)
        {
            printf("Student %d:\n", i + 1);
            printf("  Roll No: %d\n", students[i].roll);
            printf("  Div: %d\n", students[i].div);
            printf("  Percentage: %.2f\n", students[i].percent);
            printf("  Name: %s\n", students[i].name);
            printf("  Address: %s\n", students[i].address);
        }
        
        printf("Press 1 to continue or any other key to exit: ");
        scanf("%d", &z);
    } while (z == 1);

    return 0;
}

/*
~~~~~~~~~~~~~~~~~~~~ OUTPUT ~~~~~~~~~~~~~~~~~~~~ 

PS C:\Users\Sanch\OneDrive\Sanchit\All codes\COL\DSAColl> cd "c:\Users\Sanch\OneDrive\Sanchit\All codes\COL\DSAColl\" ; if ($?) { gcc Assgn1.c -o Assgn1 } ; if ($?) { .\Assgn1 }

Enter the number of students: 3

Enter details for student 1:
Roll No: 11
Div: 1
Percentage: 11
Name: Rohan
Address: Pune

Enter details for student 2:
Roll No: 12
Div: 1
Percentage: 12
Name: Mohan
Address: Pune

Enter details for student 3:
Roll No: 13
Div: 1
Percentage: 13
Name: Sohan
Address: Pune

Student data before sorting:
Student 1:
  Roll No: 11
  Div: 1
  Percentage: 11.00
  Name: Rohan
  Address: Pune
Student 2:
  Roll No: 12
  Div: 1
  Percentage: 12.00
  Name: Mohan
  Address: Pune
Student 3:
  Roll No: 13
  Div: 1
  Percentage: 13.00
  Name: Sohan
  Address: Pune

Choose sorting method:
1. Bubble Sort
2. Selection Sort
3. Insertion Sort
Enter your choice: 1

Student data after sorting by roll number:
Student 1:
  Roll No: 11
  Div: 1
  Percentage: 11.00
  Name: Rohan
  Address: Pune
Student 2:
  Roll No: 12
  Div: 1
  Percentage: 12.00
  Name: Mohan
  Address: Pune
Student 3:
  Roll No: 13
  Div: 1
  Percentage: 13.00
  Name: Sohan
  Address: Pune
Press 1 to continue or any other key to exit: 1

Choose sorting method:
1. Bubble Sort
2. Selection Sort
3. Insertion Sort
Enter your choice: 2

Student data after sorting by roll number:
Student 1:
  Roll No: 11
  Div: 1
  Percentage: 11.00
  Name: Rohan
  Address: Pune
Student 2:
  Roll No: 12
  Div: 1
  Percentage: 12.00
  Name: Mohan
  Address: Pune
Student 3:
  Roll No: 13
  Div: 1
  Percentage: 13.00
  Name: Sohan
  Address: Pune
Press 1 to continue or any other key to exit: 1

Choose sorting method:
1. Bubble Sort
2. Selection Sort
3. Insertion Sort
Enter your choice: 3

Student data after sorting by roll number:
Student 1:
  Roll No: 11
  Div: 1
  Percentage: 11.00
  Name: Rohan
  Address: Pune
Student 2:
  Roll No: 12
  Div: 1
  Percentage: 12.00
  Name: Mohan
  Address: Pune
Student 3:
  Roll No: 13
  Div: 1
  Percentage: 13.00
  Name: Sohan
  Address: Pune
Press 1 to continue or any other key to exit: 2
*/