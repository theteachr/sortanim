main: main.c core.h core.c animate.h animate.c bubble.c
	gcc main.c core.c animate.c bubble.c -o main

run: main
	./main

.PHONY: run
