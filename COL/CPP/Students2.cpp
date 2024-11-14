#include<bits/stdc++.h>

using namespace std;

class Students{
private:
    int rollNumber, division, telephoneNumber, aadharNumber, classNumber;
    string Name, dateOfBirth, bloodGroup, address;
    static int counter;
public:
    // Students(){
    //     // counter++;
    //     rollNumber - 23;
    //     division = 23;
    //     telephoneNumber = 23;
    //     aadharNumber = 23;
    //     classNumber = 23;
    //     Name = "Samuel";
    //     dateOfBirth = "12/12/12";
    //     bloodGroup = "B+";
    //     address = "23/23 Twenty Third street Twenty three";
    // }

    ~Students(){
         cout<<"Destructor has been called."<<endl;
    }

    Students()
    {
        // int roll, int div, int tele, int aadhar, int classNo, string name, string DOB, string blood, string add
        cout<<"Enter the name of the student: ";
        cin>>Name;    
        
        cout<<"Enter the class number :";

        cin>>classNumber;

        cout<<"Enter the division :";
        cin>>division;

        cout<<"Enter the roll number :";
        cin>>rollNumber;

        cout<<"Enter the contact number";
        cin>>telephoneNumber;

        cout<<"Enter the Aadhar number :";
        cin>>aadharNumber;
        
        cout<<"Enter the date of birth :";
        cin>>dateOfBirth;
        
        cout<<"Enter the blood group :";
        cin>>bloodGroup;
        
        cout<<"Enter the address :";
        cin>>address;
    }

    void displayValues(){
        cout<<"\n";
        cout<<"Name :"<<Name<<endl;
        cout<<"Class :"<<classNumber<<endl;
        cout<<"Div :"<<division<<endl;
        cout<<"Roll Number :"<<rollNumber<<endl;
        cout<<"Contact Number :"<<telephoneNumber<<endl;
        cout<<"Aadhar Number :"<<aadharNumber<<endl;
        cout<<"Date of Birth :"<<dateOfBirth<<endl;
        cout<<"Blood Group :"<<bloodGroup<<endl;
        cout<<"Address :"<<address<<endl;
    }


};

int main(){
    Students Samuel;

    Samuel.displayValues();
    cout<<1+1<<endl;    
    return 0;
}