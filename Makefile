NAME = maze_game
C = g++
SRC_DIR = src
FLAGS = -W -O3

all : maze

maze :
	$(C) $(FLAGS) $(SRC_DIR)/*.h $(SRC_DIR)/*.cpp -o $(NAME)

clean :
#	rm -f *.o
	rm $(NAME)
	
