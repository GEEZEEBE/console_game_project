Execute : accumulateObject backgroundObject codelineObject descendObject gameoverObject mainObject non_blocking_typingObject scoreObject shootObject
	g++ -o typingshooting accumulate.o background.o codeline.o descend.o gameover.o main.o non_blocking_typing.o score.o shoot.o -lcurses
accumulateObject :
	g++ -c -o accumulate.o accumulate.cpp
backgroundObject :
	g++ -c -o background.o background.cpp
codelineObject :
	g++ -c -o codeline.o codeline.cpp
descendObject :
	g++ -c -o descend.o descend.cpp
gameoverObject :
	g++ -c -o gameover.o gameover.cpp
mainObject :
	g++ -c -o main.o main.cpp
non_blocking_typingObject :
	g++ -c -o non_blocking_typing.o non_blocking_typing.cpp
scoreObject :
	g++ -c -o score.o score.cpp
shootObject :
	g++ -c -o shoot.o shoot.cpp
clean :
	rm *.o typingshooting