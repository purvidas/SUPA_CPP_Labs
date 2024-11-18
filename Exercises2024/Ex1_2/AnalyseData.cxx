// Purvi Das, Nov 13, 2024

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

using namespace std; // instead of std:: 

int main(){
    ifstream file("input2D_float.txt"); 

    string line;
    while(getline(file, line)){
        cout << '(' << line << ')' << '\n';
    }
    file.close();
    return 0;
}