Main:Person.cpp ATM.cpp Main.cpp
	g++ Person.cpp ATM.cpp Main.cpp -o Main -lmysqlclient -std=c++11
clean:
	rm -f Main
