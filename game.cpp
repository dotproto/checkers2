#include <iostream>
#include "game.h"
using namespace std;

Game::Game() {
  m_boardHeight = 8;
  m_boardWidth = 8;
  m_boardPosPerRow = m_boardWidth / 2;
  m_boardRowsPerPlayer = 3;

  // TODO: Replace temp values with 
  // Initialize Player 1
  m_players[0].color = COLOR_BLACK;
  m_players[0].name  = "Sim";
  m_players[0].side  = BOARD_TOP;
  // Initialize Player 2
  m_players[1].color = COLOR_WHITE;
  m_players[1].name  ="COMPUTER";
  m_players[1].side  = BOARD_BOTTOM;

  PrepareGame();
}

void Game::InitializePositions(Player &player, Draughts &draughts) {
  int posCount = m_boardPosPerRow * m_boardRowsPerPlayer;
  enum BoardSide side = player.side;
  int startPos = -1;
  int endPos = -1;

  if (side == BOARD_TOP) {
    endPos = m_boardPosPerRow * m_boardHeight;
    startPos = endPos - posCount + 1; // +1 bumps the value to first entry in new row
  } else {
    startPos = 1;
    endPos = posCount;
  }

  for (Position i = startPos; i <= endPos; i++) {
    Draught *current    = new Draught;
    current->m_king     = false;
    current->m_inPlay   = true;
    current->m_location = i;
    current->m_ownedBy  = &player;

    draughts.push_back(*current);
  }

  return;
};

void Game::PrepareGame() {
  // 1. Empty the follwoing vectors: m_player1Draughts, m_player2Draughts, and m_turnHistory
  // 2. Populate draught vectors with starting positions.
  
  m_turnHistory.clear();
  m_player1Draughts.clear();
  m_player2Draughts.clear();

  // Initialize white draught locations
  InitializePositions(m_players[0], m_player1Draughts);
  InitializePositions(m_players[1], m_player2Draughts);

  // TODO: These are temp vars. Replace them with acutal impl
  Player p1;
  Player p2;
};

