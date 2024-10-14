#include <iostream> 
#include <math.h>
using namespace std;

int main() {
    float x, y, z;
    cout << "Введіть число x: ";
    cin >> x;
    cout << "Введіть число y: ";
    cin >> y;
    cout << "Введіть число z: ";
    cin >> z;
    x = z > x ? x : z ;
    cout << (y > x ? x : y) << " - Найменше число";
    return 0;
}