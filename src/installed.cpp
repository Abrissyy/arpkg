#include <iostream>
#include <cstdlib>
#include <string>

void list_installed_packages() {
    std::cout << "[\033[92mARPKG\033[97m] Listing installed packages:\n";
    
    // Polecenie do wyświetlania zainstalowanych pakietów
    std::string command = "dpkg -l | grep '^ii'";  
    
    int result = std::system(command.c_str());
    
    if (result != 0) {
        std::cerr << "[\033[91mARPKG\033[97m] Failed to list packages.\n";
    }
}
