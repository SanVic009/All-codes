#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;

class record
{
    int rollno, marks;
    char name[20];
    friend class student;
};

class hashing
{
    int rollno, pos;

public:
    hashing()
    {
        rollno = -1;
        pos = -1;
    }
    friend class student;
};

class student
{
    record rec;
    hashing h[10];
    int s, relt;

public:
    student();
    void create_wor();
    void create_wr();
    void modify();
    void retrieve();
    void delete_rec();
    void display();
    void displayall();
    void rebuild_hash_table();
};

student::student()
{
    s = sizeof(record);
    relt = 0;
    for (int i = 0; i < 10; i++)
    {
        h[i].rollno = -1;
        h[i].pos = -1;
    }
    rebuild_hash_table();
}

void student::rebuild_hash_table()
{
    ifstream f("student.txt", ios::binary);
    if (!f)
        return;
    int pos = 0;
    while (f.read((char *)&rec, sizeof(record)))
    {
        int loc = rec.rollno % 10;
        while (h[loc].rollno != -1)
            loc = (loc + 1) % 10;
        h[loc].rollno = rec.rollno;
        h[loc].pos = pos;
        pos++;
    }
    relt = pos;
    f.close();
}

void student::create_wr()
{
    char ans;
    fstream f("student.txt", ios::binary | ios::in | ios::out | ios::app);
    do
    {
        cout << "Enter the details:\n";
        cout << "Roll no:\t";
        cin >> rec.rollno;
        cout << "Name:\t";
        cin >> rec.name;
        cout << "Marks:\t";
        cin >> rec.marks;

        int loc = rec.rollno % 10;
        if (h[loc].rollno == -1)
        {
            h[loc].rollno = rec.rollno;
            h[loc].pos = relt;
        }
        else
        {
            int i = 1;
            while (h[(loc + i) % 10].rollno != -1 && i < 10)
                i++;
            if (i == 10)
            {
                cout << "Hash table full. Cannot insert.\n";
                return;
            }
            loc = (loc + i) % 10;
            h[loc].rollno = rec.rollno;
            h[loc].pos = relt;
        }

        f.write((char *)&rec, s);
        relt++;
        cout << "Do you want to add next student record? (y/n): ";
        cin >> ans;
    } while (ans == 'y' || ans == 'Y');
    f.close();
}

void student::create_wor()
{
    char ans;
    fstream f("student.txt", ios::binary | ios::in | ios::out | ios::app);
    do
    {
        cout << "Enter the details:\n";
        cout << "Roll no:\t";
        cin >> rec.rollno;
        cout << "Name:\t";
        cin >> rec.name;
        cout << "Marks:\t";
        cin >> rec.marks;

        int loc = rec.rollno % 10;
        int i = 0;
        while (h[(loc + i) % 10].rollno != -1 && i < 10)
            i++;

        if (i == 10)
        {
            cout << "Hash table full. Cannot insert.\n";
            return;
        }

        loc = (loc + i) % 10;
        h[loc].rollno = rec.rollno;
        h[loc].pos = relt;

        f.write((char *)&rec, s);
        relt++;

        cout << "Do you want to add next student record? (y/n): ";
        cin >> ans;
    } while (ans == 'y' || ans == 'Y');
    f.close();
}

void student::delete_rec()
{
    int roll;
    cout << "Enter the roll no to be deleted: ";
    cin >> roll;

    fstream f("student.txt", ios::binary | ios::in);
    fstream t("temp.txt", ios::binary | ios::out);
    int pos = 0;
    relt = 0;

    for (int i = 0; i < 10; i++)
    {
        h[i].rollno = -1;
        h[i].pos = -1;
    }

    while (f.read((char *)&rec, sizeof(record)))
    {
        if (rec.rollno != roll)
        {
            t.write((char *)&rec, sizeof(record));
            int loc = rec.rollno % 10;
            while (h[loc].rollno != -1)
                loc = (loc + 1) % 10;
            h[loc].rollno = rec.rollno;
            h[loc].pos = pos++;
        }
    }

    relt = pos;
    f.close();
    t.close();
    remove("student.txt");
    rename("temp.txt", "student.txt");
}

void student::modify()
{
    int roll;
    cout << "Enter roll number to modify: ";
    cin >> roll;

    fstream f("student.txt", ios::binary | ios::in | ios::out);
    bool found = false;

    for (int i = 0; i < 10; i++)
    {
        if (h[i].rollno == roll)
        {
            f.seekg(h[i].pos * sizeof(record), ios::beg);
            f.read((char *)&rec, sizeof(record));

            cout << "Current Record:\n";
            cout << "Roll No: " << rec.rollno << "\nName: " << rec.name << "\nMarks: " << rec.marks << endl;

            cout << "Enter new name: ";
            cin >> rec.name;
            cout << "Enter new marks: ";
            cin >> rec.marks;

            f.seekp(h[i].pos * sizeof(record), ios::beg);
            f.write((char *)&rec, sizeof(record));
            found = true;
            break;
        }
    }
    if (!found)
        cout << "Record not found.\n";
    f.close();
}

void student::display()
{
    int roll;
    cout << "Enter roll number to display: ";
    cin >> roll;

    fstream f("student.txt", ios::binary | ios::in);
    bool found = false;

    for (int i = 0; i < 10; i++)
    {
        if (h[i].rollno == roll)
        {
            f.seekg(h[i].pos * sizeof(record), ios::beg);
            f.read((char *)&rec, sizeof(record));
            cout << "Roll No: " << rec.rollno << "\nName: " << rec.name << "\nMarks: " << rec.marks << endl;
            found = true;
            break;
        }
    }
    if (!found)
        cout << "Record not found.\n";
    f.close();
}

void student::displayall()
{
    fstream f("student.txt", ios::binary | ios::in);
    cout << "\n--- All Student Records ---\n";
    while (f.read((char *)&rec, sizeof(record)))
    {
        cout << "Roll No: " << rec.rollno << "\tName: " << rec.name << "\tMarks: " << rec.marks << endl;
    }
    f.close();
}

int main()
{
    student s;
    int choice;
    do
    {
        cout << "\n--- Student Record System ---\n";
        cout << "1. Create with Replacement\n";
        cout << "2. Create without Replacement\n";
        cout << "3. Delete a Record\n";
        cout << "4. Modify a Record\n";
        cout << "5. Display a Record\n";
        cout << "6. Display All Records\n";
        cout << "7. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            s.create_wr();
            break;
        case 2:
            s.create_wor();
            break;
        case 3:
            s.delete_rec();
            break;
        case 4:
            s.modify();
            break;
        case 5:
            s.display();
            break;
        case 6:
            s.displayall();
            break;
        case 7:
            cout << "Exiting...\n";
            break;
        default:
            cout << "Invalid choice. Try again.\n";
        }
    } while (choice != 7);

    return 0;
}