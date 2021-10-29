#include <iostream>

using namespace std;


int find_max(int*, int);

int main(){


return 0;

}

int find_max(int* numbers, int size){

    int max{INT_MIN};
    for (size_t i = 0; i < size; i++)
        max = numbers[i] > max ? numbers[i] : max;
    
    return max;
    
}

int find_min(int* numbers, int size){

    int min{INT_MAX};
    for (size_t i = 0; i < size; i++)
        min = numbers[i] < min ? numbers[i] : min;
    
    return min;
}