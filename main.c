#include "aminoacid.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define SIZE 1024 // Number of characters readed simultaneously from file.

int main(void)
{
    char *buffer = (char *)malloc(sizeof(char)); // Dynamic buffer used to read input from file. At first, it just points to one char.
    size_t bufferSize = 1;                       // Only one char.
    FILE *inputFile = fopen("input.txt", "r");   // Pointer to input file, using reading mode and text mode.
    clock_t start = 0;                           // Start time.
    clock_t end = 0;                             // Finish time.
    double timeSpent = 0;                        // Time that took whatever we measure.
    char inputFileString[SIZE] = "0";            // Array to save strings from file. We initialize to "0" because later on we compare to empty string ("").

    strncpy(buffer, "", bufferSize); //"", which converts to the \0 character.

    if (inputFile == NULL) // If the input file couldn't be opened:
    {
        printf("ERROR: the system failed to open input.txt\n");
    }
    else
    {
        // If the input file could be opened:
        start = clock(); // We get start time.
        // String reading based on https://www.geeksforgeeks.org/fread-function-in-c/
        while (!feof(inputFile) && (strncmp(inputFileString, "", SIZE) != 0)) // While the file hasn't finished and no empty string has appear:
        {
            fread(inputFileString, sizeof(inputFileString), 1, inputFile); // We read the string from file.
            if ((strncmp(inputFileString, "", SIZE) != 0))                 // If the string isn't empty:
            {
                bufferSize += strlen(inputFileString);                       // The buffer size increases to save the new string in buffer.
                buffer = (char *)realloc(buffer, bufferSize * sizeof(char)); // The buffer reallocates to supply the new buffer size. Previous string stay in buffer.
                if (buffer != NULL)                                          // If the reallocation was good:
                {
                    strncat(buffer, inputFileString, sizeof(inputFileString)); // The new string is appended to the previous string of buffer.
                }
            }
        }
    }

    fclose(inputFile); // File is closed.

    size_t size = strlen(buffer) + 1;                   // We reserve needed memory plus one more for '\0'.
    char *input = (char *)malloc(size * sizeof(char));  // Input string to be processed. Saved on heap as it is a huge array.
    char *output = (char *)malloc(size * sizeof(char)); // Output string processed. Saved on heap as it is a huge array.

    strncpy(input, buffer, bufferSize); // Buffer is copied to input.

    free(buffer); // We free buffer memory, as contents were copied to input.

    end = clock(); // We get end time.

    timeSpent = ((double)(end - start) / CLOCKS_PER_SEC) * 1000; // We get seconds and we transform to milliseconds.

    printf("Reading from input.txt lasted %f milliseconds\n", timeSpent);

    start = clock();                   // We get start time.
    replaceInput(input, output, size); // Input solution processed in output string.
    end = clock();                     // We get end time.

    timeSpent = ((double)(end - start) / CLOCKS_PER_SEC) * 1000; // We get seconds and we transform to milliseconds.

    // printf("%s\n", output);

    // We free the rest of dynamic memory:
    free(input);
    free(output);

    printf("The function lasted %f milliseconds\n", timeSpent);

    return EXIT_SUCCESS;
}