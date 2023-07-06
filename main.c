#include <stdio.h>
#include <string.h>
#include "types.h"

int main()
{
    FILE *BL_exp, *exp_fixed, *output_fixed, *BrainLearn_readable;


    
    if(!(BL_exp = fopen("./experience_files/experience.bin", "rb")))
    {
        printf("Could not open the BrainLearn experience file...\n");
        return 1;
    }

    if(!(BrainLearn_readable = fopen("./readable_exp/brainlearn.txt", "w")))
    {
        printf("Could not open brainlearn txt file to write...\n");
        return 2;
    }

    if(!(exp_fixed = fopen("./experience_files/experience_fixed.bin", "wb")))
    {
        printf("Could not open experience file to fix...\n");
        return 3;
    }

    if(!(output_fixed = fopen("./readable_exp/brainlearn_fixed.txt", "w")))
    {
        printf("Could not open brainlearn fixed txt file to write...\n");
        return 4;
    }

    write_BLexp_entry_toTxTFile(BL_exp, BrainLearn_readable);
    delete_depth0_entries(BL_exp, exp_fixed);

    fclose(exp_fixed);

    if(!(exp_fixed = fopen("./experience_files/experience_fixed.bin", "rb")))
    {
      printf("Could not open fixed exp file to read...\n");
      return 5;
    }
    
    write_BLexp_entry_toTxTFile(exp_fixed, output_fixed);

    fclose(BL_exp);
    fclose(BrainLearn_readable);
    fclose(exp_fixed);
    fclose(output_fixed);
    
    return 0;
}
