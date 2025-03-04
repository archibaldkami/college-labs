#include <iostream>
#include <cassert>
using namespace std;


string encrypt(string text, int n)
{
    for (int iter = 0; iter < n; iter++) {
        string result_str_1 = "";
        string result_str_2 = "";
        for (int i = 0; i < text.size(); i++) {
            if (i % 2) result_str_1 += text[i];
            else result_str_2 += text[i];
        }
        text = result_str_1 + result_str_2;
    }
    return text;
}

string decrypt(string encryptedText, int n)
{
    for (int iter = 0; iter < n; iter++) {        
        string result_str = "";
        for (int i = 0; i < (encryptedText.size() / 2 + encryptedText.size() % 2); i++) {
            result_str += encryptedText[i + encryptedText.size() / 2];
            if (i < encryptedText.size() / 2) result_str += encryptedText[i];
        }
        encryptedText = result_str;
    }
    return encryptedText;
}

int main() {
    assert(encrypt("This is a test!", 0) == "This is a test!");
    assert(encrypt("This is a test!", 1) == "hsi  etTi sats!");
    assert(encrypt("This is a test!", 2) == "s eT ashi tist!");
    assert(encrypt("This is a test!", 3) == " Tah itse sits!");
    assert(encrypt("This is a test!", 4) == "This is a test!");
    assert(encrypt("This is a test!", -1) == "This is a test!");
    assert(encrypt("This kata is very interesting!", 1) == "hskt svr neetn!Ti aai eyitrsig");

    // cout << decrypt("hsi  etTi sats!", 1) << endl;
    assert(decrypt("This is a test!", 0) == "This is a test!");
    assert(decrypt("hsi  etTi sats!", 1) == "This is a test!");
    assert(decrypt("s eT ashi tist!", 2) == "This is a test!");
    assert(decrypt(" Tah itse sits!", 3) == "This is a test!");
    assert(decrypt("This is a test!", 4) == "This is a test!");
    assert(decrypt("This is a test!", -1) == "This is a test!");
    assert(decrypt("hskt svr neetn!Ti aai eyitrsig", 1) == "This kata is very interesting!");

    assert(encrypt("", 0) == "");
    assert(encrypt("", 3) == "");
    assert(decrypt("", 0) == "");
    assert(decrypt("", 3) == "");

    cout << "All is \033[1;32mOK\033[0m" << endl;
    return 0;
}

