#include <iostream>
#include <cmath>

// Part 1
// Declare  two  variables,  x  and  y,  and  assign  them  the  values  x=2.3  and  y=4.5.   
// Assuming these are x and y components of a 2-D vector,  compute the magnitude of the vector andhave your program print the answer to the screen.

int main(){

    float x = 2.3;
    float y = 4.5;

    float magnitude = sqrt(pow(x, 2) + pow(y, 2));
    std::cout << magnitude << std::endl;
    return 0;

}