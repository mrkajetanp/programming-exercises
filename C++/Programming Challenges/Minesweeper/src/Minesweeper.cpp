#include <iostream>
#include <vector>
#include <utility>
#include <gtest/gtest.h>

// TODO: Make a class out of it
// TODO: Split into files
// TODO: Separate function for sweeping corners, edges and middle

// TODO: Finish Me
void getField () {
	int n, m; // lines and columns
	std::cin >> n >> m;

	std::vector<std::string> field;
	std::string newRow;

	std::cin >> newRow;

	std::cout << newRow << std::endl;

}

std::vector<std::string> fakeField () {
	std::vector<std::string> field;

	field.push_back(".*..");
	field.push_back("*..*");
	field.push_back("**..");
	field.push_back(".*..");

	return field;
}

int f (int a) {
	return a*2;
}

std::vector<std::string> sweepField (std::vector<std::string> field) {
	std::vector<std::string> result = field;
	int rowEnd = 3, collEnd = 3;
	std::string tempRow;

	// Corner case
	std::vector<std::pair<int, int>> corners = { {0,0}, {0,rowEnd}, {collEnd,0}, {collEnd,rowEnd} };
	std::vector<std::pair<int, int>> c1adj = { {0,1}, {1,0}, {1,1} };
	std::vector<std::pair<int, int>> c2adj = { {0,rowEnd-1}, {1,rowEnd}, {1,rowEnd-1} };
	std::vector<std::pair<int, int>> c3adj = { {collEnd, 1}, {collEnd-1,0}, {collEnd-1,1} };
	std::vector<std::pair<int, int>> c4adj = { {collEnd, rowEnd-1}, {collEnd-1,rowEnd}, {rowEnd-1,collEnd-1} };

	int bombs = 0;

	for (auto& xy : corners) {
		if (xy.first == 0) {
			if (xy.second == 0) { // (0,0)
				if (field[xy.first][xy.second] == '*')
					continue;
				for (auto& ij : c1adj)
					if (field[ij.first][ij.second] == '*')
						bombs++;
				result[xy.first][xy.second] = static_cast<char>('0'+bombs);
				bombs = 0;
			}
			else { // (0,rowEnd)
				if (field[xy.first][xy.second] == '*')
					continue;
				for (auto& ij : c2adj)
					if (field[ij.first][ij.second] == '*')
						bombs++;
				result[xy.first][xy.second] = static_cast<char>('0'+bombs);
				bombs = 0;
			}
		}
		else {
			if (xy.second == 0) { // (collEnd,0)
				if (field[xy.first][xy.second] == '*')
					continue;
				for (auto& ij : c3adj)
					if (field[ij.first][ij.second] == '*')
						bombs++;
				result[xy.first][xy.second] = static_cast<char>('0'+bombs);
				bombs = 0;
			}
			else { // (collEnd,rowEnd)
				if (field[xy.first][xy.second] == '*')
					continue;
				for (auto& ij : c4adj)
					if (field[ij.first][ij.second] == '*')
						bombs++;
				result[xy.first][xy.second] = static_cast<char>('0'+bombs);
				bombs = 0;
			}
		}
	}
	return result;
}

int main () {
	std::cout << std::endl;

	std::vector<std::string> f1 = sweepField (fakeField());

	for (auto& s : f1)
		std::cout << s << std::endl;

	EXPECT_EQ (f1[0], "2*.1");
	EXPECT_EQ (f1[1], "*..*");
	EXPECT_EQ (f1[2], "**..");
	EXPECT_EQ (f1[3], "3*.0");

	std::cout << std::endl;

	return 0;
}
