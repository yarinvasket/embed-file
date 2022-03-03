#pragma once

#include <fstream>
#include <array>
#include <string>

using byte = unsigned char;

namespace ReadFile {
	constexpr std::array<byte, bytes> readFile(const std::string &path) {
		auto fd = std::ifstream(path, std::ios::binary | std::ios::ate);
		auto size = fd.tellg();
		std::array<byte, size> bytes;
		fd.read(&bytes, size);
		return bytes;
	}
}
