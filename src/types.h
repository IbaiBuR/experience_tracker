#ifndef TYPES_H
#define TYPES_H

#include <stdint.h>

#define DEFAULT_FILENAME "experience.exp"
#define READABLE_DIR "readable_exp"
#define MINIMUM_DEPTH 4
#define RESULT_LENGTH 16

typedef struct MOVE
{
    unsigned first_rank: 3;
    unsigned first_letter: 3;
    unsigned second_rank: 3;
    unsigned second_letter: 3;
} MOVE;

#endif //TYPES_H