#include <stdio.h>
#include <string.h>
#include <dirent.h>
#include <sys/types.h>
#include <sys/stat.h>
#include "types.h"

int main(int argc, char *argv[])
{
    FILE *BL_exp, *exp_fixed, *output_fixed, *BrainLearn_readable;
    const char *dirname = "readable_exp";
    DIR *readable_exp = opendir(dirname);
    char resp;
    unsigned depth;

    if(readable_exp)
    {
        closedir(readable_exp); //directory already exists
    }
    else
    {
        mkdir("./readable_exp", S_IRWXU | S_IRWXG | S_IROTH | S_IXOTH); //directory does not exist so we create it... NOTE: For Windows compilers this function is a bit different
    }

    if(argc < 2)
    {
        printf("Incorrect number of parameters...\n");
        return 1;
    }
    
    if(!(BL_exp = fopen(argv[1], "rb")))
    {
        printf("Could not open the BrainLearn experience file...\n");
        return 2;
    }

    if(!(BrainLearn_readable = fopen("./readable_exp/brainlearn.txt", "w")))
    {
        printf("Could not open brainlearn txt file to write...\n");
        return 3;
    }

    if(!(exp_fixed = fopen("experience_fixed.exp", "wb")))
    {
        printf("Could not open experience file to fix...\n");
        return 4;
    }

    if(!(output_fixed = fopen("./readable_exp/brainlearn_fixed.txt", "w")))
    {
        printf("Could not open brainlearn fixed txt file to write...\n");
        return 5;
    }

    write_BLexp_entry_toTxTFile(BL_exp, BrainLearn_readable);

    printf("Do you want to defrag with an specific depth? (s/N)");
    scanf("%c", &resp);

    if(resp == 's' || resp == 'S')
    {
        printf("\nEnter the depth to defrag with: ");
        fflush(stdin);
        scanf("%d", &depth);
        defrag_min_depth(BL_exp, exp_fixed, depth);

    }

    else
    {
        delete_depth0_entries(BL_exp, exp_fixed); //If the user does not specify a depth, we delete all the depth 0 entries
    }


    fclose(exp_fixed);

    if(!(exp_fixed = fopen("experience_fixed.exp", "rb")))
    {
      printf("Could not open fixed exp file to read...\n");
      return 6;
    }
    
    write_BLexp_entry_toTxTFile(exp_fixed, output_fixed);

    fclose(BL_exp);
    fclose(BrainLearn_readable);
    fclose(exp_fixed);
    fclose(output_fixed);
    
    return 0;
}
