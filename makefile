build:
	clear && clang++ main.cpp source/*.cpp -o bin/debug -I include -I SDL2.framework/Headers -I include/collection -F ./ -framework SDL2
run:
	clear && ./bin/debug