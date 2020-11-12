// "Copyright [2020] <Taraymovich Igor>"
#include <iostream>
#include <string>
#include <csignal>

void signal_handler(int signal) {
    std::string signal_name;
    switch (signal) {
    case SIGINT:
        signal_name = "SIGINT";
        break;
    case SIGTERM:
        signal_name = "SIGTERM";
    }

    std::cerr << "Got " << signal_name << " (" << signal << ")." << std::endl;
    exit(EXIT_FAILURE);
}

int main(void) {
    std::signal(SIGINT, signal_handler);
    std::signal(SIGTERM, signal_handler);
    for (;;) {}
    return EXIT_SUCCESS;
}
