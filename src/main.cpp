#include <smart.h>

int main() {

    // PT 1.
    homework::Resource resource;
    std::cout << "Using smart pointer:" << std::endl;
    // No need to free this as it is automatically handled
    std::unique_ptr<homework::Resource> s_ptr = homework::setResource(resource);

    std::cout << "Using raw pointer:" << std::endl;
    homework::Resource* raw_ptr = new homework::Resource(); 
    delete raw_ptr;
    std::cout << "Raw pointer resource freed." << std::endl;

    // PT.2.
    // while (1) homework::fun(); (COMMENTED OUT AS IT IS AN INFINITE LOOP)

    // PT.3.
    std::shared_ptr<homework::FileHandler> filePtr(
        new homework::FileHandler("example.txt"),
        [](homework::FileHandler* fh) {
        std::cout << "Calling custom deleter for FileHandler Shared Pointer" << std::endl;
        delete fh;
    }
    );
    
    auto pt2 = filePtr;


    //PT.4.

    int* arr = new int[10];

    auto deleter = [](int *p) {
        delete[] p;
        std::cout << "Array deleted" << std::endl;
    };

    std::unique_ptr<int[], decltype(deleter)> arrInt(arr, deleter);


}