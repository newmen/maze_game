/*
 * Maze.cpp
 *
 *  Created on: 27.12.2011
 *      Author: newmen
 */

#include "Maze.h"
#include <fstream>
#include <iostream>
#include <termios.h> // для правильной обработки нажатия клавишь

#include "FileOpenError.h"

namespace MazeGame {

typedef std::vector<const Symbol*> ConstSymbols;
typedef std::vector<ConstSymbols> AllConstSymbols;

Maze::Maze() : _finish(false) {}

Maze::~Maze() {
	for (AllElements::iterator pel = _elements.begin(); pel != _elements.end(); ++pel) {
		for (Elements::iterator p = pel->begin(); p != pel->end(); ++p) {
			delete *p;
		}
	}

	resetTerminal();
}

void Maze::build(const char *maze_file_name) {
	Element::setMaze(this);

	std::ifstream file(maze_file_name);
	if (!file) throw new FileOpenError(maze_file_name);

	const int BUF_SIZE = 1024;
	char buf[BUF_SIZE];
	int x, y = 0;
	while (true) {
		file.getline(buf, BUF_SIZE);
		if (file.eof()) break;

		Elements line;
		x = 0;
		for (char *p = buf; *p; ++p) {
			line.push_back(Element::factory(*p, x++, y));
		}
		_elements.push_back(line);
		++y;
	}
}

void Maze::play() {
	Message msg("Найдите выход из лабиринта!");
	do {
		clrscr();
		printMaze();
		printMessage(msg);
		msg = readAndMove();
	} while (!_finish);

	clrscr();
	printMessage(msg);
	std::cout << "  Для выхода из лабиринта Вам потребовалось " << _character.steps() << " шагов\n" << std::endl;
}

void Maze::onExit() {
	_finish = true;
}

void Maze::firstMoveCharacter(int x, int y) {
	Point p(x, y);
	_character.move(&p);
}

void Maze::clrscr() const {
	const int lines = 50;
	for (int i = 0; i < lines; ++i) std::cout << "\n";
}

void Maze::printMaze() const {
	AllConstSymbols symbols;

	for (AllElements::const_iterator pel = _elements.begin(); pel != _elements.end(); ++pel) {
		ConstSymbols line;
		for (Elements::const_iterator p = pel->begin(); p != pel->end(); ++p) {
			line.push_back(*p);
		}
		symbols.push_back(line);
	}

	symbols[_character.y()][_character.x()] = &_character;

	for (AllConstSymbols::const_iterator psl = symbols.begin(); psl != symbols.end(); ++psl) {
		for (ConstSymbols::const_iterator p = psl->begin(); p != psl->end(); ++p) {
			std::cout << (*p)->symbol();
		}
		std::cout << "\n";
	}
}

void Maze::printMessage(const Message &message) {
	std::cout << "\n  " << message.text() << "\n" << std::endl;
}

Message Maze::readAndMove() {
	struct termios t;
	tcgetattr(0, &t);
	t.c_lflag &= ~ICANON;
	t.c_lflag &= ~ECHO;
	tcsetattr(0, TCSANOW, &t);

	char c;
	ssize_t result;
	bool good_key = false;
	do {
		result = read(0, &c, 1);
		if (c == 91) {
			result = read(0, &c, 1); // если нажимаем стрелку - считываем ещё раз
			if (c > 64 && c < 69) good_key = true;
		}
	} while (!good_key);

	std::cout << "RESULT: " << result << std::endl;

	int x = _character.x();
	int y = _character.y();

	switch (c) {
	case 65: // UP
		--y;
		break;
	case 66: // DOWN
		++y;
		break;
	case 67: // RIGHT
		++x;
		break;
	case 68: // LEFT
		--x;
		break;
	}

	return _elements[y][x]->enter(&_character);
}

void Maze::resetTerminal() const {
	struct termios t;
	tcgetattr(0, &t);
	t.c_lflag |= ICANON;
	t.c_lflag |= ECHO;
	tcsetattr(0, TCSADRAIN, &t);
}

}
