#include <iostream>
#include <string>

using namespace std;

class students
{
public:
    string name, blood, address, dob, contact, aadhar;
    int roll, marks, div;
    float percent;
    static int count;

    void inputdata()
    {
        cout << "Enter the name of the student: ";
        cin >> name;
        cout << "Enter the roll no: ";
        cin >> roll;
        cout << "Enter the division: ";
        cin >> div;
        cout << "Enter the Date of Birth: ";
        cin >> dob;
        cout << "Enter the Aadhar Number: ";
        cin >> aadhar;
        cout << "Enter the blood group: ";
        cin >> blood;
        cout << "Enter the address: ";
        cin >> address;
        cout << "Enter the telephone number: ";
        cin >> contact;
        cout << "Enter the percentage: ";
        cin >> marks;
    }

    static void display_data(students &s)
    {
        cout << endl;
    }

    friend void display_percentage(students s);
    static int return_count()
    {
        return count;
    }
};

void display_percentage(students s)
{
    cout << "The percent scored by " << s.name << " is " << s.percent << "%." << endl;
}

int main()
{
    int num = 0;
    cout << "Enter the number of student record you want to enter";
    cin >> num;

    students s[num];

    for (int i = 0; i < num; i++)
    {
        s[i].inputdata();
    }

    for (int i = 0; i < num; i++)
    {
        students::display_data(s[i]);
        display_percentage(s[i]);
    }

    cout << "Total number of students are :" << students::count << endl;

    return 0;
}