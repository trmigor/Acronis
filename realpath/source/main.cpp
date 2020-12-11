// "Copyright [2020] <Taraymovich Igor>"
#include <iostream>
#include "realpath.hpp"

int main() {
    std::cout << "weakly_canonical(\"source/main.cpp\"): " <<
        weakly_canonical("source/main.cpp") << std::endl;
    std::cout << "weakly_canonical(\"source/mai.cpp\"): " <<
        weakly_canonical("source/mai.cpp") << std::endl;

    std::cout << "weakly_canonical(\"source/../source/./main.cpp\"): " <<
        weakly_canonical("source/../source/./main.cpp") << std::endl;
    std::cout << "weakly_canonical(\"source/../source/./mai.cpp\"): " <<
        weakly_canonical("source/../source/./mai.cpp") << std::endl;

    std::cout << "weakly_canonical(\"source/sdf/../mai.cpp\"): " <<
        weakly_canonical("source/sdf/../mai.cpp") << std::endl;

    std::cout << "weakly_canonical(\"/bin/\"): " <<
        weakly_canonical("/bin/") << std::endl;
    std::cout << "weakly_canonical(\"/bin/asdf\"): " <<
        weakly_canonical("/bin/asdf") << std::endl;

    std::cout << "weakly_canonical(\"/\"): " <<
        weakly_canonical("/") << std::endl;
    std::cout << "weakly_canonical(\"//\"): " <<
        weakly_canonical("//") << std::endl;
    std::cout << "weakly_canonical(\"/..\"): " <<
        weakly_canonical("/..") << std::endl;
    std::cout << "weakly_canonical(\"/.\"): " <<
        weakly_canonical("/.") << std::endl;

    std::cout << "weakly_canonical(\"/sdfsdf/../../../asd/\"): " <<
        weakly_canonical("/sdfsdf/../../../asd/") << std::endl;
}
