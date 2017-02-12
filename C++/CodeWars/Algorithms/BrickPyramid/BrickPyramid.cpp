#include <iostream>
#include <assert.h>

class Pyramid {
	public:
		static double weight (int row, int pos);
};

double Pyramid::weight (int row, int pos) {
	if (row == 0 && pos == 0)
		return 0;

	if (pos == 0) // left edge
		return (weight (row-1, pos)+1)/2;

	if (pos == row) // right edge
		return (weight (row-1, pos-1)+1)/2;

	// in the middle
	return (weight (row-1, pos-1)+1)/2 + (weight (row-1, pos)+1)/2;
}


int main () {
	assert (Pyramid::weight (0,0) == 0.0);
	assert (Pyramid::weight (1,0) == 0.5);
	assert (Pyramid::weight (1,1) == 0.5);
	assert (Pyramid::weight (2,0) == 0.75);
	assert (Pyramid::weight (2,1) == 1.5);
	assert (Pyramid::weight (2,2) == 0.75);
	assert (Pyramid::weight (3,0) == 0.875);
	assert (Pyramid::weight (3,1) == 2.125);
	assert (Pyramid::weight (3,2) == 2.125);
	assert (Pyramid::weight (3,3) == 0.875);
	std::cout << "Everything works!" << std::endl;
	return 0;
}
