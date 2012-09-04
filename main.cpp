#include <iostream>
#include <vector>
#include <sstream>
#include "game.h"
#include "utilities.h"
using namespace std;

int main()
{
  Game myGame;
  myGame.DrawBoard();

  //vector<string> bar;
  //bar.push_back("a");
  //bar.push_back("b");
  //bar.push_back("c");
  //bar.push_back("d");
  //bar.push_back("e");
  //bar.push_back("f");
  //bar.push_back("g");
  //bar.push_back("h");
  //bar.push_back("i");

  //int xPos = 1;
  //int yPos = 1;
  //int width = 3;
  //int targetPos = 0;
  //enum direction {
  //  UP,
  //  DOWN
  //};

  //int stable = 0, shift = 0;

  //direction pointing = UP;
  //vector<string>::iterator iter;
  //ostringstream output;


  //for (iter = bar.begin(); iter != bar.end(); ++iter) {
  //  int vecPos = distance(bar.begin(), bar.end()) - distance(bar.begin(), iter);
  //  int coordPos = yPos * width + xPos;
  //  if (vecPos == coordPos) {
  //    output << "The string at position [" << xPos << "," << yPos << "] is " << *iter;
  //    targetPos = vecPos;
  //  }

  //  if ((vecPos + width) % width == 0) {
  //    cout << endl;
  //  }

  //  cout << vecPos << "." << *iter;
  //  if ((vecPos + width - 1) % width != 0)
  //    cout << ", ";
  //}
  //cout << endl << endl;
  //string out = output.str();
  //cout << out << endl;

  //stable = targetPos;
  //stable += (pointing == UP) ? width : -(width);
  //shift = stable;
  //shift += (yPos % 2) ? 1 : -(1);

  //cout << targetPos << " -> " << stable << "," << shift << endl;

  //if (IsWithinBounds(0, bar.max_size(), stable) && IsWithinBounds(0, bar.max_size(), shift)) {
  //  cout << "Safe to continue." << endl;
  //} else {
  //  cout << "ABORT!" << endl;
  //}
  
  bool foo;
  cin >> foo;

  return 0;
}
