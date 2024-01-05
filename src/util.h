#ifndef UTIL_H
#define UTIL_H

#include <stdint.h>

char *move_from_decimal(int32_t, char *); // Converts a move from decimal format to string format
uint64_t reverseKey(uint64_t); // Reverses the 8 bytes key

#endif //UTIL_H