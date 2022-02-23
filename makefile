# A build command for macOS compilation
build-mac:
	clear && clang++ \
	main.cpp \
	source/game-engine/*.cpp \
	source/game-object/*.cpp \
	source/other/*.cpp \
	-o bin/debug \
	-I include \
	-I SDL2.framework/Headers \
	-I include/collection \
	-I include/game-object \
	-I include/game-engine \
	-I include/other \
	-F ./ -framework SDL2

# A run command for macOS, launching the program
run-mac:
	clear && ./bin/debug