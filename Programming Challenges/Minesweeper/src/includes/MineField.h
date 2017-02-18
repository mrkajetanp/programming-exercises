#ifndef MINE_FIELD_INCLUDED
#define MINE_FIELD_INCLUDED

#include <vector>


class MineField {
private:
	std::vector<std::vector<char>> field;
	int moves[8][2] = {{-1,0}, {-1, -1}, {0, -1}, {1, -1}, {1, 0}, {1, 1}, {0, 1}, {-1, 1}};
public:
	MineField ();
	MineField (std::vector<std::vector<char>>& vec);
	MineField (std::istream& is);
	std::vector<std::vector<char>> getData ();
	void sweep ();
	void display ();
};

#endif /* ifndef MINE_FIELD_INCLUDED */
