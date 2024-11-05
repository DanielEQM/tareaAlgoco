all2:
		g++ FuerzaBruta.cpp funtion.hpp costos.hpp -o si
		./si < input.txt

all:
		g++ editdistance.cpp funtion.hpp costos.hpp -o si
		./si < input.txt

run:
		g++ matrix.cpp -o si
		./si

clear:
		rm -f si