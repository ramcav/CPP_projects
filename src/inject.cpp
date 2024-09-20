#include <iostream>
#include <string>
void root_privileged_print(std::string message, volatile auto user){
    if (user==0xbada55){
    std::cout<<"Root: "<<message<<std::endl;
    }
    if(user == 0xdeadbeef){
    std::cout<<"Users do not have the rights to print"<<std::endl;
    }
}
void injection(){

    // I'm going through the stack memory one by one and
    // changing each address to be the root

    for (int i = 0; i < 10; i++) {
        int *ptr = (int*)(&ptr+i);
        *ptr = 0xbada55;
    }
}

int main(){
    auto user = 0xdeadbeef;
    injection();
    root_privileged_print("ALL YOUR BASE ARE BELONG TO US", user);
    return 0;
}