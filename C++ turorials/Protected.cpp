#include <bits/stdc++.h>

using namespace std;
class base{
    protected:
        int a;
    public:
        int b;
};

/*	                        Public Derivation      	  Private Derivation    	Protected Derivation
Private members           	Not Inherited              	Not Inherited           	Not Inherited              
Protected members             Protected                  Private                 	Protected                    
Public members           	   Public	                  Private                   Protected
*/
class derived{};

int main(){
    base b;
    derived d;
    return 0;
}

