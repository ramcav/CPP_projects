#include <zipf.h>
#include <zipf_algo.h>
#include <iostream>
#include <vector>
#include <string>

using namespace zipf_law;

void processBookWithMap(const std::string &filename, const std::string &outputPrefix) {
    auto text = readBook(filename);
    std::map<std::string, int> freqMap = computeWordFrequency(text);
    int uniqueWords = countUniqueWords(text);
    std::cout << "UNIQUE WORDS " << filename << ": " << uniqueWords << std::endl;

    std::multimap<int, std::string, std::greater<>> sortedFreqs = sortFrequencies(freqMap);
    hapax(sortedFreqs);
    writeRanksToFile(sortedFreqs, outputPrefix);
    plotLogLog(outputPrefix + "_ranks.txt");
}

void processBookWithAlgo(const std::string &filename, const std::string &outputPrefix) {
    auto text = readBook(filename);
    std::vector<std::pair<std::string, int>> wordFreq = computeWordFrequencyAlgo(text);
    std::vector<std::pair<std::string, int>> sortedFreq = sortWordFrequencyAlgo(wordFreq);
    
    int uniqueWordsAlgo = countUniqueWordsAlgo(text);
    std::cout << "UNIQUE WORDS " << filename << " WITH ALGORITHM: " << uniqueWordsAlgo << std::endl;

    hapaxAlgo(wordFreq);
    writeRanksToFileAlgo(sortedFreq, outputPrefix + "_algo");
}

int main() {
    // Process Moby Dick using both methods
    processBookWithMap("mobby.txt", "mobby");
    processBookWithAlgo("mobby.txt", "mobby");

    // Process Don Quijote using both methods
    processBookWithMap("quijote.txt", "quijote");
    processBookWithAlgo("quijote.txt", "quijote");

    // The Don Quijote VS Moby Dick comparison plot will be handled by Python
}