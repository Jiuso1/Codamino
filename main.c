#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "aminoacid.h"

int main(void)
{
    const char *input = "UUCCUGAUAAUGGUGAGCCCGGCGUAC";
    size_t size = strlen(input) + 1; // We reserve needed memory plus one more for '\0'.
    char output[size];

    replaceCodons(input, output, size);

    // printf("%s\n", output);

    return EXIT_SUCCESS;
}