#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <sstream>
#include <map>
#include <set>
#include <cmath>
#include <matplot/matplot.h>

namespace zipf_law {
    /**
     * @brief Read a book from a file
     * 
     * @param fileName The name of the file to read
     * @return std::vector<char> A vector of characters representing the book
     */
    std::vector<char> readBook(std::string fileName);

    /**
     * @brief Compute the frequency of words in a book from a vector of characters representing the book
     * 
     * @param book A vector of characters representing the book
     * @return std::map<std::string, int> A map of strings and integers representing the word and its frequency
     */
    std::map<std::string, int> computeWordFrequency(const std::vector<char>& book);

    /**
     * @brief Count the number of unique words in a book
     * 
     * @param book A vector of characters representing the book
     * @return int The number of unique words in the book
     */
    int countUniqueWords(const std::vector<char>& book);

    /**
     * @brief Sort the word frequency in descending order
     * 
     * @param frequencies A map of strings and integers representing the word and its frequency
     * @return std::multimap<int, std::string, std::greater<>> A multimap of integers and strings representing the frequency and the word sorted in descending order
     */
    std::multimap<int, std::string, std::greater<>> sortFrequencies(const std::map<std::string, int>& frequencies);

    /**
     * @brief Write the ranks of words to a file
     * 
     * @param sortedFreqs A multimap of integers and strings representing the frequency and the word sorted in descending order
     * @param filename The name of the file to write the ranks to
     * @return void
     */
    void writeRanksToFile(const std::multimap<int, std::string, std::greater<>>& sortedFreqs, std::string filename);

    /**
     * @brief Plot the ranks of words in a log-log plot
     * 
     * @param filename The name of the file to read the ranks from
     * @return void
     * @details The file should have the format: rank frequency word
     */
    void plotLogLog(std::string filename);

    /**
     * @brief Find the hapax legomena in a book
     * @details A hapax legomenon is a word that occurs only once in a book
     * 
     * @param sortedFreqs A multimap of integers and strings representing the frequency and the word sorted in descending order
     * @return std::vector<std::string> A vector of strings representing the hapax legomena in the book
     */
    std::vector<std::string> hapax(const std::multimap<int, std::string, std::greater<>>& sortedFreqs);
}