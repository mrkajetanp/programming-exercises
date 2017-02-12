#include <iostream>
#include <vector>
#include <utility>
#include "gtest/gtest.h"
#include "includes/MineField.h"

int main () {
	auto field = 1, maxFields = 0;
	while (std::cout << "Number of field: " && !(std::cin >> maxFields)) {
		std::cin.clear ();
		std::cin.ignore (std::numeric_limits<std::streamsize>::max(), '\n');
		std::cerr << "Invalid input. Please re-enter." << std::endl;
	}

	for (int i = 0 ; i < maxFields ; ++i) {
		MineField m (std::cin);
		m.sweep ();
		std::cout << std::endl;
		std::cout << "Field #" << field << ":" << std::endl;
		m.display ();
		std::cout << std::endl;
		field++;
	}
	return 0;
}

