/*
 * FileOpenError.cpp
 *
 *  Created on: 27.12.2011
 *      Author: newmen
 */

#include "FileOpenError.h"
#include <cstring>

namespace MazeGame {

FileOpenError::FileOpenError(const char *file_name) {
	int length = strlen(file_name);
	_file_name = new char[length + 1];
	strcpy(_file_name, file_name);
}

FileOpenError::FileOpenError(const FileOpenError &other) {
	int length = strlen(other._file_name);
	_file_name = new char[length + 1];
	strcpy(_file_name, other._file_name);
}

FileOpenError::~FileOpenError() {
	delete [] _file_name;
}

void FileOpenError::printMessage(std::ostream &os) const {
	os << "Невозможно открыть файл " << _file_name << std::endl;
}

}
