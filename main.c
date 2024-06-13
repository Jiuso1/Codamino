#include "aminoacid.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

int main(void)
{
    const char *input = "UUCCUGAUAAUGGUGAGCCCGACGGCGUACUGACACCAGAACAAGGACGAGUGCUGGAGGGGG";
    const size_t size = strlen(input) + 1; // We reserve needed memory plus one more for '\0'.
    char output[size];
    clock_t start = 0;
    clock_t end = 0;
    double timeSpent = 0;

    start = clock();
    replaceInput(input, output, size);
    end = clock();

    timeSpent = (double)(end - start) / CLOCKS_PER_SEC; // We get seconds.
    timeSpent *= 1000;                                  // We transform seconds to milliseconds.

    printf("%s\n", output);

    printf("The function lasted %f milliseconds\n", timeSpent);

    return EXIT_SUCCESS;
}