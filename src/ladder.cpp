#include "ladder.h"
#define my_assert(e) {cout << #e << ((e) ? " passed": " failed") << endl;}
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
    cout << endl;
}

bool is_adjacent(const string& word1, const string& word2){
    int diff_count = 0;
    //Same length
    if (word1.size() == word2.size() ){
        for (int i = 0; i < word1.size() && diff_count <= 1; ++i){
        if (word1[i] != word2[i]){
            ++diff_count;
            if (diff_count > 1)
            return false;
        }
    }
    return diff_count <= 1;
    }
    else{
        return edit_distance_within(word1, word2, 1);
    }
    return false;
}

bool edit_distance_within(const std::string& str1, const std::string& str2, int d){
    //Length d which I'm assuming is hardcode 1;
    const string& short_word = str1.size() < str2.size() ? str1 : str2;
    const string& long_word = str1.size() < str2.size() ? str2 : str1;

    if (abs(int(str1.size() - str2.size())) == d) {
        int mismatch_counter = 0;
        int i = 0; int j = 0;
        while (i < short_word.size() && j < long_word.size()){
            if (mismatch_counter > d) return false;
            if (short_word[i] != long_word[j]){
                ++mismatch_counter;
                ++j;
            }
            else{
                ++i;
                ++j;
            }
        }
        return mismatch_counter <= d;
    }
    return false;
}

vector<string> generate_word_ladder(const string& begin_word, const string& end_word, const set<string>& word_list){
    std::queue<std::vector<std::string>> ladder_queue;
    ladder_queue.push({begin_word});
    set<string> visited;
    visited.insert(begin_word);

    while (!ladder_queue.empty()){
        vector<string> ladder = ladder_queue.front();
        ladder_queue.pop();
        string last_word = ladder.back();

        for (auto word: word_list){
            if (is_adjacent(last_word, word)){
                if (visited.find(word) == visited.end()){
                    visited.insert(word);
                    vector<string> new_ladder = ladder;
                    new_ladder.push_back(word);
                    if (word == end_word){
                        return new_ladder;
                    }
                    ladder_queue.push(new_ladder);
                }
            }
        }
    }

    return {"No word ladder found."};
}


void verify_word_ladder() {

    set<string> word_list;

    load_words(word_list, "src/words.txt");

    my_assert(generate_word_ladder("cat", "dog", word_list).size() == 4);

    my_assert(generate_word_ladder("marty", "curls", word_list).size() == 6);

    my_assert(generate_word_ladder("code", "data", word_list).size() == 6);

    my_assert(generate_word_ladder("work", "play", word_list).size() == 6);

    my_assert(generate_word_ladder("sleep", "awake", word_list).size() == 8);

    my_assert(generate_word_ladder("car", "cheat", word_list).size() == 4);

}