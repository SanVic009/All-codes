#include<bits/stdc++.h>

using namespace std;

class Records{
public:
    int rollno;
    int marks;
    string name;
    friend class student;
};

class Hashing{
private:
    int rollno;
    int pos;

public:
    Hashing(){
        rollno = INT_MIN;
        pos = INT_MIN;
    }
    friend class student;
};

class student{
private:
    Records records;
    Hashing hash[10];
    int size;
    int relatiev_pos;

public:
    student(){
        size = sizeof(records);
        for(int i=0 ; i<10 ; i++){
            hash[i].rollno = INT_MIN;
            hash[i].pos = INT_MIN;
        }
        relatiev_pos=0;
    }

    void create_without_replacement(){
        char choice;
        int loc;
        fstream f;
        f.open("students.csv",ios::binary | ios::out );
        do{
            cout<<"Enter details of the student: "<<endl;

            cout<<"Roll No.: ";
            cin>>records.rollno;

            cout<<"Name: ";
            cin>>records.name;

            cout<<"Marks: ";
            cin>>records.marks;

            loc=records.rollno%10;

            if(hash[loc].rollno == INT_MIN){
                hash[loc].rollno = records.rollno;
                hash[loc].pos = relatiev_pos;
                f.write((char*)&records, size);
                relatiev_pos++;
            }
            else{
                for(int i = 1; i < 10; i++){
                    loc=(loc+1) % 10;
                    if(hash[loc].rollno == INT_MIN){
                        hash[loc].rollno = records.rollno;
                        hash[loc].pos = relatiev_pos;
                        f.write((char*)&records, size);
                        relatiev_pos++;
                        break;
                    }
                }
            }
            cout<<"If you want to continue, enter Y/y";
            cin>>choice;
        }while(choice=='Y' || choice=='y');
        f.close();
    }

    void create_without_replacement(){
        char choice;
        int loc;
        Hashing temp;
        fstream f;
        f.open("students.csv",ios::binary | ios::out );
        do{
            cout<<"Enter details of the student: "<<endl;

            cout<<"Roll No.: ";
            cin>>records.rollno;

            cout<<"Name: ";
            cin>>records.name;

            cout<<"Marks: ";
            cin>>records.marks;

            loc=records.rollno%10;

            if(hash[loc].rollno == INT_MIN){
                hash[loc].rollno = records.rollno;
                hash[loc].pos = relatiev_pos;
                f.write((char*)&records, size);
                relatiev_pos++;
            }
        }while(choice=='Y' || choice=='y');

    }
    
};

int main(){
    return 0;
}