#include "experience.h"

#include <stdio.h>

#include "util.h"

void write_BLexp_entry_toTxTFile(FILE *experience, FILE *output)
{
    BL_EXP_ENTRY exp_data;
    char result[16];

    while (fread(&exp_data, sizeof(BL_EXP_ENTRY), 1, experience))
    {
        fprintf(output, "Key: %lx, Move: %s, Score: %d, Depth: %d, Performance: %d\n",
                exp_data.key, move_from_decimal(exp_data.move, result), exp_data.score, exp_data.depth,
                exp_data.performance);
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