#include <iostream>
#include <stdlib.h>

#define MAX 500

using namespace std;

struct _s {
    int data[MAX];
    int top = -1;
};
//
//
//_s init_stack() {
//
//    _s s = new _s;
//
//    return s;
//
//}

bool empty(_s *s) {
    if (s->top == -1) {
//        cout << "Stack is empty" << endl;
        return true;
    }
    return false;
}

bool full(_s *s) {
    if (s->top == MAX - 1) {
        return true;
    }
    return false;
}

void push(_s *s, int data) {
    if (full(s)) {
        cout << "Can't add, stack is full!" << endl;
        return;
    }
    s->top++;
    s->data[s->top] = data;
}

void pop(_s *s) {
    if (empty(s)) {
        cout << "Can't pop, stack is empty!" << endl;
        return;
    }
    s->top--;
}

void display(_s *s) {

    if (empty(s)) {
        cout << "Stack is empty" << endl;
        return;
    }
    for (int i = s->top; i >= 0; i--) {
        cout << s->data[i] << endl;
    }
}

int main() {
    int switcher;

    _s *s = new _s;

    do {
        system("clear");
        display(s);
        cout << "0.Exit \n1.Push \n2. Pop\n" << endl;
        cin >> switcher;
        switch (switcher) {
            case 1:
                int n;
                cout << "Data : ";
                cin >> n;
                push(s, n);
                break;
            case 2:
                pop(s);
                break;
        }
    } while (switcher != 0);
}
