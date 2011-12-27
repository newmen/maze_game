/*
 * Exit.h
 *
 *  Created on: 27.12.2011
 *      Author: newmen
 */

#ifndef EXIT_H_
#define EXIT_H_

#include "Element.h"

namespace MazeGame {

class Exit: public Element {
public:
	Exit(int x, int y);

	char symbol() const { return ' '; }
	Message enter(Character *ch);
};

}

#endif /* EXIT_H_ */
