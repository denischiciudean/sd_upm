#include <iostream>
#include <stdlib.h>

using namespace std;


struct Node {
    Node *prev;
    int data;
    Node *next;
};

typedef struct {
    Node *first;
    Node *last;
} Ends;

Ends init_ends() {
    Ends e;
    Node *node = new Node;
    e.first = node;
    e.last = node;
    return e;
}

Ends insert_begin(Ends e, int data) {

    Node *n = new Node;
    Node *first_node = e.first;

    n->next = first_node;
    n->prev = NULL;
    n->data = data;
    if (first_node->prev == NULL) {
        first_node->prev = n;
    }
    e.first = n;
    if (e.last == NULL) {
        e.last = n;
    }
    return e;
}

Ends insert_end(Ends e, int data) {
    Node *last_node = e.last;
    Node *new_node = new Node;
    new_node->prev = last_node;
    last_node->next = new_node;
    new_node->data = data;
    e.last = new_node;
    return e;
}

Ends insert_after_element(Ends e, int element, int data) {

    Node *new_node = new Node;
    Node *current_node = e.first;

    int counter = 1;

    while (counter != element) {
        current_node = current_node->next;
        counter++;
    }

    current_node->next->prev = new_node;
    new_node->data = data;
    new_node->prev = current_node;
    new_node->next = current_node->next;
    current_node->next = new_node;

    return e;

}

Ends delete_begin(Ends e) {
    Node *next = e.first->next;
    free(e.first);
    next->prev = NULL;
    e.first = next;
    return e;
}

Ends delete_end(Ends e) {
    Node *prev = e.last->prev;
    free(e.last);
    prev->next = NULL;
    e.last = prev;
    return e;
}

Ends delete_after_element(Ends e, int n) {
    Node *current_node = e.first;
    int counter = 1;
    while (counter != n) {
        current_node = current_node->next;
        counter++;
    }
    current_node->prev->next = current_node->next;
    current_node->next->prev = current_node->prev;
    free(current_node);
    return e;
}

void display_list_begin(Ends e) {
    if (e.first == NULL) {
        cout << "List is empty!" << endl;
        return;
    }
    Node *first_node = e.first;
    Node *current_node = e.first;
    while (current_node != NULL) {
        cout << "[ \'" << current_node->prev << "' '" << current_node->data << "' '" << current_node->next << "' ]->";
        current_node = current_node->next;
    }
    cout << "" << endl;
}

int main() {
    int meniu, submeniu;
    Ends ends = init_ends();
    do {
        display_list_begin(ends);
        cout << "Introduceti o varianta de la 0-7\n";
        cout << "0. Iesire din program\n";
        cout << "1. Initializare LDI\n";
        cout << "2. Inserare LDI\n";
        cout << "3. Stergere LDI\n";
        cout << "4. Cautare LDI\n";
        cout << "5. Traversare(Afisare) LDI\n";
        cout << "6. Actualizare LDI\n";
        cout << "7. Eliberare LDI\n";
        cin >> meniu;

        switch (meniu) {
            case 0:
                break;
            case 1: {
                cout << "Apel de functie initializare\n";
                break;
            }
            case 2: {
                //cout << "Apel de functie de iserare\n";
                do {
                    cout << "Apasati Enter a sterge ecranul\n";
                    system("clear");
                    insert_menu:
                    cout << "Introduceti o varainta de la 0-3\n";
                    cout << "0. Revenire in meniul principal\n";
                    cout << "1. Inserare la inceput\n";
                    cout << "2. Inserare la sfasit\n";
                    cout << "3. Inserare dupa un anumit element\n";
                    cin >> submeniu;
                    switch (submeniu) {
                        case 0:
                            break;
                        case 1: {
                            cout << "Apel de functie de inserare la inceput\n";
                            int n;
                            cout << "Data : ";
                            cin >> n;
                            ends = insert_begin(ends, n);
                            break;
                        }
                        case 2: {
                            cout << "Apel de functie de inserare la sfarsit\n";
                            int n;
                            cout << "Data : ";
                            cin >> n;
                            ends = insert_end(ends, n);
                            break;
                        }
                        case 3: {
                            cout << "Apel de functie de inserare dupa un anumit el.\n";
                            int el, n;

                            cout << "Al catelea element? : ";

                            cin >> el;
                            cin >> n;
                            ends = insert_after_element(ends, el, n);
                            break;
                        }
                        default:
                            cout << "Varianta gresita\n. Introduceti o valoare de la 0-3\n";
                            goto insert_menu;
                    }//switch inchis

                } while (submeniu != 0);
                break;
            }//case 2 inchis
            case 3: {
                //cout << "Apel de functie de stergere\n";
                do {
                    cout << "Apasati Enter a sterge ecranul\n";
                    system("clear");

                    cout << "Introduceti o varainta de la 0-3\n";
                    cout << "0. Revenire in meniul principal\n";
                    cout << "1. Stergere la inceput\n";
                    cout << "2. Stergere la sfasit\n";
                    cout << "3. Stergere dupa un anumit element\n";
                    cin >> submeniu;
                    switch (submeniu) {
                        case 0:
                            break;
                        case 1: {
                            cout << "Apel de functie de stergeere de la inceput\n";
                            ends = delete_begin(ends);
                            break;
                        }
                        case 2: {
                            cout << "Apel de functie de stergere de la sfarsit\n";
                            ends = delete_end(ends);
                            break;
                        }
                        case 3: {
                            cout << "Apel de functie de stergere dupa un anumit el.\n";
                            cout << "Al catelea element : ";
                            int n;
                            cin >> n;
                            ends = delete_after_element(ends, n);
                            break;
                        }
                        default:
                            cout << "Varianta gresita.\n Introduceti o valoare de la 0-3\n";
                    }//switch inchis

                } while (submeniu != 0);
                break;
            }//case 3 inchis
            case 4: {
                cout << "Apel de functie de cautare\n";
                break;
            }
            case 5: {
                cout << "Apel de functie de traversare(afisare)\n";
                break;
            }
            case 6: {
                cout << "Apel de functie de actualizare\n";
                break;
            }
            case 7: {
                cout << "Apel de functie de eliberare\n";
                break;
            }
            default: {
                cout << "Varianta gresita.\n Introduceti o valoare de la 0-7\n";
            }
        }//switch inchis
        cout << "Apasati Enter pentru a sterge ecranul\n";
        system("clear");
    }//do inchis
    while (meniu != 0);
    //_getch();
    return 0;
}