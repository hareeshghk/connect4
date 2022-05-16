default: connect4

connect4:
	/usr/bin/g++ -std=c++17 -stdlib=libc++ -fdiagnostics-color=always -g main.cpp connect4.cpp -o connect4.out