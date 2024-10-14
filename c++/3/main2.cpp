#include <iostream> 
using namespace std;


int main() {
    int num;
    int n = 0;
    cout << "Введіть число: ";
    cin >> num;
    // cout << num % 3 << endl;
    if (num <= 0) n = 0;
    else {
        for (int i=0; i<num; i++){
            if (i % 3 == 0) n += i;
            else if (i % 5 == 0) n += i;
        }
    }
    cout << "Сумма всіх чисел кратних 3 і 5 дорівнює " << n << endl;
    return 0;
}