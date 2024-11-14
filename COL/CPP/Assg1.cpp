#include <iostream>
#include <string>

using namespace std;

class Student
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
    static void displayinfo(Student &s)
    {
        cout << "Name: " << s.name << endl;
        cout << "Roll Number: " << s.roll << endl;
        cout << "Division: " << s.div << endl;
        cout << "Date of Birth: " << s.dob << endl;
        cout << "Aadhar Number: " << s.aadhar << endl;
        cout << "Blood Group: " << s.blood << endl;
        cout << "Contact Address: " << s.address << endl;
        cout << "Telephone Number: " << s.contact << endl;
    }
    friend void displaypercent(Student &s);
    static int studentcount()
    {
        return count;
    }
};

int Student::count = 0;

void displaypercent(Student &s)
{
    cout << "Percentage Marks: " << s.marks << "%" << endl;
}

int main()
{
    int numstudent = 2;
    Student s[numstudent];
    for (int i = 0; i < numstudent; i++)
    {
        cout << "Enter details for student " << i + 1 << ":" << endl;
        s[i].inputdata();
    }
    for (int i = 0; i < numstudent; i++)
    {
        cout << "Displaying details of student " << i + 1 << ":" << endl;
        Student::displayinfo(s[i]);
        displaypercent(s[i]);
    }
    cout << "Total number of students: " << Student::studentcount() << endl;
    return 0;
}