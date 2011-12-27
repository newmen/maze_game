/*
 * Entrance.h
 *
 *  Created on: 27.12.2011
 *      Author: newmen
 */

#ifndef ENTRANCE_H_
#define ENTRANCE_H_

#include "Element.h"

namespace MazeGame {

class Entrance: public Element {
public:
	Entrance(int x, int y);

	char symbol() const { return ' '; }
	Message enter(Character *ch);
};

}

#endif /* ENTRANCE_H_ */
