CXXFLAGS += -g -Wall -std=c++14 -Wextra

TARGETS = CarTest

all : $(TARGETS)

run :
	./bin/CarTest

clean :
	rm bin/*

Car.o : ./src/Car.cpp
	$(CXX) $(CXXFLAGS) -c src/Car.cpp -o bin/Car.o

CarTest.o : ./src/CarTest.cpp
	$(CXX) $(CXXFLAGS) -c src/CarTest.cpp -o bin/CarTest.o

CarTest : CarTest.o Car.o
	$(CXX) $(CXXFLAGS) bin/CarTest.o bin/Car.o -o bin/$@

#Tests : Tests.o gtest_main.a MineField.o
#	$(CXX) $(CPPFLAGS) $(CXXFLAGS) -lpthread $(TESTS_DEPENDS) -o $(BIN_DIR)/$@


