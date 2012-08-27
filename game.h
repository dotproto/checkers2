////////////////////////////////////////////////////////////////////////////////
#ifndef GAME_H
#define GAME_H
////////////////////////////////////////////////////////////////////////////////

#include "objects.h"

class Game {
  void StartTurn(Player);
  void MoveDraught();
  void GetValidDraughts(vector<Draught>);
  void GetValidMoves();


public:
  Game();
  void DrawBoard();
  void PrepareGame();
    // Draughts redDraughts,
    //   Draughts whiteDraughts,
    //   BoardLocations specialLocations);

  
  // Convert a standard board position into a pair of X,Y board coordintes (top
  // left corner).
  bool PositionToCoordinate(Position pos, int& row, int& col);

  // Convert a pair of X,Y board coords (top left corner) into a standard board
  // position. Bool indicates the success/failure of the operation; pos's value
  // will be uncainged on failure.
  bool CoordinatesToPosition(int row, int col, Position& pos);

private:
  Player    m_players[2];
  Turns     m_turnHistory;
  Draughts  m_draughts;
  int       m_boardHeight;
  int       m_boardWidth;
  int       m_boardPosPerRow;
  int       m_boardRowsPerPlayer;

  void InitializePositions(Player &player);
  bool CheckDraughtInPos(Position currentPos, Draught &draught);
};

////////////////////////////////////////////////////////////////////////////////
#endif
////////////////////////////////////////////////////////////////////////////////
