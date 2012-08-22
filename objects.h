#include <vector>
#include <string>
using namespace std;

// templated definition for Clamp() - www.jonhoyle.com/Presentations/PDFs/templates.pdf
template <class T>
void Clamp(T &x, T min, T max)
{
  if (x < min)
  {
    x = min;
  }
  if (x > max)
  {
    x = max;
  }
}

class Rule {};

enum Color
{
  white = 0,
  black,
  red   = 1
};

// Valid from 1-32
typedef char Position;
typedef vector<Position> Positions;

struct Player {
  Color     m_color;
  string    m_name;
};

struct Draught {
  bool      m_king;
  bool      m_inPlay;
  Player    m_ownedBy;
  Position  m_location;
};
typedef vector<Draught> Draughts;

class BoardLocation {
  Position  position;
  char      m_value;   // Character that should appear in the center of the
  char      m_prepend;
  char      m_append;

  void SetLocation(Position value);
  Position GetLocation();
  void SetValue(char value);
  char GetValue();
  void SetPrepend(char prepend);
  char GetPrepend();
  void SetAppend(char prepend);
  char GetAppend();
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

class Game {
  void StartTurn(Player);
  void MoveDraught();
  void GetValidDraughts(vector<Draught>);
  void GetValidMoves();

public:
  void DrawBoard();
    // Draughts redDraughts,
    //   Draughts whiteDraughts,
    //   BoardLocations specialLocations);

private:
  Player    m_players[2];
  Turns     m_turnHistory;
  Draughts  m_draughts;
};
