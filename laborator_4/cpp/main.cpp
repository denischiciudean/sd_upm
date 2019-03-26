#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
using namespace std;




  struct nodLDI {
    int nr;
    nodLDI *prev;
    nodLDI *next;
  };

  struct _list {
    nodLDI *first;
    nodLDI *end;
  };

  _list init_list(_list list){
    _list new_list;
    nodLDI *empty_node = new nodLDI;
    new_list.first = empty_node;
    new_list.end = empty_node;
    list = new_list;
    return list;
  }

  bool empty_node(nodLDI *node){
    if(node == NULL){
      return true;
    }
    return false;
  }


  void display(_list list){
    nodLDI *current_node = list.first;
    if(empty_node(current_node)){
      std::cout << "First node is empty" << '\n';
      return;
    }
    while(current_node != NULL){
      cout << "[ \'" << current_node->prev << "' '" << current_node->nr << "' '" << current_node->next
           << "' ]->";
      current_node = current_node->next;
    }
  }

  _list adaugare_la_inceput(_list list, int nr){
    nodLDI *new_node = new nodLDI;
    nodLDI *first_node = list.first;
    //
    //
    new_node->nr = nr;
    new_node->next = first_node;
    new_node->prev = NULL;
    if(!empty_node(first_node)){
      first_node->prev = new_node;
    }
    list.first = new_node;

    if(list.end == NULL){
      list.end = list.first;
    }

    return list;
  }

  _list adaugare_la_sfarsit(_list list, int nr){


    if(list.first == NULL){
      list = adaugare_la_inceput(list, nr);
    }else{
      nodLDI *new_node = new nodLDI;
      nodLDI *last_node = list.end;

      new_node->nr = nr;
      new_node->next = NULL;
      new_node->prev = last_node;
      if(!empty_node(last_node)){
        last_node->next = new_node;
      }
      list.end = new_node;
    }

    return list;
  }


int main() {
	int meniu, submeniu;

  _list list;

	do {

     display(list);

		cout << "Introduceti o varianta de la 0-7\n";
		cout << "0. Iesire din program\n";
		cout << "1. Initializare LSI\n";
		cout << "2. Inserare LSI\n";
		cout << "3. Stergere LSI\n";
		cout << "4. Cautare LSI\n";
		cout << "5. Traversare(Afisare) LSI\n";
		cout << "6. Actualizare LSI\n";
		cout << "7. Eliberare LSI\n";
		cin >> meniu;
		switch (meniu) {
		case 0: break;
		case 1: {
			cout << "Apel de functie initializare\n";
			break;
		}
		case 2: {
			//cout << "Apel de functie de iserare\n";
			do {
				cout << "Apasati Enter a sterge ecranul\n";
				system("clear");

				cout << "Introduceti o varainta de la 0-3\n";
				cout << "0. Revenire in meniul principal\n";
				cout << "1. Inserare la inceput\n";
				cout << "2. Inserare la sfasit\n";
				cout << "3. Inserare dupa un anumit element\n";
				cin >> submeniu;
				switch (submeniu) {
				case 0: break;
				case 1: {
					cout << "Apel de functie de inserare la inceput\n";
          std::cout << "Numar :";
          int n;
          std::cin >> n;
          list = adaugare_la_inceput(list,n);
					break;
				}
				case 2: {
					cout << "Apel de functie de inserare la sfarsit\n";
          std::cout << "Numar :";
          int n;
          std::cin >> n;
          list = adaugare_la_sfarsit(list,n);
          break;
        }
				case 3: {
					cout << "Apel de functie de inserare dupa un anumit el.\n";
					break;
				}
				default: cout << "Varianta gresita\n. Introduceti o valoare de la 0-3\n";
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
				cout << "1. Inserare la inceput\n";
				cout << "2. Inserare la sfasit\n";
				cout << "3. Inserare dupa un anumit element\n";
				cin >> submeniu;
				switch (submeniu) {
				case 0: break;
				case 1: {
					cout << "Apel de functie de stergeere de la inceput\n";
					break;
				}
				case 2: {
					cout << "Apel de functie de stergere de la sfarsit\n";
					break;
				}
				case 3: {
					cout << "Apel de functie de stergere dupa un anumit el.\n";
					break;
				}
				default: cout << "Varianta gresita.\n Introduceti o valoare de la 0-3\n";
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
