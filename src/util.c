#include "util.h"

#include <stdio.h>
#include <stdlib.h>

#include "types.h"

char *moveToString(int32_t move, char *result)
{
    MOVE converted;
    unsigned masc = 7;

    converted.first_rank = (move >> 9) & masc;
    converted.first_letter = (move >> 6) & masc;
    converted.second_rank = (move >> 3) & masc;
    converted.second_letter = move & masc;

    sprintf(result, "%c%d%c%d", 'a' + converted.first_letter, converted.first_rank + 1, 'a' + converted.second_letter,
            converted.second_rank + 1);

    return result;
}

char *scoreToString(int32_t score, char *result)
{

    if (abs(score) < VALUE_TB_WIN_IN_MAX_PLY)
        sprintf(result, "%-6d%s", toCP(score), "cp");
    else if (abs(score) <= VALUE_TB)
    {
        const int ply = VALUE_TB - 1 - abs(score);
        sprintf(result, "%-6d%s", score > 0 ? 20000 - ply : -20000 + ply, "cp");
    }
    else
        sprintf(result, "%s%-6d", "M", (score > 0 ? VALUE_MATE - score + 1 : -VALUE_MATE - score) / 2);

    return result;
}

int32_t toCP(int32_t score)
{
    return 100 * score / PAWN_VALUE_NORMALIZATION;
}