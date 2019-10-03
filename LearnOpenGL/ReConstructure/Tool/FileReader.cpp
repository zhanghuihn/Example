#include <string>
#include <fstream>
#include <sstream>
#include <iostream>

#include "FileReader.h"

const char* FileReader::ReadFile(const char* filePath)
{
	std::string fileContent;
	std::ifstream ifile;
	ifile.exceptions(std::ifstream::failbit | std::ifstream::badbit);

	try {
		ifile.open(filePath);

		std::stringstream fileStream;
		fileStream << ifile.rdbuf();
		ifile.close();
		fileContent = fileStream.str();
	}
	catch (std::ifstream::failure e) {
		std::cout << "ERROR::SHADER::FILE_NOT_SUCCESFULLY_READ" << std::endl;
	}

	const char* pFileContent = fileContent.c_str();

	return pFileContent;
}