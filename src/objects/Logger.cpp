#include "Logger.h"
//#include "../logs/"

Engine::Logger::Logger(std::string _logFile)
{
	logFile = _logFile;
	std::stringstream sstr;
	sstr << "src/logs/" << logFile;
	fout.open(sstr.str());
	std::cout << "[Engine]: start logging.\n";
}

Engine::Logger::~Logger()
{
	fout.close();
	std::cout << "[Engine]: end logging.\n";
}

void Engine::Logger::Message(std::string text, TYPE outputType)
{
	switch (outputType)
	{
	case Engine::TYPE::CONSOLE:
	{
		std::cout << "[Engine]: " << text.c_str() << "." << std::endl;
		break;
	}
	case Engine::TYPE::FILE:
	{
		/*std::stringstream sstr;
		sstr << "logs/" << logFile;
		std::ofstream fout(sstr.str(), std::ios::app);*/
		fout << "[Engine]: " << text.c_str() << "." << std::endl;
		/*fout.close();*/
		break;
	}
	case Engine::TYPE::CONSOLE_FILE:
	{
		std::cout << "[Engine]: " << text.c_str() << "." << std::endl;
		/*std::stringstream sstr;
		sstr << "logs/" << logFile;
		std::ofstream fout(sstr.str(), std::ios::app);*/
		fout << "[Engine]: " << text.c_str() << "." << std::endl;
		/*fout.close();*/
	}
		break;
	default:
		break;
	}
}
