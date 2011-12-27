/*
 * Element.cpp
 *
 *  Created on: 27.12.2011
 *      Author: newmen
 */

#include "Element.h"

#include "Maze.h"
#include "Entrance.h"
#include "Exit.h"
#include "Wall.h"
#include "Door.h"
#include "Portal.h"
#include "Passage.h"

#include "BuildError.h"

namespace MazeGame {

Maze *Element::__maze = 0;

Element::Element(int x, int y) : Point(x, y) {}

void Element::setMaze(Maze *maze) {
	__maze = maze;
}

Element *Element::factory(char symbol, int x, int y) {
	static Portal *first_portal = 0;
	Portal *current_portal = 0;

	switch (symbol) {
	case 'b':
		__maze->firstMoveCharacter(x, y);
		return new Entrance(x, y);
	case 'e': return new Exit(x, y);
	case '#': return new Wall(x, y);
	case '-': return new Door(x, y, true);
	case '=': return new Door(x, y, false);
	case '0':
		current_portal = new Portal(x, y);
		if (first_portal) {
			current_portal->setWayOut(first_portal);
			first_portal->setWayOut(current_portal);
		} else {
			first_portal = current_portal;
		}
		return (Element *)current_portal;
	case ' ': return new Passage(x, y, 0);
	case 'k':
		return new Passage(x, y, Item::factory(symbol));
	}

	throw new BuildError(symbol, x, y);
	return 0;
}

}
