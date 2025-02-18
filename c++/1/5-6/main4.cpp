#include <iostream> 
#include <cmath>
using namespace std;

void mreow(int n) {
    int r = n, res = 0;
    for (int i = 1; i < r; i++) {
        int t = sqrt(r * r - i * i);
        res += t;
    }
    cout << "Кількість точок в колі з радіусом " << r << " дорівнює - \e[32m" << res * 4 + r * 4 + 1 << "\e[0m | Сектор - " << res << endl;
}
int main() {
    int y;
    cout << "Введіть кількість ітерацій: ";
    cin >> y;
    for (int n = 1; n <= y; n++) mreow(n);
    return 0;
}