#include <iostream>
#include <cmath>
#include <iomanip> 

using namespace std;

double f(double x) {
    return (x * x) - 5;; // Example function (can be changed later)
}

double bisectionMethod(double a, double b, double tol = 0.00005, int max_iter = 100) {

    if (f(a) * f(b) >= 0) {
        cout << "Bisection method fails. The function must change signs in the interval." << endl;
        return NAN;
    }

    int iteration = 0;
    double c, fc;


    cout << left << setw(10) << "Iteration" 
         << "| " << setw(15) << "Interval" 
         << "| " << setw(12) << "Midpoint" 
         << "| " << setw(10) << "f(c)" << endl;
    cout << string(55, '-') << endl;

    while (iteration < max_iter) {
        c = (a + b) / 2.0; // Midpoint
        fc = f(c);


        cout << left << setw(10) << iteration + 1 
             << "| [" << setw(7) << fixed << setprecision(5) << a << ", " 
                        << setw(7) << fixed << setprecision(5) << b << "]"
             << "| " << setw(10) << fixed << setprecision(5) << c 
             << "| " << setw(10) << fixed << setprecision(5) << fc << endl;

        if (fabs(fc) <= tol) { // Stop if f(c) is very close to 0
            cout << string(55, '-') << endl;
            cout << "Approximate root: " << fixed << setprecision(5) << c << endl;
            cout << "Total iterations: " << iteration + 1 << endl;
            return c;
        }

        if (f(a) * fc < 0) {
            b = c; // Root is in the left subinterval
        } else {
            a = c; // Root is in the right subinterval
        }

        iteration++;
    }

    cout << string(55, '-') << endl;
    cout << "Max iterations reached. Approximate root: " << fixed << setprecision(5) << c << endl;
    return c;
}

int main() {
    double a, b;

    // Get user input
    cout << "Enter the lower bound (a): ";
    cin >> a;
    cout << "Enter the upper bound (b): ";
    cin >> b;

    double root = bisectionMethod(a, b);

    if (!isnan(root)) {
        cout << "Final Approximate Root: " << fixed << setprecision(5) << root << endl;
    }

    return 0;
}
