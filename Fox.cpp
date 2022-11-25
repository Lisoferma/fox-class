/// Класс описывающий лис
/// @author Пилипейко А.А.


#include "Fox.h"


const unsigned Fox::MAX_AGE = 20;
bool Fox::isRandInitialized = false;			// инициализирован ли srand

const unsigned Fox::N_NAME = 11;				// размер массива FOX_NAME (количество имён)

// имена лис для случайной генерации
const char* Fox::FOX_NAME[N_NAME] =
	{ "Foxy", "Autumn", "Mr. Big Ears", "Lisa", "Gideon Grey",
      "Cinnamon", "Kitsune", "Apricot", "Mars", "Finnegan", "Cheese"};

const unsigned Fox::N_SPECIES = 7;				// размер массива FOX_SPECIES (количество видов)

// виды лис для случайной генерации
const char* Fox::FOX_SPECIES[N_SPECIES] =
	{ "vulpes vulpes", "vulpes lagopus", "vulpes zerda", "vulpes ferrilata",
	  "vulpes bengalensis", "urocyon littoralis", "lycalopex" };


Fox::Fox() {

	_name    = "Foxy";
	isMale   = false;
	_age     = 3;
	_species = "vulpes vulpes";
	prevailingСolor.setСolor(207, 87, 0);
}


/// red, green, blue - преобладающий цвет лисы в RGB формате
Fox::Fox(const std::string& name, bool isMale, unsigned age, const std::string& species,
	     unsigned char red, unsigned char green, unsigned char blue) {

	setName(name);
	this->isMale = isMale;
	setAge(age);
	setSpecies(species);	
	prevailingСolor.setСolor(red, green, blue);
}


/// прочитать имя
std::string Fox::getName() const {

	return _name;
}


/// задать имя
void Fox::setName(const std::string& name) {

	if (name.empty())
		throw std::length_error("Length error: argument is empty");

	_name = name;
}


/// прочитать вид
std::string Fox::getSpecies() const {

	return _species;
}


/// задать вид
void Fox::setSpecies(const std::string& species) {

	if (species.empty())
		throw std::length_error("Length error: argument is empty");

	_species = species;
}


/// прочитать возраст
unsigned Fox::getAge() const {

	return _age;
}


/// задать возраст; age < maxAge
void Fox::setAge(unsigned age) {

	if (age > MAX_AGE)
		throw std::invalid_argument("Invalid argument: age > maxAge");

	_age = age;
}


/// задать характеристики случайно
void Fox::random() {

	if (isRandInitialized = false) {
		srand( static_cast<unsigned int>(time(0)) );
		isRandInitialized = true;
	}
	
	_name    = FOX_NAME[rand() % N_NAME];
	_species = FOX_SPECIES[rand() % N_SPECIES];
	_age     = rand() % MAX_AGE;
	isMale   = rand() % 2;
	setColorBasedOnSpecies(_species);	
}


/// задать цвет соответствующий преобладающему цвету вида
void Fox::setColorBasedOnSpecies(const std::string& species) {

	if (species.empty()) {
		throw std::length_error("Length error: argument is empty");
	}
	else if (species == "vulpes vulpes") {
		prevailingСolor.setСolor(207, 87, 0);
	}
	else if (species == "vulpes lagopus") {
		prevailingСolor.setСolor(250, 247, 238);
	}
	else if (species == "vulpes zerda") {
		prevailingСolor.setСolor(196, 160, 134);
	}
	else if (species == "vulpes ferrilata") {
		prevailingСolor.setСolor(180, 166, 156);
	}
	else if (species == "vulpes bengalensis") {
		prevailingСolor.setСolor(148, 112, 108);
	}
	else if (species == "urocyon littoralis") {
		prevailingСolor.setСolor(187, 168, 162);
	}
	else if (species == "lycalopex" || species == "pseudalopex") {
		prevailingСolor.setСolor(203, 176, 146);
	}
	else {
		throw std::domain_error("Domain error: no condition is found that satisfies the argument");
	}
}


/// вывод характеристик в консоль
void Fox::printToConsole() const {

	std::cout << "   Name: " << _name                  << std::endl;
	std::cout << "    Age: " << static_cast<int>(_age) << std::endl;
	std::cout << "Species: " << _species               << std::endl;
	std::cout << "    Sex: ";

	if (isMale) std::cout << "male"   << std::endl;
	else        std::cout << "female" << std::endl;

	std::cout << "  Color: "
		<< static_cast<int>(prevailingСolor.red)   << ", "
		<< static_cast<int>(prevailingСolor.green) << ", "
		<< static_cast<int>(prevailingСolor.blue)  << std::endl;
}


/// запись характеристик в строку
std::string Fox::toString() const {

	std::string str;

	str = "   Name: " + _name                + "\n"
		  "    Age: " + std::to_string(_age) + "\n"
		  "Species: " + _species             + "\n"
		  "    Sex: ";

	if (isMale) str += "male\n";
	else        str += "female\n";

	str += "  Color: "
		+ std::to_string(prevailingСolor.red)   + ", "
		+ std::to_string(prevailingСolor.green) + ", "
		+ std::to_string(prevailingСolor.blue);

	return str;
}


/// сохранение объекта в файл
void Fox::saveToFile(const std::string& filename) const {

	std::ofstream file(filename, std::ios::binary);

	if (!file.is_open()) {
		throw std::runtime_error("Runtime error: file opening failed");
	}

	file.write((char*)&_name,    sizeof(_name));
	file.write((char*)&isMale,   sizeof(isMale));
	file.write((char*)&_age,     sizeof(_age));
	file.write((char*)&_species, sizeof(_species));
	file.write((char*)&prevailingСolor.red,   sizeof(prevailingСolor.red));
	file.write((char*)&prevailingСolor.green, sizeof(prevailingСolor.green));
	file.write((char*)&prevailingСolor.blue,  sizeof(prevailingСolor.blue));

	file.close();
}


/// загрузка объекта из файла
void Fox::loadFromFile(const std::string& filename) const {

	std::ifstream file(filename, std::ios::binary);

	if (!file.is_open()) {
		throw std::runtime_error("Runtime error: file opening failed");
	}

	file.read((char*)&_name,    sizeof(_name));
	file.read((char*)&isMale,   sizeof(isMale));
	file.read((char*)&_age,     sizeof(_age));
	file.read((char*)&_species, sizeof(_species));
	file.read((char*)&prevailingСolor.red,   sizeof(prevailingСolor.red));
	file.read((char*)&prevailingСolor.green, sizeof(prevailingСolor.green));
	file.read((char*)&prevailingСolor.blue,  sizeof(prevailingСolor.blue));

	file.close();
}

