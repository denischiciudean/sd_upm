#include <iostream>
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

using namespace std;


struct nodLSI {
  int info = 0;
  nodLsi* next;
};

nodLSI* alocare_nod_LSI(int _info){
  nodLSI* new_node = new nodLSI;
  new_node->info = _info;
  new_node->next = NULL;

  return new_node;
}

nodLSI* inserare_sfarsit_LSI(nodLSI* list, int _info){

}

int main() {

  nodLsi* list; //primul nod in lista

	int meniu, submeniu;
	do{

	cout<<"Introduceti un numar de la 0-7\n";
	cout<<"0.Iesire din program\n";
	cout<<"1.Initializare LSI\n";
	cout<<"2.Inserare LSI\n";
	cout<<"Stergere LSI\n";
	cout<<"4.Cautare in LSI\n";
	cout<<"5.Traversare(Afisare) LSI\n";
	cout<<"6.Actualizare LSI\n";
	cout<<"7.Eliberare LSI\n";
	cin>>meniu;
	switch(meniu){
		case 0:break;
		case 1:{
      cout<<"Apelul functiei de initializare / Resetare\n";
			break;
		}
		case 2:{
			//submeniu

			cout<<"Variante de inserare\n";
				do{
					cout<<"Apasati Enter pentru a continua....";
				system("clear");
				cout<<"Introduceti un numar de lla 0-3\n";
				cout<<"0.Revenire la meniul principal\n";
				cout<<"1.Inserare la inceput\n";
				cout<<"2.Inserare la sfarsit\n";
				cout<<"3.Inserare dupa un element dat\n";
				cin>>submeniu;
				switch(submeniu){
					case 0:break;
					case 1:{



						cout<<"Apel de inserare la inceput\n";
						break;
					}
					case 2:{
						cout<<"Apel de inserare la sfarsit\n";
						break;
					}
					case 3:{
						cout<<"Apel de inserare dupa un element dat\n";
						break;
					}
					default:{
							cout<<"Varianta incorecta!!!\nIntroduceti un numar de la 0-3.\n";
						break;
					}
				}

			}while(submeniu!=0);
			break;
		}
		case 3:{
			cout<<"Variante de stergere\n";
			cout<<"Apasati Enter pentru a continua....";
				system("clear");
			cout<<"Variante de stergere\n";
				do{
				cout<<"Introduceti un numar de la 0-3\n";
				cout<<"0.Revenire la meniul principal\n";
				cout<<"1.Stergere la inceput\n";
				cout<<"2.Stergere la sfarsit\n";
				cout<<"3.Stergere dupa un element dat\n";
				cin>>submeniu;
				switch(submeniu){
					case 0:break;
					case 1:{
						cout<<"Apel de stergere la inceput\n";
						break;
					}
					case 2:{
						cout<<"Apel de stergere la sfarsit\n";
						break;
					}
					case 3:{
						cout<<"Apel de stergere dupa un element dat\n";
						break;
					}
					default:{
							cout<<"Varianta incorecta!!!\nIntroduceti un numar de la 0-3.\n";
						break;
					}
				}
				cout<<"Apasati Enter pentru a continua....";
				system("clear");
			}while(submeniu!=0);
			break;
		}
		case 4:{
			cout<<"Apelul functiei de cautare\n";
			break;
		}
		case 5:{
			cout<<"Apelul functiei de traversare\n";
			break;
		}
		case 6:{
			cout<<"Apelul functiei de actualizare\n";
			break;
		}
		case 7:{
			cout<<"Apelul functiei de eliberare\n";
			break;
		}
		default:{
			cout<<"Varianta incorecta!!!\nIntroduceti un numar de la 0-7.\n";
			break;
		}
	}
	cout<<"Apasati Enter pentru a continua....";
				system("clear");
	}while(meniu!=0);
	return 0;
}
