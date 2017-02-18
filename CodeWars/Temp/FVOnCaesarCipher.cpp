// Copyright 2017 Cajetan Puchalski

#include <iostream>
#include <vector>
#include <cmath>

class CaesarCipher {
	public:
		static std::vector<std::string> movingShift (const std::string& s, int shift);
		static std::string demovingShift (std::vector<std::string>& s, int shift);
};

std::vector<std::string> CaesarCipher::movingShift (const std::string& s, int shift) {
	std::string rs = s;
	for (char &c : rs) {
		if (isalpha(c)) {
			if (islower(c)) {
				if (c+shift%26 > 'z') // if result would exceed the size of the alphabet
					c = 'a'-1 + (c+shift%26)-'z'; // "jump" to the beginning of the alphabet
				else // if it's okay, just add the required shift
					c += shift%26; // %26 because there are 26 letters in the alphabet
			}
			if (isupper(c)) { // same as above, for the uppercase letters
				if (c+shift%26 > 'Z')
					c = 'A'-1 + (c+shift%26)-'Z';
				else
					c += shift%26;
			}
		}
		shift++;
	}
	double size = std::ceil(static_cast<double>(rs.size())/5); // size of 4 parts of the message

	int pos = 0; // position in a result string
	std::vector<std::string> result;
	for (int i = 0; i < 4; ++i) { // 4 times, because there are 4 parts with the same size
		result.push_back(rs.substr (pos, size)); // push a part to the result vector
		pos += size; // move the position, so that the next part begins after the previous one ends
	}
	result.push_back (rs.substr(pos)); // push back remaining chars as the 5th part
	return result;
}

std::string CaesarCipher::demovingShift (std::vector<std::string>& s, int shift) {
	std::string res;
	for (std::string& str : s)
		res += str;
	for (char &c : res) {
		if (isalpha(c)) {
			if (islower(c)) {
				if (c-shift%26 < 'a') // same as in CaesarCipher::movingShift, just reversed
					c = 'z'+1 - (shift%26-(c-'a'));
				else
					c -= shift%26;
			}
			if (isupper(c)) {
				if (c-shift%26 < 'A')
					c = 'Z'+1 - (shift%26-(c-'A'));
				else
					c -= shift%26;
			}
		}
		shift++;
	}
	return res;
}

int main () {
	std::vector<std::string> v1;
	v1 = CaesarCipher::movingShift ("I should have known that you would have a perfect answer for me!!!", 1);

	for (std::string& s : v1)
		std::cout << "\"" << s << "\" ";
	std::cout << std::endl;

	std::cout << CaesarCipher::demovingShift (v1, 1) << std::endl;

	return 0;
}
