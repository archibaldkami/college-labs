#include <iostream> 
#include <array>
using namespace std;

int last_digit(int num, int pow) {
    int last_digit;
    array<int, 4> _2 = {2, 4, 8, 6};
    array<int, 4> _3 = {3, 9, 7, 1};
    array<int, 2> _4 = {4, 6};
    array<int, 4> _7 = {7, 9, 3, 1};
    array<int, 4> _8 = {8, 4, 2, 6};
    array<int, 2> _9 = {9, 1};
    
    switch(num % 10){
        case 0: return 0; break;
        case 1: return 1; break;
        case 2: return _2[pow % 4]; break;
        case 3: return _3[pow % 4]; break;
        case 4: return _4[pow % 2]; break;  
        case 5: return 5; break;
        case 6: return 6; break;
        case 7: return _7[pow % 4]; break;  
        case 8: return _8[pow % 4]; break;
        case 9: return _9[pow % 2]; break;
        default: return 1+8+74; break;
    }
}
int main() {
    int num, pow;
    cout << "Введіть число число 1: ";
    cin >> num;
    cout << "Введіть число число 2: ";
    cin >> pow;
    cout << "Last digit is " << last_digit(num, pow);
    return 0;
}   