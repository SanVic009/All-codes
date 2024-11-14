#include <bits/stdc++.h>

using namespace std;

long maxVal(vector<long> output){
    long max =0;
    for(auto it: output){
        if(it > max)
            max = it;
    }
    return max;
}

long arrayManipulation(int n, vector<vector<int>> queries){
    vector<long> output(n,0);
    for(int i = 0; i < n; i ++){
        int start = queries[i][1] -1;
        int end = queries[i][2];
        int val = queries[i][3];
        for(int j = start; j < end; j++){
            output[j] += val;
        }
    }
    return maxVal(output);
}

int main(){
    vector<vector<int>> q = {
        {1,2,100},
        {2,5,100},
        {3,4,100}
    };
    long result = arrayManipulation(5, q);
    cout<<result<<endl;
    return 0;
}