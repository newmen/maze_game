/*
 * Key.cpp
 *
 *  Created on: 27.12.2011
 *      Author: newmen
 */

#include "Key.h"

namespace MazeGame {

Key::Key() {}

bool Key::raise(Character *ch) const {
	if (ch->hasKey()) return false;

	ch->takeKey();
	return true;
}

}
