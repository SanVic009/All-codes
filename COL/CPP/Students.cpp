#include<bits/stdc++.h>

using namespace std;

class Students{
private:
    int rollNumber, division, telephoneNumber, aadharNumber, classNumber;
    string Name, dateOfBirth, bloodGroup, address;
public:
    Students(){
        rollNumber - 23;
        division = 23;
        telephoneNumber = 23;
        aadharNumber = 23;
        classNumber = 23;
        Name = "Samuel";
        dateOfBirth = "12/12/12";
        bloodGroup = "B+";
        address = "23/23 Twenty Third street Twenty three";
    }

        
    // int size;
    // cout<<"Enter the size of record to be entered: ";
    // cin>>size;
    // Students arr[size];

    // for (int i = 0; i < size; i++)
    // {
    //     cout<<"Enter the ";
    // }// Students(int roll, int div, int tele, int aadhar, int classNo, string name, string DOB, string blood, string add)
    // {
    //     counter++;
    //     rollNumber = roll;
    //     division = div;
    //     telephoneNumber = tele;
    //     aadharNumber = aadhar;
    //     classNumber = classNo;
    //     Name = name;
    //     dateOfBirth = DOB;
    //     bloodGroup = blood;
    //     address = add;
    // }

    // void setRoll(int roll){
    //     rollNumber = roll;
    // }
    
    // void setDivision(int div){
    //     division = div;
    // }

    // void setTelephoneNumber(int tele){
    //     telephoneNumber = tele;
    // }

    // void setAadharNumber(int aadhar){
    //     aadharNumber = aadhar;
    // }

    // void setClassNumber(int classNo){
    //     classNumber = classNo;
    // }

    // void setName(string name){
    //     name = Name;
    // }

    // void setDOB(string DOB){
    //     dateOfBirth = DOB;
    // }

    // void setBloodGroup(string blood){
    //     bloodGroup = blood;
    // }

    // void setAddress(string add){
    //      address = add;
    // }

    ~Students(){
        cout<<"Destructor has been called."<<endl;
    }


    void displayValues(){
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
    cout<<"main ends"<<endl;
    
    return 0;
}