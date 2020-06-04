all:
	g++ -L lib32 -I include32 yams.cpp libgraphique.cpp -o Programme -lmingw32 -lSDL2main -lSDL2 -LSDL2_image -lSDL2_ttf  -mwindows
clean:
	rm -f *o

