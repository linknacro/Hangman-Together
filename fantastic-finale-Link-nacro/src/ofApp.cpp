#include "ofApp.h"
#include <algorithm>
#include <iostream>
#include <string>

//--------------------------------------------------------------
void ofApp::setup() {
    if (current_state_ == START) {
        screen_width_ = 1920;
        screen_height_ = 1080;

        ofSetWindowPosition(0, screen_height_ * 0.035);
        ofSetWindowShape(screen_width_, screen_height_ * 0.92);
        ofSetWindowTitle("Hangman126");
        ofBackground(167, 255, 145);
        title_.load("images/HangmanTitle.png");
        gallow_.load("images/HangmanGallow.png");
        message_.load("images/Message.png");
        tile_.load("images/Emptyletter.png");
        head_.load("images/Head.JPG");
        head_.resize(screen_width_ * 0.0521, screen_height_ * 0.1111);
        body_.load("images/Body.png");
        left_limb_.load("images/LeftLimb.png");
        right_limb_.load("images/RightLimb.png");
        cross_.load("images/Cross.png");
        cross_.resize(screen_width_ * 0.0208, screen_height_ * 0.037);
        win_message_.load("images/WinMessage.png");
        lose_message_.load("images/LoseMessage.png");
        restart_message_.load("images/RestartMessage.png");
        request_message_.load("images/RequestMessage.png");
        reminder_.load("images/Reminder.png");
        background_.load("sounds/bgm.mp3");
        background_.setLoop(true);
        background_.play();
        background_.setVolume(0.2);
        right_guess_.load("sounds/yes.mp3");
        wrong_guess_.load("sounds/oof.mp3");
        myfont_.load("fonts/bold.ttf", 32);

        ofImage letter;
        std::string path1 = "images/";
        std::string path2 = ".png";
        for (size_t i = 0; i < 26; i++) {
            letter.load(path1 + to_string(i) + path2);
            letters_.push_back(letter);
        }

        game_.pickWord();
        game_.calcLetters();
        answer_ = game_.getCurrentWord();
        letters_in_word_ = game_.getLetters();
        std::transform(answer_.begin(), answer_.end(), answer_.begin(),
                       ::toupper);
        int xPos = screen_width_ * 0.3177;
        int yPos = screen_height_ * 0.8055;
        for (size_t i = 0; i < answer_.length(); i++) {
            Tile tile;
            tile.setIndex(i);
            tile.setXPos(xPos + screen_width_ * 0.0182);
            tile.setYPos(yPos - screen_height_ * 0.0324);
            tile.setLetter(answer_.at(i));
            tile.setLetterIndex(answer_.at(i));
            tile.setLetterImage(letters_.at(tile.getLetterIndex()));
            tiles_.push_back(tile);
            xPos += screen_width_ * 0.0469;
        }
    }
}

//--------------------------------------------------------------
void ofApp::update() {
    if (lives_ <= 0 || guessed_letters_.size() == letters_in_word_.size()) {
        current_state_ = FINISHED;
    }
    if (current_state_ == IN_PROGRESS && !game_.isSinglePlayer() &&
        !multi_setup_) {
        tiles_.clear();
        game_.clearLetters();
        game_.setCurrentWord(input_word_);
        game_.calcLetters();
        answer_ = game_.getCurrentWord();
        letters_in_word_ = game_.getLetters();
        std::transform(answer_.begin(), answer_.end(), answer_.begin(),
                       ::toupper);
        int xPos = screen_width_ * 0.3177;
        int yPos = screen_height_ * 0.8055;
        for (size_t i = 0; i < answer_.length(); i++) {
            Tile tile;
            tile.setIndex(i);
            tile.setXPos(xPos + screen_width_ * 0.0182);
            tile.setYPos(yPos - screen_height_ * 0.0324);
            tile.setLetter(answer_.at(i));
            tile.setLetterIndex(answer_.at(i));
            tile.setLetterImage(letters_.at(tile.getLetterIndex()));
            tiles_.push_back(tile);
            xPos += screen_width_ * 0.0469;
        }
        multi_setup_ = true;
    }
}

