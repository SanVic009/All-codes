#include<bits/stdc++.h>

using namespace std;

class n_queen{
private:
    vector<int>queen_pos;
    int n;

public:

    n_queen(int n){
        this->n = n;
        queen_pos.resize(n);
    }

    void display_board();
    void nq(int k);
    bool collision(int k, int i);
};

void n_queen::nq(int k ){
    for(int i=0; i<n; i++){
        if(collision(k, i)){
            queen_pos[k]=i;
            if(k==n-1)
                display_board();
            else
                nq(k+1);
        }
    }
}

bool n_queen::collision(int k, int i){
    for(int j=0; j<k; j++){
        if(queen_pos[j]==i || abs(queen_pos[j]-i) == abs(j-k)){
            return false;
        }
    }
    return true;
}

void n_queen::display_board(){
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            if(queen_pos[i] == j ){
                cout<<"Q";
            }
            else{
                cout<<"\t";
            }
        }
        cout<<endl;
        // cout<<"_____________"<<endl;
    }
    cout<<"________________--------------_______________"<<endl;
}

int main(){
    int n;
    cout<<"Enter the number of queens: ";
    cin>>n;
    n_queen queen(n);
    queen.nq(0);
    return 0;
}






