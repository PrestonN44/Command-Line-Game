

run: game.o helper.cpp Monster.o Moves.o Player.o
	g++ game.o helper.cpp Monster.o Moves.o Player.o -o run

helper.o: helper.cpp headers/helper.h
	g++ -c helper.cpp

game.o: game.cpp headers/helper.h
	g++ -c game.cpp

Monster.o: Monster.cpp headers/Monster.h headers/Monsters/*.h
	g++ -c Monster.cpp

Moves.o: Moves.cpp headers/Moves.h
	g++ -c Moves.cpp

Player.o: Player.cpp headers/Player.h
	g++ -c Player.cpp

clean:	
	del *.o run.exe