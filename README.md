# Hangman 126

## Description
This is a hangman game with two game modes. 
- In the single player mode, the player plays the classic hangman game with a word randomly chosen from the word bank. 
- In the multiplayer mode, one player types in the word, and the other player will guess that word. The player has 6 guesses for each word.

At the end of each game, the player can reset the game and choose game mode again. All the required instructions are provided in the game.

## How to run the game
Ideally, you should have Visual Studio 2017 build tools and run this game on Visual Studio 2019, because I know that this works for sure. 
The game might work on Xcode, but I cannot guarantee the outcome.
- All image files are stored in the file **game images**
- All audio files are stored in the file **sounds**

Since C++ can only recognize full file paths, the user will need to change the file paths in "ofApp.cpp"

Detailed instructions:
1. Go to file "ofApp.cpp"
2. Under ofApp::setup(), find the spots where the images are loaded
3. Change the parameter in .load() method to your own full local file path
  
