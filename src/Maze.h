/*
 * Maze.h
 *
 *  Created on: 27.12.2011
 *      Author: newmen
 */

#ifndef MAZE_H_
#define MAZE_H_

#include <vector>
#include "Character.h"
#include "Element.h"
#include "Message.h"

namespace MazeGame {

typedef std::vector<Element*> Elements;
typedef std::vector<Elements> AllElements;

class Maze {
public:
	Maze();
	virtual ~Maze();

	void build(const char *maze_file_name);
	void play();
	void onExit();
	void firstMoveCharacter(int x, int y);

private:
	void clrscr() const;
	void printMaze() const;
	void printMessage(const Message &message);
	Message readAndMove();
	void resetTerminal() const;

private:
	Character _character;
	AllElements _elements;
	bool _finish;
};

}

#endif /* MAZE_H_ */
