#include <iostream>
#include <sstream>
#include <vector>
using namespace std;

// Lab 1
vector<int> Sort_Select(vector<int> input_list) {
    for (int j = input_list.size() - 1; j >= 0; j--) {
        int max = input_list[j];
        int idx = j;
        for (int i = 0; i < j; i++)
            if (input_list[i] > max) {
            max = input_list[i];
            idx = i;
            }
        int tmp = input_list[j];
        input_list[j] = input_list[idx];
        input_list[idx] = tmp;
    }
    return input_list;
}

// Lab 2
vector<int> Sort_Paste(vector<int> input_list) {
    for (int j = 1; j < input_list.size(); j++) {
        int el = 0;
        for (int i = 0; i <= j; i++) {
        el = input_list[j];
        if (input_list[i] >= el) {
            input_list[j] = input_list[i];
            input_list[i] = el;
            }
        }
    }
    return input_list;
}

// Lab 3
vector<int> Sort_Bubble(vector<int> input_list) {
    for (int j = 0; j < input_list.size(); j++)
        for (int i = 0; i < input_list.size()-1; i++)
            if (input_list[i+1] < input_list[i]) {
            int tmp = input_list[i+1];
            input_list[i+1]=input_list[i];
            input_list[i]=tmp;
            }
    return input_list;
}

vector<int> makelist() {
    string sub_select[2];
    int isub_select;
    system("clear");
    cout << "\t----\tA2E\t----\n";
    cout << "\nChoose list create method from list below:\n\n";
    cout << "1. Input manually\n2. Generate random\n";
    cout << "\nMethod to use (default: 1) : "; getline(cin, sub_select[0]);

    if (sub_select[0].empty()) sub_select[0] = "1";

    system("clear");
    cout << "\t----\tA2E\t----\n";
    cout << "\nInput list size:\n\n";
    cout << "\n(default: 10) : "; getline(cin, sub_select[1]);

    if (sub_select[1].empty()) sub_select[1] = "10";
    stringstream ss(sub_select[1]);
    if (ss >> isub_select) ss >> isub_select;

    vector<int> list_(isub_select);
    if (sub_select[0] == "1") {
        for (int i = 0; i < isub_select ;i++) {
            cout << "Input number at index " << i << ": "; 
            cin >> list_[i];
        }
    } else if (sub_select[0] == "2")
        for (int i = 0; i < isub_select; i++) {
            list_[i] = rand() % 101;
        }
    return list_;
}

void interface(int len, string methods[]) {
    string option;
    system("clear");
    cout << "\t----\tA2E\t----\n";
    cout << "\nChoose sort method from list below:\n\n";
    for (int i = 0; i < len; i++) {
        cout << i+1 << ". " << methods[i] << endl;
    }
    cout << "\nMethod to use (default: 1) : ";
    getline(cin, option);

    if (option.empty()) option = "1";


    vector<int> list_;

    if (option == "1") {

        list_ = makelist();

        system("clear");
        cout << "\t----\tA2E\t----\n";
        cout << "\nSort Select\n";
        cout << "\nInput list:";
        for (int i = 0; i < list_.size(); i++) cout << " " << list_[i];
        cout << endl;

        list_ = Sort_Select(list_);
        cout << "Output list:";
        for (int i = 0; i < list_.size(); i++) cout << " " << list_[i];
        cout << endl;

    } else if (option == "2") {

        list_ = makelist();

        system("clear");
        cout << "\t----\tA2E\t----\n";
        cout << "\nPaste Sort\n";
        cout << "\nInput list:";
        for (int i = 0; i < list_.size(); i++) cout << " " << list_[i];
        cout << endl;

        list_ = Sort_Paste(list_);
        cout << "Output list:";
        for (int i = 0; i < list_.size(); i++) cout << " " << list_[i];
        cout << endl;
        
    } else if (option == "3") {

        list_ = makelist();

        system("clear");
        cout << "\t----\tA2E\t----\n";
        cout << "\nSort Bubble\n";
        cout << "\nInput list:";
        for (int i = 0; i < list_.size(); i++) cout << " " << list_[i];
        cout << endl;

        list_ = Sort_Bubble(list_);
        cout << "Output list:";
        for (int i = 0; i < list_.size(); i++) cout << " " << list_[i];
        cout << endl;
        
    } else cout << "incorrect method number\n";



    
}

int main() {
    string methods[] = {"Sort Select", "Sort Paste", "Sort Bubble"};
    interface((sizeof(methods)/sizeof(*methods)), methods);
    return 0;
}