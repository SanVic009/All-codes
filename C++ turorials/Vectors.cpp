#include <iostream>
#include <vector>

using namespace std;

template <class T>
void display(vector<T> &vec)
{
    for (int i = 0; i < vec.size(); i++)
    {
        std::cout << vec[i] << "\t";
    }
    std::cout << endl;
}

int main()
{
    std::vector<int> vecna1;

    int size;
    std::cout << "Enter the size of the vector required: ";
    std::cin >> size;

    for (int i = 0; i < size; i++)
    {
        int element;
        std::cin >> element;
        vecna1.push_back(element);
    }
    display(vecna1);

    vecna1.pop_back();
    display(vecna1);

    std::vector<int>::iterator it = vecna1.begin();
    vecna1.insert(it, 43);
    display(vecna1);

    // vecna1.insert(it+3, 32, 34);
    // display(vecna1);
    

    std::vector<int> vec1; //zero length vector
    std::vector<int> vec2(4); //4 length vector
    std::vector<int> vec3(vec2); // a 4 length integar vector from vec2
    std::vector<int> vec4(4, 5); //4 element vector of '5'
    display(vec4);

    return 0;
}