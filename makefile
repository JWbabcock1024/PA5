CC = g++
FLAGS = -Wall -std=c++17 
LINKS = -lsfml-graphics -lsfml-window -lsfml-system 
game: main.o game.o welcome.o play.o car.o button.o results.o
	$(CC) $(FLAGS) $^ -o $@ $(LINKS)

main.o: main.cpp game.h
	$(CC) $(FLAGS) -c $< -o main.o

game.o: game.cpp game.h states.h welcome.h play.h results.h
	$(CC) $(FLAGS) -c $< -o game.o

welcome.o: welcome.cpp welcome.h states.h button.h
	$(CC) $(FLAGS) -c $< -o welcome.o

play.o: play.cpp play.h states.h button.h car.h
	$(CC) $(FLAGS) -c $< -o play.o

car.o: car.cpp car.h   
	$(CC) $(FLAGS) -c $< -o car.o

button.o: button.cpp button.h
	$(CC) $(FLAGS) -c $< -o button.o

results.o: results.cpp results.h states.h button.h
	$(CC) $(FLAGS) -c $< -o results.o