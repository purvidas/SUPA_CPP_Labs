// Purvi Das, Dec 4, 2024

#include <iostream>
#include <vector>
#include <fstream>
#include "FiniteFunctions.h"
#include "Distributions.h"

int main() {
    const std::string inputFile = "/workspaces/SUPA_CPP_Labs/Exercises2024/Ex3_4/Outputs/data/MysteryData03414.txt";

    std::vector<double> data;
    std::ifstream infile(inputFile);
    if (!infile.is_open()) {
        std::cerr << "Error: Could not open file " << inputFile << std::endl;
        return -1;
    }

    double value;
    while (infile >> value) {
        data.push_back(value);
    }
    infile.close();

    if (data.empty()) {
        std::cerr << "Error: No data found in file " << inputFile << std::endl;
        return -1;
    }

    std::cout << "Loaded " << data.size() << " data points from " << inputFile << std::endl;

    FiniteFunction finiteFunc(-20.0, 20.0, "output");
    finiteFunc.plotFunction();
    finiteFunc.plotData(data, 100, true); 
    finiteFunc.printInfo();


    NormalDistribution normal(0.0, 1.0, -15.0, 15.0, "normal");
    CauchyLorentzDistribution cauchy(0.0, 1.0, -15.0, 15.0, "cauchy");
    NegativeCrystalBall crystal(-1.0, 1.0, 1.5, 5.0, -15.0, 15.0, "crystal");

    std::vector<FiniteFunction*> functions = {&normal, &cauchy, &crystal};

    for (auto* func : functions) {
        func->plotFunction();
        func->plotData(data, 50);
        func->printInfo();
    }

    return 0;
}