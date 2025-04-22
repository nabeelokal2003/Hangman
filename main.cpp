#include <iostream>
#include <vector>
using namespace std;

string selectRandWord();
vector<char> fillTheBlanks(vector<char> text);
void playerGuess(vector<char> wordTarget);

int main() {
    // PLayer's lives
    // short lives = 10;

    cout << "Welcome to Hangman Game!" << endl;

    string word = selectRandWord();

    // Converting from word into characters
    vector<char> chosen_word(word.begin(), word.end());

    // Fill the blanks
    vector<char> blanks = fillTheBlanks(chosen_word);
    while (true) {
        for (char blank: blanks)
            cout << blank << " ";
        cout << endl;
        playerGuess(blanks);
    }

    return 0;
}

string selectRandWord() {
    srand(time(0));
    int r = rand() % 10;
    vector<string> words = {"Horizon", "Thunder", "Puzzle",
                            "Volcano", "Whisper", "Kingdom",
                            "Lantern", "Oxygen", "Freedom"};
    return words[r];
}

vector<char> fillTheBlanks(vector<char> text) {
    int len = text.size();
    vector<char> blanks {};
    for (int i = 0; i < len; i++) {
        blanks.push_back('_');
    }
    return blanks;
}

void playerGuess(vector<char> wordTarget) {
    char guess {};
    cout << "Enter your guess: ";
    cin >> guess;

    for (int i = 0; i < wordTarget.size(); i++) {
        if (guess == wordTarget[i]) {
            cout << "Correct!" << endl;
            wordTarget.push_back(guess);
        }else {
            cout << "Incorrect!" << endl;
        }
    }

}