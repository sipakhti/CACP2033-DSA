#include <iostream>

using namespace std;

template <typename T>
class Queue
{
private:
    T* data;
    int head, tail, size;

public:
    Queue(){
        data = nullptr;
        head = tail = 0;
    }
    Queue(int _size){
        size = _size;
        data = new T[size];
        head = tail = 0;
    };
    Queue(const Queue &obj){
        data = obj.data;
        head = obj.head;
        tail = obj.tail;
        size = obj.size;
    }
    ~Queue(){
        if (data != nullptr)
            delete[] data;
    }

    void enqueue(T value){
        if (data == nullptr)
            return;
        if (ifFull())
            return;
        data[tail++] = value;
    }

    T deque(){
        if (data != nullptr && !isEmpty())
            return data[head++];
        
        throw "QUE EMPTY";
    }

    bool ifFull(){
        return  !(tail < size);
    }

    bool isEmpty(){
        return head == tail;
    }

    bool isUnInitialized(){
        return data == nullptr;
    }

    void display(){
        for (size_t i = head; i < tail; i++)
        {
            cout << data[i] << " ";
        }
        cout << endl;
        
    }
};


int main(){

    Queue <int>que(5);
    que.enqueue(20);
    que.enqueue(65);
    que.enqueue(78);
    que.display();
    que.enqueue(99);
    cout << que.deque() << endl;
    que.display();
    que.enqueue(15);
    cout << que.deque() << endl;
    


    return 0;
}
