#ifndef EXPERIENCE_H
#define EXPERIENCE_H

#include <stdbool.h>
#include <stdio.h>
#include <stdint.h>

enum ExperienceMode
{
    BrainLearn,
    SugarV2
};

typedef struct BL_EXP_ENTRY
{
    uint64_t key;
    int32_t depth, score, move, performance;
} BL_EXP_ENTRY;

typedef struct SG_V2_EXP_ENTRY
{
    uint64_t key;
    int32_t move, score, depth;
    uint16_t count;
    __attribute__((unused)) uint8_t padding[2];
} SG_V2_EXP_ENTRY;

void processBLExp(FILE *, FILE *, FILE *, unsigned); // Defrag and export BrainLearn-like experience data
void processSGV2Exp(FILE *, FILE *, FILE *, unsigned); // Defrag and export SugarV2-like experience data
bool detectSignature(FILE *); // Check if the SugarV2 signature is present

#endif //EXPERIENCE_H