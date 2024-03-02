.PHONY: help all clean

all: main test # Build all targets

help: # Show help for each of the Makefile recipes.
	@printf "\n"
	@grep -E '^[a-z].*:.*'  Makefile | while read -r l; do printf "\033[1;32m$$(echo $$l | cut -f 1 -d':')\033[00m:$$(echo $$l | cut -f 2- -d'#')\n"; done
	@printf "\n"

main: main.cpp # Build main file
	g++ -std=c++20 -Iinclude animals.cpp main.cpp -o main

test: ../tests/animals_test.cpp # Build test program
	g++ -std=c++20 -Iinclude animals.cpp ../tests/animals_test.cpp -o test

clean: # Delete all builded files
	rm -f main test