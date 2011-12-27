/*
 * Error.h
 *
 *  Created on: 27.12.2011
 *      Author: newmen
 */

#ifndef ERROR_H_
#define ERROR_H_

#include <ostream>

namespace MazeGame {

class Error {
public:
	virtual void printMessage(std::ostream &os) const = 0;

protected:
	Error() {}
};

}

#endif /* ERROR_H_ */
