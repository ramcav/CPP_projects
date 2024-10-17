#include "gtest/gtest.h"
#include "split.h"
#include "mytype.h"
#include "pair.h"
#include "sum.h"
#include "transform.h"
#include "is_raw_pointer.h"
#include "flexible_container.h"
#include <fstream>
#include <numeric>
#include <list>
#include <array>
#include <tuple>
#include <iostream>

using namespace homework;
TEST(Split, MultipleWordsWithExtraSpaces){
    auto res = split(" hello world lorem ipsum ");
    ASSERT_EQ(res.size(),4);
    ASSERT_EQ(res[0],"hello");
    ASSERT_EQ(res[1],"world");
    ASSERT_EQ(res[2],"lorem");
    ASSERT_EQ(res[3],"ipsum");
}
TEST(MyType, WriteRead){
    MyType mt(42,3.14);
    writeToFile(mt,"mytype.txt");
    auto mt2 = readFromFile(mt,"mytype.txt");
    ASSERT_EQ(mt,mt2);
}

TEST(SumVector, Int){
    std::vector<int> vint = {1,2,3,4,5};
    auto sum_ints = sum_elements(vint, 0);
    auto sum_ints_ref = std::accumulate(vint.begin(),vint.end(),0);
    ASSERT_EQ(sum_ints,sum_ints_ref);
}

TEST(SumVector, Double){
    std::vector<double> vdouble = {1.1,2.2,3.3,4.4,5.5};
    auto sum_doubles = sum_elements(vdouble, 0.0);
    auto sum_doubles_ref =
    std::accumulate(vdouble.begin(),vdouble.end(),0.0);
    ASSERT_NEAR(sum_doubles,sum_doubles_ref,1e-10);
}

TEST(SumVector, String){
    std::vector<std::string> vstring = {"hello","world"};
    auto sum_string = sum_elements(vstring, std::string()); // We pass std::string() because "" is of type char and not a string
    ASSERT_EQ(sum_string,"helloworld"); 
}

TEST(SumSequence, List){
    std::list<int> lint = {1,2,3,4,5};
    auto sum_ints = sum_elements(lint, 0);
    auto sum_ints_ref = std::accumulate(lint.begin(),lint.end(),0);
    ASSERT_EQ(sum_ints,sum_ints_ref);
}

TEST(SumSequence, Array){
    std::array<int,5> aint = {1,2,3,4,5};
    auto sum_ints = sum_elements(aint, 0);
    auto sum_ints_ref = std::accumulate(aint.begin(),aint.end(),0);
    ASSERT_EQ(sum_ints,sum_ints_ref);
}

TEST(SumVector, CustomType){

    struct MyType{
        int i;
        double d;
        public:
            auto operator==(const MyType& other) const {
                    return i == other.i && d == other.d;
                }

            auto operator+=(const MyType& other) {
                    this->i += other.i;
                    this->d += other.d;
                    return *this;
                }
    };

    std::vector<MyType> vmt = {{1,1.1},{2,2.2},{3,3.3}};
    auto sum_mts = sum_elements(vmt, MyType{0,0.0});
    ASSERT_EQ(sum_mts,(MyType{6,6.6}));
}

TEST(Tuple, make){
    auto t = homework::make_tuple(1,2.2,"hello");
    ASSERT_EQ(std::get<0>(t),1);
    ASSERT_NEAR(std::get<1>(t),2.2,1e-10);
    ASSERT_EQ(std::get<2>(t),"hello");
}
TEST(Tuple, make2){
    auto t = homework::make_tuple("word", std::vector<int>{1,2,3}); // I also included the homework:: namespace to avoid conflicts
    ASSERT_EQ(std::get<0>(t),"word");
    ASSERT_EQ(std::get<1>(t),(std::vector<int>{1,2,3})); // I had to wrap this in () because it caused my computer to crash
    // According to chat, it is because when passing a vector, or another type to a Macro like ASSERT_EQ,
    // It recognizes the commas as separators for elements. Thus, not recognizing a vector but several random
    // elements. Using the () solved my issue, and, as I understand, it tells the compiler to treat everything
    // In () as a single argument
}

