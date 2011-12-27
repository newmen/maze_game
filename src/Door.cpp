/*
 * Door.cpp
 *
 *  Created on: 27.12.2011
 *      Author: newmen
 */

#include "Door.h"
#include <cstdlib>

namespace MazeGame {

Door::Door(int x, int y, bool opened) : Element(x, y), _opened(opened) {}

char Door::symbol() const {
	if (_opened) return '-';
	return '=';
}

Message Door::enter(Character *ch) {
	if (_opened) {
		ch->move(this);
		return Message("Вы проходите в открытую дверь");
	}

	if (ch->hasKey()) {
		_opened = true;
		ch->useKey();
		ch->move(this);
		return Message("Вы открываете дверь и проходите в неё");
	}

	int r = rand() % 2;
	if (r == 0) return Message("Со всего маху вы влетаете в закрытую дверь");
	return Message("Дверь заперта, чтобы пройти нужен ключ");
}

}
