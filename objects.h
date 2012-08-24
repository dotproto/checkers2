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
  COLOR_UNSET = -1,
  COLOR_WHITE,
  COLOR_BLACK,
  COLOR_RED   = 1
};

enum BoardSide {
  BOARD_UNSET = -1,
  BOARD_TOP,
  BOARD_BOTTOM
};

// Valid from 1-32
typedef char Position;
typedef vector<Position> Positions;

class Player {
public:
  Player();
  void SetName(string name);
  string GetName();
  void SetColor(Color color);
  Color GetColor();
  void SetSide(BoardSide side);
  BoardSide GetSide();

private:
  BoardSide   m_side;
  string      m_name;
  Color       m_color;
};

struct Draught {
  bool      m_king;
  bool      m_inPlay;
  Player    *m_ownedBy;
  Position  m_location;
};
typedef vector<Draught> Draughts;

class BoardLocation{
public:
  // Legal location for a draught to appear on the board
  void SetLocation(Position value);
  Position GetLocation();
  // The main content of the board location (e.g. draught charcter, selection number, etc.)
  void SetValue(char value);
  char GetValue();
  // Character that will appear in front of the location value
  void SetAppend(char append);
  char GetAppend();
  // Character that will appear behind the location value
  void SetPrepend(char prepend);
  char GetPrepend();

private:
  Position  position;
  char      m_value;   // Character that should appear in the center of the
  char      m_prepend;
  char      m_append;
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
  Game();
  void DrawBoard();
  void PrepareGame();
    // Draughts redDraughts,
    //   Draughts whiteDraughts,
    //   BoardLocations specialLocations);

private:
  Player    m_players[2];
  Turns     m_turnHistory;
  Draughts  m_player1Draughts;
  Draughts  m_player2Draughts;
  int       m_boardHeight;
  int       m_boardWidth;
  int       m_rowsPerPlayer;

  void InitializePositions(Player &player, Draughts &draughts);
};
