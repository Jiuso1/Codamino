#include "aminoacid.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

int main(void)
{
    time_t start = 0;
    time_t end = 0;
    const char *input = "UUCCUGAUAAUGGUGAGCCCGACGGCGUACUGACACCAGAACAAGGACGAGUGCUGGAGGGGG";
    size_t size = strlen(input) + 1; // We reserve needed memory plus one more for '\0'.
    char output[size];

    time(&start);
    replaceInput(input, output, size);
    time(&end);

    printf("The function lasted %ld seconds\n", end - start);

    return EXIT_SUCCESS;
}