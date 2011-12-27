/*
 * Item.cpp
 *
 *  Created on: 27.12.2011
 *      Author: newmen
 */

#include "Item.h"

#include "Key.h"

namespace MazeGame {

Item *Item::factory(char symbol) {
	switch (symbol) {
	case 'k': return new Key();
	}

	return 0;
}

}
