#include <iostream>
#include <sstream>
#include <vector>
#include <chrono>
using namespace std;
using namespace std::chrono;

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
    for (int j = 0; j < input_list.size(); j++) {
        for (int i = 0; i < input_list.size() - 1; i++)
            if (input_list[i+1] < input_list[i]) {
            int tmp = input_list[i+1];
            input_list[i+1] = input_list[i];
            input_list[i] = tmp;
            }
        // for (int i = 0; i < input_list.size(); i++) cout << " " << input_list[i];
        // cout << endl;
    }
    return input_list;
}

int Sorted_Test(vector<int> input_list) {
    for (int i = 0; i < input_list.size() - 1; i++) {
        if ( ! (input_list[i] <= input_list[i+1]) ) return 0;
    }
    return 1;
}

vector<int> makelist(int test = 0, int list_size = 10) {
    if (!test) {
        string sub_select[2];
        int isub_select;
        system("clear");
        cout << "\t----\tA2E\t----\n";
        cout << "\nChoose list create method from list below:\n\n";
        cout << "1. Generate random\n2. Input manually\n";
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
            for (int i = 0; i < isub_select; i++) {
                list_[i] = rand() % 101;
            }
        } else if (sub_select[0] == "2")
            for (int i = 0; i < isub_select ;i++) {
                cout << "Input number at index " << i << ": "; 
                cin >> list_[i];
            } else cout << "Incorrect input\n";
        return list_;
    } else {
        vector<int> list_(list_size);
        for (int i = 0; i < list_size; i++) list_[i] = rand() % 101;
        return list_;
    }
}

int interface(int len, string methods[]) {
    string option;
    system("clear");
    cout << "\t----\tA2E\t----\n";
    cout << "\nChoose sort method from list below: ( add \"t\" at start to test method )\n\n";
    for (int i = 0; i < len; i++) {
        cout << i+1 << ". " << methods[i] << endl;
    }
    cout << "\nMethod to use (default: 1) : ";
    getline(cin, option);

    if (option.empty()) option = "1";

    auto sort_function = Sort_Select;
    vector<int> list_ = {1, 2, 3};

    if (option[0] == 't') {
        int iter;
        int list_size;
        int err = 0;
    
        cout << "\n\nInput number of iterations: "; cin >> iter;
        cout << "Input lists size: "; cin >> list_size;
        system("clear");
        if (option[1] == '1') sort_function = Sort_Select;
        else if (option[1] == '2') sort_function = Sort_Paste;
        else if (option[1] == '3') sort_function = Sort_Bubble;
        else {
            cout << "incorrect method number\n";
            return 0;
        }

        auto start = high_resolution_clock::now();

        for (int i = 1; i <= iter; i++) {
            list_ = makelist(1, list_size);
            list_ = sort_function(list_);
            int is_sorted = Sorted_Test(list_);
            cout << "Test " << i << ": " << (is_sorted ? "[ \033[1;32mOK\033[0m ]" : "[ \033[1;31mBAD\033[0m ]") << endl;
            if (!is_sorted) {
                err++;
                cout << "[ ";
                for (int j = 0; j < list_size; j++) cout << list_[j] << " ";
                cout << "]\n";
            }
        }

        cout << "\nBAD count: " << err << "/" << iter << endl; 
        cout << ((err > 0) ? ( (err < 100) ? "Some is \033[1;33mNOT OK\033[0m" : "All is \033[1;31mBAD\033[0m" ) : "All is \033[1;32mOK\033[0m") << endl;

        auto stop = high_resolution_clock::now();
        float duration = duration_cast<microseconds>(stop - start).count();
        cout << duration / 1000000 << " seconds" << endl;

    } else {

        list_ = makelist();
        system("clear");
        cout << "\t----\tA2E\t----\n";

        if (option[0] == '1') {
            cout << "\nSort Select\n";
            sort_function = Sort_Select;

        } else if (option[0] == '2') {
            cout << "\nSort Paste\n";
            sort_function = Sort_Paste;
            
        } else if (option[0] == '3') {
            cout << "\nSort Bubble\n";
            sort_function = Sort_Bubble;

        } else {
            cout << "incorrect method number\n";
            return 0;
        }

        cout << "\nInput list:";
        for (int i = 0; i < list_.size(); i++) cout << " " << list_[i];
        list_ = sort_function(list_);
        cout << "\nOutput list:";
        for (int i = 0; i < list_.size(); i++) cout << " " << list_[i];
        cout << endl;
    }
    return 0;
}

int main() {
    string methods[] = {"Sort Select", "Sort Paste", "Sort Bubble"};
    interface((sizeof(methods)/sizeof(*methods)), methods);
    return 0;
}