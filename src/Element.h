/*
 * Element.h
 *
 *  Created on: 27.12.2011
 *      Author: newmen
 */

#ifndef ELEMENT_H_
#define ELEMENT_H_

#include "Point.h"
#include "Symbol.h"
#include "Character.h"
#include "Item.h"

#include "Message.h"
#include "BuildError.h"

namespace MazeGame {

class Maze;

class Entrance;
class Exit;
class Wall;
class Door;
class Portal;
class Passage;

class Element: public Point, public Symbol {
public:
	static void setMaze(Maze *maze);
	static Element *factory(char symbol, int x, int y);

	virtual Message enter(Character *ch) = 0;

protected:
	Element(int x, int y);

	static Maze *__maze;
};

}

#endif /* ELEMENT_H_ */
