#include <iostream>
#include <fstream>

int main(){
    std::ifstream file("input2D_float.txt"); 

    std::string line;
    while(std::getline(file, line)){
        std::cout << line << '\n';
    }
    return 0;
}