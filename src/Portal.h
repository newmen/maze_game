/*
 * Portal.h
 *
 *  Created on: 27.12.2011
 *      Author: newmen
 */

#ifndef PORTAL_H_
#define PORTAL_H_

#include "Element.h"

namespace MazeGame {

class Portal: public Element {
public:
	Portal(int x, int y);

	void setWayOut(Portal *way_out);

	const char symbol() const { return '0'; }
	Message enter(Character *ch);

private:
	Portal *_way_out;
};

}

#endif /* PORTAL_H_ */
