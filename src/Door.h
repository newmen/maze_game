/*
 * Door.h
 *
 *  Created on: 27.12.2011
 *      Author: newmen
 */

#ifndef DOOR_H_
#define DOOR_H_

#include "Element.h"

namespace MazeGame {

class Door: public Element {
public:
	Door(int x, int y, bool opened);

	char symbol() const;
	Message enter(Character *ch);

private:
	bool _opened;
};

}

#endif /* DOOR_H_ */
