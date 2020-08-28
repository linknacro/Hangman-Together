#include "hangman.h"

// getters
bool Hangman::isSinglePlayer() { return single_player_; }
vector<std::string> Hangman::getWordBase() { return word_base_; }
vector<char> Hangman::getLetters() { return letters_; }
std::string Hangman::getCurrentWord() { return current_word_; }
int Hangman::getLength() { return length_; }

// setters
void Hangman::setSinglePlayer(bool value) { single_player_ = value; }
void Hangman::setCurrentWord(std::string word) { current_word_ = word; }
void Hangman::setLength(int size) { length_ = size; }

void Hangman::pickWord() { 
	int base_size = word_base_.size();
    srand(time(0));
    int index = (rand() % base_size);
    current_word_ = word_base_.at(index);
    length_ = current_word_.length();
}

void Hangman::calcLetters() {
    vector<char>::iterator itr;
    for (size_t i = 0; i < current_word_.length(); i++) {
        char letter = current_word_.at(i);
        itr = std::find(letters_.begin(), letters_.end(), letter);
        if (itr == letters_.end()) {
            letters_.push_back(letter);
		}
    }
}

void Hangman::clearLetters() { letters_.clear(); }