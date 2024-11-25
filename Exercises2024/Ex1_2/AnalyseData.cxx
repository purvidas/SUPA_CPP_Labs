// Purvi Das, Nov 13, 2024

#include <iostream>
#include "CustomFunctions.h"

int main(){
    int i, n, dataset_output;
    vector<pair<double, double>> dataset = fileread("input2D_float.txt");
    vector<pair<double, double>> error = fileread("error2D_float.txt");
    string leastsquare_string = leastsquare(dataset, error);

    bool run = true;

    while (run){
        cout << "1. Print dataset (with or without magnitude)" << endl;
        cout << "2. Print leastsquare fit and X^2/NDF" << endl;
        cout << "3. Print x^y of the dataset" << endl;
        cout << "Which operation do you want to execute?: ";
        cin >> i;
        cout << '\n'; 

        switch (i){
            case 1:
                cout << "1. Dataset \n2. Dataset with Magnitude \nWhat do you want?: ";
                cin >> dataset_output; 
                cout << "\nProvide the number of lines you want to print: ";
                cin >> n;

                if(dataset_output == 1){
                    print(dataset, n, false);
                    fileprint(dataset, n, false, "dataset_output.txt");  
                    cout << '\n';             
                }
                else{
                    print(dataset, n, true);
                    fileprint(dataset, n, true, "dataset_magnitude_output.txt");  
                    cout << '\n';               
                }
                break;
            case 2:
                print(leastsquare_string);
                fileprint(leastsquare_string, "leastsquare_output.txt");
                cout << '\n';  
                break;
            case 3:
                print(dataset);
                fileprint(dataset, "xy_output.txt");
                cout << '\n';  
                break;
            default:{
                cout << "Please select correct choice." << endl;
                break;
            }
        }
        if (run){
            cout << "Do want to do another operation? \n1. Yes \n2. No \n" << endl;
            int continue_output;
            cin >> continue_output;
            if (continue_output == 2){
                run = false;
                cout << "Ending!" << endl;
            }
        }
    }
    return 0;
}