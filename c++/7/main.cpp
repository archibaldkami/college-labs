#include <iostream>
using namespace std;

void first(int edge) 
{
    for (int num = 1 ;num <= edge; num++) {
        cout << num << " ";
    }
    cout << endl;
}
void second(int n)
{
    for (int i = 0; i <= n; i++) cout << i << " ";
    cout << endl;
}

void third(int d = 1)
{
    int i, Smax = 50, n = 10, sum = 0, k = 0;
    for (i = 1; sum <= Smax; i += d) {
        sum += i; k++;
    }
    cout << "Iterations: " << k << endl;
}

int main() {
    first(100);
    first(10);
    first(30);
    first(4000);
    second(5);
    second(-1);
    third();
    third(5);
    return 0;
}
