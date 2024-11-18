// Purvi Das, Nov 13, 2024

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector> 
#include <utility>

using namespace std; // instead of std:: 

int main(){
    ifstream file("input2D_float.txt"); 
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
    file.close(); // safe practice

    for (const auto& [x, y]: dataset){ 
        // const ensures the elements are not modified 
        // auto to know the type automatically 
        cout << '(' << x << ',' << y << ')' << '\n';
    }
    return 0;
}