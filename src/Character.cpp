/*
 * Character.cpp
 *
 *  Created on: 27.12.2011
 *      Author: newmen
 */

#include "Character.h"

namespace MazeGame {

Character::Character() : Point(-1, -1), _steps(0), _has_key(false) {}

void Character::move(const Point *point) {
	_x = point->x();
	_y = point->y();
	++_steps;
}

}
