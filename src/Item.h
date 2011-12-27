/*
 * Item.h
 *
 *  Created on: 27.12.2011
 *      Author: newmen
 */

#ifndef ITEM_H_
#define ITEM_H_

#include "Symbol.h"
#include "Character.h"

namespace MazeGame {

class Key;

class Item: public Symbol {
public:
	static Item *factory(char symbol);

	virtual const char *name() const = 0;
	virtual bool raise(Character *ch) const = 0;

protected:
	Item() {}
};

}

#endif /* ITEM_H_ */
