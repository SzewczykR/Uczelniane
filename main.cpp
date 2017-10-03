#include <iostream>
#include <cstdlib>
#include <string>
#include <sstream>
#include <vector>

using namespace std;


#define STUDENTS_COUNT 10

class Student {
	private:
		string studentNo;
		string studentFName;
		string studentLName;
		bool studentState;
		
	public:		
		Student(string studentNo, string studentFName, string studentLName, bool studentState = true) {
			this->studentNo = studentNo;
			this->studentFName = studentFName;
			this->studentLName = studentLName;
			this->studentState = studentState;
		}
		
		string getStudentNo() {
			return this->studentNo;
		}
		
		string getStudentFName() {
			return this->studentFName;
		}
		
		string getStudentLName() {
			return this->studentLName;
		}
		
		bool getStudentState() {
			return this->studentState;
		}
		
		
};

//FUNKCJE
string fNameTab[10] = {"Janusz", "Tomasz", "Krzysztof", "Piotr", "Ryszard", "Mateusz", "Jakub", "Rados³aw", "Andrzej", "Grzegorz"};
string lNameTab[10] = {"Ró¿añski", "Bronczek", "Czurpalewicz", "Kap³aniak", "Jacewicz", "Piluk", "Szetner", "Borowiecki", "Cieœliñski", "Rejniak"};

string getRandomStudentFName(){
	string randomFName = fNameTab[rand() % 10];
	return randomFName;
}

string getRandomStudentLName(){
	string randomLName = lNameTab[rand() % 10];
	return randomLName;
}

bool getRandomStudentState(){
	return rand() % 1;
}

string getRandomStudentNumber() {
	ostringstream ss;
	int randomNumber = rand() % 2000 + 37000;
	ss << randomNumber;
	return ss.str();
}
//KONIEC FUNKCJI

int main() {
	system("chcp 1250"); 
	system("CLS");
	vector<Student> students;
	
	for(int i = 0; i < STUDENTS_COUNT; i++) {
		Student student(getRandomStudentNumber(), getRandomStudentFName(), getRandomStudentLName());
		students.push_back(student);
	}
	
	cout  << "Students group have been filled." << endl << endl;
	cout <<"Index\tFirst Name\tLast Name"<<endl << endl;
	
	for(int i = 0; i < students.size(); i++) {
		cout << students.at(i).getStudentNo() + "\t" + students.at(i).getStudentFName() + "   \t" + students.at(i).getStudentLName() << endl;
	}
	
	return 0;
}
