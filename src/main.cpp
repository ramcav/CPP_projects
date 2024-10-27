#include <zipf.h>

using namespace homework;
int main() {
    auto x = readBook("mobby.txt");
    std::map<std::string, int> freqMap = computeWordFrequency(x);
    int uniqueWords = countUniqueWords(x);
    std::cout << "UNIQUE WORDS MOBBY DICK: " << uniqueWords << std::endl;
    std::multimap<int, std::string, std::greater<>> sortedFreqs = sortFrequencies(freqMap);
    hapax(sortedFreqs);
    writeRanksToFile(sortedFreqs, "mobby");
    plotLogLog("mobby_ranks.txt");

    // For Don Quijote
    auto y = readBook("quijote.txt");
    std::map<std::string, int> freqMapY = computeWordFrequency(y);
    int uniqueWordsY = countUniqueWords(y);
    std::cout << "UNIQUE WORDS QUIJOTE: " << uniqueWordsY << std::endl;
    std::multimap<int, std::string, std::greater<>> sortedFreqsY = sortFrequencies(freqMapY);
    writeRanksToFile(sortedFreqsY, "quijote");
    plotLogLog("quijote_ranks.txt");

    // The VS plot is plotted using python
}