TEST(Pair, IntPair) {
    Pair<int, int> p{1, 2};
    ASSERT_EQ(p.first, 1);
    ASSERT_EQ(p.second, 2);
}
TEST(Pair, DoublePair) {
    Pair<double, double> p{1.1, 2.2};
    ASSERT_EQ(p.first, 1.1);
    ASSERT_EQ(p.second, 2.2);
}
TEST(Pair, IntStringPair) {
    Pair<int, std::string> p{1, "Hello"};
    ASSERT_EQ(p.first, 1);
    ASSERT_EQ(p.second, "Hello");
}

TEST(Transform, IntVector) {
    std::vector v{1, 2, 3};
    auto doubled = v;
    transform(doubled, [](int x) { return x * 2; });
    ASSERT_EQ(doubled.size(), 3);
    for (auto i : v)
    ASSERT_EQ(doubled[i], v[i] * 2);
}
TEST(Transform, StringVector) {
    std::vector<std::string> v{"Hello", "World"};
    auto reversed = v;
    auto reverser = [](std::string s) {
        std::reverse(s.begin(), s.end());
        return s;
    };
    transform(reversed, reverser);
    ASSERT_EQ(reversed.size(), 2);
    ASSERT_EQ(reversed[0], "olleH");
    ASSERT_EQ(reversed[1], "dlroW");
}

TEST(Transform, SquareList) {
    std::list l{1, 2, 3};
    auto squared = l;
    transform(squared, [](int x) { return x * x; });
    ASSERT_EQ(squared.size(), 3);
    std::list expected{1, 4, 9};
    ASSERT_EQ(squared, expected);
}

TEST(Transform, DoubleVectorSum) {
    std::vector v{1.1, 2.2, 3.3};
    auto incremented = v;
    // Your code here
    transform(incremented, [](double x) {return x+1;});
    ASSERT_EQ(incremented.size(), 3);
    std::vector expected{2.1,3.2,4.3};
    ASSERT_EQ(incremented,expected);
}

TEST(IsRawPointer, Int) {
    ASSERT_FALSE(IsRawPointer<int>::value);
}
TEST(IsRawPointer, IntPointer) {
    ASSERT_TRUE(IsRawPointer<int*>::value);
}
TEST(IsRawPointer, IntConstPointer) {
    ASSERT_TRUE(IsRawPointer<const int*>::value);
}
TEST(IsRawPointer, IntReference) {
    ASSERT_FALSE(IsRawPointer<int&>::value);
}
TEST(IsRawPointer, String){
    ASSERT_FALSE(IsRawPointer<std::string>::value);
}

TEST(IsRawPointerv, Doubles){
    ASSERT_FALSE(IsRawPointer_v<double>);
    ASSERT_TRUE(IsRawPointer_v<double*>);
}

TEST(FlexibleContainer, IntStorage) {
    FlexibleContainer<int> container;
    container.add(5);
    container.add(10);
    ASSERT_EQ(container.size(), 2);
    ASSERT_EQ(container.get(0), 5);
    ASSERT_EQ(container.get(1), 10);
}
TEST(FlexibleContainer, StringStorage) {
    FlexibleContainer<std::string> container;
    container.add("Hello");
    container.add("World");
    ASSERT_EQ(container.size(), 2);
    ASSERT_EQ(container.get(0), "Hello");
    ASSERT_EQ(container.get(1), "World");
}
TEST(FlexibleContainer, DefaultType) {
    FlexibleContainer container;
    container.add(42);
    ASSERT_EQ(container.size(), 1);
    ASSERT_EQ(container.get(0), 42);
}

TEST(FlexibleContainer, MapFunction) {
    FlexibleContainer<int> container;
    container.add(1);
    container.add(2);
    container.add(3);
    auto doubled = container;
    doubled.map([](int x) { return x * 2; });
    std::cout << doubled.get(0) <<doubled.get(1)<< doubled.get(2) <<std::endl;
    ASSERT_EQ(doubled.size(), 3);
    ASSERT_EQ(doubled.get(0), 2);
    ASSERT_EQ(doubled.get(1), 4);
    ASSERT_EQ(doubled.get(2), 6);
}

TEST(FlexibleContainer, VariadicConstructor) {
    FlexibleContainer<int> container(1, 2, 3, 4, 5);
    ASSERT_EQ(container.size(), 5);
    ASSERT_EQ(container.get(0), 1);
    ASSERT_EQ(container.get(4), 5);
    FlexibleContainer<std::string> strContainer("Hello", "World", "C++");
    ASSERT_EQ(strContainer.size(), 3);
    ASSERT_EQ(strContainer.get(0), "Hello");
    ASSERT_EQ(strContainer.get(2), "C++");
}