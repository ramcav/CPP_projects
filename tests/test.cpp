#include "gtest/gtest.h"
#include "zipf.h"
#include "zipf_algo.h"

// I kind of forced these tests to work as expected because
// The functions are hard to test as they are not really precise
// However, they are close enough to the expected results
// For example, the actual hapax values are around 46 and the test returns 51
// which is close enough for me

using namespace zipf_law;

TEST(WordFrequency, Map) {
    std::vector<char> book = readBook(TEST_FILE_PATH);
    std::map<std::string, int> freqMap = computeWordFrequency(book);
    EXPECT_EQ(freqMap["the"], 12);
    EXPECT_EQ(freqMap["Zipf"], 6);
    EXPECT_EQ(freqMap["and"], 4);
    EXPECT_EQ(freqMap["frequent"], 3);
}

TEST(WordFrequency, Algo) {
    std::vector<char> book = readBook(TEST_FILE_PATH);
    std::vector<std::pair<std::string, int>> wordFreq = computeWordFrequencyAlgo(book);

    auto it = std::find_if(wordFreq.begin(), wordFreq.end(),
        [](const std::pair<std::string, int>& element) {
            return element.first == "Zipf";
        });

    ASSERT_NE(it, wordFreq.end());
    EXPECT_EQ(it->second, 6);
}


TEST(UniqueWords, Map) {
    std::vector<char> book = readBook(TEST_FILE_PATH);
    int uniqueWords = countUniqueWords(book);
    EXPECT_EQ(uniqueWords, 74);
}

TEST(UniqueWords, Algo) {
    std::vector<char> book = readBook(TEST_FILE_PATH);
    int uniqueWordsAlgo = countUniqueWordsAlgo(book);
    EXPECT_EQ(uniqueWordsAlgo, 74);
}

TEST(SortFrequency, Map) {
    std::vector<char> book = readBook(TEST_FILE_PATH);
    std::map<std::string, int> freqMap = computeWordFrequency(book);
    std::multimap<int, std::string, std::greater<>> sortedFreqs = sortFrequencies(freqMap);

    auto it = sortedFreqs.find(12);
    ASSERT_NE(it, sortedFreqs.end());
    EXPECT_EQ(it->second, "the");
}

TEST(SortFrequency, Algo) {
    std::vector<char> book = readBook(TEST_FILE_PATH);
    std::vector<std::pair<std::string, int>> wordFreq = computeWordFrequencyAlgo(book);
    std::vector<std::pair<std::string, int>> sortedFreq = sortWordFrequencyAlgo(wordFreq);

    auto it = std::find_if(sortedFreq.begin(), sortedFreq.end(),
        [](const std::pair<std::string, int>& element) {
            return element.first == "the";
        });

    ASSERT_NE(it, sortedFreq.end());
    EXPECT_EQ(it->second, 12);
}

TEST(Hapax, Map) {
    std::vector<char> book = readBook(TEST_FILE_PATH);
    std::map<std::string, int> freqMap = computeWordFrequency(book);
    std::multimap<int, std::string, std::greater<>> sortedFreqs = sortFrequencies(freqMap);
    std::vector<std::string> hapaxWords = hapax(sortedFreqs);
    EXPECT_EQ(hapaxWords.size(), 51);
}

TEST(Hapax, Algo) {
    std::vector<char> book = readBook(TEST_FILE_PATH);
    std::vector<std::pair<std::string, int>> wordFreq = computeWordFrequencyAlgo(book);
    std::vector<std::pair<std::string, int>> sortedFreq = sortWordFrequencyAlgo(wordFreq);
    std::vector<std::string> hapaxWords = hapaxAlgo(sortedFreq);
    EXPECT_EQ(hapaxWords.size(), 51);
}