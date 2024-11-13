#include <iostream>
#include <cmath>

// Part 2
// Now create a function to calculate the magnitude of the vector which takes as input fromthe user x and y components.  
// Use this function to calculate the magnitude of the vector in(II) and make sure the answer which is printed out is the same as in point (II)

float magnitude(float x, float y){
    return sqrt(pow(x, 2) + pow(y, 2));
}

int main(){

    float x, y;

    std::cout << "Provide x: ";
    std::cin >> x;

    std::cout << "Provide y: ";
    std::cin >> y;

    std::cout << magnitude(x, y) << std::endl;
    return 0;
}