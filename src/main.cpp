#include <iostream>
#include <vector>
#include <split.h>
#include <string>

int main() {

    std::vector<std::string> splitted = homework::split("HELLO MY NAME IS JOHN CENA");

    for (int i = 0; i < splitted.size(); i++) {
        std::cout << splitted[i] << std::endl;
    }
    
    return 0;
}