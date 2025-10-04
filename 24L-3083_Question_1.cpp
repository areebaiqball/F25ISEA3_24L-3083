#include <iostream>
#include <string>
#include <conio.h>
#include <cctype>   
using namespace std;

/// <summary>
/// Convert input string to lowercase 
/// </summary>
string generalizedInput(const string& str) {
    string generalized = "";
    for (char c : str) {
        generalized += tolower(c);
    }
    return generalized;
}

/// <summary>
/// Check if a string is a palindrome
/// </summary>
bool isPalindrome(const string& str) {
    int left = 0;
    int right = str.length() - 1;
    while (left < right) {
        if (str[left] != str[right]) {
            return false;
        }
        left++;
        right--;
    }
    return true;
}

/// <summary>
/// Get input from user
/// </summary>
string getInput() {
    string input;
    cout << "Enter a word: ";
    cin >> input;
    return input;
}

/// <summary>
/// Display result of palindrome check
/// </summary>
void checkPalindrome(const string& input) {
    string generalInput = generalizedInput(input);
    if (isPalindrome(generalInput)) {
        cout << "Palindrome" << endl;
    }
    else {
        cout << "Not Palindrome" << endl;
    }
}

/// <summary>
/// Process one complete input cycle
/// </summary>
void processInput() {
    string input = getInput();
    checkPalindrome(input);
}

int main() {
    cout << "Press any key to continue or ESC to exit" << endl;
    while (true) {
        char ch = _getch();   
        if (ch == 27) {       // ESC key
            cout << "Program Terminated" << endl;
            break;
        }
        processInput();
    }
}
