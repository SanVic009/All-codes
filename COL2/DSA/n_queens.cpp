#include <iostream>
#include <cmath>

using namespace std;

class nqueen{
    int x[10] , n;

    public:
        void NQueen(int k, int n);
        bool Place(int k, int i);
        void display(int n);
};

/// @brief this checks if there is queen blocking at index [k,i]
/// @param k row index
/// @param i column index
/// @return True: if square not blocked. False if conflict is present
bool nqueen::Place(int k, int i) {
    for (int j = 1; j < k; j++) {
        if (x[j] == i || abs(x[j] - i) == abs(j - k))
            return false;
    }
    return true;
}


void nqueen::display(int n){
    for(int i = 1 ; i<=n ; i++){
        for(int j = 1 ; j<=n ; j++){
            if(x[i]==j){
                cout<<"Q";
            }
            else{
                cout << ".";
            }
        }
        cout<<endl;
    }
    cout<<endl;
}

void nqueen::NQueen(int k, int n) {
    for (int i = 1; i <= n; i++) {
        if (Place(k, i)) {
            x[k] = i;
            if (k == n) {
                display(n);
            } else {
                NQueen(k + 1, n);
            }
        }
    }
}

int main() {
    nqueen solver;
    int n;
    cout << "Enter number of queens: ";
    cin >> n;
    solver.NQueen(1,n);
    return 0;
}