#include <zipf.h>

namespace zipf_law {
    std::vector<char> readBook(std::string fileName) {

        std::vector<char> chars;

        std::ifstream file(fileName, std::ios_base::in);

        if (!file.is_open()) {
            std::cerr << "Error opening file!" << std::endl;
            return chars;
        };

        std::string line;
        char character;


        while (file.get(character)) {

            if (std::isalnum(character) or std::isspace(character)) {
                chars.push_back(character);
                // std::cout << character << std::endl;
            } else {
                chars.push_back(' ');
            }
        };
        
        return chars;
    }

    std::map<std::string, int> computeWordFrequency(const std::vector<char>& book) {

        std::map<std::string, int> occurrences;
        std::string book_str(book.begin(), book.end());
        std::stringstream ss(book_str);
        std::string word;
        while(ss>>word) {
            occurrences[word]++;
        };

        // I commented the output to avoid cluttering the output
        /*
        for (auto x: occurrences) {
            std::cout << x.first << " : " << x.second <<std::endl;
        }
        */
        

        return occurrences;
    }

    int countUniqueWords(const std::vector<char>& book) {
        std::set<std::string> uniqueWords;
        std::string book_str(book.begin(), book.end());
        std::stringstream ss(book_str);
        std::string word;

        while(ss>>word) {
            uniqueWords.insert(word);
        };

        // I commented the output to avoid cluttering the terminal
        /*
        for (auto x: uniqueWords) {
            std::cout << x << std::endl;
        }
        */
        

        return uniqueWords.size();
    }

    std::multimap<int, std::string, std::greater<>> sortFrequencies(const std::map<std::string, int>& frequencies) {
        std::multimap<int, std::string, std::greater<>> sortedFreqs;

        for (auto x: frequencies) {
            sortedFreqs.insert({x.second,x.first});
        }

        // I commented the output to avoid cluttering the terminal
        /*
        for (auto x: sortedFreqs) {
            std::cout << x.first << " : " << x.second <<std::endl;
        }
        */
    
        return sortedFreqs;
    }

    void writeRanksToFile(const std::multimap<int, std::string, std::greater<>>& sortedFreqs, std::string filename) {
        std::ofstream file("output/" + filename + "_ranks.txt");
        if (!file.is_open()) {
            std::cerr << "Error opening file for writing: " << filename + "_ranks.txt" << std::endl;
            return;
        }
        
        int i = 1;

        // Using structured-bindings
        for (const auto& [rank, freq]: sortedFreqs) {
            file << i << " " << rank << " " << freq << std::endl;
            i++;
        }
    }

    void plotLogLog(std::string filename) {
        std::ifstream file("output/"+filename);
        if (!file.is_open()) {
            std::cerr << "Error opening file: " << filename << std::endl;
            return;
        }

        std::vector<int> ranks, frequencies;

        int rank, freq;
        std::string word;

        while (file >> rank >> freq >> word) {
            ranks.push_back(rank);
            frequencies.push_back(freq);
        }

        using namespace matplot;

        auto fig = figure(true);
        loglog(ranks, frequencies);
        xlabel("Rank (log scale)");
        ylabel("Frequency (log scale)");
        title("Word Frequency Distribution (Log-Log Scale)");

        save("img/plot_cpp.jpeg");
    }

    std::vector<std::string> hapax(const std::multimap<int, std::string, std::greater<>>& sortedFreqs) {
        int key = 1;
        auto range = sortedFreqs.equal_range(key);

        std::vector<std::string> hapax_words;
        
        for (auto it = range.first; it != range.second; ++it) {
            hapax_words.push_back(it->second);
            std::cout << it->second << std::endl;
        }
        

        return hapax_words;
    }


}