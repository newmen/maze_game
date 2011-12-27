/*
 * Portal.cpp
 *
 *  Created on: 27.12.2011
 *      Author: newmen
 */

#include "Portal.h"

namespace MazeGame {

Portal::Portal(int x, int y) : Element(x, y), _way_out(0) {}

void Portal::setWayOut(Portal* way_out) {
	_way_out = way_out;
}

Message Portal::enter(Character *ch) {
	if (_way_out) {
		ch->move(_way_out);
		return Message("Вы проходите в портал и оказываетесь по ту сторону сумрака");
	}

	return Message("У этого портала нет выхода, Вы не можете в него войти");
}

}
