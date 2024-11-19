// Purvi Das, Nov 19, 2024

#ifndef FUNCTIONSEXAMPLE_H
#define FUNCTIONSEXAMPLE_H
#include "CustomFunctions.cxx"

using namespace std; // std:: in namespace 

vector<pair<double, double>> fileread(const string& input_file);

vector<double> magnitude(const vector<pair<double, double>>& dataset);

void print(const vector<pair<double, double>>& dataset, vector<double>& magnitude, int n, bool magnitude_bool);

#endif