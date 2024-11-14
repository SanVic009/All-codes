#include<bits/stdc++.h>

using namespace std;

class Heap{
private:
    vector<int> heap;

    int leftChild(int index){
        return 2*index +1;
    }
    int rightChild(int index){
        return 2*index +2;
    }

    int parent(int index){
        return (index -1)/2;
    }

    void swap(int index1, int index2){
        int temp = heap[index1];
        heap[index1] = heap[index2];
        heap[index2] = temp;
    }

public:
    void insert(int value){
        heap.push_back(value);
        int current = heap.size()-1;
        while(heap[current] > heap[parent(current)] && current > 0){
            swap(current, parent(current));
            current = parent(current);
        }
    }

    void printHeap (){
        cout<<endl;
        for(int val : heap){
            cout<<val<<"\t";
        }
    }

};



int main(){
    Heap *myHeap = new Heap ();
    myHeap->insert(88);
    myHeap->insert(45);
    myHeap->insert(34);
    myHeap->insert(97);
    myHeap->insert(29);

    myHeap->printHeap();

    myHeap->insert(100);
    myHeap->printHeap();

    return 0;
}