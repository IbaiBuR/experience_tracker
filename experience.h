#ifndef EXPERIENCE_H
#define EXPERIENCE_H

#include <stdio.h>
#include <stdint.h>

typedef struct BL_EXP_ENTRY
{
    uint64_t key;
    int32_t depth, score, move, performance;
} BL_EXP_ENTRY;

void write_BLexp_entry_toTxTFile(FILE *, FILE *); //Writes experience entries in a txt file with a human-readable format
void delete_depth0_entries(FILE *, FILE *); //Deletes all the depth 0 entries
void defrag_min_depth(FILE *, FILE *, unsigned); //Deletes the entries that have a depth lower than the specified one

#endif //EXPERIENCE_H