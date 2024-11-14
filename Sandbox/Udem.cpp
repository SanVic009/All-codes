#include<bits/stdc++.h>

using namespace std;

void rem(vector <int> nums, int val){
    int place = 0;
    for(auto it : nums){
        if(it == val)
            nums.erase(nums.begin() + place);
        place ++;
    }
}

int main(){
    vector<int> nums = {1, 10, 2, 10, 3, 10, 4, 10, 5};
    rem(nums, 10);
    for(auto it : nums){
        cout<<it<<endl;
    }
    return 0;
}