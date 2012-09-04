////////////////////////////////////////////////////////////////////////////////
#ifndef OBJECTS_H
#define OBJECTS_H
////////////////////////////////////////////////////////////////////////////////

#include <vector>
#include <string>
using namespace std;

enum Color
{
  COLOR_UNSET = -1,
  COLOR_WHITE,
  COLOR_BLACK,
  COLOR_RED   = COLOR_BLACK
};

enum BoardSide {
  BOARD_UNSET = -1,
  BOARD_TOP,
  BOARD_BOTTOM
};

// Valid from 1-32
typedef unsigned char Position;
typedef vector<Position> Positions;

struct Player {
  BoardSide   side;
  string      name;
  Color       color;
};

struct Draught {
  bool      m_king;
  bool      m_inPlay;
  Player*   m_ownedBy;
  Position  m_location;
};
typedef vector<Draught> Draughts;
typedef vector<Draught*> pDraughts;

struct BoardLocation{
  Position  position;
  string    prepend;
  string    value;
  string    append;
};
typedef vector<BoardLocation> BoardLocations;

struct Turn {
  Player    m_player;
  Draught   m_draught;
  Position  m_startLoc;
  Positions m_moveTo;
  Draughts  m_draughtsJumped;
};
typedef vector<Turn> Turns;

////////////////////////////////////////////////////////////////////////////////
#endif
////////////////////////////////////////////////////////////////////////////////
