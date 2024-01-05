#include "experience.h"

#include <inttypes.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "util.h"

// Experience V2 default signature
const char *expV2Signature = "SugaR Experience version 2";

void processBLExp(FILE *experience, FILE *txt, FILE *output, unsigned depthLimit)
{
    BL_EXP_ENTRY exp_data;
    char moveResult[16];
    char scoreResult[16];

    while (fread(&exp_data, sizeof(BL_EXP_ENTRY), 1, experience))
    {
        // Perform defragment
        if (exp_data.depth > depthLimit)
            fwrite(&exp_data, sizeof(BL_EXP_ENTRY), 1, output);

        // Export experience data
        fprintf(txt, "Key: %-16lX, Move: %-5s, Score: %-6s, Depth: %-3d, Performance: %d\n",
                exp_data.key, moveToString(exp_data.move, moveResult), scoreToString(exp_data.score, scoreResult),
                exp_data.depth,
                exp_data.performance);
    }
}

void processSGV2Exp(FILE *experience, FILE *txt, FILE *output, unsigned depthLimit)
{
    SG_V2_EXP_ENTRY exp_data;
    char moveResult[16];
    char scoreResult[16];

    // Skip the expV2 signature
    fseek(experience, strlen(expV2Signature), SEEK_SET);

    while (fread(&exp_data, sizeof(SG_V2_EXP_ENTRY), 1, experience))
    {
        // Perform defragment
        if (exp_data.depth > depthLimit)
            fwrite(&exp_data, sizeof(SG_V2_EXP_ENTRY), 1, output);

        // Export experience data
        fprintf(txt, "Key: %-16lX, Move: %-5s, Score: %-6s, Depth: %-3d, Count: %" PRIu16 "\n",
                exp_data.key, moveToString(exp_data.move, moveResult),
                scoreToString(exp_data.score, scoreResult),
                exp_data.depth,
                exp_data.count);
    }
}

bool detectSignature(FILE *experience)
{
    const size_t signatureLegth = strlen(expV2Signature);
    char *signatureBuffer = (char *) malloc(signatureLegth);
    bool signatureMatches;

    if (!(fread(signatureBuffer, signatureLegth, 1, experience)))
    {
        free(signatureBuffer);
        signatureMatches = false;
    }
    else
        signatureMatches = (memcmp(signatureBuffer, expV2Signature, signatureLegth) == 0);

    // Free memory and bring the file pointer to the beginning of the file
    free(signatureBuffer);
    rewind(experience);

    return signatureMatches;
}