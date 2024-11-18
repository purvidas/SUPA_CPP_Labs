// Purvi Das, Nov 13, 2024

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector> 
#include <utility>

using namespace std; // instead of std:: 

int main(){
    // ifstream file("input2D_float.txt"); 


    ifstream file("input2D_float.txt"); 
    vector<pair<double, double>> dataset;

    string line;
    while(getline(file, line)){
        stringstream s(line);
        double x, y;
        char c;
        while(s >> x >> c >> y){
            dataset.emplace_back(x, y);
            }
        }
    file.close();

    for (const auto& [x, y]: dataset){
        cout << '(' << x << ',' << y << ')' << '\n';
    }
    return 0;
}