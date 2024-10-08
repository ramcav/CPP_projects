#include <split.h>
#include <sstream>
#include <iostream>
#include <vector>

namespace homework {
    std::vector<std::string> split(const std::string& str) {
        std::istringstream  ss(str);
        
        std::vector<std::string> words;
        for (std::string word; ss>>word;) {
            words.insert(words.end(), word);
        }

        return words;
    }
}