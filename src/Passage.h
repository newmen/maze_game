/*
 * Passage.h
 *
 *  Created on: 27.12.2011
 *      Author: newmen
 */

#ifndef PASSAGE_H_
#define PASSAGE_H_

#include "Element.h"

namespace MazeGame {

class Passage: public Element {
public:
	Passage(int x, int y, Item *item);
	virtual ~Passage();

	char symbol() const;
	Message enter(Character *ch);

private:
	Item *_item;
};

}

#endif /* PASSAGE_H_ */
