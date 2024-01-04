#ifndef TYPES_H
#define TYPES_H

#include <stdint.h>

#define DEFAULT_FILENAME "experience.exp"
#define READABLE_DIR "readable_exp"

typedef struct BL_EXP_ENTRY
{
    uint64_t key;
    int32_t depth, score, move, performance;
} BL_EXP_ENTRY;

typedef struct MOVE
{
    unsigned first_rank: 3;
    unsigned first_letter: 3;
    unsigned second_rank: 3;
    unsigned second_letter: 3;
} MOVE;


void write_BLexp_entry_toTxTFile(FILE *, FILE *); //Writes experience entries in a txt file with a human-readable format
void delete_depth0_entries(FILE *, FILE *); //Deletes all the depth 0 entries
void defrag_min_depth(FILE *, FILE *, unsigned); //Deletes the entries that have a depth lower than the specified one
char *move_from_decimal(int32_t); //Converts a move from decimal format to string format
#endif