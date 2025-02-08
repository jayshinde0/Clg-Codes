#include <iostream>
#include <string>
using namespace std;

string removeWhiteSpaces(string str) {
    string result = "";
    for (char c : str) {
        if (c != ' ') {
            result += c;
        }
    }
    return result;
}

int main() {
    string str;
    cout << "Enter a sentence: ";
    getline(cin, str);
    cout << "Sentence without spaces: " << removeWhiteSpaces(str) << endl;
    return 0;
}
