#include <iostream> 

int main() {
    float d;
    std::cout << "Введіть відстань в дюймах: ";
    std::cin >> d;
    std::cout << d << " дюйм(-ів) дорівнює " << d*2.54 << " сантиметр(-ів)" << std::endl;
    return 0;
}