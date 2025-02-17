#include <iostream>
#include <cstdlib>
#include <string>
#include <cstdio> 

void locate_package(const std::string& package_name) {
    std::cout << "[\033[92mARPKG\033[97m] Locating package: " << package_name << "\n";

    std::string command = "dpkg -l | grep " + package_name; 
    FILE* pipe = popen(command.c_str(), "r");
    
    if (!pipe) {
        std::cerr << "[\033[91mARPKG\033[97m] Failed to run dpkg command.\n";
        return;
    }

    char buffer[128];
    bool found = false;
    
    while (fgets(buffer, sizeof(buffer), pipe) != nullptr) {
        std::cout << buffer;  
        found = true;
    }

    if (!found) {
        std::cerr << "[\033[91mARPKG\033[97m] Cannot find package: " << package_name << "\n";
    }
    fclose(pipe);
}
