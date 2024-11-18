// Purvi Das, Nov 13, 2024

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector> 
#include <utility>

using namespace std; // instead of std:: 

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

void print(const vector<pair<double, double>>& dataset, int n){
    if (n < dataset.size()){
        for(int i = 0; i < n && i < dataset.size(); i++){
            const auto& [x, y] = dataset[i];
            // const ensures the elements are not modified 
            // auto to know the type automatically 
            cout << '(' << x << ',' << y << ')' << '\n';
        }
    } else {
        cout << "Warning! " << '\n';
        for(int i = 0; i < 5 ; i++){
            const auto& [x, y] = dataset[i];
            cout << '(' << x << ',' << y << ')' << '\n';
        }
    }   
}

int main(){
    vector<pair<double, double>> dataset = fileread("input2D_float.txt");
    int n;
    cout << "Provide the number of lines you want to print: ";
    cin >> n;
    print(dataset, n);
    return 0;
}