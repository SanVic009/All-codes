#include <bits/stdc++.h>

using namespace std;

// Student --> test, sports {DONE}
// test-->result
// sport-->result
class Students{
    protected:
        int rollNumber;
    public:
        void setNumber(int a){
            rollNumber=a;
        }

        void printNumber(void){
            cout<<"The roll number is : "<<rollNumber<<endl;
        }
};

class Test: virtual public Students{
    protected:
        float maths, phy;
    public:
        void setMarks(int m, int p){
            maths=m;
            phy=p;
        }
        void printMarks(void){
            cout<<"Your result is following: "<<endl<<"Maths :"<<maths<<endl<<"Physics : "<<phy<<endl;
        }
};

class Sports: virtual public Students{

    protected:
        int score;
    public:
        void setScore(int s){
            score =s;
        }
        void printScore(void){
            cout<<"Your scoer was :"<<score<<endl;
        }
};

class Result : public Test, public Sports{
    private:
        int total;
    public:
        void display(void){
            total = maths+phy+score;
            printNumber();
            printMarks();
            printScore();
            cout<<"Your total marks + score is : "<<total<<endl;
        }

};


int main(){
    Result Sanchit;
    Sanchit.setNumber(233);
    Sanchit.setMarks(34, 35);
    Sanchit.setScore(646);

    Sanchit.display();
    return 0;
}