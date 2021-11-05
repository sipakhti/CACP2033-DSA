#include <iostream>

using namespace std;

// class Assignment{
//     char* heading;
//     char* description;
//     char* author;
//     char* dateCreated;
//     char* submissionDate;
//     Question* questions;

// };

struct question
{
    public:
        char* text;
        struct question* next;
        int marks;


        question(char* _text, int _marks){
            this->text = _text;
            this->marks = _marks;
            this->next = nullptr;
        };
        ~question(){
            delete this->text;
            if (this->next == nullptr)
                return;
            delete this->next;
        };

};

class Questions {
    private:
        question* head = nullptr;
        question* tail = nullptr;
        int size;

    public:
        Questions(){
            this->size = 0;
        };
        ~Questions(){
            delete this->head;
            delete this->tail;
        }
        void push(char* _text, int _marks){
            // if linkedlist is empty
            // if (this->size == 0)
            if (this->head == nullptr){
                this->head = new question(_text,_marks);
                this->size++;
            }
            else if (this->size == 1){
                this->tail = new question(_text, _marks);
                this->head->next = this->tail;
                this->size++;
            }
            else if (this->size > 1){
                question* temp = this->tail;
                // added a new node at the end of the existing tail
                this->tail->next = new question(_text,_marks);
                // repointed tail to the new mode
                this->tail = temp->next;
                // delete temp;
            }
        };

        void print(){
            question* seek = this->head;
            int count = 1;
            cout << "Number of Questions: " << this->size << endl;
            while(seek != nullptr){
                cout << "Question " << count++ << ": " << seek->text << endl;
                cout << "Marks: " << seek->marks << endl;
                seek = seek->next; 
            }
        }
};
