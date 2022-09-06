all: compilar linkar

compilar:
	g++ -I -c ../sources/principal.cpp -c ../sources/knapsack.cpp -c ../sources/jogo.cpp -lsfml-graphics -lsfml-window -lsfml-system

linkar:
	g++ principal.o knapsack.o jogo.o -o Jogo_Binario -w -l sfml-graphics -l sfml-window -l sfml-system -l sfml-audio && rm *.o && ./Jogo_Binario