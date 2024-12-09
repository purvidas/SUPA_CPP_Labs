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

    double value;
    while (infile >> value) {
        data.push_back(value);
    }
    infile.close();

    std::cout << "Loaded " << data.size() << " data points from " << inputFile << std::endl;

    FiniteFunction finiteFunc(-20.0, 20.0, "mystery");
    finiteFunc.printInfo();
    finiteFunc.plotFunction();
    finiteFunc.plotData(data, 50, true); 
    std::cout << std::endl;

    int numSamples = 10000;
    double stepSize = 0.5; 
    std::vector<double> metropolisSamples = finiteFunc.metropolisSampling(numSamples, stepSize);

    finiteFunc.plotData(metropolisSamples, 50, false);

    NormalDistribution normal(0.989641, 2.97515, -20.0, 20.0, "normal");
    CauchyLorentzDistribution cauchy(0.989641, 2.97515, -20.0, 20.0, "cauchy");
    NegativeCrystalBall crystal(0.989641, 2.97515, 1.5, 5.0, -20.0, 20.0, "crystal");

    std::vector<FiniteFunction*> functions = {&normal, &cauchy, &crystal};

    for (auto* func : functions) {
        std::cout << std::endl;
        func->printInfo();
        func->plotFunction();
        func->plotData(data, 50, true);

        std::vector<double> samples = func->metropolisSampling(numSamples, stepSize);

        func->plotData(samples, 50, false);
    }

    return 0;
}