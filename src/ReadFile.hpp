#pragma once

#include <fstream>
#include <array>
#include <cstddef>

namespace ReadFile {
//	Unfortunately impossible, file read is not constexpr
	constexpr auto readFile(const char *path) {
		auto fd = std::ifstream(path, std::ios::binary | std::ios::ate);
		auto size = fd.tellg();
		std::array<std::byte, size> bytes{};
		fd.read((char *)&bytes, size);
		fd.close();
		return bytes;
	}
}
