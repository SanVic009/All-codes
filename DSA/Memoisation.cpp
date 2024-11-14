#include <iostream>
#include <vector>

using namespace std;

vector<int> memo(100, -1);
static int count = 0;

int fib(int n){
    count++;
    if(memo[n] != -1)
        return memo[n];
        
    if(n == 0 || n ==1 ){
        memo[n] == n;
        return n;
    }

    memo[n] = fib(n-1) + fib(n - 2);
    return memo[n];
}

int main(){
    int t = 7;
    while(t--)
    cout<<fib(t)<<endl;

    cout<<"Count is : "<<count<<endl;
    
    return 0;
}