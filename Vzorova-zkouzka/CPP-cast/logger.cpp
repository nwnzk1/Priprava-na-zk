#include "logger.h"

#include <string>
#include <iostream>
#include <fstream>
#include <cstdlib>

void Logger::log(std::string uroven, std::string objekt, std::string zprava) {
	std::ofstream outFile;

	outFile.open(filename, std::ios::app);
	
	/* Vygenerováno od AI, pro to, aby každý zápis pokračoval číslem, u kterého to skončilo během minulého generování:
	
	// 1. Inicializace počítadla (provede se jen při prvním volání metody)
	static int pocitadlo = -1;

	if (pocitadlo == -1) {
		// Zkusíme načíst poslední číslo ze souboru 'filename'
		
		std::ifstream in("filename");
		if (in.is_open()) {
			in >> pocitadlo; // Pokud soubor existuje, načteme číslo
			in.close();
		}
		else {
			pocitadlo = 17000; // Pokud soubor neexistuje (první spuštění), začneme na 17000
		}
	}
	
	*/
	
	static int pocitadlo = 17000;

	if (outFile.is_open()) {
		outFile << "[" << pocitadlo << "] " << uroven << ": " << objekt << " - " << zprava << std::endl;
        outFile.close();

		pocitadlo++;
	}

	else {
		std::cout << "Soubor se nepodarilo otevrit" << std::endl;
	}

}

void Server::run(int pocetUdalosti) {
	Logger mujLogger;                    // důležité kvůli tomu, co je na posledním řádku v if()

	// vytvoření pole s názvy, ze kterého si kód bude random vybírat urovne/zpravy/atd
	std::string urovne[] = { "INFO", "WARNING", "ERROR"};
	std::string objekty[] = { "Databaze", "Server", "System" };
	
	std::string infoZpravy[] = { "Start procesu", "Uzivatel prihlasen", "Zaloha dokoncena" };
	std::string warningZpravy[] = { "Vysoka odezva", "Nizka pamet", "Neznamy pozadavek" };
	std::string errorZpravy[] = { "Spojeni selhalo", "Segfault", "Disk plny" };

	// náhodné generování
	for (int i = 0; i < pocetUdalosti; i++) {
		int indexUrovne = std::rand() % 3; // (0-2)
		std::string zvolenaUroven = urovne[indexUrovne];

		int indexObjektu = std::rand() % 3;
		std::string zvolenyObjekt = objekty[indexObjektu];


		// náhodné generování správné zprávy 
		int indexZpravy = std::rand() % 3;
		std::string zvolenaZprava;

		if (zvolenaUroven == "INFO") {
			zvolenaZprava = infoZpravy[indexZpravy];
		}
		else if (zvolenaUroven == "WARNING") {
			zvolenaZprava = warningZpravy[indexZpravy];
		}
		else {
			zvolenaZprava = errorZpravy[indexZpravy];
		}

		mujLogger.log(zvolenaUroven, zvolenyObjekt, zvolenaZprava);
	}
};
