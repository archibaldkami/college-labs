#include <iostream> 
#include <math.h>

int main() {
    float x;
    std::cout << "Введіть число x: ";
    std::cin >> x;
    if (x <= -4) std::cout << "x дорівнює " << 2*x - 1;
    if (x > -4 && x <= 5) std::cout << "x дорівнює " << x*x + 2;
    if (x > 5) std::cout << "x дорівнює " << x + 3;
    return 0;
}