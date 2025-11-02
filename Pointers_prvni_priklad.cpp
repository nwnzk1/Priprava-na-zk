#include <iostream>
#include <string>
using namespace std;

struct Student {
    string Jmeno;
    int vek;
    double prumer;
};

Student* vytvorStudenta() 
{
    Student* novyStudent = new Student;          // nová proměnná novyStudent je deklarován jako pointer na typ Student, new = vrací pamětovou adresu

    std::cout << "Zadej jmeno: "; cin >> novyStudent->Jmeno;        // -> =  member access operator (získá skutečný objekt + přistoupí k proměnné)
    std::cout << "Zadej vek: "; cin >> novyStudent->vek;
    std::cout << "Zadej prumer studenta: "; cin >> novyStudent->prumer;

    return novyStudent;
}

void zobrazStudenta(const Student* s) 
{
    if (s == nullptr) {
        std::cout << "Ukazatel je null" << endl;
    }

    std::cout << "Jmeno: " << s->Jmeno << ", Vek: " << s->vek << ", Prumer studenta: " << s->prumer << endl;
}



int main()
{
    Student* mujStudent = nullptr;
    mujStudent = vytvorStudenta();
    zobrazStudenta(mujStudent);
    delete mujStudent;
    return 0;
}

