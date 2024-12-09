// Purvi Das, Dec 8, 2024
// University of Glasgow

#include "Distributions.h"
#include <cmath>
#include <iostream>

// Normal distribution 
NormalDistribution::NormalDistribution(double mean, double stddev, double range_min, double range_max, std::string outfile)
    : FiniteFunction(range_min, range_max, outfile), m_Mean(mean), m_StdDev(stddev) {}

double NormalDistribution::callFunction(double x) {
    double norm_const = 1.0 / (m_StdDev * sqrt(2.0 * M_PI));
    double exp_term = exp(-0.5 * pow((x - m_Mean) / m_StdDev, 2));
    return norm_const * exp_term;
}

// Cauchy lorentz distribution
CauchyLorentzDistribution::CauchyLorentzDistribution(double location, double scale, double range_min, double range_max, std::string outfile)
    : FiniteFunction(range_min, range_max, outfile), m_Location(location), m_Scale(scale) {}

double CauchyLorentzDistribution::callFunction(double x) {
    double norm_const = 1.0 / (M_PI * m_Scale);
    double denom = 1.0 + pow((x - m_Location) / m_Scale, 2);
    return norm_const / denom;
}

// Negative crystal ball distribution
NegativeCrystalBall::NegativeCrystalBall(double mean, double stddev, double alpha, double n, double range_min, double range_max, std::string outfile)
    : FiniteFunction(range_min, range_max, outfile), m_Mean(mean), m_StdDev(stddev), m_Alpha(alpha), m_N(n) {
    calculateConstants();
}

void NegativeCrystalBall::calculateConstants() {
    double abs_alpha = fabs(m_Alpha);
    m_A = pow(m_N / abs_alpha, m_N) * exp(-0.5 * abs_alpha * abs_alpha);
    m_B = m_N / abs_alpha - abs_alpha;

    double C = m_N / abs_alpha * 1.0 / (m_N - 1.0) * exp(-0.5 * abs_alpha * abs_alpha);
    double D = sqrt(M_PI / 2.0) * (1 + erf(abs_alpha / sqrt(2.0)));
    m_NormConst = 1.0 / (m_StdDev * (C + D));
}

double NegativeCrystalBall::callFunction(double x) {
    double t = (x - m_Mean) / m_StdDev;
    if (t > -m_Alpha) {
        return exp(-0.5 * t * t);
    } else {
        return m_A * pow(m_B - t, -m_N);
    }
}
