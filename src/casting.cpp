#include <iostream>

int main() {
    
     // Casting

    int my_variable = 2;
    float int_to_reint = 0x40000000; // Used chat to get this

    float c_casting = (float) my_variable;
    float s_casting = static_cast<float>(my_variable);
    auto r_casting = *reinterpret_cast<double*>(&int_to_reint);

    std::cout<<"My C casted var = "<<c_casting<<std::endl;
    std::cout<<"My static casted var = "<<s_casting<<std::endl;
    std::cout<<"My reinterpret casted var = "<<r_casting<<std::endl;

    return 0;
}