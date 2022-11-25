/// Пример работы с классом
/// @author Пилипейко А.А.


#include "Fox.h"
#include <iostream>


using namespace std;


/// пример работы с const объектами и их полями
void constObj(const Fox& f) {
	cout << f.getName();
}


int main() {

	// ----- пример работы с классом -----

	Fox fox;


	cout << "fox():\n" << endl;
	fox.printToConsole();

	cout << "\nfox.random():\n" << endl;
	fox.random();
	cout << fox.toString() << endl;


	// ----- динамическое создание объекта -----

	Fox* f = new Fox();


	cout << "\nf->setName(""Kitsune"")\n";
	f->setName("Kitsune");

	cout << "f->getName() = " << f->getName() << endl << endl;
	
	delete f;


	// ----- массив из объектов -----

	unsigned N = 3;
	Fox* arrFox = new Fox[N];
	

	cout << "----- Dynamic array of objects:\n" << endl;

	for (unsigned i = 0; i < N; ++i) {
		arrFox[i].random();
		arrFox[i].printToConsole();
		cout << endl;
	}

	delete [] arrFox;


	// ----- массив из указателей на объекты -----

	Fox** arrKitsune = new Fox*[N];


	cout << "----- Array of pointers to object:\n" << endl;

	for (unsigned i = 0; i < N; ++i) {
		arrKitsune[i] = new Fox();
		arrKitsune[i]->random();
		arrKitsune[i]->printToConsole();
		cout << endl;
	}

	for (unsigned i = 0; i < N; ++i) {
		delete arrKitsune[i];
	}

	delete [] arrKitsune;


	// ----- пример работы с const объектами и их полями -----

	cout << "fox.name = ";
	constObj(fox);

	cout << endl;
}
