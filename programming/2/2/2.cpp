#include <iostream>
using namespace std;

bool is_walk_correct(char road[], int length) {
    if (length != 10) return false;
    else {
        int pos[2] = {0, 0};
        for (int i = 0; i < 10; i++) {
            switch (road[i]) {
                case 'n': pos[0]--; break;
                case 's': pos[0]++; break;
                case 'w': pos[1]--; break;
                case 'e': pos[1]++; break;
            }
        }
        // cout << pos[0] << " " << pos[1] << endl;
        // cout << (!pos[0] && !pos[1]) << endl;
        return ((!pos[0] && !pos[1]) ? true : false);
    }
}

int main() {
    char road1[] = {'n', 's', 'e', 'w', 'n', 's', 'w', 'e', 's', 'n'};
    cout << (is_walk_correct(road1, sizeof(road1) / sizeof(road1[0])) ? "\033[1;32mOK\033[0m" : "\033[1;31mBAD\033[0m") << endl;

    char road2[] = {'n', 's', 'e', 'w', 'n', 's', 'w', 'e', 's', 's'};
    cout << (is_walk_correct(road2, sizeof(road2) / sizeof(road2[0])) ? "\033[1;32mOK\033[0m" : "\033[1;31mBAD\033[0m") << endl;
    
    char road3[] = {'n', 's', 'e', 'w', 'n', 's', 'w', 'e', 's', 'n', 'n'};
    cout << (is_walk_correct(road3, sizeof(road3) / sizeof(road3[0])) ? "\033[1;32mOK\033[0m" : "\033[1;31mBAD\033[0m") << endl;
    
    return 0;
}