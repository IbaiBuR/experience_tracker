#include "util.h"

#include <stdio.h>

#include "types.h"

char *move_from_decimal(int32_t move, char *result)
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