#include <iostream>
#include <cstdlib>
#include <vector>
using namespace std;

string selectRandWord();

int main() {
    // PLayer's lives
    short lives = 10;
    cout << "Welcome to Hangman Game!" << endl;

    string word = selectRandWord();

    // Converting from word into characters

    vector<char> chosen_word {};
    for (int i = 0; i < word.size(); i++) {
        chosen_word.push_back(word[i]);
    }

    cout << "Chosen word: ";
    for (char i: chosen_word) cout << i;
    return 0;
}

string selectRandWord() {
    srand(time(0));
    int r = rand() % 10;
    vector<string> words {"Horizon", "Thunder", "Puzzle",
                            "Volcano", "Whisper", "Kingdom",
                            "Lantern", "Oxygen", "Freedom"};
    return words[r];
}