#include "ladder.h"
// #define my_assert(e) {cout << #e << ((e) ? " passed": " failed") << endl;}
using namespace std;

void error(string word1, string word2, string msg){
    cout << "This word: " << word1 << "and this other word: " << word2 << "has the following error: " << msg;
}

void load_words(set<string> & word_list, const string& file_name){
    std::ifstream file(file_name);
    string word;


    while (file >> word){
        word_list.insert(word);
    }

    file.close();
}

void print_word_ladder(const vector<string>& ladder){
    for (int i = 0; i < ladder.size(); ++i){
        cout << ladder[i] << " ";
    }
}

bool is_adjacent(const string& word1, const string& word2){
    int diff = 0;
    //Same length
    if (word1.size() == word2.size() ){
        for (int i = 0; i < word1.size() && diff <= 1; ++i){
        if (word1[i] != word2[i]){
            ++diff;
            if (diff > 1)
            return false;
        }
    }
    return diff == 1;
    }
    else{
        return edit_distance_within(word1, word2, 1);
    }
    return false;
}

bool edit_distance_within(const std::string& str1, const std::string& str2, int d){
    //Length d which I'm assuming is hardcode 1;
    const string& shorter_word = "";
    const string& longer_word = str2;
    if (abs(int(str1.size() - str2.size())) == d){
        if (str1.size() < str2.size()){
            const string& shorter_word = str1;
            const string& longer_word = str2;
        }
        else{
            const string& shorter_word = str2;
            const string& longer_word = str1;
        }

        int mistmatch_count = 0;
        int i = 0; int j = 0;
        while (i < shorter_word.size() && j < longer_word.size()){
            if (mistmatch_count > d) return false;
            if (shorter_word[i] != longer_word[i]){
                mistmatch_count = true;
                ++j;
            }
            else{
                ++i;
                ++j;
            }
        }
        return true;
    }
    return false;
}
// void verify_word_ladder() {

//     set<string> word_list;

//     load_words(word_list, "words.txt");

//     my_assert(generate_word_ladder("cat", "dog", word_list).size() == 4);

//     my_assert(generate_word_ladder("marty", "curls", word_list).size() == 6);

//     my_assert(generate_word_ladder("code", "data", word_list).size() == 6);

//     my_assert(generate_word_ladder("work", "play", word_list).size() == 6);

//     my_assert(generate_word_ladder("sleep", "awake", word_list).size() == 8);

//     my_assert(generate_word_ladder("car", "cheat", word_list).size() == 4);

// }