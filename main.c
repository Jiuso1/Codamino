#include "aminoacid.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

int main(void)
{
    char *buffer = (char *)malloc(sizeof(char)); // Dynamic buffer used to read input from file. At first, it just points to one char.
    size_t bufferSize = 1;                       // Only one char.
    FILE *inputFile = fopen("input.txt", "r");   // Pointer to input file, using reading mode and text mode.
    char inputFileCharacter = '\0';              // Char that will save each character readed from file.
    clock_t start = 0;                           // Start time.
    clock_t end = 0;                             // Finish time.
    double timeSpent = 0;                        // Time that took whatever we measure.

    strncpy(buffer, "", bufferSize); //"", the \0 character.

    if (inputFile == NULL) // If the input file couldn't be opened:
    {
        printf("ERROR: the system failed to open input.txt\n");
    }
    else
    {
        start = clock(); // We get start time.
        // If the input file could be opened:
        //  Character reading based on https://www.codevscolor.com/c-program-read-file-contents-character
        while (inputFileCharacter != EOF) // While the file hasn't finished:
        {
            inputFileCharacter = fgetc(inputFile); // We get a char from file.
            if (inputFileCharacter != EOF)         // If the file hasn't finished:
            {
                bufferSize++;                                 // The buffer size increases to save the new char in buffer.
                buffer = (char *)realloc(buffer, bufferSize); // The buffer reallocates to supply the new buffer size. Previous string stay in buffer.
                if (buffer != NULL)                           // If the reallocation was good:
                {
                    strncat(buffer, &inputFileCharacter, 1); // The new char is appended to the previous string of buffer.
                }
            }
        }
    }

    fclose(inputFile); // File is closed.

    size_t size = strlen(buffer) + 1; // We reserve needed memory plus one more for '\0'.
    char input[size];                 // Input string to be processed.
    char output[size];                // Output string processed.

    strncpy(input, buffer, bufferSize); // Buffer is copied to input.
    free(buffer);                       // We free buffer memory, as contents were copied to input.

    end = clock(); // We get end time.

    timeSpent = (double)(end - start) / CLOCKS_PER_SEC; // We get seconds.
    timeSpent *= 1000;                                  // We transform seconds to milliseconds.

    printf("Reading from input.txt lasted %f milliseconds\n", timeSpent);

    start = clock();                   // We get start time.
    replaceInput(input, output, size); // Input solution processed in output string.
    end = clock();                     // We get end time.

    timeSpent = (double)(end - start) / CLOCKS_PER_SEC; // We get seconds.
    timeSpent *= 1000;                                  // We transform seconds to milliseconds.

    // printf("%s\n", output);

    printf("The function lasted %f milliseconds\n", timeSpent);

    return EXIT_SUCCESS;
}