#include <iostream>
#include <string>

int main() {
    std::cout << "What's your name?" << std::endl;
    std::string var;
    //int var;
    std::cin >> var;
    std::cout << "Hello " << var << "!" << std::endl;
    return 0; 
}
