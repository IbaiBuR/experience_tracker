#include "experience.h"

#include <stdio.h>

#include "util.h"

// Value to normalize / scale the scores to centipawns (PawnValue / 100)
static const double scoreCPNormalization = 2.08;

void processBLExp(FILE *experience, FILE *txt, FILE *output, unsigned depthLimit)
{
    BL_EXP_ENTRY exp_data;
    char result[16];

    while (fread(&exp_data, sizeof(BL_EXP_ENTRY), 1, experience))
    {
        if (exp_data.depth > depthLimit)
            fwrite(&exp_data, sizeof(BL_EXP_ENTRY), 1, output);

        fprintf(txt, "Key: %-16lX, Move: %-5s, Score: %-6d%s, Depth: %-3d, Performance: %d\n",
                exp_data.key, move_from_decimal(exp_data.move, result),
                (int32_t) (exp_data.score / scoreCPNormalization), "cp", exp_data.depth,
                exp_data.performance);
    }
}