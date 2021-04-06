#pragma once
#include <iostream>
#include <sstream>
#include <fstream>

namespace Engine
{
	enum class TYPE {
		CONSOLE = 0,
		FILE,
		CONSOLE_FILE
	};

	class Logger
	{
	private:
		std::string logFile;
		std::ofstream fout;

	public:
		Logger(std::string _logFile = "log.txt");
		~Logger();

		void Message(std::string text, TYPE outputType = TYPE::CONSOLE);
	};
}

