#ifndef EXPERIENCE_H
#define EXPERIENCE_H

#include <stdio.h>
#include <stdint.h>

typedef struct BL_EXP_ENTRY
{
    uint64_t key;
    int32_t depth, score, move, performance;
} BL_EXP_ENTRY;

void processBLExp(FILE *, FILE *, FILE *, unsigned); // Defrag and export experience data

#endif //EXPERIENCE_H