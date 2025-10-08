#include <iostream>
#include <string>
#include <conio.h>
#include <cctype>   
using namespace std;

/// <summary>
/// Converts the given string to lowercase for case-insensitive comparison.
/// </summary>
/// <param name="str">The input string entered by the user.</param>
/// <returns>A new string converted entirely to lowercase.</returns>
string generalizedInput(const string& str) {
    string generalized = "";
    for (char c : str) {
        generalized += tolower(c);
    }
    return generalized;
}

/// <summary>
/// Checks whether the given string is a palindrome or not.
/// </summary>
/// <param name="str">The string to be checked.</param>
/// <returns>True if the string is a palindrome and false otherwise.</returns>
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
/// Prompts the user to enter a word and retrieves the input.
/// </summary>
/// <returns>The word entered by the user.</returns>
string getInput() {
    string input;
    cout << "Enter a word: ";
    cin >> input;
    return input;
}

/// <summary>
/// Determines and displays whether the provided word is a palindrome.
/// </summary>
/// <param name="input">The user-entered word to be checked.</param>
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
/// Handles one complete palindrome checking cycle, gets input and displays result.
/// </summary>
void processInput() {
    string input = getInput();
    checkPalindrome(input);
}

/// <summary>
/// Main function to repeatedly process user input until ESC key is pressed.
/// </summary>
int main() {
    while (true) {
        cout << "Press any key to continue or ESC to exit" << endl;
        char ch = _getch();
        if (ch == 27) { // ESC key
            cout << "Program Terminated" << endl;
            break;
        }
        processInput();
    }
}
