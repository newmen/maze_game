/*
 * FileOpenError.h
 *
 *  Created on: 27.12.2011
 *      Author: newmen
 */

#ifndef FILEOPENERROR_H_
#define FILEOPENERROR_H_

#include "Error.h"

namespace MazeGame {

class FileOpenError: public Error {
public:
	FileOpenError(const char *file_name);
	FileOpenError(const FileOpenError &other);
	virtual ~FileOpenError();

	void printMessage(std::ostream &os) const;

private:
	char *_file_name;
};

}

#endif /* FILEOPENERROR_H_ */
