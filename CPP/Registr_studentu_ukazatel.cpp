#include <iostream>
#include <fstream>  
#include <sstream>
#include <string>

using namespace std;

struct Student {
    int vek;
    double prumer;
    string jmeno;
};

Student* pridatS() 
{                                                                              // dynamické alokování na heap (oblast paměti v ramce) pro jeden objekt typu Student 
    Student* novyStudent = new Student;                                       // novyStudent = ukazatel který drží adresu této paměti 
    std::cout << "Zadej jmeno studenta: "; getline(cin >> ws, novyStudent->jmeno);
    std::cout << "Zadej vek studenta: "; cin >> novyStudent->vek;
    std::cout << "Zadej prumer studenta: "; cin >> novyStudent->prumer;
    return novyStudent;
}

Student** alokujPole(int velikost) 
{                                                           // Students = ukazetel na ukazatel Student**, který drží adresu tohoto pole
    Student** Students = new Student* [velikost];          // danamické alokování pole o velikosti velikost -> každý prvek v tomto poli je ukazatel na Studenta[Student*]
    for (int i = 0; i < velikost; i++) {
        Students[i] = nullptr;
    }

    return Students;
}

void naplnPole(Student** pole, int velikost) 
{
    for (int i = 0; i < velikost; i++) {
        pole[i] = pridatS();
    }
}

void zobrazS(const Student* s) 
{
    cout << "Jmeno a prijmeni: " << s->jmeno << ", Vek: " << s->vek << ", Prumer studenta: " << s->prumer << endl;
}


void zobrazPole(Student** pole, int velikost) 
{
    for (int i = 0; i < velikost; i++) {
        cout << "Student c." << i+1 << endl;
        zobrazS(pole[i]);
    }
}

void vyprazdniP(Student** pole, int velikost) 
{
    for (int i = 0; i < velikost; i++) {
        delete pole[i];
    }
    delete[] pole;
}



int main()
{
    int n = 3;

    Student** registr = nullptr;
    registr = alokujPole(n);
    naplnPole(registr, n);
    zobrazPole(registr, n);
    vyprazdniP(registr, n);

    registr = nullptr;

    return 0;
}

