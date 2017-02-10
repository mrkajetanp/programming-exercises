#include <iostream>
#include "gtest/gtest.h"
#include "../includes/MineField.h"

int main (int argc, char *argv[]) {
	std::cout << std::endl;
	testing::InitGoogleTest (&argc, argv);
	return RUN_ALL_TESTS();
}

TEST (GeneralSweeps, SweepOne) {
	std::vector<std::vector<char>> newField;
	std::vector<std::vector<char>> expectedField;
	newField.push_back ({ '.', '.', '.', '.' });
	newField.push_back ({ '.', '*', '.', '*' });
	newField.push_back ({ '.', '.', '.', '.' });
	newField.push_back ({ '.', '.', '*', '.' });

	expectedField.push_back ({ '1', '1', '2', '1' });
	expectedField.push_back ({ '1', '*', '2', '*' });
	expectedField.push_back ({ '1', '2', '3', '2' });
	expectedField.push_back ({ '0', '1', '*', '1' });

	MineField b (newField);
	b.sweep ();

	EXPECT_EQ (b.getData(), expectedField);
}

TEST (GeneralSweeps, SweepTwo) {
	std::vector<std::vector<char>> newField1;
	std::vector<std::vector<char>> expectedField1;
	newField1.push_back ({ '.', '*', '.', '.' });
	newField1.push_back ({ '*', '*', '.', '*' });
	newField1.push_back ({ '.', '.', '.', '.' });
	newField1.push_back ({ '.', '*', '*', '.' });

	expectedField1.push_back ({ '3', '*', '3', '1' });
	expectedField1.push_back ({ '*', '*', '3', '*' });
	expectedField1.push_back ({ '3', '4', '4', '2' });
	expectedField1.push_back ({ '1', '*', '*', '1' });

	MineField b1 (newField1);
	b1.sweep ();

	EXPECT_EQ (b1.getData(), expectedField1);
}

