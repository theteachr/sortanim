main: main.c core.h core.c animate.h animate.c
	gcc main.c core.c animate.c -o main

run: main
	./main

.PHONY: run
