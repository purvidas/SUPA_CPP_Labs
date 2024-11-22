// Purvi Das, Nov 19, 2024

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector> 
#include <utility>
#include <cmath>

using namespace std; // std:: in namespace 

vector<pair<double, double>> fileread(const string& input_file){ // string input 
    ifstream file(input_file); 
    vector<pair<double, double>> dataset;
    string line;
    while(getline(file, line)){
        stringstream s(line);
        double x, y;
        char c;
        while(s >> x >> c >> y){ // because of ,
            dataset.emplace_back(x, y); // add directly to the vector
            }
        }
    return dataset;
}

string leastsquare(const vector<pair<double, double>>& dataset, const vector<pair<double, double>>& error){
    float sum_x = 0, sum_y = 0, sum_xx = 0, sum_xy = 0, chi_squared = 0, chi, y_i;
    float n = dataset.size();

    for(int i = 0; i < n; i++){
        const auto& [x, y] = dataset[i];
        sum_x += x;
        sum_y += y;
        sum_xx += x*x;
        sum_xy += x*y;
    }

    float m = ((n * sum_xy) - (sum_x * sum_y))/((n * sum_xx) - (sum_x * sum_x));
    float c = ((sum_y * sum_xx) - (sum_x * sum_xy))/((n * sum_xx) - (sum_x * sum_x));
    float ndf = n - 2;

    for(int j = 0; j < n; j++) {
        const auto& [x, y] = dataset[j];
        const auto& [x_e, y_e] = error[j];
        y_i = m * x + c; // y of the model
        chi_squared += pow((y - y_i), 2) / pow((y_e), 2); // standard formula for chi
    }


    chi = chi_squared / ndf;

    stringstream leastsquarestring;
    leastsquarestring << "The best fit value of the curve for the given dataset is : y = " << m << "x + " << c << '\n';
    leastsquarestring << "X^2/NDF is " << chi;
    string functionstring = leastsquarestring.str();

    return functionstring;
}

double powerfunction(double x, double y){
    int y_int = round(y);  // converting to int
    if (y == 0) return 1;
    if (y_int < 0) 
        return 1 / powerfunction(x, -y_int); // for negatives 
    return (x * powerfunction(x, y_int - 1));
}

// keeping all the print in void print 

void print(const vector<pair<double, double>>& dataset, int n, bool magnitude_needed){
    if (n <= dataset.size()){
    for(int i = 0; i < n && i < dataset.size(); i++){
        const auto& [x, y] = dataset[i];
        cout << '(' << x << ',' << y << ')';
        if(magnitude_needed == true){
            double magnitude = sqrt(pow(x,2) + pow(y,2)); // directly calculating magnitude 
            cout << " = " << magnitude;
            }
        cout << '\n';
        }
    } else {
    cout << "Warning! Number of lines exceeded! " << '\n';
    for(int i = 0; i < 5 ; i++){
        const auto& [x, y] = dataset[i];
        cout << '(' << x << ',' << y << ')';
        if(magnitude_needed == true){
            double magnitude = sqrt(pow(x,2) + pow(y,2));
            cout << " = " << magnitude;
            }
        cout << '\n';
        }
    }  
}

void print(const string& leastsquare_output, const string& outputfile){
    cout << leastsquare_output <<endl;

    ofstream output(outputfile);
    output.is_open();
    output << leastsquare_output;
    output.close();
    cout << "Saved the best fit and X^2 fit in: " << outputfile << endl;
}

void print(const vector<pair<double, double>>& dataset){
    cout << "x^y dataset is: " << endl; 
    for (const auto& [x, y] : dataset){
        double power = powerfunction(x, y);
        cout << power << endl;
    }    
}
