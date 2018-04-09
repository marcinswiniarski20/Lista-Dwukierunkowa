#include<iostream>
#include<iomanip>

using namespace std;

	struct wezel{
	
		wezel* poprz;
		int wartosc;
		wezel* nast;
	
	};

void wypisz_menu(wezel*);
void wypisz_liste(wezel*);
void tworz_liste(wezel*, wezel*);

void dodaj_lewy(wezel*&, wezel*&);
void dodaj_prawy(wezel*&, wezel*&);
void usun_lewy(wezel*&, wezel*&);
void usun_prawy(wezel*&, wezel*&);

void znajdz_wezel(wezel*);
void usun_liste(wezel*&, wezel*&);
void dodaj_konkret(wezel*, wezel*&);
void usun_konkret(wezel*&, wezel*&);

void bubblesort(wezel*);
void bubblesort_prawo(wezel*);
//void bubblesort1(wezel*, wezel*&, wezel*&);

int main(){
	
	wezel* lewy = NULL; wezel* prawy = NULL;
	tworz_liste(lewy, prawy);
	
}

void wypisz_menu(wezel *lewy){
	
		system("cls");
	
		wypisz_liste(lewy);
	
		cout << "MENU GLOWNE!" << endl;
		cout << "1. Dodaj element z lewej strony listy" << endl;
		cout << "2. Dodaj element z prawej strony listy" << endl;
		cout << "3. Usun element z lewej strony listy" << endl;
		cout << "4. Usun element z prawej strony listy" << endl;
		cout << "5. Dodaj element za wskazanym elementem" << endl;
		cout << "6. Usun konkretny element z listy" << endl;
		cout << "7. Usun liste (zwolnij pamiec)" << endl;
		cout << "8. Posortuj liste z lewej" << endl;
		cout << "9. Posortuj liste z prawej" << endl;
		cout << "10. Znajdz konkretny element" << endl;
		cout << "11. Wyjscie z programu" << endl;
	
}

void wypisz_liste(wezel* lewy){
	
		cout << "--------------------------------------------------------------------" << endl;
	
		if(lewy != NULL)
			do{
				cout << setw(4) << lewy->wartosc << " ";
				lewy = lewy->nast;
			}while(lewy != NULL);
		else cout << "Niestety lista jest pusta :(" << endl;
	
		cout << endl << "--------------------------------------------------------------------" << endl;
	
}

void tworz_liste(wezel* lewy, wezel* prawy){
	
	int opcja;
		while(true){	
			wypisz_menu(lewy);
			cout<<"Wybor: ";
			cin>> opcja;
				switch(opcja){
					case 1 : 
						dodaj_lewy(lewy, prawy); 
						break;
					case 2 :
						dodaj_prawy(lewy, prawy);				
						break;
					case 3 : 
						usun_lewy(lewy, prawy);
						break;
					case 4 : 
						usun_prawy(prawy, lewy);
						break;
					case 5 : 
						dodaj_konkret(lewy, prawy);
						break;
					case 6 : 
						usun_konkret(lewy, prawy);
						break;
					case 7 : 
						usun_liste(lewy, prawy);
						break;	
					case 8 : 
						bubblesort(lewy);
						break;
					case 9 : 
						bubblesort_prawo(lewy);
						break;					
					case 10 :
						znajdz_wezel(lewy);
						break;
					case 11 : 
						exit(0);
					default: 
						cout << "Nie ma takiej opcji w menu!" << endl;
						getchar(); getchar();
						break;
				}
		}
		
}

void dodaj_lewy(wezel* &lewy, wezel *&prawy){
	
	int a;		
		cout << "Podaj wartosc: ";
		cin >> a;
	
	wezel* nowy = new wezel;
		
		nowy->wartosc = a;
		if(lewy == NULL){
			nowy->nast = nowy->poprz = NULL;
			prawy = lewy = nowy;
		}
		else{
			nowy->poprz = NULL;
			lewy->poprz = nowy;
			nowy->nast = lewy;
			lewy = nowy;
		}
		
}

void dodaj_prawy(wezel *&lewy, wezel* &prawy){
	
	int a;
		
		cout << "Podaj wartosc: ";
		cin >> a;
		
	wezel* nowy = new wezel;
		
		nowy->wartosc = a;
		if(prawy == NULL){
			nowy->nast = nowy->poprz = NULL;
			prawy = lewy = nowy;
		}
		else{
			nowy->nast = NULL;
			prawy->nast = nowy;
			nowy->poprz = prawy;
			prawy = nowy;
			
		}
	
}

