/*
 * Passage.cpp
 *
 *  Created on: 27.12.2011
 *      Author: newmen
 */

#include "Passage.h"
#include <cstdio>

namespace MazeGame {

Passage::Passage(int x, int y, Item *item) : Element(x, y), _item(item) {}

Passage::~Passage() {
	if (_item) delete _item;
}

char Passage::symbol() const {
	if (_item) return _item->symbol();
	return ' ';
}

Message Passage::enter(Character *ch) {
	ch->move(this);

	if (_item) {
		if (_item->raise(ch)) {
			char msg_buf[100];
			sprintf(msg_buf, "Вы поднимаете %s", _item->name());

			delete _item;
			_item = 0;

			return Message(msg_buf);
		} else {
			return Message("Вы не можете поднять это");
		}
	}

	return Message("Вы идёте по тёмному коридору");
}

}
