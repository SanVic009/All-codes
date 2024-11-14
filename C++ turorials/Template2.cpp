#include <bits/stdc++.h>

using namespace std;

template <class F1, class F2>
class Test
{
    public:
        F1 x;
        F2 y;
        Test(F1 a, F2 b){
            x = a;
            y = b;
        }

        void display(){
            cout<<"The value of X is :"<<this->x<<endl;
            cout<<"The value of Y is :"<<this->y<<endl;
        }
};

int main(){

    Test <int , float>v1(1, 4.34);
    v1.display();
    cout<<endl;
    Test <int , char>v2(1, 'd');
    v2.display();
  
    return 0;
}