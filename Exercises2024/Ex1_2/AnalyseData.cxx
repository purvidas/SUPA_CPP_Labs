// Purvi Das, Nov 13, 2024

#include <iostream>
#include "CustomFunctions.h"

int main(){
    int n, output, leastsquare_bool;
    vector<pair<double, double>> dataset = fileread("input2D_float.txt");

    cout << "1. Dataset \n2. Dataset with Magnitude \nWhat do you want?: ";
    cin >> output; 
    cout << "Provide the number of lines you want to print: ";
    cin >> n;

    if(output == 1){
        print(dataset, n, false);               
    }
    else{
        print(dataset, n, true);
    }
    cout << "Do you want the best fit of the dataset?: \n1. Yes \n2. No\n";
    cin >> leastsquare_bool;
    string leastsquare_output = leastsquare(dataset);

    if (leastsquare_bool == 1){
        print(leastsquare_output, "output.txt");
    }
    else{
        return 0;
    }
}