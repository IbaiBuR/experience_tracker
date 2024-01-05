#include <errno.h>
#include <sys/stat.h>
#include <stdio.h>
#include <string.h>

#ifdef _WIN32
#include <direct.h>
#include <ncursesw/ncurses.h>
#else

#include <ncurses.h>

#endif

#include "experience.h"
#include "types.h"

int main(int argc, char *argv[])
{
    FILE *experience, *exp_fixed, *readable_exp;
    struct stat st;
    unsigned depth;
    char resp;
    bool signatureFound;
    initscr();

    addstr("Initializing...\n");
    refresh();

    if (stat(READABLE_DIR, &st) != 0)
    {

#ifdef _WIN32
        if (_mkdir(READABLE_DIR) != 0)
#else
        if (mkdir(READABLE_DIR, S_IRWXU | S_IRWXG | S_IROTH | S_IXOTH) != 0)
#endif
        {
            printw("Could not create the directory...\n");
            refresh();
            return 1;
        }
    }

    // Determine the filename to open based on the provided argument or use the default 'experience.exp'
    const char *experience_filename = (argc >= 2) ? argv[1] : DEFAULT_FILENAME;

    // Check if the default 'experience.exp' file is used
    if (strcmp(experience_filename, DEFAULT_FILENAME) == 0)
    {
        printw("Using default filename experience.exp\n");
        refresh();
    }

    addstr("Preparing experience data...\n");
    refresh();

    if (!(experience = fopen(experience_filename, "rb")))
    {
        printw("Could not open the BrainLearn experience file '%s' (Error: %d - %s)...\n",
               experience_filename, errno, strerror(errno));
        refresh();

        if (strcmp(experience_filename, DEFAULT_FILENAME) == 0)
            printw("Make sure the default 'experience.exp' file exists in the current directory.\n");
        refresh();

        return 2;
    }

    // Open necessary files for writing
    if (!(readable_exp = fopen("./readable_exp/experience.txt", "w")))
    {
        printw("Could not create the readable text file.\n");
        refresh();
        return 3;
    }

    if (!(exp_fixed = fopen("experience_fixed.exp", "wb")))
    {
        printw("Could not create the fixed experience file.\n");
        refresh();
        return 4;
    }

    addstr("Checking for V2 signature...\n");
    signatureFound = detectSignature(experience);

    if (signatureFound)
    {
        addstr("Signature found, detected SugaR V2 experience file format.\n");
        refresh();
    }
    else
    {
        addstr("Signature not found, detected BrainLearn experience file format.\n");
        refresh();
    }

    // Prompt the user for defragmentation with a specific depth
    printw("Do you want to defrag with a specific depth? (y/N): ");
    refresh();
    resp = getch();

    // Perform defragmentation with a specified depth if the user chooses to
    if (resp == 'y' || resp == 'Y')
    {
        printw("\nEnter the minimum depth to defrag with: ");
        scanw("%u", &depth);
        addstr("\nProcessing experience data with specific minimum depth to defrag...\n");
        refresh();
        signatureFound ? processSGV2Exp(experience, readable_exp, exp_fixed, depth) : processBLExp(experience,
                                                                                                   readable_exp,
                                                                                                   exp_fixed, depth);
    }
    else
    {
        addstr("\nProcessing experience data with default depth 4 to defrag...\n");
        refresh();
        signatureFound ? processSGV2Exp(experience, readable_exp, exp_fixed, MINIMUM_DEPTH) : processBLExp(experience,
                                                                                                           readable_exp,
                                                                                                           exp_fixed,
                                                                                                           MINIMUM_DEPTH);
    }

    // Close all the open files
    fclose(experience);
    fclose(readable_exp);
    fclose(exp_fixed);

    // Prompt the user to press a key and close ncurses window
    addstr("Press any key too exit...\n");
    refresh();
    getch();
    endwin();

    return 0;
}