#include <iostream>
#include <vector>

using namespace std;

int fib(int n){
    vector <int> naci(n+1);
    if( n == 0 || n == 1)
        return n;

    naci[0] = 0;
    naci[1] = 1;

    for(int i = 2; i <= n; i ++){
        naci[i] = naci [i-1] + naci[i -2];
    }
    return naci[n];
}

int main(){

    int x =20;
    for (int i = 0; i < x; i++)
    {
        cout<<fib(i)<<endl;
    }
    // cout<<fib(7);
    
    return 0;
}