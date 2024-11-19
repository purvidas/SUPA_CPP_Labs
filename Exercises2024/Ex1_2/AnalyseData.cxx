// Purvi Das, Nov 13, 2024

#include <iostream>
#include "CustomFunctions.h"

int main(){
    vector<pair<double, double>> dataset = fileread("input2D_float.txt");
    vector<double> magnitude_output = magnitude(dataset);
    int n, output; 

    cout << "1. Dataset \n2. Dataset with Magnitude \nWhat do you want?: ";
    cin >> output; 
    cout << "Provide the number of lines you want to print: ";
    cin >> n;

    if(output == 1){
        print(dataset, magnitude_output, n, false);
    }
    else{
        print(dataset, magnitude_output, n, true);               
    }

    leastsquare(dataset, "output.txt");

    return 0;
}