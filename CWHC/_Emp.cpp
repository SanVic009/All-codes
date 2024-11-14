#include <bits/stdc++.h>

using namespace std;

int main(){
    int n;
    for (int i = 0; i < 3; i++)
    {
        cout<<"Enter the length of the employee id : ";
        cin>>n;
        getchar();
        char* ptr;
        ptr = (char *) calloc(n, sizeof(int));
        cout<<"Enter the id of employee"<<endl;
        cin>>ptr;
        getchar();
        cout<<"The employee id is : "<<ptr<<endl;
        free(ptr);
    }
    return 0;
}

/* ~~~output~~~

Enter the length of the employee id : 3
Enter the id of employee
sdfs
The employee id is : sdfs

how is it possible if i specified that n is 3 and stil is taking 4 chars and not throwing a error

*/