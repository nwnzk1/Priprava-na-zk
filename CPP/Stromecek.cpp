#include <iostream>
using namespace std;

int main()
{
	int velikost;
	int kmen;
	std::cout << "Zadej velikost kmene: "; std::cin >> kmen;
	std::cout << "Zadej velikost stromu: "; std::cin >> velikost;
	std::cout << "\n";

	for (int i = 0; i < velikost; i++) // i = 0; cyklus se opakuje dokud i se nerovná velikosti, i++ nám tu hodnotu zvyšuje o 1 do ukoncení cyklu
	{
		for (int j = 0; j < velikost - i - 1; j++)   // mezery na novém rádku, kadı rádek = méne mezer
		{
			std::cout << " ";
		}
		for (int k = 0; k < (2 * i + 1); k++)  // vypisuje hvezdicky, kadı rádek = více hvezdicek
		{
			std::cout << "*";
		}
		std::cout << std::endl;      // prechod na novı rádek pomocí endl;
	}

	for (int i = 0; i < kmen; i++)
	{
		for (int j = 0; j < velikost - 1; j++)  // mezery pred kmenem, kadı rádek = stejnı pocet mezer
		{
			std::cout << " ";
		}
		std::cout << "|" << std::endl;   // napíše nám znak a prejde na novı ?ádek, dokud nám neskoc?í for cyklus
	}
}

