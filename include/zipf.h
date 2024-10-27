#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <sstream>
#include <map>
#include <set>
#include <cmath>
#include <matplot/matplot.h>

namespace homework {
    std::vector<char> readBook(std::string fileName);
    std::map<std::string, int> computeWordFrequency(const std::vector<char>& book);
    int countUniqueWords(const std::vector<char>& book);
    std::multimap<int, std::string, std::greater<>> sortFrequencies(const std::map<std::string, int>& frequencies);
    void writeRanksToFile(const std::multimap<int, std::string, std::greater<>>& sortedFreqs, std::string filename);
    void plotLogLog(std::string filename);
    std::vector<std::string> hapax(const std::multimap<int, std::string, std::greater<>>& sortedFreqs);
}