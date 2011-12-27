/*
 * Wall.h
 *
 *  Created on: 27.12.2011
 *      Author: newmen
 */

#ifndef WALL_H_
#define WALL_H_

#include "Element.h"

namespace MazeGame {

class Wall: public Element {
public:
	Wall(int x, int y);

	const char symbol() const { return '#'; }
	Message enter(Character *ch);
};

}

#endif /* WALL_H_ */
