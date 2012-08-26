#include <iostream>
#include <vector>
#include "game.h"
using namespace std;

int main()
{
  cout << "Hello world!" << endl;

  Game myGame;
  //myGame.DrawBoard();
  
  int x = 7, y = 4;
  Position pos = 5;
  
  while (true) {
    //cout << "X: ";
    //if (!(cin >> x))
    //  break;
    //cout << "Y: ";
    //if (!(cin >> y))
    //  break;
    //if (myGame.CoordinatesToPosition(x, y, pos))
    //  cout << ( int ) pos << endl << endl;
    //else
    //  cout << "ERROR: Invalid coords" << endl;

    cout << "Position: ";
    int input;
    if (!(cin >> input))
      break;
    pos = ( Position ) input;
    if (myGame.PositionToCoordinate(pos, x, y))
      cout << "Position " << ( int ) pos << " is at coordinate " << x << "," << y << endl << endl;
    else
      cout << "ERROR: Position " << ( int ) pos << " is not a valid coodinate." << endl << endl;
  }
  return 0;
}
