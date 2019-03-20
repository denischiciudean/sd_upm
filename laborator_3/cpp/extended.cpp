#include <iostream>
#include<stdio.h>
#include<stdlib.h>
#include<string>

using namespace std;

struct nodLSI {
    string nume;
    string prenume;
    int age;
    nodLSI *next;
};

struct cartierNodLSI {
    nodLSI *persoane;
    string nume;
    cartierNodLSI *next;
};

nodLSI *alocare_nod_LSI(int _age, string nume, string prenume) {
    nodLSI *new_node = new nodLSI;
    new_node->age = _age;
    new_node->nume = nume;
    new_node->prenume = prenume;
    new_node->next = NULL;
    return new_node;
}

cartierNodLSI *alocare_cartier(string nume) {
    cartierNodLSI *cartier = new cartierNodLSI;
    cartier->nume = nume;
    cartier->next = NULL;
    cartier->persoane = NULL;
}

bool empty_list(nodLSI *list) {
    if (list == NULL) {
        return true;
    }
    return false;
}

void citire_lista(nodLSI *first_node) {

    nodLSI *current_node = first_node;
//    cout << &current_node->next << endl;
    while (current_node != 0) {
        cout << "[ \'" << current_node->age << "' '" << current_node->nume << "' '" << current_node->prenume
             << "' ]->";
        current_node = current_node->next;
    }
}

nodLSI *cautare(nodLSI *first_node, int by, int age_query, string other_query) {
    nodLSI *current_node = first_node;
    switch (by) {
        case 1: {
            while (current_node->nume != other_query) {
                current_node = current_node->next;
            }
            break;
        }
        case 2: {
            while (current_node->prenume != other_query) {
                current_node = current_node->next;
            }
            break;
        }
        case 3: {
            while (current_node->age != age_query) {
                current_node = current_node->next;
            }
            break;
        }
    }
    return current_node;
}

/*
 * Adaugare la inceputul listei
 */
nodLSI *adaugare_inceput(nodLSI *first_node, int age, string nume, string prenume) {
    nodLSI *new_node = alocare_nod_LSI(age, nume, prenume);
    new_node->next = first_node;
    first_node = new_node;
    return first_node;
}

/*
 * Adaugare la finalul listei
 */
nodLSI *adaugare_sfarsit(nodLSI *first_node, int age, string nume, string prenume) {
    nodLSI *new_node = alocare_nod_LSI(age, nume, prenume);
    nodLSI *current_node = first_node;
    while (current_node->next != NULL) {
        current_node = current_node->next;
    }
    current_node->next = new_node;

    return first_node;
}

nodLSI *adaugare_dupa_element(nodLSI *first_node, int element, int age, string nume, string prenume) {
    nodLSI *current_node = first_node;
    nodLSI *new_node = alocare_nod_LSI(age, nume, prenume);
    int current_node_nr = 1;
    while (current_node_nr != element) {
        current_node = current_node->next;
        current_node_nr += 1;
    }
    new_node->next = current_node->next;
    current_node->next = new_node;
    return first_node;
}

nodLSI *sterge_inceput(nodLSI *first_node) {
    return first_node = first_node->next;
}

nodLSI *sterge_sfarsit(nodLSI *first_node) {
    nodLSI *current_node = first_node;

    while (current_node->next->next != NULL) {
        current_node = current_node->next;
    }
    current_node->next = NULL;
    return first_node;
}

nodLSI *stergere_element(nodLSI *first_node, int n) {
    nodLSI *current_node = first_node;
    nodLSI *prev_node = first_node;
    int current_node_nr = 1;
    while (current_node_nr != n) {
        prev_node = current_node;
        current_node = current_node->next;
        current_node_nr += 1;
    }
    prev_node->next = current_node->next;
    return first_node;
}

