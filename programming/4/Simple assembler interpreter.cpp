#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <unordered_map>
#include <cassert>

using namespace std;

unordered_map<string, int> assembler(const vector<string>& program)
{
  unordered_map<string, int> result;
  for ( unsigned long i = 0; i < program.size(); i++ ) {
    vector<string> instruction;
    
    string word;
    stringstream ss(program[i]);
    
    while (getline(ss, word, ' ')) {
      instruction.push_back(word);        
    }
    switch(instruction.size()) {
      case 2:
        
        if (instruction[0] == "inc") result[instruction[1]]++;
        else result[instruction[1]]--;
        break;
        
      default:
        int y;

        if (isdigit(instruction[2][0]) || instruction[2][0] == '-') {    
            y = stoi(instruction[2]);
        }
        else y = result[instruction[2]];
        
        if (instruction[0] == "mov") result[instruction[1]] = y;
        else {
            int x;
            if (isdigit(instruction[1][0]) || instruction[1][0] == '-') {    
                x = stoi(instruction[1]);
            }
            else x = result[instruction[1]];
            i = (x != 0) ? i + y - 1 : i;
        }
    }
  }
  return result;
}

int main() {
    vector<string> program{ "mov a 5", "inc a", "dec a", "dec a", "jnz a -1", "inc a" };
    unordered_map<string, int> result = {{"a", 1}};
    assert(assembler(program) == result);
    cout << "Test \033[1;32mpassed\033[0m" << endl;
    return 0;
}