all: main.c
	gcc -O3 -Wall -Wextra -Werror \
	  main.c \
	  -fsanitize=signed-integer-overflow \
	  -fsanitize=undefined \
	  -fsanitize=bounds \
	  -fsanitize=address \
	  -o main 
	./main
