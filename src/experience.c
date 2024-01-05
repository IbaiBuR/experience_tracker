#include "experience.h"

#include <stdio.h>

#include "util.h"

void processBLExp(FILE *experience, FILE *txt, FILE *output, unsigned depthLimit)
{
    BL_EXP_ENTRY exp_data;
    char result[16];

    while (fread(&exp_data, sizeof(BL_EXP_ENTRY), 1, experience))
    {
        if (exp_data.depth > depthLimit)
            fwrite(&experience, sizeof(BL_EXP_ENTRY), 1, output);

        fprintf(txt, "Key: %-20lx, Move: %-5s, Score: %-5d, Depth: %-5d, Performance: %-5d\n",
                exp_data.key, move_from_decimal(exp_data.move, result), exp_data.score, exp_data.depth,
                exp_data.performance);
    }
}