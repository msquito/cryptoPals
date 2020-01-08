// cryptoPals_01.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "cryptoPals_01.h"

std::string base64[64] = { "A", "B", "C", "D", "E", "F", "G", "H",
							"I", "J", "K", "L",	"M", "N", "O", "P",
							"Q", "R", "S", "T", "U", "V", "W", "X",
							"Y", "Z", "a", "b", "c", "d", "e", "f",
							"g", "h", "i", "j", "k", "l", "m", "n",
							"o", "p", "q", "r", "s", "t", "u", "v",
							"w", "x", "y", "z", "0", "1", "2", "3",
							"4", "5", "6", "7", "8", "9", "+", "/" };

std::string hexToBase64(std::string hexIn) {
	std::vector<std::string> hexChunks = chunk(hexIn, 2);
	std::string binary;
	for (auto x : hexChunks) {
		binary += hexToBits(x);
	}

	std::vector<std::string> b64Binary = chunk(binary, 6);
	int length = b64Binary.back().length();
	std::string pad;
	for (int i = 0; i < (6 - length); i++) {
		pad += "0";
	}

	b64Binary.back() += pad;

	std::vector<int> b64Values;
	for (auto x : b64Binary) {
		std::bitset<6> temp(x);
		b64Values.insert(b64Values.end(), temp.to_ulong());
	}
	std::string output = "";
	for (auto x : b64Values) {
		output += base64[x];
	}
	return output;
}

void print_vec(const std::vector<std::string>& vec)
{
	for (auto x : vec) {
		std::cout << ' ' << x;
	}
	std::cout << '\n';
}

std::vector<std::string> chunk(std::string input, int size) {
	int length = input.length();
	int chunkSize = size;
	int chunks = length / chunkSize;
	std::vector<std::string> chunkV;
	for (int i = 0; i < chunks; i++) {
		std::string temp = input.substr(i*chunkSize, chunkSize);
		chunkV.insert(chunkV.end(), temp);
	}
	return chunkV;
}

std::string hexToBits(std::string hexIn) {
	std::stringstream sstr;
	sstr << hexIn;
	int value;
	sstr >> std::hex >> value;

	std::bitset<8> bitsOut(value);
	return bitsOut.to_string();
}

int main()
{
	std::string test_h = "49276d206b696c6c696e6720796f757220627261696e206c696b65206120706f69736f6e6f7573206d757368726f6f6d";
	std::string test_b = "SSdtIGtpbGxpbmcgeW91ciBicmFpbiBsaWtlIGEgcG9pc29ub3VzIG11c2hyb29t";

	std::cout << hexToBase64(test_h) << std::endl;
	std::cout << test_b << std::endl;
}
