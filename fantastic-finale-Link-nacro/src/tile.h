#include "ofMain.h"
#pragma once

class Tile {
   private:
    int xPos_;
    int yPos_;
    int index_;
    char letter_;
    int letter_index_ = -1;
    ofImage letter_image_;

   public:
    Tile() = default;

    // getters
    int getXPos();
    int getYPos();
    int getIndex();
    char getLetter();
    int getLetterIndex();
    ofImage getLetterImage();

    // setters
    void setXPos(int newX);
    void setYPos(int newY);
    void setIndex(int new_index);
    void setLetter(char the_new_letter);
    void setLetterIndex(char new_letter);
    void setLetterImage(ofImage image);

	// other functions
    void update(int xPos, int yPos);
};