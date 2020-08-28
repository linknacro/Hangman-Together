#pragma once

#include "ofMain.h"
#include "hangman.h"
#include "tile.h"

enum GameState { START = 0, SETUP, IN_PROGRESS, FINISHED };
class ofApp : public ofBaseApp{

	private:
		GameState current_state_ = START;
		Hangman game_;
        std::string answer_;
        int lives_ = 6;
        ofImage title_;
        ofImage gallow_;
        ofImage message_;
        ofImage tile_;
        ofImage head_;
        ofImage body_;
        ofImage left_limb_;
        ofImage right_limb_;
        ofImage cross_;
        ofImage win_message_;
        ofImage lose_message_;
        ofImage restart_message_;
        ofImage request_message_;
        ofImage reminder_;
        vector<ofImage> letters_;
        vector<Tile> tiles_;
        vector<int> tiles_to_update_;
        vector<char> letters_in_word_;
        vector<char> guessed_letters_;
        vector<Tile> input_tiles_;
        std::string input_word_;
        int input_ctr_ = 0;
        bool multi_setup_ = false;
        vector<Tile> word_bank_;
        vector<char> missed_letters_;
        ofSoundPlayer background_;
        ofSoundPlayer right_guess_;
        ofSoundPlayer wrong_guess_;
        ofTrueTypeFont myfont_;

		int screen_width_;
        int screen_height_;

        void startGame();

	public:
		void setup();
		void update();
		void draw();
		void keyPressed(int key);
		void keyReleased(int key);
		void mouseMoved(int x, int y );
		void mouseDragged(int x, int y, int button);
		void mousePressed(int x, int y, int button);
		void mouseReleased(int x, int y, int button);
		void mouseEntered(int x, int y);
		void mouseExited(int x, int y);
		void windowResized(int w, int h);
		void dragEvent(ofDragInfo dragInfo);
		void gotMessage(ofMessage msg);
};
