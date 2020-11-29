CC = g++

ifeq ($(OS),Windows_NT)
	LIBS = -lmingw32
	clr = del /s *.o
	propre = del /s *.exe
else
	LIBS = `sdl2-config --cflags --libs`
	clr = rm -rf *.o
	propre = find . -type f -executable -delete
endif

TradInstance: main.o utils.o
	${CC} $^ -o $@ ${LIBS}

%.o: %.c
	${CC} $< -c -o $@ ${LIBS}

clean:
	${clr}

mrproper: clean
	${propre}