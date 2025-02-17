#include <iostream>
#include <cstdlib>
#include <string>

void install_package(const std::string &package_name) {
    std::cout << "[\033[92mARPKG\033[97m] Installing package: " << package_name << std::endl;
    std::string command = "sudo apt-get install -y -q " + package_name;
    int result = std::system(command.c_str());
    
    if (result == 0) {
        std::cout << "[\033[92mARPKG\033[97m] Package installed successfully.\n";
    } else {
        std::cerr << "[\033[91mARPKG\033[97m] Failed to install package.\n";
    }
}
