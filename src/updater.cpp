#include <iostream>
#include <cstdlib>

void update_packages() {
    std::cout << "[\033[92mARPKG\033[97m] Updating package index...\n";
    int result = std::system("sudo apt-get update");
    
    if (result == 0) {
        std::cout << "[\033[92mARPKG\033[97m] Package index updated successfully.\n";
    } else {
        std::cerr << "[\033[91mARPKG\033[97m] Failed to update package index.\n";
    }
}
