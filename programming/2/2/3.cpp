#include <iostream>
#include <vector>

using namespace std;

vector<int> move_zeros(vector<int> a) {
    vector<int> result(a.size()); int iter = 0;
    for (int i = 0; i < a.size(); i++) {
        result[i] = 0;
        if (a[i] != 0) result[iter++] = a[i];
    }
    return result;
}

int main() {
    vector<int> list_ = move_zeros({1, 0, 1, 2, 0, 1, 3});
    for (int i = 0; i < list_.size(); i++) cout << list_[i] << " ";
    cout << endl;
    return 0;
}