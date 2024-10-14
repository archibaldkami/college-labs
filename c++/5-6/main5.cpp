#include <iostream> 
#include <math.h>
#include <list>
using namespace std;

void last_digit(int num, int pow){
    list<int> _0 = {0};
    list<int> _1 = {1};
    list<int> _2 = {2, 4, 8, 6};
    list<int> _3 = {3, 9, 7, 1};
    list<int> _4 = {4, 6};
    list<int> _5 = {5};
    list<int> _6 = {6};
    list<int> _7 = {7, 9, 3, 1};
    list<int> _8 = {8, 4, 2, 6};
    list<int> _9 = {9, 1};
    // _7.size()
    //
    // list<int>::iterator _it0 = _2.begin() + 1;
}

int main() {
    int num, pow;
    cout << "Введіть число число 1: ";
    cin >> num;
    cout << "Введіть число число 2: ";
    cin >> pow;
    last_digit(num, pow);
    return 0;
}