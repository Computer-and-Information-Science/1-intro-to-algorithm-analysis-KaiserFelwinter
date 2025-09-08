// Print all permutations of characters in a given string. Assumes, but does
// not verify, that all characters in the string are unique.
#include <iostream>
#include <string>
using namespace std;

 int call_count = 0; // global variable, :(

// Finds all permutations of the given string where the first *pos* characters
// are fixed (i.e. finds all permutations of characters in positions *pos* to
// the end of the string).
void permute (const string& str, size_t pos) {
	call_count++;

	string s1 = str.substr(0, pos);		// fixed part
	string s2 = str.substr(pos);		// variable part

	if (s2.size()) { // if there is a variable part
		for (size_t i = 0; i < s2.size(); i++) {
			permute(s1 + s2, pos + 1);
			s2 = s2.substr(1) + s2.substr(0, 1); // move first character to end
		}
	}
	else
		cout << s1 << endl; // no variable part, output the string
}

// Finds all permutations of the given string (assumes that all characters
// in the string are unique).
void permute (const string& str) {
	permute(str, 0);
}

int main () {
	string s;
	cout << "String: ";
	cin >> s;
	permute(s);
	cout << "Call count: " << call_count << endl;
}
