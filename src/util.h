#ifndef UTIL_H
#define UTIL_H

#include <stdint.h>

static const int MAX_PLY = 246;
static const int VALUE_MATE = 32000;
static const int VALUE_TB = (VALUE_MATE - MAX_PLY) - 1;
static const int VALUE_TB_WIN_IN_MAX_PLY = VALUE_TB - MAX_PLY;
static const int PAWN_VALUE_NORMALIZATION = 328;

char *moveToString(int32_t, char *); // Converts a move from int format to string format
char *scoreToString(int32_t, char *); // Converts a score from int format to string format
int32_t toCP(int32_t); // Scales the score to centipawns

#endif //UTIL_H