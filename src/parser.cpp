#include <fstream>
#include <stdexcept>
#include <string>

int main(int argc, char *argv[]) {
	if (argc < 3) {
		throw std::invalid_argument("Too few arguments");
	}

	auto f = std::ifstream(argv[1], std::ios::binary | std::ios::ate);
	auto size = f.tellg();

	std::byte *buffer = new std::byte[size];
	f.read((char *)buffer, size);
	f.close();

	std::string toWrite;
	for (size_t i = 0; i < size; i++) {
		toWrite += std::to_string(buffer[i]) + ',';
	}
	toWrite.pop_back();
	auto buffer2 = toWrite.data();
	f = std::ofstream(argv[2], std::ios::binary);
	f.write(buffer2, toWrite.length());
	f.close();
}
