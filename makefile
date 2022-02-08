build:
	clear && clang++ *.cpp -o bin/debug -I include -I SDL2.framework/Headers -F ./ -framework SDL2
run:
	clear && ./bin/debug