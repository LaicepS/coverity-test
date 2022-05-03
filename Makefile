all: main.c
	gcc -O3 -Wall -Wextra -Werror -fsanitize=undefined main.c -o main
	./main
