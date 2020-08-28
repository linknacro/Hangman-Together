#include "ofMain.h"
#include <vector>
#include <ctime>
#include <cstdlib>
#pragma once

class Hangman {
	
	private:
		bool single_player_;
		vector<std::string> word_base_{
			"polymorphism", "cryptography", "cybersecurity", "hackathon",
			"internship",   "javascript",  "debug", "dynamic", "easy", "programmer",
			"hardware", "software", "memory", "imperative"};
        vector<char> letters_;
		std::string current_word_;
        int length_;

	public:
        Hangman() = default;
		
		// getters
		bool isSinglePlayer();
        vector<std::string> getWordBase();
		vector<char> getLetters();
        std::string getCurrentWord();
        int getLength();

		// setters
        void setSinglePlayer(bool value);
        void setCurrentWord(std::string word);
        void setLength(int size);

		// other functions
		void pickWord();
        void calcLetters();
		void clearLetters();
};