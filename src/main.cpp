#include <iostream>
#include <string>
#include <cstdlib>
#include <vector>
#include <algorithm>
#include "installer.h"
#include "updater.h"
#include "installed.h"
#include "locate.h"
#include "remover.h"
#include "credits.h"

void print_help() {

    std::cout << "\nARPkg is a user-friendly package manager designed for Debian-based Linux distributions.\nIt provides essential package management functions such as installing, updating, and removing packages while maintaining \na simple and intuitive interface.\n\n";
    std::cout << "Usage: arpkg <command> [options]\n";
    std::cout << "Commands:\n";
    std::cout << ">  install <package_name>   Install a package.\n";
    std::cout << ">  remove <package_name>    Remove a package.\n";
    std::cout << ">  locate <package_name>    Find your package in installed pkgs.\n";
    std::cout << ">  update                   Update package index.\n";
    std::cout << ">  installed                Show list of installed packages.\n";
    std::cout << ">  help                     Show this message.\n";
    std::cout << ">  credits                  Show author credits.\n";
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        print_help();
        return 1;
    }

    std::string command = argv[1];
    
    if (command == "install" && argc == 3) {
        std::string package_name = argv[2];
        install_package(package_name);
    } else if (command == "update" && argc == 2) {
        update_packages();
    } else if (command == "installed" && argc == 2) {
        list_installed_packages();
    } else if (command == "help") {
        print_help();
    } else if (command == "credits" && argc == 2) {
        show_credits();
    } else if (command == "locate" && argc == 3) {  
        std::string package_name = argv[2];
        locate_package(package_name);  
    } else if (command == "remove" && argc == 3) {
        std::string package_name = argv[2];
        remove_package(package_name);
    } else {
        std::cout << "[\033[91mARPKG\033[97m] Unknown command or invalid arguments.\n";
        print_help();
        return 1;
    }

    return 0;
}
