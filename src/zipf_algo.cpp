#include <zipf_algo.h>

namespace zipf_law {
    std::vector<std::pair<std::string, int>> computeWordFrequencyAlgo(const std::vector<char>& book) {
        std::vector<std::pair<std::string, int>> occurrences;
        std::string book_str(book.begin(), book.end());
        std::stringstream ss(book_str);
        std::string word;

        while (ss>>word) {
            auto it = std::find_if(occurrences.begin(), occurrences.end(),
            [&word] (const std::pair<std::string, int>& element){return word == element.first;});

            if (it != occurrences.end()) {
                it->second++;
            } else {
                occurrences.push_back({word, 1});
            }
        }

        // for (auto x: occurrences) {
        //     std::cout << x.first << " " << x.second << std::endl;
        // }

        return occurrences;
    }

    int countUniqueWordsAlgo(const std::vector<char>& book) {
        std::vector<std::string> uniqueWords;
        std::string book_str(book.begin(), book.end());
        std::stringstream ss(book_str);
        std::string word;

        while (ss >> word) {
            auto it = std::find(uniqueWords.begin(), uniqueWords.end(), word);
            if (it == uniqueWords.end()) {
                uniqueWords.push_back(word);
            }
        }

        return uniqueWords.size();
    }

    std::vector<std::pair<std::string, int>> sortWordFrequencyAlgo(std::vector<std::pair<std::string, int>>& occurrences) {
        std::sort(occurrences.begin(), occurrences.end(),
        [](std::pair<std::string, int> a, std::pair<std::string, int> b){return a.second > b.second;});

        // I commented the output to avoid cluttering the terminal
        /*
        for (auto x: occurrences) {
            std::cout << x.first << " " << x.second << std::endl;
        }
        */
        return occurrences;
    }

    auto lambda_hapax(const std::pair<std::string, int>& element, std::vector<std::string>& hapaxWords) {
        if (element.second == 1) {
            hapaxWords.push_back(element.first);
        }
    }

    std::vector<std::string> hapaxAlgo(const std::vector<std::pair<std::string, int>>& occurrences) {
        std::vector<std::string> hapaxWords;
        std::for_each(occurrences.begin(), occurrences.end(),
        [&](const std::pair<std::string, int>& element){lambda_hapax(element,hapaxWords);});
        
        // for (auto x: hapaxWords) {
        //      std::cout << x << std::endl;
        // }
        
        return hapaxWords;
    }

    void writeToFileLambda(const std::pair<std::string, int>& el, std::ofstream& file, int& i) {
        file << i << " " << el.second << " " << el.first << std::endl;
        i++;
    }

    void writeRanksToFileAlgo(const std::vector<std::pair<std::string, int>>& sorted, std::string filename) {
        std::ofstream file("output/" + filename + "_ranks.txt");
        if (!file.is_open()) {
            std::cerr << "Error opening file for writing: " << filename + "_ranks.txt" << std::endl;
            return;
        }
        
        int i = 1;

        std::for_each(sorted.begin(), sorted.end(),
        [&](const std::pair<std::string, int>& el){writeToFileLambda(el, file, i);});
    }


}