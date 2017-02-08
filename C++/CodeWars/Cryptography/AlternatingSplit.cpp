#include <iostream>
#include <string>
#include <cassert>

std::string encrypt (std::string text, int n) {
	if (text.empty())
		return "";
	std::string str = text;
	std::string temp1, temp2;

	for (int i = 0; i < n; ++i) {
		for (size_t i = 0, j = 0; i < str.size() ; ++i) {
			if (j == 1) {
				temp1.push_back (str[i]);
				j = 0;
			}
			else {
				temp2.push_back (str[i]);
				j++;
			}
		}
		str = temp1+temp2;
		temp1.clear();
		temp2.clear();
	}
	return str;
}

std::string decrypt (std::string text, int n) {
	if (text.empty())
		return "";
	std::string str (text);
	std::string part1, part2;

	for (int i = 0; i < n; ++i) {
		std::cout << "s: " << str.size() << std::endl;
		int split = (str.size()%2==0) ? (str.size()/2) : (str.size()-1)/2;
		part1 = str.substr (0, split);
		part2 = str.substr (split);
		str.clear ();
		for (size_t j = 0; j < part2.size(); ++j) {
			str.push_back (part2[j]);
			str.push_back (part1[j]);
		}
		if (part1.size() != part2.size())
			str.pop_back ();
	}
	return str;
}

int main () {
	assert (decrypt("This is a test!", 0) == "This is a test!");
	assert (decrypt("hsi  etTi sats!", 1) == "This is a test!");
	assert (decrypt("s eT ashi tist!", 2) == "This is a test!");
	assert (decrypt("This is a test!", 0) == "This is a test!");
	return 0;
}
