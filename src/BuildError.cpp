/*
 * BuildError.cpp
 *
 *  Created on: 27.12.2011
 *      Author: newmen
 */

#include "BuildError.h"

namespace MazeGame {

BuildError::BuildError(char symbol, int x, int y) : Point(x, y), _symbol(symbol) {}

void BuildError::printMessage(std::ostream& os) const {
	os << "Неизвестный символ \"" << _symbol << "\" в "
			<< y() + 1 << " строке, " << x() + 1 << " символ" << std::endl;
}

}
