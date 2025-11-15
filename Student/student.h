#pragma once

#include <string>
#include <vector>

class Student {
protected:
	std::string jmeno;
	std::string prijmeni;
	int vek;
	int rocnik;
public:
	Student(std::string jmeno, std::string prijmeni, int vek, int rocnik);

	virtual ~Student();

	virtual void vypisInfo();

	std::string getCeleJmeno();

};

class Doktorant : public Student {
private:
	std::string temaPrace;
	int stipendium;
public:
	Doktorant(std::string jmeno, std::string prijmeni, int vek, int rocnik, std::string temaPrace, int stipendium);

	~Doktorant();

	void vypisInfo() override;

};

class seznamStudentu {
private:
	std::vector<Student*> studenti;
public:
	void pridejStudenta(Student* student);
	void vypisVsechny();

	~seznamStudentu();
	
};
