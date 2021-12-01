#include <iostream>

using namespace std;

// void mystery(Stack& s,Stack& t){
//     while (!s.isEmpty())
//     {
//         t.push(2 * s.top());
//         s.pop();
//     }
    
// }
template <typename T>
class Stack
{
private:
    T* data;
    int top;
    int size;
    bool Full(){
        return top >= size;
    }
    bool Empty(){
        return top < 0;
    }

public:
    Stack(int _size){
        size = _size;
        data = new T[_size];
        top = -1;
    };
    ~Stack(){
        if (data != nullptr)
            delete[] data;
    }
    bool push(T value){
        if (isFull())
            return false;
        data[++top] = value;
        return true;
    }

    T pop(){
        if (isEmpty())
            throw "MEH";
        return data[top--];
    }

    bool isFull(){
        return Full();
    }

    bool isEmpty(){
        return Empty();
    }
};


void mystery(Stack<int>& source, Stack<int>& target){
    while (!source.isEmpty())
        target.push(2*source.pop());
}

int main(){

    int list[] = {5,10,15,20,25};
    Stack<int> s1(5), s2(5);
    for (int i = 0; i < 5; i++)
    {
        s1.push(list[i]);
        mystery(s1,s2);
    }
    
    while (!s2.isEmpty())
    {
        cout << s2.pop() << " ";
    }

    // 50 40 30 20 10
    cout << endl;

    return 0;
    
}

