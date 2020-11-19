macos:
	clang++ -std=c++17 -o program driver.cpp bag.cpp
gnu:
	g++ -std=c++17 -o program driver.cpp bag.cpp
win:
	g++ -std=c++17 -static-libgcc -static-libstdc++ -o program.exe driver.cpp bag.cpp
debug:
	g++ -std=c++17 -g -o program driver.cpp bag.cpp
clean:
	rm -rf program*
cleaner:
	DEL .\program.exe
