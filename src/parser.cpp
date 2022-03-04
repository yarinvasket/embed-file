#include <fstream>
#include <stdexcept>
#include <string>
#include <cstring>

using byte = unsigned char;

int main(int argc, char *argv[]) {
	if (argc < 2) {
		throw std::invalid_argument("Too few arguments");
	}

	for (auto i = 1; i < argc; i++) {
		auto s = argv[i];
		auto f = std::ifstream(s, std::ios::binary | std::ios::ate);
		auto size = f.tellg();
		f.close();
		byte* buffer = new byte[size];
		f = std::ifstream(s, std::ios::binary);

		f.read((char *)buffer, size);
		f.close();

		std::string toWrite;
		for (std::size_t i = 0; i < size; i++) {
			toWrite += std::to_string(buffer[i]) + ',';
		}
		delete[] buffer;
		toWrite.pop_back();

		char sneo[100];
		strcpy(sneo, s);
		strcat(sneo, ".arr");

		auto buffer2 = toWrite.data();
		auto of = std::ofstream(sneo, std::ios::binary);
		of.write(buffer2, toWrite.length());
		of.close();
	}
}
