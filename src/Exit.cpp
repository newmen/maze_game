/*
 * Exit.cpp
 *
 *  Created on: 27.12.2011
 *      Author: newmen
 */

#include "Exit.h"

#include "Maze.h"

namespace MazeGame {

Exit::Exit(int x, int y) : Element(x, y) {}

Message Exit::enter(Character *ch) {
	ch->move(this);
	__maze->onExit();
	return Message("Поздравляем! Вы таки достигли выхода");
}

}
