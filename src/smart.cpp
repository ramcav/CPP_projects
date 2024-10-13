#include <smart.h>
#include <iostream>
#include <memory>
#include <string>

namespace homework {
    
    Resource::Resource(){
        std::cout<<"Resource Acquired"<<std::endl;
    }

    Resource::~Resource() {
        std::cout<<"Resource destroyed"<<std::endl;
    }

    std::unique_ptr<Resource> setResource(Resource resource) {
        std::unique_ptr<Resource> ptr = std::make_unique<Resource>();
        return ptr;
    }

    Database::Database() {
        std::vector<int> data(1000000);
    }

    void fun() {
        std::unique_ptr<Database> ptr = std::make_unique<Database> (Database());
    }

    FileHandler::FileHandler(std::string filename) {
        this->file.open(filename);
    }

    FileHandler::~FileHandler() {
        this->file.close();
    }

};