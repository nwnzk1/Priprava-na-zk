#include <iostream>
#include <ctime>
using namespace std;

void vypis(int** pole, int radky, int sloupec) 
{
	for (int i = 0; i < radky; i++)
	{
		for (int j = 0; j < sloupec; j++)
		{
			std::cout << pole[i][j] << " ";
		}
		std::cout << std::endl;
	}
}

void soucet(int** matice_1, int** matice_2, int radek, int sloupec) 
{
	int** vysledek = new int* [radek];
	for (int i = 0; i < radek; i++) {
		vysledek[i] = new int[sloupec];
		for (int j = 0; j < sloupec; j++) {
			vysledek[i][j] = matice_1[i][j] + matice_2[i][j];
		}
	}

	std::cout << "Soucet matic:" << std::endl;
	vypis(vysledek, radek, sloupec);
}


int main()
{
	int radek, sloupec;
	std::cin >> radek;
	std::cin >> sloupec;

	int** matice_1 = nullptr;
	matice_1 = new int* [radek];
	std::srand(std::time(0));

	for (int i = 0; i < radek; i++)
	{
		matice_1[i] = new int[sloupec];
		for (int j = 0; j < sloupec; j++) 
		{
			matice_1[i][j] = std::rand() % 10;
		}
	}
	vypis(matice_1, radek, sloupec);


	int** matice_2 = nullptr;
	matice_2 = new int* [radek];
	

	for (int i = 0; i < radek;  i++) 
	{
		matice_2[i] = new int[sloupec];
		for (int j = 0; j < sloupec; j++) 
		{
			matice_2[i][j] = std::rand() % 10;
		}
	}
	vypis(matice_2, radek, sloupec);

	soucet(matice_1, matice_2, radek, sloupec);

}


