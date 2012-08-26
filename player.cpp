#include "objects.h"

// Set default values for player
Player::Player() {
  m_name = "";
  m_color = COLOR_UNSET;
  m_side = BOARD_UNSET;
}

// Get/Set player's color
Color Player::GetColor() {
  return m_color;
}
void Player::SetColor(Color color) {
  m_color = color;
}

// Get/Set player's name
void Player::SetName(string name) {
  m_name = name;
}
string Player::GetName() {
  return m_name;
}

// Get/Set player's side of board
void Player::SetSide(BoardSide side) {
  m_side = side;
}
BoardSide Player::GetSide() {
  return m_side;
}
