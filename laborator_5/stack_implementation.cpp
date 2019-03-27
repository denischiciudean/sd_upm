#include <iostream>
#include <stdlib.h>

#define MAX 500

using namespace std;

int top;

struct _s {
    int data;
};

_s s[MAX];

void init_stack() {
    top = -1;
}

bool empty_list() {
    if (top == -1) {
        return true;
    }
    return false;
}

bool full() {
    if (top == MAX - 1) {
        return true;
    }
    return false;
}

void push(int data) {

    if (full()) {
        cout << "Stack is full" << endl;
        return;
    }
    ++top;
    s[top].data = data;
    cout << "Pushed " << data << endl;
}

void pop() {
    if (empty_list()) {
        cout << "Can't pop, list is empty!" << endl;
        return;
    }
    cout << "Removed " << s[top].data << endl;
//    free(s[top]);
    --top;
}

void display() {

    if (empty_list()) {
        cout << "Can't pop, list is empty!" << endl;
        return;
    }

    for (int i = top; i >= 0; i--) {
        cout << s[i].data << endl;
    }

}

int main() {
    init_stack();

    int switcher;

    do {
        display();

        cout << "0. Exit \n 1. Push \n 2. Pop" << endl;
        cin >> switcher;

        switch (switcher) {
            case 1:
                int n;
                cout << "Push number : ";
                cin >> n;
                push(n);
                break;
            case 2:
                pop();
                break;
        }

    } while (switcher != 0);

}