#include <iostream>
#include "objects.h"
using namespace std;

#define BOARDHEIGHT 8
#define BOARDWIDTH  8
#define POSPERROW BOARDWIDTH / 2

Draughts Game::InitializePositions(Player &player, enum BoardSide side) {
  int posCount = POSPERROW * m_rowsPerPlayer;
  int startPos;
  int endPos;
  if (side == BOARD_TOP) {
    endPos = POSPERROW * BOARDHEIGHT;
    startPos = endPos - posCount;
  } else {
    startPos = 1;
    endPos = posCount;
  }

  Draughts draughtPositions;
  for (Position i = startPos; i < endPos; i++) {
    Draught *current    = new Draught;
    current->m_king     = false;
    current->m_inPlay   = true;
    current->m_location = i;
    current->m_ownedBy  = &player; // TODO: I have no idea what I'm doing.

    draughtPositions.push_back(*current);
  }
  return draughtPositions;
};

void Game::PrepareGame() {
  // 1. Empty the follwoing vectors: m_player1Draughts, m_player2Draughts, and m_turnHistory
  // 2. Populate draught vectors with starting positions.

  m_turnHistory.clear();
  m_player1Draughts.clear();
  m_player2Draughts.clear();

  // Initialize white draught locations
  InitializePositions(m_players[0], BOARD_TOP);
  InitializePositions(m_players[1], BOARD_BOTTOM);

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
  for (int j = 0; j != BOARDWIDTH; j++) {
    if (j == 0) {
      // BOARD TOP LEFT CORNER
      // first column, top left corner (┌)
      cout << BoxTopLeft;
    }

    // TOP EDGE
    cout << BoxHorizontal << BoxHorizontal << BoxHorizontal;

    // TOP RIGHT CORNER
    if (j != BOARDWIDTH - 1) {
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

  for (int i = 0; i != BOARDHEIGHT; i++) {
    // FIRST LINE
    string prepend = " ";
    string append  = " ";
    string value   = " ";

    for (int j = 0; j != BOARDWIDTH; j++) {
      // CELL LEFT EDGE
      cout << BoxVertical;

      // CELL BODY
      cout << prepend << value << append;

      // BODY RIGHT EDGE
      if (j == BOARDWIDTH - 1) {
        cout << BoxVertical;
      }
      // End line
    }
    cout << endl;

    // SECOND LINE
    for (int j = 0; j != BOARDWIDTH; j++) {
      // LEFT EDGE
      if (j == 0) {
        // BOARD LEFT INTERSECT
        if (i != BOARDHEIGHT - 1) {
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
        if (i != BOARDHEIGHT - 1) {
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
      if (j == BOARDWIDTH - 1) {
        if (i != BOARDHEIGHT - 1) {
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
