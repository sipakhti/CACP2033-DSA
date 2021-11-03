#include <iostream>

using namespace std;

void questionOne();
void questionTwo();
void questionThree();
void questionFour();
void findMax(int*, int);
void printArray(int*, int);
void printArray(char*);

int main(){

    questionFour();

return 0;

}

/**
 * @brief How to insert and print one dimension array elements? Size of the array is 10. 15 marks
 * 
 */
void questionOne(){
    const int size = 10;
    int numbers[size];
    for (size_t i = 0; i < size; i++)
        numbers[i] = rand();

    printArray(numbers, size);
    

}

/**
 * @brief Take Inputs from User and Store Them in an Array.
 *  And also print array elements? Size of the array is 7. 15 marks
 * 
 */
void questionTwo(){
    const int size = 7;
    int numbers[size];
    cout << "Please enter " << size << " numbers as prompted!" << endl;
    for (size_t i = 0; i < size; i++)
    {
        cout << "Index -> " << i << " :";
        cin >> numbers[i];
    }

    cout << "Elements in the array" << endl;
    for (size_t i = 0; i < size; i++)
        cout << "Value at Index[" << i << "]: " << numbers[i] << endl;
    
    
}

/**
 * @brief Write a C++ program to find k largest elements in a given array of integers.
 *  The Array is Arr[10]={6,66,3,12,1,3,44,51,76,8}. MARKS 15
 * 
 */
void quesionThree(){
    int Arr[10]={6,66,3,12,1,3,44,51,76,8};
    int max = INT_MIN;
    for (size_t i = 0; i < 10; i++)
        if (Arr[i] > max)
            max = Arr[i];

    cout << "MAX: " << max;
    
}


/**
 * @brief Write a C++ program to find the most occurring element in an array of integers.
 *  The Array is Arr[10]={1,66,3,12,1,3,44,51,76,3}. 15 marks 
 * 
 */
void questionFour(){
    int numbers[10]={1,66,3,12,1,3,44,3,76,3};
    int count = 0;
    int maxOccured;

    for (size_t i = 0; i < 10; i++)
    {
        int repeat = 0;
        for (size_t j = i; j < 10; j++)
        {
            if (numbers[i] == numbers[j]){
                repeat++;
            }
        }
        if (repeat >= count){
            count = repeat;
            maxOccured = numbers[i];
        }

        
    }

    cout << "repeated: " << count << endl;
    cout << "number: " << maxOccured << endl;
    
}


/**
 * @brief prints an array on a single console line
 * 
 * @param numbers pointer to array that is to be printed
 * @param length length of the array
 */
void printArray(int* numbers, int length){
    for (size_t i = 0; i < length; i++)
        cout << numbers[i] << " ";

    cout << endl;    
}