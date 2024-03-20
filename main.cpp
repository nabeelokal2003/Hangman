#include <iostream>
#include <cstdlib>
#include <vector>
using namespace std;

string select_word();
vector<char> get_characters(string ex);
void player_guess(char choice, vector<char> check_vec);
vector<char> fill_vec();
vector<char> fill_vec_for_blanks(int size);
bool check_win(vector<char> blanks);

int main() {
    // Fill in the characters using random words.
    vector<char> word {fill_vec()};
    int count {0};
    for(int i{0}; i < word.size(); i++) { count += 1; }
    vector<char> blanks {fill_vec_for_blanks(count)};

    for(char i: blanks) { cout << i << " ";};

        int i {0};
        while (i < blanks.size()) {
            char choice{};
            cout << "\nEnter your choice: ";
            cin >> choice;
            if (word[i] == choice) {
                cout << "\nCorrect!\n";
                blanks[i] = choice;
                for (int i{0}; i < blanks.size(); i++)
                    cout << blanks[i] << " ";
            } else {
                cout << "Incorrect!\n";
                for (int i{0}; i < blanks.size(); i++)
                    cout << blanks[i] << " ";
            }
            i++;
//            for (int i{0}; i < blanks.size(); i++)
//                cout << blanks[i] << " ";
        }
//        if (check_win(blanks)) {
//            cout << "Congrats!! you guessed it.";
//            break;
//        }
    return 0;
}
string select_word() {
    vector<string> list_words {"Sunshine", "Bicycle", "Adventure", "Symphony", "Pineapple",
                             "Bed", "Electronics", "Jacket", "Wall", "Perfume"};

    srand(time(0));
    int choice = rand() % 10;

    return list_words.at(choice);
}

vector<char> get_characters(string ex){
    vector<char> word {};
    for(int i{0}; i < ex.size(); i++){
        word.push_back(ex[i]);
    }
    return word;
}

void player_guess(char choice, vector<char> check_vec){
    for(int i {0}; i < check_vec.size(); i++){
        if(check_vec.at(i) == choice){
            cout << "\nCorrect!\n";
            cout << choice;
            check_vec[i] = choice;
        }
        if(check_vec.at(i) != choice){
            cout << " _ ";
        }
    }
}

vector<char> fill_vec(){
    vector<char> word {};
    string rand_word {select_word()};
    for(int i{0}; i < rand_word.size(); i++){
        word.push_back(rand_word[i]);
    }
    return word;
}

vector<char> fill_vec_for_blanks(int size){
    vector<char> num_of_blanks {};
    for(int i{0}; i < size; i++){
        num_of_blanks.push_back('_');
    }
    return num_of_blanks;
}

bool check_win(vector<char> blanks){
    // if the characters of the blanks are all != underscores
    for(int i{0}; i < blanks.size(); i++){
        if (blanks[i] == '_'){
            return false;
        }
    }
    return true;
}