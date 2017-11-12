#include <iostream>
//#include <stdlib.h>
//#include <time.h>
#include <vector>
//#include <string>
//#include <sstream>
//#include <cstdlib>
#include <iomanip>

using namespace std;
//////////////////// klasa

class Student{
	private:
		string imie;
		string nazwisko;
		string pesel;
		int index;
		string adres;
		int rok;
		
	public:
		void pokaStudenta(){
			cout<<setw(15)<<this->imie<<setw(20)<<this->nazwisko<<setw(15)<<this->pesel<<setw(9)<<this->index;
			if(this->rok==1)
			cout<<setw(5)<<"I"<<endl;
			else if(this->rok==2)
			cout<<setw(5)<<"II"<<endl;
			else if(this->rok==3)
			cout<<setw(5)<<"III"<<endl;
			else if(this->rok==4)
			cout<<setw(5)<<"IV"<<endl;
			else if(this->rok==5)
			cout<<setw(5)<<"V"<<endl;
			else
			cout<<setw(5)<<"-"<<endl;
			string comp="0";
			if(comp.compare(this->adres))
			cout<<setw(18)<<"adres:"<<setw(50)<<this->adres<<endl;
		}
		
		Student(string imie, string nazwisko, string pesel, int index){
			this->imie=imie;
			this->nazwisko=nazwisko;
			this->pesel=pesel;
			this->index=index;
			this->rok=0;
			this->adres="0";
		}
		void setAdres(string adres){
			this->adres=adres;
		}
		void setRok(int rok){
			this->rok=rok;
		}
};

//////////////////// koniec klasy
//////////////////// validatory

bool validateIndex(int index){
	if(index>35000 && index<40000) return 1;
	else return 0;
}

bool validateRok(int rok){
	if(rok>0 && rok<6) return 1;
	else return 0;
}

bool validatePesel(string pesel){
	bool perla=true;
	char temp1;
	int temp2;
	temp1=pesel.at(2);
	temp2=(temp1-48)*10;
	temp1=pesel.at(3);
	temp2+=(temp1-48);
	if(temp2<1 || temp2>12) perla=false;
	temp1=pesel.at(4);
	temp2=(temp1-48)*10;
	temp1=pesel.at(5);
	temp2+=(temp1-48);
	if(temp2<1 || temp2>31) perla=false;
	if(pesel.length()!=11) perla=false;
	return perla;
}

//////////////////// koniec validatorów
//////////////////// inne funkcje

Student dodajStudenta(){
string imie;
	
	string nazwisko;
	string pesel;
	int index;
	system("CLS");
	cout<<"Podaj imie: ";
	cin>>imie;
	system("CLS");
	cout<<"Podaj nazwisko: ";
	cin>>nazwisko;
	system("CLS");
	cout<<"Podaj PESEL: ";
	bool ads=true;
	while(ads){
	cin>>pesel;
		if (validatePesel(pesel))
		ads=false;
		else {
		system("CLS");
			cout<<"Pesel nie przeszed³ walidacji (rok 01-99, miesi¹c 1-12, dzieñ 1-31, 11 znaków)"<<endl;
			cout<<"Podaj PESEL: ";
		}
	}
	system("CLS");
	bool asd=true;
	while(asd){
	cout<<"Podaj numer indeksu: ";
	cin>>index;
	system("CLS");
	if (cin.fail() || !validateIndex(index)){
		cin.clear();
		cin.ignore(INT_MAX, '\n');
		cout<<"B³¹d! (z³y typ danych / za d³ugi/krótki numer)\n";
	}
	else asd=false;
	}
	Student studentz(imie, nazwisko, pesel, index);
	return studentz;
}

Student debugStudents(){
	Student s1("Janusz", "Pawlikowski", "75103012345", 37210);
	return s1;
}



//////////////////// koniec innych funkcji

int main(int argc, char** argv) {
	int x;
	system("chcp 1250"); 
	system("CLS");
	vector<Student> students;
	students.push_back(debugStudents());
	bool zamykanko=true;
	while(zamykanko){
	cout<<"1. Wyœwietl studentów\n2. Dodaj studenta\n3. Inne\n4. WyjdŸ\n";
	cin>>x;
	switch(x){
		case 1: {
			system("CLS");
			cout<<"np"<<setw(16)<<"imiê"<<setw(20)<<"nazwisko"<<setw(15)<<"pesel"<<setw(9)<<"index"<<setw(6)<<"rok"<<endl;
			for(int i = 0; i < students.size(); i++) {
				cout<<i+1<<". ";
			students.at(i).pokaStudenta();
			}
			cout<<endl;
			break;
		}
		case 2: {
			//system("CLS");
			students.push_back(dodajStudenta());
			break;
		}
		case 3: {
			system("CLS");
			int nr;
			int y=0;
			bool zamykanko2=true;
			while(zamykanko2){
			cout<<"1. Dodaj/zmieñ adres\n2. Dodaj/zmieñ rok\n3. Wróæ"<<endl;
			cin>>y;
			
			
			
			if(y==1){
					string adres;
					system("CLS");
					cout<<"Podaj numer studenta: ";
					cin>>nr;
					cout<<"Podaj adres: ";
					cin.clear();
					cin.ignore(INT_MAX, '\n');
					getline(cin,adres);
					students.at(nr-1).setAdres(adres);
					y==0;
					system("CLS");
				}
			else if (y==2){
					int rok;
					system("CLS");
					cout<<"Podaj numer studenta: ";
					cin>>nr;
					bool pepsi=true;
					while(pepsi){
					
					cout<<"Podaj rok: ";
					cin>>rok;
					if(validateRok(rok)){
					students.at(nr-1).setRok(rok);
					pepsi=false;
					}
					else {
						system("CLS");
						cout<<"Tylko wartoœci z zakresu 1-5!"<<endl;
					}
					}
					y==0;
					system("CLS");
				}
				else if (y==3)
					zamykanko2=false;
					
			}
			system("CLS");
			break;
		}
		case 4: {
			system("CLS");
			zamykanko=false;
			break;
		}
		default: {
			system("CLS");
			break;
		}
	}
}
	return 0;
}
