#include <iostream>
#include <string>
using namespace std;

void dec_to_8bit(int num) {
	if (num < 128 && num > -1) { // ASCII uses 7-bit numbers
		
		// Store binary
		int binary[8];
		for (int i = 7; i >= 0; i--) {
			binary[i] = num % 2;
			num = num / 2;
		}

		// Output binary
		cout << "8-bit Binary: ";
		for (int i = 0; i < 8; i++) {
			cout << binary[i];
		}
		cout << endl;

	} else {
		cout << "Invalid number: " << num << endl;
	}
}

int _8bit_to_dec(int num[8]) {
	int iter = 1;
	int result = 0;
	for (int i = 7; i >= 0; i--) {
		if (num[i]) result += iter;
		iter *= 2;
	}
	return result;
}

void dec_to_6bit(int num) {
	if (num < 128 && num > -1) {
		
		// Store binary
		int binary[6];
		for (int i = 5; i >= 0; i--) {
			binary[i] = num % 2;
			num = num / 2;
		}

		// Output binary
		cout << "6-bit Binary: ";
		for (int i = 0; i < 6; i++) {
			cout << binary[i];
		}
		cout << endl;

	} else {
		cout << "Invalid number: " << num << endl;
	}
}

int _6bit_to_dec(int num[6]) {
	int iter = 1;
	int result = 0;
	for (int i = 5; i >= 0; i--) {
		if (num[i]) result += iter;
		iter *= 2;
	}
	return result;
}

void base_encode(string input_string) {
	
	char base64_dictionary[64] = {
    'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H',
    'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P',
    'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X',
    'Y', 'Z', 'a', 'b', 'c', 'd', 'e', 'f',
    'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n',
    'o', 'p', 'q', 'r', 's', 't', 'u', 'v',
    'w', 'x', 'y', 'z', '0', '1', '2', '3',
    '4', '5', '6', '7', '8', '9', '+', '/'
};

	cout << "Input TEXT: " << input_string << endl;
	cout << "ASCII: ";

	// Store ASCII number
	int ascii[input_string.length()];
	for (int i = 0; i < input_string.length(); i++) {
		ascii[i] = int(input_string[i]);
		cout << ascii[i] << " ";
	}
	cout << endl;

	int padding =  (input_string.length() % 3) ? (6 - input_string.length() % 3 * 2) : 0;

	// Store binary
	int binary[input_string.length() * 8 + padding];
	for (int number = 0; number < input_string.length(); number++) {
		for (int i = 7; i >= 0; i--) {
			binary[i + number * 8] = ascii[number] % 2;
			ascii[number] = ascii[number] / 2;
		}

		// Output each 8-bit binary
		for (int i = 0; i < 8; i++) {
			cout << binary[i + number * 8];
		}
		cout << endl;
	}
	
	// Insert padding
	for (int i = 0; i < padding; i++) {
		binary[input_string.length() * 8 + i] = 0;
		cout << binary[input_string.length() * 8 + i];
	}
	cout << endl << endl;

	int result;
	int iter;

	cout << "Output base64: ";
	for (int number = 0; number < (input_string.length() * 8 + padding) / 6; number++) {
		iter = 1;
		result = 0;
		for (int i = 5; i >= 0; i--) {
			if (binary[i + number * 6]) result += iter;
			iter *= 2;
		}
		cout << base64_dictionary[result];
	}
	for (int i = 0; i < padding / 2; i++) {
		cout << "=";
	}
	cout << endl;
};

void base_decode(string input_string) {
	
	char base64_dictionary[64] = {
    'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H',
    'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P',
    'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X',
    'Y', 'Z', 'a', 'b', 'c', 'd', 'e', 'f',
    'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n',
    'o', 'p', 'q', 'r', 's', 't', 'u', 'v',
    'w', 'x', 'y', 'z', '0', '1', '2', '3',
    '4', '5', '6', '7', '8', '9', '+', '/'
	};

	cout << "Input base64: " << input_string << endl;

	// Get len without padding
	int len_without_padding = 0;
	string temp_letter = "=";
	for (int letter = 0; letter < input_string.length(); letter++) {
		// temp_letter = input_string[letter];
		// cout << temp_letter << " " << temp_letter != "=" << endl;
		if (input_string[letter] != temp_letter[0]) len_without_padding++;
	}
	// cout << "Length: " << len_without_padding << endl;

	// int base64_string[len_without_padding];
	int binary[len_without_padding * 6];

	// Get binary
	for (int letter = 0; letter < len_without_padding; letter++) {
		// cout << endl << "Length: " << len_without_padding << endl;
		for (int i = 0; i < 64; i++) {
			if (input_string[letter] == base64_dictionary[i]) {
				cout << endl;
				for (int iter = 5; iter >= 0; iter--) {
					binary[iter + letter * 6] = i % 2;
					i = i / 2;
				}
				for (int iter = 0; iter < 6; iter++) cout << binary[iter + letter * 6];
				break;
			}
		}
	}
	cout << endl << endl << "Output TEXT: ";
	int iter;
	for (int bin = 0; bin < (len_without_padding * 6) / 8; bin++) {
		iter = 1;
		int result[(len_without_padding * 6) / 8];
		result[bin] = 0;
		for (int i = 7; i >= 0; i--) {
			if (binary[i + bin * 8]) result[bin] += iter;
			iter *= 2;
		}
		cout << char(result[bin]);
	}
	cout << endl;
};

int main() {
	// string text = "Hello";
	string text = "Lorem ipsum";
	// string base64_text = "SGVsbG8=";
	string base64_text = "TG9yZW0gaXBzdW0=";
	// int _8bit[8] = {0, 0, 0, 0, 1, 0, 1, 0};
	int _8bit[8] = {1, 1, 1, 1, 1, 1, 1, 1};
	int _6bit[6] = {0, 0, 1, 0, 1, 0};
	// int _6bit[6] = {1, 1, 1, 1, 1, 1};

	dec_to_8bit(10);
	cout << "8-bit Number: " << _8bit_to_dec(_8bit) << endl;
	dec_to_6bit(10);
	cout << "6-bit Number: " << _6bit_to_dec(_6bit) << endl << endl;

	base_encode(text);
	base_decode(base64_text);
	return 0;
}