#include <iostream>
using namespace std;

int main()
{
    double vaha;
    double vyska;
    double vek;
    char pohlavi;

    cout << "Zadejte vasi vahu (kg): "; cin >> vaha;
    cout << "Zadejte vasi vysku (cm): "; cin >> vyska;
    cout << "Zadejte vas vek: "; cin >> vek;
    cout << "Zadejte vase pohlavi (M/Z): "; cin >> pohlavi;

    int volba; // přidáno mimo cyklus

    do {
        cout << endl;
        cout << "MENU FITNESS KALKULACKY" << endl;
        cout << "1. Vypocet BMI" << endl;
        cout << "2. Vypocet BMR" << endl;
        cout << "3. Konec" << endl;
        cout << "Zadejte volbu (1-3): "; cin >> volba;

        switch (volba) {
        case 1: {
            float bmi = vaha / ((vyska / 100) * (vyska / 100));
            cout << "Vase BMI je: " << bmi << endl;
            if (bmi < 18.5) {
                cout << "Ucastník vyletu do specialnich pracovnich taboru" << endl;
            }
            else if (bmi >= 18.5 && bmi < 25) {
                cout << "Jsi normalni" << endl;
            }
            else if (bmi >= 25 && bmi < 30) {
                cout << "Jsi Mara Musil" << endl;
            }
            else if (bmi >= 30) {
                cout << "Gorlock the Destroyer" << endl;
            }
            break;
        }
        case 2: {
            double bmr;
            if (pohlavi == 'M' || pohlavi == 'm') {
                bmr = 88.362 + (13.397 * vaha) + (4.799 * vyska) - (5.677 * vek);
            }
            else if (pohlavi == 'Z' || pohlavi == 'z') {
                bmr = 447.593 + (9.247 * vaha) + (3.098 * vyska) - (4.330 * vek);
            }
            cout << "Vase BMR je: " << bmr << endl;
            break;
        }
        case 3: {
            cout << "Dekuji za vyuziti me skvele kalkulacky" << endl;
            return 0;
        }
        default:
            cout << "Neplatna volba!" << endl;
            break;
        }

    } while (true);

    return 0;
}