int main() {

    nodLSI *cartiere = NULL; //primul nod in lista



    int meniu, submeniu;
    do {

        if (!empty_list(cartiere)) {
            cout << "List : " << endl;
            citire_lista(cartiere);
            cout << endl;
        }

        cout << "Introduceti un numar de la 0-7\n";
        cout << "0.Iesire din program\n";
        cout << "1.Initializare LSI\n";
        cout << "2.Inserare LSI\n";
        cout << "3.Stergere LSI\n";
        cout << "4.Cautare in LSI\n";
        cout << "5.Traversare(Afisare) LSI\n";
        cout << "6.Actualizare LSI\n";
        cout << "7.Eliberare LSI\n";
        cin >> meniu;
        switch (meniu) {
            case 0:
                break;
            case 1: {
                cartiere = cartiere("Nazna");
                cout << "Apelul functiei de initializare / Resetare\n";
                break;
            }
            case 2: {
                //submeniu

                cout << "Variante de inserare\n";
                do {
                    cout << "Apasati Enter pentru a continua....";
                    system("clear");
                    cout << "Introduceti un numar de lla 0-3\n";
                    cout << "0.Revenire la meniul principal\n";
                    cout << "1.Inserare la inceput\n";
                    cout << "2.Inserare la sfarsit\n";
                    cout << "3.Inserare dupa un element dat\n";
                    cin >> submeniu;
                    switch (submeniu) {
                        case 0:
                            break;
                        case 1: {
                            cout << "Apel de inserare la inceput\n";

                            int age;
                            string nume, prenume;
                            cout << "Age:" << endl;
                            cin >> age;
                            cout << "Nume:" << endl;
                            cin >> nume;
                            cout << "Prenume" << endl;
                            cin >> prenume;
                            list = adaugare_inceput(list, age, nume, prenume);
                            break;
                        }
                        case 2: {
                            cout << "Apel de inserare la sfarsit\n";
                            int age;
                            string nume, prenume;

                            cout << "Age:" << endl;
                            cin >> age;
                            cout << "Nume:" << endl;
                            cin >> nume;
                            cout << "Prenume" << endl;
                            cin >> prenume;
                            list = adaugare_sfarsit(list, age, nume, prenume);
                            break;
                        }
                        case 3: {
                            cout << "Apel de inserare dupa un element dat\n";

                            int age, n;
                            string nume, prenume;
                            cout << "N :" << endl;
                            cin >> n;
                            cout << "Age:" << endl;
                            cin >> age;
                            cout << "Nume:" << endl;
                            cin >> nume;
                            cout << "Prenume" << endl;
                            cin >> prenume;
                            list = adaugare_dupa_element(list, n, age, nume, prenume);

                            break;
                        }
                        default: {
                            cout << "Varianta incorecta!!!\nIntroduceti un numar de la 0-3.\n";
                            break;
                        }
                    }

                } while (submeniu != 0);
                break;
            }
            case 3: {
                cout << "Variante de stergere\n";
                cout << "Apasati Enter pentru a continua....";
                system("clear");
                cout << "Variante de stergere\n";
                do {
                    cout << "Introduceti un numar de la 0-3\n";
                    cout << "0.Revenire la meniul principal\n";
                    cout << "1.Stergere la inceput\n";
                    cout << "2.Stergere la sfarsit\n";
                    cout << "3.Stergere dupa un element dat\n";
                    cin >> submeniu;
                    switch (submeniu) {
                        case 0:
                            break;
                        case 1: {
                            cout << "Apel de stergere la inceput\n";
                            list = sterge_inceput(list);
                            break;
                        }
                        case 2: {
                            cout << "Apel de stergere la sfarsit\n";
                            list = sterge_sfarsit(list);
                            break;
                        }
                        case 3: {
                            cout << "Apel de stergere dupa un element dat\n";
                            cout << "Element to remove :" << endl;
                            int n;
                            cin >> n;
                            list = stergere_element(list, n);
                            break;
                        }
                        default: {
                            cout << "Varianta incorecta!!!\nIntroduceti un numar de la 0-3.\n";
                            break;
                        }
                    }
                    cout << "Apasati Enter pentru a continua....";
                    system("clear");
                } while (submeniu != 0);
                break;
            }
            case 4: {
                cout << "Apelul functiei de cautare\n";
                int by;
                cout << "Search by:" << endl;
                cout << "1. Nume" << endl;
                cout << "2. Prenume" << endl;
                cout << "3. Age" << endl;

                cout << "What to search :" << endl;
                cin >> by;
                nodLSI *res;

                if (by == 3) {
                    int query;
                    cin >> query;
                    res = cautare(list, by, query, " ");
                } else {
                    string query;
                    cin >> query;
                    res = cautare(list, by, 0, query);
                }
                break;
            }
            case 5: {
                cout << "Apelul functiei de traversare\n";
                break;
            }
            case 6: {
                cout << "Apelul functiei de actualizare\n";
                break;
            }
            case 7: {
                list = NULL;
                free(list);
                cout << "Apelul functiei de eliberare\n";
                break;
            }
            default: {
                cout << "Varianta incorecta!!!\nIntroduceti un numar de la 0-7.\n";
                break;
            }
        }
        cout << "Apasati Enter pentru a continua....";
        system("clear");
    } while (meniu != 0);
    return 0;
}
