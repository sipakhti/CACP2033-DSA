#include <iostream>

using namespace std;
// signature for binarySearchRecursive
int binarySearchRecursive(int* , int , int);
int binarySearchRecursive(int* , int , int, int);
template <typename T>
class stackType
{
private:
    T* data;
    int topVal;
    int maxSize;
public:
    // Constructor
    stackType(int size = 100)
    {
        maxSize = size;
        data = new T[size];
        topVal = -1;
    }
    stackType(int* numbers, int len){
        maxSize = len;
        data = new T[len];
        topVal = -1;
        for (size_t i = 0; i < len; i++)
            push(numbers[i]);
    }
    // Destructor
    ~stackType()
    {
        delete [] data;
    }
    // Copy constructor
    stackType(const stackType<T>& otherStack)
    {
        data = new T[otherStack.maxSize];
        topVal = otherStack.topVal;
        for (int i = 0; i <= topVal; i++)
            data[i] = otherStack.data[i];
    }
    // push into stack
    void push(const T& newItem)
    {
        if (topVal == maxSize - 1)
            cout << "Stack is full" << endl;
        else
        {
            data[++topVal] = newItem;
        }
    }
    // pop from stack
    void pop()
    {
        if (topVal == -1)
            cout << "Stack is empty" << endl;
        else
        {
            topVal--;
        }
    }
    // peek at topVal of stack
    T top()
    {
        if (topVal == -1)
            cout << "Stack is empty" << endl;
        else
        {
            return data[topVal];
        }
        return T();
    }
    // check if stack is empty
    bool isEmpty()
    {
        return (topVal == -1);
    }
    // check if stack is full
    bool isFull()
    {
        return (topVal == maxSize - 1);
    }


};



// //Question #1: Consider the following statements:
// int main()
// {
//     stackType<int> stack = stackType<int>(100);
//     int x;
// // Suppose that the input is:
// // 14 45 34 23 10 5 -999
// // Show what is output by the following segment of code:
//     stack.push(5);
//     cin >> x;
//     while (x != -999)
//     { 
//         if (x % 2 == 0)
//         { 
//             if (!stack.isFull())
//                 stack.push(x); 
//         }
//         else
//             cout << "x = " << x << endl;
//             cin >> x; 
//     }

//     cout << "Stack Elements: ";
//     while (!stack.isEmpty())
//     {
//         cout << stack.top() << " ";
//         stack.pop();
//     }
//     cout << endl;
//     return 0;
// }

// void mystery(stackType<int>& s, stackType<int>& t)
// {   while (!s.isEmpty())
//     { 
//         t.push(2 * s.top());
//         s.pop(); 
//     }
// }

// int main(){
//     int list[] = {5, 10, 15, 20, 25};
//     stackType<int> s1;
//     stackType<int> s2;
//     for (int i = 0; i < 5; i++)
//         s1.push(list[i]);
//     mystery(s1, s2);
//     while (!s2.isEmpty())
//     { 
//         cout << s2.top() << " ";
//         s2.pop();
//     }
//     cout << endl; 
//     return 0;
// }

// a queue is a data structure that is a FIFO (first in first out)
// a class for a queue
template <typename T>
class queueType
{
private:
    T* data;
    int frontVal;
    int rearVal;
    int maxSize;
public:
    // Constructor
    queueType(int size = 100)
    {
        maxSize = size;
        data = new T[size];
        frontVal = 0;
        rearVal = -1;
    }
    // Constructor that takes an integer pointer and length as argument
    queueType(int* numbers, int len){
        maxSize = len*2;
        data = new T[len*2];
        frontVal = 0;
        rearVal = -1;
        for (size_t i = 0; i < len; i++)
            enqueue(numbers[i]);
    }
    // Destructor
    ~queueType()
    {
        delete [] data;
    }
    // Copy constructor
    queueType(const queueType<T>& otherQueue)
    {
        data = new T[otherQueue.maxSize];
        frontVal = otherQueue.frontVal;
        rearVal = otherQueue.rearVal;
        for (int i = 0; i <= rearVal; i++)
            data[i] = otherQueue.data[i];
    }
    // enqueue
    void enqueue(const T& newItem)
    {
        if (rearVal == maxSize - 1)
            cout << "Queue is full" << endl;
        else
        {
            data[++rearVal] = newItem;
        }
    }
    // dequeue
    void dequeue()
    {
        if (frontVal == rearVal + 1)
            cout << "Queue is empty" << endl;
        else
        {
            frontVal++;
        }
    }
    // peek at front of queue
    T front()
    {
        if (frontVal == rearVal + 1)
            cout << "Queue is empty" << endl;
        else
        {
            return data[frontVal];
        }
        return T();
    }
    // check if queue is empty
    bool isEmpty()
    {
        return (frontVal == rearVal + 1);
    }
    // check if queue is full
    bool isFull()
    {
        return (rearVal == maxSize - 1);
    }
};

