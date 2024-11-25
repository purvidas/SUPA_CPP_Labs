// Purvi Das, Nov 13, 2024

#include <iostream>
#include "CustomFunctions.h"

int main(){
    int n, dataset_output, leastsquare_output, xy_output;
    vector<pair<double, double>> dataset = fileread("input2D_float.txt");
    vector<pair<double, double>> error = fileread("error2D_float.txt");

    cout << "1. Dataset \n2. Dataset with Magnitude \nWhat do you want?: ";
    cin >> dataset_output; 
    cout << "\nProvide the number of lines you want to print: ";
    cin >> n;

    if(dataset_output == 1){
        print(dataset, n, false);
        fileprint(dataset, n, false, "dataset_output.txt");               
    }
    else{
        print(dataset, n, true);
        fileprint(dataset, n, false, "dataset_magnitude_output.txt");               
    }

    cout << "\nDo you want the best fit and X^2/NDF of the dataset?: \n1. Yes \n2. No\n";
    cin >> leastsquare_output;
    string leastsquare_string = leastsquare(dataset, error);

    if (leastsquare_output == 1){
        print(leastsquare_string);
        fileprint(leastsquare_string, "leastsquare_output.txt");
    }

    cout << "\nDo you want the x^y dataset: \n1. Yes \n2. No \n";
    cin >> xy_output;

    if(xy_output == 1){
        print(dataset);
        fileprint(dataset, "xy_output.txt");
    }
    else{
        return 0;
    }

}