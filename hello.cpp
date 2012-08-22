#include <iostream>
#include <vector>
#include "objects.h"
using namespace std;

int main()
{
  cout << "Hello world!" << endl;

  Draughts redDraughts;
  Draughts whiteDraughts;
  BoardLocations specialLocations;
  Game myGame;
  myGame.DrawBoard();
  return 0;
}
