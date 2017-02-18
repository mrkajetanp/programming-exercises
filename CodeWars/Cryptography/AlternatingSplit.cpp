#include <iostream>
#include <string>
#include <cassert>

std::string encrypt (std::string text, int n) {
	if (text.empty())
		return "";
	std::string str = text;
	std::string temp1, temp2;

	for (int i = 0; i < n; ++i) {
		bool switcher = false;
		for (auto c : str) {
			if (switcher) {
				temp1.push_back (c);
				switcher = false;
			}
			else {
				temp2.push_back (c);
				switcher = true;
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
		int split = (str.size()%2==0) ? (str.size()/2) : (str.size()-1)/2;
		part1 = str.substr (0, split);
		part2 = str.substr (split);
		str.clear ();
		for (size_t j = 0; j < part2.size(); ++j) {
			str.push_back (part2[j]);
			if (part1[j])
				str.push_back (part1[j]);
		}
	}
	return str;
}

int main () {
	assert (encrypt ("This is a test!", 0) == "This is a test!");
	assert (encrypt ("This is a test!", 1) == "hsi  etTi sats!");
	assert (encrypt ("This is a test!", 2) == "s eT ashi tist!");
	assert (encrypt ("This is a test!", 3) == " Tah itse sits!");
	assert (encrypt ("This is a test!", 4) == "This is a test!");
	assert (encrypt ("This is a test!", -1) == "This is a test!");

	assert (decrypt ("hsi  etTi sats!", 1) == "This is a test!");
	assert (decrypt ("s eT ashi tist!", 2) == "This is a test!");
	assert (decrypt ("This is a test!", 0) == "This is a test!");
	return 0;
}
