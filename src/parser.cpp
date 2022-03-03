#include <fstream>
#include <stdexcept>
#include <string>

using byte = unsigned char;

int main(int argc, char *argv[]) {
	if (argc < 3) {
		throw std::invalid_argument("Too few arguments");
	}

	auto f = std::ifstream(argv[1], std::ios::binary | std::ios::ate);
	auto size = f.tellg();
	f.close();
	f = std::ifstream(argv[1], std::ios::binary);

	byte* buffer = new byte[size];
	f.read((char *)buffer, size);
	f.close();

	std::string toWrite;
	for (size_t i = 0; i < size; i++) {
		toWrite += std::to_string(buffer[i]) + ',';
	}
	delete[] buffer;
	toWrite.pop_back();
	auto buffer2 = toWrite.data();
	auto of = std::ofstream(argv[2], std::ios::binary);
	of.write(buffer2, toWrite.length());
	of.close();
}
