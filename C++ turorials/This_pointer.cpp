#include <bits/stdc++.h>

using namespace std;

// "THIS"  is a keyword which is a pointer which points to the object which invokes the member function.
class This{
    int a;
    public:
        void set_Data(int a){
            this->a=a;
        }

        This & set_Data2(int a){
            this->a= a;
            return *this;
        }

        void get_Data(void){
            cout<<"The value of a is "<<a<<"\n";
        }
};

int main(){
    This a, b;

    a.set_Data(5);
    a.get_Data();
    
    b.set_Data2(2).get_Data();
    return 0;
}