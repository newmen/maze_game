#include <iostream>
#include "Maze.h"

int main(int argc, char* argv[]) {
	if (argc != 2) {
		std::cerr << "Неверное количество аргументов! Попробуйте:\n"
				<< argv[0] << " путь/до_файла/лабиринта.txt" << std::endl;
		return 1;
	}

	MazeGame::Maze maze;
	try {
		maze.build(argv[1]);
	} catch (MazeGame::Error *error) {
		error->printMessage(std::cerr);
		delete error;
		return 1;
	}

	maze.play();

	return 0;
}
