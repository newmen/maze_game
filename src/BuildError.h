/*
 * BuildError.h
 *
 *  Created on: 27.12.2011
 *      Author: newmen
 */

#ifndef BUILDERROR_H_
#define BUILDERROR_H_

#include "Point.h"
#include "Error.h"

namespace MazeGame {

class BuildError : public Point, public Error {
public:
	BuildError(char symbol, int x, int y);

	void printMessage(std::ostream &os) const;

private:
	char _symbol;
};

}

#endif /* BUILDERROR_H_ */
