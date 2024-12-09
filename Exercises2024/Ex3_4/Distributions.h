// Purvi Das, Dec 8, 2024
// University of Glasgow

#include "FiniteFunctions.h"
#include <cmath>
#include <string>
#pragma once //Replacement for IFNDEF

class NormalDistribution : public FiniteFunction {
public:
    NormalDistribution(double mean, double stddev, double range_min, double range_max, std::string outfile);
    double callFunction(double x) override;

private:
    double m_Mean;
    double m_StdDev;
};

class CauchyLorentzDistribution : public FiniteFunction {
public:
    CauchyLorentzDistribution(double location, double scale, double range_min, double range_max, std::string outfile);
    double callFunction(double x) override;

private:
    double m_Location;
    double m_Scale;
};

class NegativeCrystalBall : public FiniteFunction {
public:
    NegativeCrystalBall(double mean, double stddev, double alpha, double n, double range_min, double range_max, std::string outfile);
    double callFunction(double x) override;

private:
    double m_Mean;
    double m_StdDev;
    double m_Alpha;
    double m_N;
    double m_A;
    double m_B;
    double m_NormConst;

    void calculateConstants();
};