/// Класс описывающий лис
/// @author Пилипейко А.А.


#pragma once


#include "СolorRGB.h"							// для цвета шерсти

#include <cstdlib>								// для srand
#include <iostream>	
#include <string>								// для вывода характеристик лисы в строку
#include <ctime>								// для инициализации srand
#include <stdexcept>							// используются стандартные исключения в классе


class Fox {
public:
	bool     isMale;							// false - female, true - male
	ColorRGB prevailingСolor;					// преобладающий цвет шерсти
		

	Fox();

	/// red, green, blue - преобладающий цвет лисы в RGB формате
	Fox(std::string name, bool isMale, unsigned age, std::string species,
		unsigned char red, unsigned char green, unsigned char blue);

	/// прочитать имя
	std::string getName() const;

	/// задать имя
	void setName(std::string name);

	/// прочитать вид
	std::string getSpecies() const;

	/// задать вид
	void setSpecies(std::string species);

	/// прочитать возраст
	unsigned getAge() const;

	/// задать возраст; age < maxAge
	void setAge(unsigned age);

	/// задать характеристики случайно
	void random();

	/// задать цвет соответствующий преобладающему цвету вида
	void setColorBasedOnSpecies(std::string species);

	/// вывод характеристик в консоль
	void printToConsole() const;

	/// запись характеристик в строку
	std::string toString() const;


private:
	std::string _name;
	std::string _species;
	char _age;

	static const unsigned MAX_AGE;

	static bool isRandInitialized;				// инициализирован ли srand

	static const unsigned N_NAME;			    // размер массива FOX_NAME (количество имён)
	static const char* FOX_NAME[];		        // имена лис для случайной генерации

	static const unsigned N_SPECIES;			// размер массива FOX_SPECIES (количество видов)
	static const char* FOX_SPECIES[];			// виды лис для случайной генерации
};

