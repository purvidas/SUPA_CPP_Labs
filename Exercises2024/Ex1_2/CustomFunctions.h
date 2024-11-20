// Purvi Das, Nov 19, 2024

#ifndef CUSTOMFUNCTIONS_H
#define CUSTOMFUNCTIONS_H
#include "CustomFunctions.cxx"

using namespace std; // std:: in namespace 

vector<pair<double, double>> fileread(const string& input_file);

string leastsquare(const vector<pair<double, double>>& dataset);

void print(const vector<pair<double, double>>& dataset, vector<double>& magnitude, int n, bool magnitude_needed);

void print(const string& leastsquare_output);

#endif