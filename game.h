////////////////////////////////////////////////////////////////////////////////
#ifndef GAME_H
#define GAME_H
////////////////////////////////////////////////////////////////////////////////

#include <array>
#include "objects.h"

class Game {
  void StartTurn(Player);
  void GetValidDraughts(vector<Draught>);
  void GetValidMoves();


public:
  Game();
  void Move(Player*& p_currentPlayer);
  void PrepareGame();
  void DrawBoard();

  // Convert a standard board position into a pair of X,Y board coordintes (top
  // left corner).
  bool PositionToCoordinate(Position pos, int& row, int& col);

  // Convert a pair of X,Y board coords (top left corner) into a standard board
  // position. Bool indicates the success/failure of the operation; pos's value
  // will be uncainged on failure.
  bool CoordinatesToPosition(int row, int col, Position& pos);

  
  // TODO
  // Ask the player to move a draught
  void PromptForMove(Player currentPlayer);
  // Determine which (if any) draughts are movable
  void FindMovableDraughts(Player* currentPlayer, pDraughts& movableDraughts);
  void SortDraughtsByPosition();// Must sort before searching for movable draughts
  bool IsDraughtMovable();      //
  void MoveDraught();           // Execute the move. Follow this with a redraw call


private:
  Player          m_players[2];
  Turns           m_turnHistory;
  Draughts        m_draughts;
  BoardLocations  m_specialLocation;
  int             m_boardHeight;
  int             m_boardWidth;
  int             m_boardPosPerRow;
  int             m_boardRowsPerPlayer;

  int GetRowFromPos(Position pos);
  void InitializePositions(Player &player);
  bool IsDraughtInPos(Position currentPos, Draught &draught);
  array<Position,2> GetMovePositions(Position start, BoardSide side);
  void LimitPosToRow(Position row, Position& pos);
  void FindTargetPositions(Player* p_currentPlayer, Draught* selectedDraught, Positions& targetPositions);
  void FindJumpedDraught(Draught* draught, Position targetPos, Draught*& jumpedDraught);
};

////////////////////////////////////////////////////////////////////////////////
#endif
////////////////////////////////////////////////////////////////////////////////
