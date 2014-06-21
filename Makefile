main: main.cpp customer/customer.h customer/customer.cpp customer/customerList.h customer/customerList.cpp 
	clear
	g++ -o main main.cpp customer/customer.h customer/customer.cpp customer/customerList.h customer/customerList.cpp -lpthread
	./main database.txt orders.txt categories.txt
	rm main

debug: main.cpp customer/customer.h customer/customer.cpp customer/customerList.h customer/customerList.cpp 
	clear
	g++ -g main.cpp customer/customer.h customer/customer.cpp customer/customerList.h customer/customerList.cpp -lpthread
	gdb a.out

consumer: consumer.cpp
	clear
	g++ -o main consumer.cpp -lpthread
	./main
	rm main
cdebug: consumer.cpp
	clear
	g++ -g consumer.cpp -lpthread
	gdb a.out
