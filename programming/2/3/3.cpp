using namespace std;

string my_first_interpreter(const string& code)
{
    unsigned char temp_char = char(0);
    string result = "";
    for (unsigned int i = 0; i < code.size(); i++) {
        if (code[i] == '+') temp_char++;
        else if (code[i] == '.') result += temp_char;
    }
    return result;
}
