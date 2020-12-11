// "Copyright [2020] <Taraymovich Igor>"
#ifndef REALPATH_INCLUDE_REALPATH_HPP_
#define REALPATH_INCLUDE_REALPATH_HPP_
#include <fstream>
#include <string>
#include <vector>

inline bool is_absolute(const std::string& path) {
    return path[0] == '/';
}

inline bool is_empty(const std::string& path) {
    return path.size() == 0;
}

inline bool exists(const std::string& path) {
    return std::ifstream(path).good();
}

std::string current();
std::string absolute(const std::string& path);
std::string canonical(const std::string& path);
std::string weakly_canonical(const std::string& path);

#endif  // REALPATH_INCLUDE_REALPATH_HPP_
