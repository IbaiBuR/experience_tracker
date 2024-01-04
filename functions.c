#include <stdio.h>
#include <stdlib.h>
#include "types.h"

void write_BLexp_entry_toTxTFile(FILE *experience, FILE *output)
{
    BL_EXP_ENTRY exp_data;

    while (fread(&exp_data, sizeof(BL_EXP_ENTRY), 1, experience))
    {
        fprintf(output, "Key: %lx, Move: %s, Score: %d, Depth: %d, Performance: %d\n",
                exp_data.key, move_from_decimal(exp_data.move), exp_data.score, exp_data.depth, exp_data.performance);
    }

    rewind(experience);
}

void delete_depth0_entries(FILE *experience, FILE *destination)
{
    BL_EXP_ENTRY exp_data;

    while (fread(&exp_data, sizeof(BL_EXP_ENTRY), 1, experience))
    {
        if (exp_data.depth > 0)
        {
            fwrite(&exp_data, sizeof(BL_EXP_ENTRY), 1, destination);
        }
    }

    rewind(experience);
    rewind(destination);

}

void defrag_min_depth(FILE *experience, FILE *destination, unsigned depth)
{
    BL_EXP_ENTRY exp_data;

    while (fread(&exp_data, sizeof(BL_EXP_ENTRY), 1, experience))
    {
        if (exp_data.depth > depth)
        {
            fwrite(&exp_data, sizeof(BL_EXP_ENTRY), 1, destination);
        }
    }

    rewind(experience);
    rewind(destination);
}

char *move_from_decimal(int32_t move)
{
    MOVE converted;
    unsigned masc = 7;
    char *result = (char *) malloc(4 * sizeof(char));

    converted.first_rank = (move >> 9) & masc;
    converted.first_letter = (move >> 6) & masc;
    converted.second_rank = (move >> 3) & masc;
    converted.second_letter = move & masc;


    sprintf(result, "%c%d%c%d", 'a' + converted.first_letter, converted.first_rank + 1, 'a' + converted.second_letter,
            converted.second_rank + 1);

    return result;
}