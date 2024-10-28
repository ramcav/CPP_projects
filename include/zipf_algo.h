#include <vector>
#include <string>
#include <iostream>
#include <sstream>
#include <algorithm>
#include <set>
#include <fstream>

namespace zipf_law {

    /**
     * @brief Compute the frequency of words in a book from a vector of characters representing the book
     * 
     * @param book A vector of characters representing the book
     * @return std::vector<std::pair<std::string, int>> A vector of pairs of strings and integers representing the word and its frequency
     */
    std::vector<std::pair<std::string, int>> computeWordFrequencyAlgo(const std::vector<char>& book);

    /**
     * @brief Sort the word frequency in descending order
     * 
     * @param occurrences A vector of pairs of strings and integers representing the word and its frequency
     * @return std::vector<std::pair<std::string, int>> A vector of pairs of strings and integers representing the word and its frequency sorted in descending order
     */
    std::vector<std::pair<std::string, int>> sortWordFrequencyAlgo(std::vector<std::pair<std::string, int>>& occurrences);

    /**
     * @brief Count the number of unique words in a book
     * 
     * @param book A vector of characters representing the book
     * @return int The number of unique words in the book
     */
    int countUniqueWordsAlgo(const std::vector<char>& book);

    /**
     * @brief Find the hapax legomena in a book
     * @details A hapax legomenon is a word that occurs only once in a book
     * 
     * @param occurrences A vector of pairs of strings and integers representing the word and its frequency
     * @return std::vector<std::string> A vector of strings representing the hapax legomena in the book
     */
    std::vector<std::string> hapaxAlgo(const std::vector<std::pair<std::string, int>>& occurrences);

    /**
     * @brief Write the ranks of words to a file
     * 
     * @param occurrences A vector of pairs of strings and integers representing the word and its frequency
     * @param filename The name of the file to write the ranks to
     * @return void
     */
    void writeRanksToFileAlgo(const std::vector<std::pair<std::string, int>>& occurrences, std::string filename);

}