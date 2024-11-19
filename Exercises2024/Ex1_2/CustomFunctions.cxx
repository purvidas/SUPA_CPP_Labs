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

vector<double> magnitude(const vector<pair<double, double>>& dataset){
    vector<double> m; 
    for(const auto& [x, y] : dataset){
        m.push_back(sqrt(pow(x, 2) + pow(y, 2)));
    }
    return m; 
}

void print(const vector<pair<double, double>>& dataset, vector<double>& magnitude, int n, bool magnitude_bool){
    if (magnitude_bool = true){ // print with magnitude 
        if (n <= dataset.size()){
        for(int i = 0; i < n && i < dataset.size(); i++){
            const auto& [x, y] = dataset[i];
            // const ensures the elements are not modified 
            // auto to know the type automatically 
            cout << '(' << x << ',' << y << ')' << " = " << magnitude[i] << '\n';
            }
        } else {
        cout << "Warning! Number of lines exceeded! " << '\n';
        for(int i = 0; i < 5 ; i++){
            const auto& [x, y] = dataset[i];
            cout << '(' << x << ',' << y << ')' << " = " << magnitude[i] << '\n';
            }
        } 
    }
    else{ // without magnitude 
        if (n < dataset.size()){
        for(int i = 0; i < n && i < dataset.size(); i++){
            const auto& [x, y] = dataset[i];
            cout << '(' << x << ',' << y << ')' << '\n';
            }
        } else {
        cout << "Warning! Number of lines exceeded! " << '\n';
        for(int i = 0; i < 5 ; i++){
            const auto& [x, y] = dataset[i];
            cout << '(' << x << ',' << y << ')' << '\n';
            }
        } 
    }
  
}

void leastsquare(const vector<pair<double, double>>& dataset, const string& outputfile){
    float sum_x = 0, sum_y = 0, sum_xx = 0, sum_xy = 0;
    for(int i = 0; i < dataset.size(); i++){
        const auto& [x, y] = dataset[i];
        sum_x += x;
        sum_y += y;
        sum_xx += x*x;
        sum_xy += x*y;
    }
    float n = dataset.size();
    float m = ((n * sum_xy) - (sum_x * sum_y))/((n * sum_xx) - (sum_x * sum_x));
    float c = ((sum_y * sum_xx) - (sum_x * sum_xy))/((n * sum_xx) - (sum_x * sum_x));

    stringstream leastsquarestring;
    leastsquarestring << "y = "<< m << "x + "<< c;
    string functionstring = leastsquarestring.str();
    cout<<"The best fit value of the curve for the given dataset is : "<< functionstring <<endl;

    ofstream output(outputfile);
    output.is_open();
    output << functionstring;
    output.close();
    cout << "Saved the best fit in: " << outputfile << endl;
}