// int main(){
//     queueType<int> queue;
//     int x, y;
//     // Show what is output by the following segment of code:
//     x = 4;
//     y = 5;
//     queue.enqueue(x);
//     queue.enqueue(y);
//     x = queue.front();
//     queue.dequeue();
//     queue.enqueue(x + 5);
//     queue.enqueue(16);
//     queue.enqueue(x);
//     queue.enqueue(y - 3);
//     cout << "Queue Elements: ";
//     while (!queue.isEmpty())
//     { 
//         cout << queue.front() << " ";
//         queue.dequeue();
//     }
//     cout << endl;

//     return 0;
// }

/**
 * @brief this function will reverse a queue using stack
 * 
 * @param q 
 */
void mystery(queueType<int>& q)
{ 
    stackType<int> s;
    while (!q.isEmpty())
    { 
        s.push(q.front());
        q.dequeue();
    }
    while (!s.isEmpty())
    { 
        q.enqueue(s.top());
        s.pop();
    }
}

int main(){
    int numbers[5] = {19,7,8,9,6};
    queueType<int> intQueue(numbers,5);

    
    mystery(intQueue);
    while (!intQueue.isEmpty())
    {
        cout <<  intQueue.front() << " ";
        intQueue.dequeue();
    }
    
}


// // QUESTION 10
// int main(){
//     // Consider the following statements:
//     stackType<int> stack;
//     queueType<int> queue;
//     int x;
// // Suppose the input is:
// // 15 28 14 22 64 35 19 32 7 11 13 30 -999
// // Show what is written by the following segment of code:
//     stack.push(0);
//     queue.enqueue(0);
//     cin >> x;
//     while (x != -999)
//     { 
//         switch (x % 4)
//         {   
//             case 0:
//                 stack.push(x);
//                 break;
//             case 1:
//                 if (!stack.isEmpty())
//                 { 
//                     cout << "Stack Element = " << stack.top() << endl;
//                     stack.pop();
//                 }
//                 else
//                     cout << "Sorry, the stack is empty." << endl;
//                 break;
//             case 2:
//                 queue.enqueue(x);
//                 break;
//             case 3:
//                 if (!queue.isEmpty())
//                 { 
//                     cout << "Queue Element = " << queue.front() << endl;
//                     queue.dequeue();
//                 }
//                 else
//                     cout << "Sorry, the queue is empty." << endl;
//                 break;
//         } //end switch

//     cin >> x;
//     } //end while
//     cout << "Stack Elements: ";
//     while (!stack.isEmpty())
//     {
//         cout << stack.top() << " ";
//         stack.pop();
//     } 
//     cout << endl;
//     cout << "Queue Elements: ";
//     while (!queue.isEmpty())
//     {
//         cout << queue.front() << " ";
//         queue.dequeue();
//     }
//     cout << endl;
// }


// function to do a biary search
int binarySearch(int* numbers, int length, int searchValue)
{
    int low = 0;
    int high = length - 1;
    int mid;
    while (low <= high)
    {
        mid = (low + high) / 2;
        if (numbers[mid] == searchValue)
            return mid;
        else if (numbers[mid] < searchValue)
            low = mid + 1;
        else
            high = mid - 1;
    }
    return -1;
}


// a recursive function to do a binary search
int binarySearchRecursive(int* numbers, int length, int searchValue)
{
    int low = 0;
    int high = length - 1;
    int mid;
    if (low <= high)
    {
        mid = (low + high) / 2;
        if (numbers[mid] == searchValue)
            return mid;
        else if (numbers[mid] < searchValue)
            return binarySearchRecursive(numbers, mid + 1, high, searchValue);
        else
            return binarySearchRecursive(numbers, mid - 1, low, searchValue);
    }
    return -1;
}


