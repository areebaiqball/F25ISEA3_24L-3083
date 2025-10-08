#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include <ctime>
#include <cctype>
using namespace std;

/// <summary>
/// Counts the number of words in a text file.
/// </summary>
/// <param name="filename">The name of the file containing the list of words.</param>
/// <returns>The total number of words found in the file.</returns>
int countWordsInFile(const string& filename) {
    ifstream file(filename.c_str());
    int count = 0;
    string word;
    while (file >> word) {
        count++;
    }
    return count;
}

/// <summary>
/// Selects and returns a random word from the given file.
/// </summary>
/// <param name="filename">The name of the file containing a list of words.</param>
/// <returns>A randomly chosen word from the file or an empty string if no words are found.</returns>
string getRandomWord(const string& filename) {
    int wordCount = countWordsInFile(filename);
    if (wordCount == 0) {
        return ""; 
    }
    srand(time(0));
    int target = rand() % wordCount; 
    ifstream file(filename.c_str());
    string word;
    int index = 0;
    while (file >> word) {
        if (index == target) {
            return word;
        }
        index++;
    }
    return "";
}

/// <summary>
/// Displays the current progress of the guessed word with revealed letters and underscores.
/// </summary>
/// <param name="secret">The secret word to be guessed.</param>
/// <param name="guessed">A boolean array representing which letters (a–z) have been guessed.</param>
void displayWord(const string& secret, const bool guessed[]) {
    for (int i = 0; i < secret.length(); i++) {
        char c = tolower(secret[i]);
        if (guessed[c - 'a']) {
            cout << secret[i] << " ";
        }
        else {
            cout << "_ ";
        }
    }
    cout << endl;
}

/// <summary>
/// Checks whether the entire word has been successfully guessed.
/// </summary>
/// <param name="secret">The secret word being guessed.</param>
/// <param name="guessed">A boolean array representing which letters (a–z) have been guessed.</param>
/// <returns>True if the word is fully guessed and false otherwise.</returns>
bool isWordGuessed(const string& secret, const bool guessed[]) {
    for (int i = 0; i < secret.length(); i++) {
        char c = tolower(secret[i]);
        if (!guessed[c - 'a']) {
            return false;
        }
    }
    return true;
}

/// <summary>
/// Runs the Hangman game, allowing the user to guess letters until the word is found or mistakes run out.
/// </summary>
/// <param name="secretWord">The word the player has to guess.</param>
void playHangman(const string& secretWord) {
    bool guessed[26] = { false }; 
    int mistakes = 7;

    cout << "Welcome to Hangman!" << endl;

    while (mistakes > 0) {
        displayWord(secretWord, guessed);

        cout << "Enter a letter: ";
        char guess;
        cin >> guess;
        guess = tolower(guess);

        if (!isalpha(guess)) {
            cout << "Invalid input. Enter only letters." << endl;
            continue;
        }

        int idx = guess - 'a';

        if (guessed[idx]) {
            cout << "You already guessed '" << guess << "'. Try another letter." << endl;
            continue;
        }

        guessed[idx] = true;

        bool found = false;
        for (int i = 0; i < secretWord.length(); i++) {
            char c = tolower(secretWord[i]);
            if (c == guess) {
                found = true;
                break;
            }
        }

        if (found) {
            cout << "Correct!" << endl;
        }
        else {
            mistakes--;
            cout << "Wrong! Remaining mistakes: " << mistakes << endl;
        }

        if (isWordGuessed(secretWord, guessed)) {
            cout << "Congratulations! You guessed the word: " << secretWord << endl;
            return;
        }
    }

    cout << "Game Over! The word was: " << secretWord << endl;
}
/// <summary>
/// Entry point of the program. Loads a random word from file and starts the Hangman game.
/// </summary>
/// <returns>0 if execution is successful and 1 if no words are found in the file.</returns>
int main() {
    string filename = "24L-3083_Question_2.txt";
    string secretWord = getRandomWord(filename);

    if (secretWord.empty()) {
        cout << "No words found in file!" << endl;
        return 1;
    }

    playHangman(secretWord);
}
