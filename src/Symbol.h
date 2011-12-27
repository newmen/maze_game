/*
 * Symbol.h
 *
 *  Created on: 27.12.2011
 *      Author: newmen
 */

#ifndef SYMBOL_H_
#define SYMBOL_H_

namespace MazeGame {

class Symbol {
public:
	virtual const char symbol() const = 0;

protected:
	Symbol() {}
};

}

#endif /* SYMBOL_H_ */
