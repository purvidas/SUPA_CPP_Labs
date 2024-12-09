// Purvi Das, Dec 9, 2024

#include <iostream>
#include <cmath>
#include <iomanip>
#include <random>

using namespace std;

/*
I am following this theory:
Probability of a point inside a circle = area of circle/area of square with side 2r = pi*r^2/4*r^2 = pi/4 = points_inside/points_total
*/

// keeping the random number function similar to previous part of the assignment
double random_double(double min, double max) {
    static random_device rd;
    static mt19937 gen(rd());
    uniform_real_distribution<> dis(min, max);
    return dis(gen);
}

int main(int argc, char* argv[]) {
    double radius;
    int n_random;

    cout << "Please provide the radius : ";
    cin >> radius;

    cout << "Please provide the random number : ";
    cin >> n_random;

    if (radius <= 0 || n_random <= 0) {
        cerr << "Please provide positive numbers!" << endl;
    }
    else{
        int inside_circle = 0;

        //creating random numbers to check if they are inside the circle
        for (int i = 0; i < n_random; ++i) {
            double x = random_double(-radius, radius);
            double y = random_double(-radius, radius);

            if ((pow(x, 2) + pow(y, 2)) <= pow(radius, 2)) {
                inside_circle++; // if it is inside or on the boundary of the circle
            }
        }

        // monte carlo estimation
        double pi = 4.0 * static_cast<double>(inside_circle) / n_random;

        cout << fixed << setprecision(10); // as asked for 10 decimal points
        cout << "The calculated π is : " << pi << endl;
        }

    return 0;
}
