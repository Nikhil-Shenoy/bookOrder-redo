main: customer.h customer.cpp custTest.cpp
	clear
	g++ -o main custTest.cpp customer.h customer.cpp
	./main
	rm main
debug: customer.h customer.cpp custTest.cpp
	clear
	g++ -g custTest.cpp customer.h customer.cpp
	gdb a.out

list: list.cpp customer.h customer.cpp customerList.h customerList.cpp
	clear
	g++ -o list customer.h customer.cpp customerList.h customerList.cpp list.cpp
	./list
	rm list
dlist: list.cpp customer.h customer.cpp customerList.h customerList.cpp
	clear
	g++ -g list.cpp customer.h customer.cpp customerList.h customerList.cpp
	gdb a.out



