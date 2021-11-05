#include <iostream>
#include <string>
// #include "Assignment 1.h"

using namespace std;



void questionOne();
void questionTwo();
void questionThree();
void questionFour();
void questionFive();
void sort(char**, int);
bool compare(char*, char*);
bool compare(char*, char*, int&);
void swap(char*, char*);
void findMax(int*, int);
void printArray(char**, int);
void printArray(int*, int);
void printArray(char*);

namespace COLOR {
    const string GREENBKGRD = "\033[42m";
    const string WARNING_TEXT = "\033[31m";
    const string FRAMED = "\033[51m";
    const string RESET = "\033[0m";
    const string UNDERLINE = "\033[4m";


};


int main(){


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
 * @brief Take Inputs from User and Store Them in a two dimension array? And also sort the array. 15 marks
 * 
 */
void questionFive(){
    int rows;
    cout << "How many names will you be entering: ";
    cin >> rows;
    char** names = new char*[rows];

    for (size_t i = 0; i < rows; i++)
    {
        names[i] = new char(50);
        for (size_t j = 0; j < 50; j++)
        names[i][j] = '\0';
    }
    
    cin.ignore();
    for (size_t i = 0; i < rows; i++)
    // taking input from user and storing it in an array
    { 
        cout << "Enter Name(" << i+1 << "/" << rows << ") " << COLOR::WARNING_TEXT << "[MAX LENGTH: 50]: " << COLOR::RESET;
        cin.getline(names[i], 50);
    }
    // SORTING THE ARRAY
    sort(names, rows);
    printArray(names, rows);

    delete (names);
    
}


/**
 * @brief sorts a 2D char array alphabetically in ascending order
 * 
 * @param wordList list of words that need to be sorted
 * @param listSize size of the list
 */
void sort(char** wordList, int listSize){
    for (size_t i = 0; i < listSize; i++){ // iterate over item list
        for (size_t j = 0; j < listSize - i - 1; j++){ // compares 
            if (compare(wordList[j], wordList[j+1])){
                swap(wordList[j], wordList[j+1]);
            }
        }
    }
}

/**
 * @brief compare two strings.
 * 
 * @param str1 
 * @param str2 
 * @return TRUE if str1 is is above or equal to str2 in descending order.
 *  FALSE if str2 is greater than str2
 */
bool compare(char* str1, char* str2){
    int depth = 0;
    return compare(str1, str2, depth);

}


/**
 * @brief overloaded compare function to compare strings recurssively
 * 
 * @param str1 
 * @param str2 
 * @param depth 
 * @return true 
 * @return false 
 */
bool compare(char* str1, char* str2, int& depth){
    if (str1[depth] == '\0')
        return  true;
    if (str2[depth] == '\0')
        return false;
    if (str1[depth] > str2[depth] )
        return true;
    if (str1[depth] < str2[depth])
        return false;
    return compare(str1, str2, ++depth);
}


void swap(char* str1, char* str2){
    for (int i = 0; str1[i] != '\0' || str2[i] != '\0'; i++){
        char temp = str1[i];
        str1[i] = str2[i];
        str2[i] = temp;
    }
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

void printArray(char** wordList, int listSize){
    for (int i = 0;i < listSize;i++){
        if (wordList[i][0] == '\0')
            return;
        cout << wordList[i] << endl;
    }
}
