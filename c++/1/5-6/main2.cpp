#include <iostream> 
#include <math.h>
using namespace std;

int main() {
    float r = 2.4;
    float s = 5;
    float k = 0.5;
    float e = 2.71;
    float x;
    cout << "Введіть число x: ";
    cin >> x;
    if (r*s == x) cout << "x дорівнює " << cos(x*x*pow(e, 3*k))/sin(x*x*pow(e, 3*k)) + log(r*x);
    if (r*s < x) cout << "x дорівнює " << 5*x - sin(k);
    if (r*s > x) cout << "x дорівнює " << sqrt(k*x + sqrt(abs(tan(r*s))));
    return 0;
}