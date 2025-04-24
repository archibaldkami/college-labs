#include <iostream>
#include <fstream>
#include <string>
#include <sstream>

using namespace std;

void makeTable(string dataset) {
    fstream file(dataset);
    string line;

    while (getline(file, line)) {
        stringstream ss(line);
        string cell;
        
        while (getline(ss, cell, ',')) cout << cell << "\t";
        cout << endl;
    }
}

int main() {
    makeTable("students.csv");
    return 0;
}