#include "ReadFile.hpp"

int main() {
	constexpr auto path = "../src/main.cpp";
	constexpr auto f = ReadFile::readFile(path);
}
