#include <iostream>
#include <array>

using byte = unsigned char;

int main() {
	constexpr byte file1[] = {
#include "../res/a.txt.arr"
	};
	constexpr auto size = sizeof(file1) / sizeof(file1[0]);

	for (auto i = 0; i < size; i++) {
		std::cout << file1[i];
	}
	std::cout << std::endl;
}
