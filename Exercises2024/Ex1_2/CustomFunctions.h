// Purvi Das, Nov 19, 2024

#ifndef CUSTOMFUNCTIONS_H
#define CUSTOMFUNCTIONS_H
#include "CustomFunctions.cxx"

using namespace std; // std:: in namespace 

vector<pair<double, double>> fileread(const string& input_file);

void outfile(ostream& output, const vector<pair<double, double>>& dataset, int n, bool magnitude_needed);

void print(const vector<pair<double, double>>& dataset, int n, bool magnitude_needed);

void fileprint(const vector<pair<double, double>>& dataset, int n, bool magnitude_needed, const string& outputfile);

string leastsquare(const vector<pair<double, double>>& dataset, const vector<pair<double, double>>& error);

void print(const string& leastsquare_output);

void fileprint(const string& string_output, const string& outputfile);

double powerfunction(double x, double y);

void outfile(ostream& output, const vector<pair<double, double>>& dataset);

void print(const vector<pair<double, double>>& dataset);

void fileprint(const vector<pair<double, double>>& dataset, const string& outputfile);

#endif