#include <iostream> 
using namespace std;


int main() {
    int x, y;
    cout << "Введіть число: ";
    cin >> x;
    if (x <= -4) y = 2*x-1;
    else if (x > -4 && x <= 5) y = x*x+2;
    else if (x > 5) y = x+3;
    cout << "Відповідь:  " << y << endl;
    return 0;
}  