void usun_lewy(wezel* &lewy, wezel *&prawy){
	
	wezel* temp;
	temp = lewy;
		if(lewy == prawy)
			lewy = prawy = NULL;
		else
			lewy = lewy->nast;
		delete temp;
	
}

void usun_prawy(wezel* &prawy, wezel* &lewy){
	
	wezel* temp;
		temp = NULL;
		if(lewy == prawy) lewy = prawy = NULL;
		else{
			temp = prawy->poprz;
			temp->nast = NULL;
			delete prawy;
			prawy = temp;
		}
		
}

void znajdz_wezel(wezel* lewy){
	
	int a;
		
		cout << "Podaj wartosc szukanego elementu: "; 
		cin >> a;
		
		while(lewy != NULL and lewy->wartosc !=a) lewy = lewy->nast;
		if(lewy == NULL) cout << "Nie ma Twojego elementu" << endl;
		else cout << "Twoj element ma adres: " << lewy << endl;
		
		getchar(); getchar();
}

void usun_liste(wezel* &lewy, wezel *&prawy){
	
	wezel* temp;
	
		while(lewy != NULL){
			temp = lewy;
			if(lewy == prawy)
				lewy = prawy = NULL;
			else
				lewy = lewy->nast;	
			delete temp;
		}
		
}

void dodaj_konkret(wezel* lewy, wezel* &prawy){
	
	int a, x;
		
		cout << "Podaj wartosc elementu, za ktorym chcesz dodac swoj wezel:  "; 
		cin >> a;
		
		wezel* temp = lewy;
		
		while(temp != NULL and temp->wartosc != a) temp = temp->nast;
		
		if(temp == NULL) cout << "Nie ma Twojego elementu" << endl;
		
		if(temp == prawy) dodaj_prawy(temp, prawy);
		else{
			cout << "Podaj wartosc elementu, ktory chcesz dodac: "; cin >> x;
			wezel* nowy = new wezel;
			nowy->wartosc = x;
			nowy->poprz = temp;
			nowy->nast = temp->nast;
			
			temp->nast->poprz = nowy;
			temp->nast = nowy;
		}
		
}

void usun_konkret(wezel* &lewy, wezel* &prawy){
	
	int a;
		
		cout << "Podaj wartosc elemetu ktory ma byc usuniety: ";
		cin >> a;
		
		wezel* temp = lewy;
		while(temp != NULL and temp->wartosc != a) temp = temp->nast;
		
		if(temp == lewy) usun_lewy(lewy, prawy);
		else if(temp == prawy) usun_prawy(prawy, lewy);
		else {
			temp->poprz->nast = temp->nast;
			temp->nast->poprz = temp->poprz;
			delete temp;
		}
		
}

void bubblesort(wezel* lewy){
	wezel* temp = new wezel;
	int buf;
	bool zrobiono = false;
	while(zrobiono == false){
		zrobiono = true;
		for(temp = lewy; temp!=NULL && temp->nast!=NULL; temp = temp->nast){
			if(temp->wartosc > temp->nast->wartosc){
				buf = temp->wartosc;
				temp->wartosc = temp->nast->wartosc;
				temp->nast->wartosc = buf;
				zrobiono = false;
			}
		}
	}
}
void bubblesort_prawo(wezel* lewy){
	wezel* temp = new wezel;
	int buf;
	bool zrobiono = false;
	while(zrobiono == false){
		zrobiono = true;
		for(temp = lewy; temp!=NULL && temp->nast!=NULL; temp = temp->nast){
			if(temp->wartosc < temp->nast->wartosc){
				buf = temp->wartosc;
				temp->wartosc = temp->nast->wartosc;
				temp->nast->wartosc = buf;
				zrobiono = false;
			}
		}
	}
}
/*void bubblesort1(wezel* temp, wezel*& lewy, wezel*& prawy){

	wezel *nowy1, *nowy2, *nowy3, *nowy4;	
	
        nowy1=lewy;
        nowy2=lewy->nast;
	        if(nowy1->wartosc > nowy2->wartosc)
	        {
	        	nowy1->poprz=nowy2;
	        	nowy1->nast=nowy2->nast;
	        	nowy2->poprz=nowy1->poprz;
	        	nowy2->nast=nowy1;
	        	lewy=nowy2;
	        	lewy->nast=nowy1;
	    	}
}*/
