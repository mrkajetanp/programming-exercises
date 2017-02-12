#include <iostream>
#include <vector>
#include "../includes/MineField.h"

MineField::MineField () {
	std::vector<std::vector<char>> newField;

	newField.push_back ({ '.', '*', '.', '.' });
	newField.push_back ({ '*', '.', '.', '*' });
	newField.push_back ({ '*', '*', '.', '.' });
	newField.push_back ({ '.', '*', '.', '.' });

	field = newField;
}

MineField::MineField (std::vector<std::vector<char>>& vec) {
	field = vec;
}

std::vector<std::vector<char>> MineField::getData () {
	return field;
}

MineField::MineField (std::istream& is) {
	auto columns = 0, rows = 0;
	while (std::cout << "Columns and rows: " && !(is >> columns >> rows)) {
		is.clear ();
		is.ignore (std::numeric_limits<std::streamsize>::max(), '\n');
		std::cout << "Invalid input. Please re-enter." << std::endl;
	}

	char c;
	for (int i = 0; i < rows; ++i) {
			std::vector<char> newRow;
			for (int j = 0; j < columns ; ++j) {
				is >> c;
				newRow.push_back (c);
			}
			field.push_back (newRow);
	}
}

void MineField::sweep () {
	auto bombs = 0;
	for (int x = 0; x < 4; x++) {
		for (int y = 0; y < 4; y++) {
			for (int i = 0; i < 8 ; ++i) {
				auto cx = x + moves[i][0];
				auto cy = y + moves[i][1];
				if (cx < 0 || cx >= 4 || cy < 0 || cy >= 4) {
					continue;
				}
				if (field[cx][cy] == '*')
					bombs++;
				}
				if (field[x][y] != '*')
					field[x][y] = '0'+bombs;
				bombs = 0;
		}
	}
}

void MineField::display () {
	for (auto& r : field) {
		for (auto& c : r)
			std::cout << c;
		std::cout << std::endl;
	}
}


