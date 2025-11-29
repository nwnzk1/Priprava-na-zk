#include "student.h"

#include <iostream>
#include <string>
#include <vector>


int main()
{
	seznamStudentu seznam;

	Student* student1 = new Student("Marek", "Musil", 20, 2);
	Student* student2 = new Student("Matej", "Novotny", 20, 2);
	Student* student3 = new Student("Matyas", "Kopecek", 20, 2);
	Doktorant* doktorant1 = new Doktorant("Rizz", "Master", 67, 69, "How to rizz", 42000);

	seznam.pridejStudenta(student1);
	seznam.pridejStudenta(student2);
	seznam.pridejStudenta(student3);
	seznam.pridejStudenta(doktorant1);

	seznam.vypisVsechny();
	seznam.~seznamStudentu();

	return 0;

}

