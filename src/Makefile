CC = g++

COMPILER_FLAGS = -g

DEPS = space_invaders.cpp game.cpp window.cpp texture.cpp

LINKER_FLAGS = -lSDL2 -lSDL2_image

OUTPUT = space_invaders

game: ${DEPS}
	${CC} ${COMPILER_FLAGS} ${DEPS} ${LINKER_FLAGS} -o ${OUTPUT} 

clean:
	rm -f *.o