// Draw the board, draughts, and any "special" entities that need to appear on
// the board.
//
// The board is drawn cell-by-cell and row-by-row from top to bottom, left to
// right. Each standard cell is two characters high and four characters wide;
// these characters are used to represent the cell value, right edge, bottom
// edge, and bottom-right corners. All edges and corners are drawn using
// standard box drawing characters.
//
//     -------------------------------------------------------------
//     | whitespace   | cell         | whitespace   | right        |
//     | (or special) | value        | (or special) | edge         |
//     |--------------|--------------|--------------|--------------|
//     | bottom       | bottom       | bottom       | bottom right |
//     | edge         | edge         | edge         | corner       |
//     -------------------------------------------------------------
//
// Given this layout, the funciton must provide special facilities to render
// the top edge of the board, the left edge of the board, and the bottom-right
// corener of each cell.
void Game::DrawBoard() {
  // Define all used box drawing charactrs (platform specific)
  #if defined(WIN32) || defined(_WIN32) || defined(__WIN32) && !defined(__CYGWIN__)
  // Flat edges
  static const string BoxVertical       = "\xB3";
  static const string BoxHorizontal     = "\xC4";
  static const string BoxHorizontalEm   = "\xFA";
  // Corner pieces
  static const string BoxTopLeft        = "\xDA";
  static const string BoxTopRight       = "\xBF";
  static const string BoxBottomLeft     = "\xC0";
  static const string BoxBottomLeftEm   = BoxBottomLeft;
  static const string BoxBottomRight    = "\xD9";
  // Perpendicular lines on a given edge (e.g. T = top)
  static const string BoxPerpenTop      = "\xC2";
  static const string BoxPerpenLeft     = "\xC3";
  static const string BoxPerpenLeftEm   = BoxPerpenLeft;
  static const string BoxPerpenRight    = "\xB4";
  static const string BoxPerpenBottom   = "\xC1";
  static const string BoxPerpenBottomEm = BoxPerpenBottom;
  // Intersection of horizontal and vertical lines (e.g. +)
  static const string BoxIntersect      = "\xC5";
  static const string BoxIntersectEm    = BoxIntersect;
  #else
  // Flat edges
  static const string BoxVertical       = "│";
  static const string BoxHorizontal     = "─";
  static const string BoxHorizontalEm   = "╴";
  // Corner pieces
  static const string BoxTopLeft        = "┌";
  static const string BoxTopRight       = "┐";
  static const string BoxBottomLeft     = "└";
  static const string BoxBottomLeftEm   = "╵";
  static const string BoxBottomRight    = "┘";
  // Perpendicular lines on a given edge (e.g. T = top)
  static const string BoxPerpenTop      = "┬";
  static const string BoxPerpenLeft     = "├";
  static const string BoxPerpenLeftEm   = "│";
  static const string BoxPerpenRight    = "┤";
  static const string BoxPerpenBottom   = "┴";
  static const string BoxPerpenBottomEm = "┘";
  // Intersection of horizontal and vertical lines (e.g. +)
  static const string BoxIntersect      = "┼";
  static const string BoxIntersectEm    = "┤";
  #endif


  // BOARD TOP EDGE
  for (int j = 0; j != m_boardWidth; j++) {
    if (j == 0) {
      // BOARD TOP LEFT CORNER
      // first column, top left corner (┌)
      cout << BoxTopLeft;
    }

    // TOP EDGE
    cout << BoxHorizontal << BoxHorizontal << BoxHorizontal;

    // TOP RIGHT CORNER
    if (j != m_boardWidth - 1) {
      // CELL TOP RIGHT CORENER
      // Not last column, internal top edge (┬)
      cout << BoxPerpenTop;
    } else {
      // BOARD TOP RIGHT CORNER
      // Last column, top right corner (┐)
      cout << BoxTopRight;
    }
  }
  cout << endl;

  for (int i = 0; i != m_boardHeight; i++) {
    // FIRST LINE
    string prepend = " ";
    string append  = " ";
    string value   = " ";

    //for (Draughts.iterator it = m_player1Draughts.begin(); it != m_player1Draughts.end(); ++it) {
    //  if (it->m_location /*== currentPos */) {
    //    // NEED 
    //  }
    //}

    for (int j = 0; j != m_boardWidth; j++) {
      // CELL LEFT EDGE
      cout << BoxVertical;

      // CELL BODY
      cout << prepend << value << append;

      // BODY RIGHT EDGE
      if (j == m_boardWidth - 1) {
        cout << BoxVertical;
      }
      // End line
    }
    cout << endl;

    // SECOND LINE
    for (int j = 0; j != m_boardWidth; j++) {
      // LEFT EDGE
      if (j == 0) {
        // BOARD LEFT INTERSECT
        if (i != m_boardHeight - 1) {
          // BOARD LEFT EDGE (├)
          if ((i + j) % 2) {
            cout << BoxPerpenLeftEm;
          } else {
            cout << BoxPerpenLeft;
          }
        } else {
          // BOARD BOTTOM LEFT CORNER (└)
          if ((i + j) % 2) {
            cout << BoxBottomLeftEm;
          } else {
            cout << BoxBottomLeft;
          }
        }
      } else {
        // CELL INTERSECT
        if (i != m_boardHeight - 1) {
          // CELL BOTTOM EDGE (┼)
          if ((i + j) % 2) {
            cout << BoxIntersectEm;
          } else {
            cout << BoxIntersect;
          }
        } else {
          // BOARD BOTTOM EDGE (┴)
          if ((i + j) % 2) {
            cout << BoxPerpenBottomEm;
          } else {
            cout << BoxPerpenBottom;
          }
        }
      }

      // BOTTOM EDGE (─)
      if ((i + j) % 2) {
        cout << BoxHorizontalEm << BoxHorizontalEm << BoxHorizontalEm;
      } else {
        cout << BoxHorizontal   << BoxHorizontal   << BoxHorizontal;
      }

      // BOARD RIGHT EDGE
      // Top right corner is handled in "board top edge"
      // Right vertical edge is handled in "body right edge"
      if (j == m_boardWidth - 1) {
        if (i != m_boardHeight - 1) {
          // BOARD RIGHT EDGE (┤)
          cout << BoxPerpenRight;
        } else {
          // BOARD RIGHT CORNER (┘)
          cout << BoxBottomRight;
        }
      }
    }
    cout << endl;
  }
}

// Utility functions1
bool Game::PositionToCoordinate(Position pos, int& col, int& row){
  // Row and column converstion notes:
  // 
  // * row - distance from board's bottom edge.
  // * col - distance from board's left edge.

  // First, make sure the position is in bounds
  if (!(pos >= 1 && pos <= 32)) {
    return false;
  }

  row = this->m_boardHeight - (pos - 1) / this->m_boardPosPerRow - 1;

  int colMod = 0;
  if (row % 2 == 0) {
    colMod++;
  }

  col = (3 - (pos - 1) % this->m_boardPosPerRow) * 2 + colMod;

  return true;
};

bool Game::CoordinatesToPosition(int col, int row, Position& pos) {
  // Only odd combinations of x & y are valid positions.
  if ( (col + row) % 2 == 0) {
      return false;
  }
  
  // -1 is used to compensate for coord's 0 based index
  int distRight  = (this->m_boardWidth - col - 1) / 2;
  int distBottom = this->m_boardHeight - row - 1;

  // for checkboard pattern, +1 adjusts to Position's 1-based index
  pos = distBottom * this->m_boardPosPerRow + distRight + 1;
  return true;
}
