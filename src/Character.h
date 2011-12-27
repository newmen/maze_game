/*
 * Character.h
 *
 *  Created on: 27.12.2011
 *      Author: newmen
 */

#ifndef CHARACTER_H_
#define CHARACTER_H_

#include "Point.h"
#include "Symbol.h"

namespace MazeGame {

class Character : public Point, public Symbol {
public:
	Character();

	void move(const Point *point);
	int steps() const { return _steps; }

	bool hasKey() const { return _has_key; }
	void takeKey() { _has_key = true; }
	void useKey() { _has_key = false; }

	const char symbol() const { return '+'; }

private:
	int _steps;
	bool _has_key;
};

}

#endif /* CHARACTER_H_ */