//--------------------------------------------------------------
void ofApp::draw() {
    title_.draw(screen_width_ * 0.3646, screen_height_ * 0.00926);

    if (current_state_ == START) {
        message_.draw(screen_width_ * 0.380, screen_height_ * 0.370);
    }

    if (current_state_ == SETUP) {
        request_message_.draw(screen_width_ * 0.260, screen_height_ * 0.370);
        for (size_t i = 0; i < input_tiles_.size(); i++) {
            input_tiles_.at(i).update(input_tiles_.at(i).getXPos(),
                                      input_tiles_.at(i).getYPos());
        }
    }

    if (current_state_ == IN_PROGRESS || current_state_ == FINISHED) {
        gallow_.draw(screen_width_ * 0.0521, screen_height_ * 0.25);
        if (lives_ == 5) {
            head_.draw(screen_width_ * 0.193, screen_height_ * 0.352);
        }
        if (lives_ == 4) {
            head_.draw(screen_width_ * 0.193, screen_height_ * 0.352);
            body_.draw(screen_width_ * 0.203, screen_height_ * 0.454);
        }
        if (lives_ == 3) {
            head_.draw(screen_width_ * 0.193, screen_height_ * 0.352);
            body_.draw(screen_width_ * 0.203, screen_height_ * 0.454);
            left_limb_.draw(screen_width_ * 0.146, screen_height_ * 0.4815);
        }
        if (lives_ == 2) {
            head_.draw(screen_width_ * 0.193, screen_height_ * 0.352);
            body_.draw(screen_width_ * 0.203, screen_height_ * 0.454);
            left_limb_.draw(screen_width_ * 0.146, screen_height_ * 0.4815);
            right_limb_.draw(screen_width_ * 0.219, screen_height_ * 0.4815);
        }
        if (lives_ == 1) {
            head_.draw(screen_width_ * 0.193, screen_height_ * 0.352);
            body_.draw(screen_width_ * 0.203, screen_height_ * 0.454);
            left_limb_.draw(screen_width_ * 0.146, screen_height_ * 0.4815);
            right_limb_.draw(screen_width_ * 0.219, screen_height_ * 0.4815);
            left_limb_.draw(screen_width_ * 0.151, screen_height_ * 0.5926);
        }
        if (lives_ == 0) {
            head_.draw(screen_width_ * 0.193, screen_height_ * 0.352);
            body_.draw(screen_width_ * 0.203, screen_height_ * 0.454);
            left_limb_.draw(screen_width_ * 0.146, screen_height_ * 0.4815);
            right_limb_.draw(screen_width_ * 0.219, screen_height_ * 0.4815);
            left_limb_.draw(screen_width_ * 0.151, screen_height_ * 0.5926);
            right_limb_.draw(screen_width_ * 0.214, screen_height_ * 0.5926);
            cross_.draw(screen_width_ * 0.203, screen_height_ * 0.38);
            cross_.draw(screen_width_ * 0.219, screen_height_ * 0.38);
        }

        reminder_.draw(screen_width_ * 0.4635, screen_height_ * 0.611);
        int miss_xPos = screen_width_ * 0.625;
        int miss_yPos = screen_height_ * 0.602;
        for (size_t i = 0; i < word_bank_.size(); i++) {
            word_bank_.at(i).update(miss_xPos, miss_yPos);
            miss_xPos += screen_width_ * 0.0469;
        }

        int xPos = screen_width_ * 0.3177;
        int yPos = screen_height_ * 0.8055;
        for (size_t i = 0; i < answer_.length(); i++) {
            tile_.draw(xPos, yPos);
            xPos += screen_width_ * 0.0469;
        }

        for (size_t i = 0; i < tiles_to_update_.size(); i++) {
            int idx = tiles_to_update_.at(i);
            tiles_.at(idx).update(tiles_.at(idx).getXPos(),
                                  tiles_.at(idx).getYPos());
        }
    }
    if (current_state_ == FINISHED) {
        if (lives_ <= 0) {
            lose_message_.draw(screen_width_ * 0.3646, screen_height_ * 0.463);
            ofSetColor(255, 0, 0, 255);
            myfont_.drawString("THE CORRECT ANSWER IS: " + answer_, screen_width_ * 0.458, screen_height_ * 0.7222);
            ofSetColor(255, 255, 255, 255);
        } else {
            win_message_.draw(screen_width_ * 0.3646, screen_height_ * 0.463);
        }
        restart_message_.draw(screen_width_ * 0.3646, screen_height_ * 0.5185);
    }
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key) {
    int upper_key = toupper(key);
    if (upper_key == 'Y' && current_state_ == START) {
        current_state_ = SETUP;
        game_.setSinglePlayer(false);
        return;
    } else if (upper_key == 'N' && current_state_ == START) {
        current_state_ = IN_PROGRESS;
        game_.setSinglePlayer(true);
    } else if (current_state_ == IN_PROGRESS) {
        Tile tile;
        tile.setLetterIndex(upper_key);
        if (tile.getLetterIndex() == -1) {
            return;
        }
        if (answer_.find(upper_key) != string::npos) {
            right_guess_.play();
            vector<char>::iterator itr;
            itr = std::find(guessed_letters_.begin(), guessed_letters_.end(),
                            upper_key);
            if (itr == guessed_letters_.end()) {
                guessed_letters_.push_back(upper_key);
                for (size_t i = 0; i < tiles_.size(); i++) {
                    if (upper_key == tiles_.at(i).getLetter()) {
                        tiles_to_update_.push_back(i);
                    }
                }
            }
        } else {
            wrong_guess_.play();
            vector<char>::iterator itr;
            itr = std::find(missed_letters_.begin(), missed_letters_.end(),
                            upper_key);
            if (itr == missed_letters_.end()) {
                lives_--;
                missed_letters_.push_back(upper_key);
                tile.setLetterImage(letters_.at(tile.getLetterIndex()));
                word_bank_.push_back(tile);
            }
        }
    }
    if (current_state_ == SETUP && key == OF_KEY_BACKSPACE) {
        if (input_ctr_ > 0) {
            input_tiles_.pop_back();
            input_ctr_--;
        }
    } else if (current_state_ == SETUP && key == OF_KEY_RETURN) {
        input_word_ = "";
        for (size_t i = 0; i < input_tiles_.size(); i++) {
            input_word_ += input_tiles_.at(i).getLetter();
        }
        current_state_ = IN_PROGRESS;
    } else if (current_state_ == SETUP) {
        int min_xPos = screen_width_ * 0.208;
        if (input_ctr_ < 14) {
            Tile tile;
            tile.setXPos(min_xPos + (screen_width_ * 0.0469 * input_ctr_));
            tile.setYPos(screen_height_ * 0.55555);
            tile.setLetterIndex(upper_key);
            tile.setLetter(upper_key);
            if (tile.getLetterIndex() == -1) {
                return;
			}
            tile.setLetterImage(letters_.at(tile.getLetterIndex()));
            input_tiles_.push_back(tile);
            input_ctr_++;
        }
    }
    if (current_state_ == FINISHED && upper_key == 'R') {
        word_bank_.clear();
        missed_letters_.clear();
        input_word_ = "";
        multi_setup_ = false;
        input_tiles_.clear();
        tiles_.clear();
        tiles_to_update_.clear();
        guessed_letters_.clear();
        letters_in_word_.clear();
        game_.clearLetters();
        lives_ = 6;
        input_ctr_ = 0;
        current_state_ = START;
        startGame();
    }
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key) {}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y) {}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button) {}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button) {}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button) {}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y) {}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y) {}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h) {}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg) {}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo) {}

void ofApp::startGame() {
    game_.pickWord();
    game_.calcLetters();
    answer_ = game_.getCurrentWord();
    letters_in_word_ = game_.getLetters();
    std::transform(answer_.begin(), answer_.end(), answer_.begin(), ::toupper);
    int xPos = 610;
    int yPos = 870;
    for (size_t i = 0; i < answer_.length(); i++) {
        Tile tile;
        tile.setIndex(i);
        tile.setXPos(xPos + 35);
        tile.setYPos(yPos - 35);
        tile.setLetter(answer_.at(i));
        tile.setLetterIndex(answer_.at(i));
        tile.setLetterImage(letters_.at(tile.getLetterIndex()));
        tiles_.push_back(tile);
        xPos += 90;
    }
}
