all: compile run

clearscreen:
	clear

clean:
	echo 0 > prompt.hex && rm prompt.hex

compile: clean
	gcc main.c linked_list.c -o prompt.hex

run: compile
	clear &&./prompt.hex