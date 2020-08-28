#include "tile.h"

// getters
int Tile::getXPos() { return xPos_; }
int Tile::getYPos() { return yPos_; }
int Tile::getIndex() { return index_; }
char Tile::getLetter() { return letter_; }
int Tile::getLetterIndex() { return letter_index_; }
ofImage Tile::getLetterImage() { return letter_image_; }

// setters
void Tile::setXPos(int newX) { xPos_ = newX; }
void Tile::setYPos(int newY) { yPos_ = newY; }
void Tile::setIndex(int new_index) { index_ = new_index; }
void Tile::setLetter(char the_new_letter) { letter_ = the_new_letter; }
void Tile::setLetterIndex(char new_letter) {
    if (new_letter == 'A') {
        letter_index_ = 0;
    }
    if (new_letter == 'B') {
        letter_index_ = 1;
    }
    if (new_letter == 'C') {
        letter_index_ = 2;
    }
    if (new_letter == 'D') {
        letter_index_ = 3;
    }
    if (new_letter == 'E') {
        letter_index_ = 4;
    }
    if (new_letter == 'F') {
        letter_index_ = 5;
    }
    if (new_letter == 'G') {
        letter_index_ = 6;
    }
    if (new_letter == 'H') {
        letter_index_ = 7;
    }
    if (new_letter == 'I') {
        letter_index_ = 8;
    }
    if (new_letter == 'J') {
        letter_index_ = 9;
    }
    if (new_letter == 'K') {
        letter_index_ = 10;
    }
    if (new_letter == 'L') {
        letter_index_ = 11;
    }
    if (new_letter == 'M') {
        letter_index_ = 12;
    }
    if (new_letter == 'N') {
        letter_index_ = 13;
    }
    if (new_letter == 'O') {
        letter_index_ = 14;
    }
    if (new_letter == 'P') {
        letter_index_ = 15;
    }
    if (new_letter == 'Q') {
        letter_index_ = 16;
    }
    if (new_letter == 'R') {
        letter_index_ = 17;
    }
    if (new_letter == 'S') {
        letter_index_ = 18;
    }
    if (new_letter == 'T') {
        letter_index_ = 19;
    }
    if (new_letter == 'U') {
        letter_index_ = 20;
    }
    if (new_letter == 'V') {
        letter_index_ = 21;
    }
    if (new_letter == 'W') {
        letter_index_ = 22;
    }
    if (new_letter == 'X') {
        letter_index_ = 23;
    }
    if (new_letter == 'Y') {
        letter_index_ = 24;
    }
    if (new_letter == 'Z') {
        letter_index_ = 25;
    }
}

void Tile::setLetterImage(ofImage image) { letter_image_ = image; }

void Tile::update(int xPos, int yPos) { 
	letter_image_.draw(xPos, yPos);
}