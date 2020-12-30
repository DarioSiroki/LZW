install: main.cpp lib/LZW.cpp lib/LZW.h
	g++ -o lzw main.cpp lib/LZW.cpp lib/LZW.h -I. -std=c++17