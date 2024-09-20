#include <iostream>
#include <vector>
#include <array>
#include <numeric>

int array_size(std::array<int, 1000> a) {

    std::cout<<"Size of array: "<<sizeof(a)<<std::endl;

    return 1;
}

int vector_size(std::vector<int> v) {

    std::cout<<"Size of vector: "<<sizeof(v)<<std::endl;

    return 1;
}

int sum_val(std::vector<int> v) {
    int sum  = 0;
    for (auto n: v) {
        sum += n;
    }

    return sum;
}

int sum_ref(const std::vector<int> &v) {
    int sum  = 0;
    for (int i = 0; i<v.size(); i++) {
        sum += v[i];
    }

    return sum;
}

int sum_ptr(const int *ptr, int size) {
    int sum = 0;

    for (int i = 0; i < size; i++) {
        sum += *ptr;
        ptr += 1;
    }
    
    return sum;
}


int main() {

    // Memory Layout

    // std::vector<int> v = {1,2,3,5,6,7,7,8,9,10,11,2,4,5,2,1,2,3,3,2,1,2,4,2,1,2,4,5,3,1,2,3,4,2};
    // std::array<int, 1000> a= {};
    // int _ = array_size(a);
    // int __ = vector_size(v);

    // Pointer arithmetic

    // int sum_val = sum_vector_value(v);
    // int sum_ref = sum_vector_ref(v);
    // int sum_p = sum_vector_pointer(&v[0], v.size());
    // std::cout<<"SUM BY VALUE: "<<sum_val<<std::endl;
    // std::cout<<"SUM BY REFERENCE: "<<sum_ref<<std::endl;
    // std::cout<<"SUM BY POINTER: "<<sum_p<<std::endl;

    // Pointer arithmetic 1/2

    constexpr int size = 1000;
    std::vector<int> v(size); // A vector with 1000 elements
    std::iota(v.begin(), v.end(), 0); // Fill the vector with 0, 1, 2, 3, ...
    std::cout<<sum_val(v)<<std::endl;
    std::cout<<sum_ref(v)<<std::endl;

    // Pointer arithmetic 2/2

    v.clear();
    auto* ptr = v.data();
    std::cout<<sum_val(v)<<std::endl;
    ptr = nullptr;
    if (ptr) {
        std::cout<<sum_ptr(ptr, v.size())<<std::endl;
    }   

    return 0;
}