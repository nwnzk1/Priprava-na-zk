#pragma once

#include <string>

class Logger {
public:
	
	std::string filename = "server.log";

	void log(std::string uroven, std::string objekt, std::string zprava);
};

class Server {
public:
	void run(int pocetUdalosti);
};
