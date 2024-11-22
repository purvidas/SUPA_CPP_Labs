// Purvi Das, Nov 13, 2024

#include <iostream>
#include "CustomFunctions.h"

int main(){
    int n, output, leastsquare_bool, xy_output;
    vector<pair<double, double>> dataset = fileread("input2D_float.txt");
    vector<pair<double, double>> error = fileread("error2D_float.txt");

    cout << "1. Dataset \n2. Dataset with Magnitude \nWhat do you want?: ";
    cin >> output; 
    cout << "\nProvide the number of lines you want to print: ";
    cin >> n;

    if(output == 1){
        print(dataset, n, false);               
    }
    else{
        print(dataset, n, true);
    }
    cout << "\nDo you want the best fit and X^2/NDF of the dataset?: \n1. Yes \n2. No\n";
    cin >> leastsquare_bool;
    string leastsquare_output = leastsquare(dataset, error);

    if (leastsquare_bool == 1){
        print(leastsquare_output, "output.txt");
    }

    cout << "\nDo you want the x^y dataset: \n1.Yes \n2. No \n";
    cin >> xy_output;

    if(xy_output == 1){
        print(dataset);
    }
    else{
        return 0;
    }

}