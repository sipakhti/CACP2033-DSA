#include <iostream>

using namespace std;

void selection_sort(int*, int, bool);
void selection_pass_asec(int*, int, int);
void selection_pass_desc(int*, int, int);
void print_array(int*, int);

int main(){
int* numbers = new int[10];
for (size_t i = 0; i < 10; i++)
{
    numbers[i] = rand();
}
print_array(numbers, 10);
selection_sort(numbers, 10, true);
print_array(numbers, 10);
selection_sort(numbers, 10, false);
print_array(numbers, 10);

return 0;

}

void selection_sort(int* numbers, int length, bool asec){
    int pass{};
    while (pass < length)
    {
        if (asec){
            selection_pass_asec(numbers, length, pass);
        }
        else {
            selection_pass_desc(numbers, length, pass);
        }
        
        pass++;
    }
    
}

void selection_pass_asec(int* numbers, int length, int pass){
    int temp;
        for (size_t i = 1 + pass; i < length; i++)
        {
            if (numbers[pass] > numbers[i]){
                temp = numbers[i];
                numbers[i] = numbers[pass];
                numbers[pass] = temp;
            }
        }
        pass++;
    }

void selection_pass_desc(int* numbers, int length, int pass){
    int temp;
        for (size_t i = 1 + pass; i < length; i++)
        {
            if (numbers[pass] < numbers[i]){
                temp = numbers[i];
                numbers[i] = numbers[pass];
                numbers[pass] = temp;
            }
        }
        pass++;
    }


void print_array(int* numbers, int length){
    cout << "[ ";
    for (size_t i = 0; i < length; i++)
    {
        cout << numbers[i] << " ";
    }
    cout << "]" << endl;
    
}