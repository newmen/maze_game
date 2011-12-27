/*
 * Wall.cpp
 *
 *  Created on: 27.12.2011
 *      Author: newmen
 */

#include "Wall.h"
#include <cstdlib>

namespace MazeGame {

Wall::Wall(int x, int y) : Element(x, y) {}

Message Wall::enter(Character *ch) {
	int r = rand() % 3;

	switch (r) {
	case 0: return Message("Вы стукнулись об стену головой");
	case 1: return Message("Вы почувствовали приятный холодок стены");
	}

	return Message("Дальше не пройти, у Вас на пути стена");
}

}
