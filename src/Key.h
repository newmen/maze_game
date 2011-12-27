/*
 * Key.h
 *
 *  Created on: 27.12.2011
 *      Author: newmen
 */

#ifndef KEY_H_
#define KEY_H_

#include "Item.h"

namespace MazeGame {

class Key: public Item {
public:
	Key();

	const char symbol() const { return 'k'; }
	const char *name() const { return "Ключ"; }
	bool raise(Character *ch) const;
};

}

#endif /* KEY_H_ */
