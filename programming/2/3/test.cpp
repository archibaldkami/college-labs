#include <iostream>
using namespace std;

int main() {
    unsigned char a = 0;
    for (int i = 0; i < 300; i++) {
        // if (int(a) < 256) a++;
        // else a = char(0);
        cout << a++ << " | " << int(a) << endl;
    }
    
    
    return 0;
}