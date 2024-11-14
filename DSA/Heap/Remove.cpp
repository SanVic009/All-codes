#include <bits/stdc++.h>

using namespace std;

class Heap
{
private:
    vector<int> heap;

    int leftChild(int index)
    {
        return 2 * index + 1;
    }
    int rightChild(int index)
    {
        return 2 * index + 2;
    }

    int parent(int index)
    {
        return (index - 1) / 2;
    }

    void swap(int index1, int index2)
    {
        int temp = heap[index1];
        heap[index1] = heap[index2];
        heap[index2] = temp;
    }

public:
    void insert(int value)
    {
        heap.push_back(value);
        int current = heap.size() - 1;
        while (heap[current] > heap[parent(current)] && current > 0)
        {
            swap(current, parent(current));
            current = parent(current);
        }
    }

    void printHeap()
    {
        cout << endl;
        for (int val : heap)
        {
            cout << val << "\t";
        }
    }

    int remove()
    {
        if (heap.empty())
            return INT_MIN;

        int maxValue = heap.front();

        if (heap.size() == 1)
        {
            heap.pop_back();
        }
        else
        {
            heap[0] = heap.back();
            heap.pop_back();
            // int current = 0;
            // while (heap[current] < heap[rightChild(current)] && heap[current] < heap[leftChild(current)])
            // {
            //     if (leftChild(current) > rightChild(current))
            //     {
            //         swap(current, leftChild(current));
            //         current = leftChild(current);
            //     }
            //     else if (leftChild(current) < rightChild(current))
            //     {
            //         swap(current, rightChild(current));
            //         current = rightChild(current);
            //     }
            // }
            sinkDown(0);
        }
        return maxValue;
    }

    void sinkDown(int index)
    {
        int maxIndex = index;
        while (true)
        {
            int leftIndex = leftChild(index);
            int rightIndex = rightChild(index);

            if (leftIndex < heap.size() && heap[leftIndex] > heap[maxIndex])
            {
                maxIndex = leftIndex;
            }

            if (rightIndex < heap.size() && heap[rightIndex] > heap[maxIndex])
            {
                maxIndex = rightIndex;
            }

            if (maxIndex != index)
            {
                swap(index, maxIndex);
                index= maxIndex;
            }else return;
        }
    }
};

int main()
{
    Heap *myHeap = new Heap();
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