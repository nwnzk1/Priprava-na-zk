#include <iostream>
#include <string>

using namespace std;

struct Student {
    string jmeno;
    int vek;
    double prumer;
};

Student* pridatStudent()
{
    Student* novyStudent = new Student;
    std::cout << "Zadej jmeno: "; getline(cin >> ws, novyStudent->jmeno);        // zadáváme celé jméno díky getline
    std::cout << "Zadej vek: "; cin >> novyStudent->vek;
    std::cout << "Zadej prumer: "; cin >>novyStudent->prumer;
    return novyStudent;
}

Student** alokaceStudenta(int pocet) 
{
    Student** Studenti = new Student* [pocet];
    for (int i = 0; i < pocet; i++) {
        Studenti[i] = nullptr;
    }

    return Studenti;
}

void zobrazStudent(const Student* s) 
{
    std::cout << "Jmeno: " << s->jmeno << ", Vek: " << s->vek << ", Prumer: " << s->prumer << endl;
}

void naplnData(Student** pole, int pocet) 
{
    for (int i = 0; i < pocet; i++) {
        pole[i] = pridatStudent();
    }
}

void zobrazVsechny(Student** pole, int pocet) 
{
    std::cout << "\n\nSeznam studentu\n" << endl;
    
    for (int i = 0; i < pocet; i++) {
        std::cout << "Student c." << i + 1 << ": " << endl;
        zobrazStudent(pole[i]);
    }
}

void vyprazdniPole(Student** pole, int pocet) {
    for (int i = 0; i < pocet; i++) {
        delete pole[i];
    }
    delete[] pole;
}

int main()
{
    int pocet = 3;
    
    Student** seznamStudentu = nullptr;
    seznamStudentu = alokaceStudenta(pocet);
    naplnData(seznamStudentu, pocet);
    zobrazVsechny(seznamStudentu, pocet);
    vyprazdniPole(seznamStudentu, pocet);

    seznamStudentu = nullptr;
    return 0;

}


