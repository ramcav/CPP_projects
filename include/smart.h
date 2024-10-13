// include/split.h
#pragma once
#include <string>
#include <vector>
#include <iostream>
#include <fstream>
#include <string>
namespace homework{

class Resource {
    public:
        Resource();
        ~Resource();       



};

class Database {
    std::vector<int> data;
    public:
        Database();
};

class FileHandler {
    std::ofstream file;

    public:
        FileHandler(std::string filename);

        ~FileHandler();
};


std::unique_ptr<Resource> setResource(Resource resource);

void fun();

} // namespace homework