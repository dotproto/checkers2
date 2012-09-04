#include "utilities.h"

bool IsWithinBounds(int lower, int upper, int value) {
  if (value <= upper && value >= lower) {
    return true;
  }
  return false;
}