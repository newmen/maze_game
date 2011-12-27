/*
 * Point.h
 *
 *  Created on: 27.12.2011
 *      Author: newmen
 */

#ifndef POINT_H_
#define POINT_H_

namespace MazeGame {

class Point {
public:
	Point(int x, int y);

	int x() const { return _x; }
	int y() const { return _y; }

protected:
	int _x, _y;
};

}

#endif /* POINT_H_ */
