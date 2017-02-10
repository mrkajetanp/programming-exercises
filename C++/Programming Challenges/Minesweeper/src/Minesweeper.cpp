#include <iostream>
#include <vector>
#include <utility>
#include "gtest/gtest.h"
#include "includes/MineField.h"

int main () {
	auto field = 1, maxFields = 0;
	std::cout << "Number of fields: ";
	std::cin >> maxFields;
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

