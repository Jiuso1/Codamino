#include <string.h>
#include <stdbool.h>

void replaceInput(const char input[], char output[], size_t size);
void replaceCodon(char codon[], size_t size);
bool isAminoacid(const char codon[], const char aminoacid[]);
