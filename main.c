#include <stdio.h>
#include <direct.h>
#include <sys/stat.h>
#include "types.h"

#define DEFAULT_FILENAME "experience.exp"
#define READABLE_DIR "readable_exp"

int main(int argc, char *argv[])
{
    FILE *BL_exp, *exp_fixed, *output_fixed, *BrainLearn_readable;
    struct stat st;
    unsigned depth;
    char resp; // Declaration of the 'resp' variable

    // Check if the 'readable_exp' directory exists, create it if not
    if (stat(READABLE_DIR, &st) != 0)
    {
        // Directory does not exist, so create it
        #ifdef _WIN32
        if (_mkdir(READABLE_DIR) != 0)
        #else
        if (mkdir(READABLE_DIR, S_IRWXU | S_IRWXG | S_IROTH | S_IXOTH) != 0)
        #endif
        {
            printf("Could not create the directory...\n");
            return 1;
        }
    }

    // Determine the filename to open based on the provided argument or use the default 'experience.exp'
    const char* experience_filename = (argc >= 2) ? argv[1] : DEFAULT_FILENAME;

    // Check if the default 'experience.exp' file is used
    if (strcmp(experience_filename, DEFAULT_FILENAME) == 0)
    {
        printf("Using default experience.exp\n");
    }

    // Open the BrainLearn experience file for reading
    if (!(BL_exp = fopen(experience_filename, "rb")))
    {
        printf("Could not open the BrainLearn experience file '%s'...\n", experience_filename);
        if (strcmp(experience_filename, DEFAULT_FILENAME) == 0)
        {
            printf("Make sure the default 'experience.exp' file exists in the current directory.\n");
        }
        return 2;
    }

    // Open necessary files for writing and reading
    BrainLearn_readable = fopen("./readable_exp/brainlearn.txt", "w");
    exp_fixed = fopen("experience_fixed.exp", "wb");
    output_fixed = fopen("./readable_exp/brainlearn_fixed.txt", "w");

    // Convert the binary BrainLearn experience to readable format and write it to 'brainlearn.txt'
    write_BLexp_entry_toTxTFile(BL_exp, BrainLearn_readable);

    // Prompt the user for defragmentation with a specific depth
    printf("Do you want to defrag with a specific depth? (y/N)");
    scanf(" %c", &resp);

    // Perform defragmentation with a specified depth if the user chooses to
    if (resp == 'y' || resp == 'Y')
    {
        printf("\nEnter the depth to defrag with: ");
        scanf("%u", &depth);
        defrag_min_depth(BL_exp, exp_fixed, depth);
    }
    else
    {
        // If the user does not specify a depth, delete all the depth 0 entries
        delete_depth0_entries(BL_exp, exp_fixed);
    }

    // Close the fixed experience file and reopen it for reading
    fclose(exp_fixed);
    if (!(exp_fixed = fopen("experience_fixed.exp", "rb")))
    {
        printf("Could not open fixed exp file to read...\n");
        return 6;
    }

    // Convert the fixed binary experience to readable format and write it to 'brainlearn_fixed.txt'
    write_BLexp_entry_toTxTFile(exp_fixed, output_fixed);

    // Close all the open files
    fclose(BL_exp);
    fclose(BrainLearn_readable);
    fclose(exp_fixed);
    fclose(output_fixed);

    return 0;
}
