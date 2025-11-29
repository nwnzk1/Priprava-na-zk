#include "student.h"

#include <iostream>
#include <string>
#include <vector>

Student::Student(std::string jmeno, std::string prijmeni, int vek, int rocnik) {
	this->jmeno = jmeno;
	this->prijmeni = prijmeni;
	this->vek = vek;
	this->rocnik = rocnik;
}

Student::~Student() {
	std::cout << "destruktor Student" << std::endl;
}

void Student::vypisInfo() {
	std::cout << "Jmeno: " << this->jmeno << ", Prijmeni: " << this->prijmeni << ", Vek: " << this->vek << ", Rocnik: " << this->rocnik << std::endl;
}

std::string Student::getCeleJmeno() {
	return this->prijmeni + " " + this->jmeno;
}

Doktorant::Doktorant(std::string jmeno, std::string prijmeni, int vek, int rocnik, std::string temaPrace, int stipendium) : Student(jmeno, prijmeni, vek, rocnik) {
	this->temaPrace = temaPrace;
	this->stipendium = stipendium;
}

Doktorant::~Doktorant() {
	std::cout << "destruktor Doktorant" << std::endl;
}

void Doktorant::vypisInfo()  {
	Student::vypisInfo();
	std::cout << "Tema prace: " << this->temaPrace << ", Stipendium: " << this->stipendium << std::endl;
}

seznamStudentu::~seznamStudentu() {
	for (Student* student : studenti) {
		delete student;
	}
}

void seznamStudentu::pridejStudenta(Student* student) {
	if (student) {
		studenti.push_back(student);
		std::cout << "Student byl pridan" << std::endl;
	}
}

void seznamStudentu::vypisVsechny() {
	if (studenti.empty()) {
		std::cout << "Prazdny seznam" << std::endl;
		return;
	}

	for (Student* student : studenti) {
		student->vypisInfo();
	}

}