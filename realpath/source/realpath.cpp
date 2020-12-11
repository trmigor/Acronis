// "Copyright [2020] <Taraymovich Igor>"
#include "realpath.hpp"
#include <unistd.h>
#include <cerrno>
#include <climits>
#include <cstdlib>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

std::vector<std::string> split(const std::string& str, char delim = '/') {
    std::vector<std::string> tokens;
    std::string token;
    std::istringstream tokenStream(str);
    while (std::getline(tokenStream, token, delim)) {
        tokens.push_back(token);
    }
    return tokens;
}

std::string current() {
    size_t size = PATH_MAX;
    char* buffer = new char[size];
    char* err = getcwd(buffer, size);
    if (err == nullptr) {
        std::cerr << "getcwd: " << errno << std::endl;
        return "";
    }
    std::string result = buffer;
    delete[] buffer;
    return result;
}

std::string absolute(const std::string& path) {
    if (is_absolute(path) || is_empty(path)) {
        return path;
    }
    return current() + '/' + path;
}

std::string lexically_normal(const std::string& path) {
    if (is_empty(path)) {
        return path;
    }
    std::string work = absolute(path);
    std::vector<std::string> parts = split(work, '/');
    std::vector<bool> take(parts.size(), true);
    for (size_t i = 0; i < parts.size(); ++i) {
        if (parts[i] == "" || parts[i] == ".") {
            take[i] = false;
        }
        if (parts[i] == "..") {
            take[i] = false;
            for (size_t j = i; j != 0; --j) {
                if (take[j - 1]) {
                    take[j - 1] = false;
                    break;
                }
            }
        }
    }

    std::string result;
    for (size_t i = 0; i < parts.size(); ++i) {
        if (take[i]) {
            result += "/" + parts[i];
        }
    }
    return is_empty(result) ? "/" : result;
}

std::string canonical(const std::string& path) {
    if (is_empty(path)) {
        return path;
    }
    std::string work = absolute(path);
    size_t size = PATH_MAX;
    char* buffer = new char[size];
    char* err = realpath(work.c_str(), buffer);
    if (err == nullptr) {
        std::cerr << "realpath(" << work << "): " << errno << std::endl;
        return "";
    }
    std::string result = buffer;
    delete[] buffer;
    return result;
}

std::string weakly_canonical(const std::string& path) {
    if (is_empty(path)) {
        return path;
    }
    std::string result = "/";
    std::string work = absolute(path);
    std::vector<std::string> parts = split(work, '/');

    bool scan = true;
    for (std::string part : parts) {
        if (part == "") {
            continue;
        }
        if (scan) {
            std::string tmp = result + "/" + part;
            if (exists(tmp)) {
                result = tmp;
            } else {
                scan = false;
                if (!is_empty(result)) {
                    result = canonical(result) + "/" + part;
                }
            }
        } else {
            result += "/" + part;
        }
    }

    if (scan) {
        result = canonical(result);
    } else {
        result = lexically_normal(result);
    }
    return result;
}
