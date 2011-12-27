/*
 * Entrance.cpp
 *
 *  Created on: 27.12.2011
 *      Author: newmen
 */

#include "Entrance.h"

namespace MazeGame {

Entrance::Entrance(int x, int y) : Element(x, y) {}

Message Entrance::enter(Character *ch) {
	ch->move(this);
	return Message("Вы вернулись в начало");
}

}
