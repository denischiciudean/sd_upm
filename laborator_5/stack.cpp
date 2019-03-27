#include<iostream>
#include<string.h>

using namespace std;

#define MAX 5

int TOP;
struct stack_s {
    int data;
};
stack_s STACK[MAX];


//stack initialization
void initStack() {
    TOP = -1;
}

//check it is empty or not
int isEmpty() {
    if (TOP == -1)
        return 1;
    else
        return 0;
}

//check stack is full or not
int isFull() {
    if (TOP == MAX - 1)
        return 1;
    else
        return 0;
}

void push(int code) {
    if (isFull()) {
        cout << "STACK is FULL." << endl;
        return;
    }
    ++TOP;
    STACK[TOP].data = code;
    cout << code << " has been inserted." << endl;
}

void display() {
    int i;
    if (isEmpty()) {
        cout << "STACK is EMPTY." << endl;
        return;
    }
    for (i = TOP; i >= 0; i--) {
        cout << STACK[i].data << "," << endl;
    }
    cout << endl;
}

//pop - to remove item
void pop() {
    int temp;
    if (isEmpty()) {
        cout << "STACK is EMPTY." << endl;
        return;
    }

    temp = STACK[TOP].data;
    TOP--;
    cout << temp << " has been deleted." << endl;
}

int main() {
    int data;

    initStack();

    char ch;

    do {
        int a;
        cout << "Chosse \n1.push\n" << "2.pop\n" << "3.display\n";
        cout << "Please enter your choice: ";
        cin >> a;
        switch (a) {
            case 1:
                cout << "Enter a code: ";
                cin >> data;
                push(data);
                break;

            case 2:
                pop();
                break;

            case 3:
                display();
                break;

            default :
                cout << "An Invalid Choice!!!\n";


        }
        cout << "Do you want to continue ? ";
        cin >> ch;
    } while (ch == 'Y' || ch == 'y');
    return 0;
}