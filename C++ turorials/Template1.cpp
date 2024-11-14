#include <bits/stdc++.h>

using namespace std;

template <class T>

class Vector
{
    public:
        T * arr;
        int size;
        Vector(int m){
            size = m;
            arr = new T[size];
        }
        T dotProduct(Vector &v){
            T d= 0;
            for (int i = 0; i < size; i++)
            {
                d += this->arr[i]*v.arr[i];
            }
            return d;            
        }
};

int main(){

    Vector <int>v1(3);
    v1.arr[0] =2 ;
    v1.arr[1] =3 ;
    v1.arr[2] =4 ;

    Vector <int>v2(3);
    v2.arr[0] =2 ;
    v2.arr[1] =3 ;
    v2.arr[2] =4 ;
    
    Vector <float>v3(3);
    v3.arr[0] =2.34;
    v3.arr[1] =3.53;
    v3.arr[2] =4.65;

    Vector <float>v4(3);
    v4.arr[0] =2.67;
    v4.arr[1] =3.86;
    v4.arr[2] =4.23;
    int result = v1.dotProduct(v2);
    cout<<result<<endl;
    
    float final = v3.dotProduct(v4);
    cout<<final<<endl;
    return 0;
}   