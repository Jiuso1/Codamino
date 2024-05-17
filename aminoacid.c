#include "aminoacid.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

// Source: https://external-content.duckduckgo.com/iu/?u=http%3A%2F%2Fkillowen.com%2Fassets%2Famino%2520acid%2520chart.png&f=1&nofb=1&ipt=1930e039717790596e7e6863cf31a1ab485651d50ad4a3cde6218c5faeaf477e&ipo=images
// Aminoacids:
char *Phe[] = {"UUU", "UUC"}; // https://stackoverflow.com/questions/1088622/how-do-i-create-an-array-of-strings-in-c
char *Leu[] = {"UUA", "UUG", "CUU", "CUC", "CUA", "CUG"};
char *Ile[] = {"AUU", "AUC", "AUA"};
char *Met[] = {"AUG"};
char *Val[] = {"GUU", "GUC", "GUA", "GUG"};
char *Ser[] = {"UCU", "UCC", "UCA", "UCG", "AGU", "AGC"};
char *Pro[] = {"CCU", "CCC", "CCA", "CCG"};
char *Thr[] = {"ACU", "ACC", "ACA", "ACG"};
char *Ala[] = {"GCU", "GCC", "GCA", "GCG"};
char *Tyr[] = {"UAU", "UAC"};
char *STOP[] = {"UAA", "UAG", "UGA"};
char *His[] = {"CAU", "CAC"};
char *Gln[] = {"CAA", "CAG"};
char *Asn[] = {"AAU", "AAC"};
char *Lys[] = {"AAA", "Lys"};
char *Asp[] = {"GAU", "GAC"};
char *Glu[] = {"GAA", "GAG"};
char *Cys[] = {"UGU", "UGC"};
char *Trp[] = {"UGG"};
char *Arg[] = {"CGU", "CGC", "CGA", "CGG", "AGA", "AGG"};
char *Gly[] = {"GGU", "GGC", "GGA", "GGG"};

// Number of codons:
const int numberOfPheCodons = 2;
const int numberOfLeuCodons = 6;
const int numberOfIleCodons = 3;
const int numberOfMetCodons = 1;
const int numberOfValCodons = 4;
const int numberOfSerCodons = 6;
const int numberOfProCodons = 4;
const int numberOfThrCodons = 4;
const int numberOfAlaCodons = 4;
const int numberOfTyrCodons = 2;
const int numberOfSTOPCodons = 3;
const int numberOfHisCodons = 2;
const int numberOfGlnCodons = 2;
const int numberOfAsnCodons = 2;
const int numberOfLysCodons = 2;
const int numberOfAspCodons = 2;
const int numberOfGluCodons = 2;
const int numberOfCysCodons = 2;
const int numberOfTrpCodons = 1;
const int numberOfArgCodons = 6;
const int numberOfGlyCodons = 4;

void replaceCodons(const char input[], char output[], size_t size)
{
    char copy[size];
    // char *replacedString = NULL;
    int index = 0;                           // Index used as iterator.
    char codon[] = {'\0', '\0', '\0', '\0'}; // String that we will use to iterate each codon. The last char is reserved for \0.
    bool match = false;                    // When the codon is matched to any aminoacid, match equals true. While there's no match, equals false.

    strncpy(copy, input, size); // We copy the contents of input in copy string.

    // We iterate each codom and we substitute it with its correct aminoacid abbreviation:

    while (index < size - 1) // We don' iterate over the last character.
    {
        codon[0] = copy[index];
        codon[1] = copy[index + 1];
        codon[2] = copy[index + 2];
        printf("%s\n", codon);
        index += 3; // We go to the next codon, so we need to jump three characters.
    }

    /*for (int i = 0; i < numberOfPheCodons; i++)
    {
        replacedString = str_replace(copy, Phe[i], "Phe");
        strncpy(copy, replacedString, size);
        free(replacedString);
    }

    for (int i = 0; i < numberOfLeuCodons; i++)
    {
        replacedString = str_replace(copy, Leu[i], "Leu");
        strncpy(copy, replacedString, size);
        free(replacedString);
    }

    for (int i = 0; i < numberOfIleCodons; i++)
    {
        replacedString = str_replace(copy, Ile[i], "Ile");
        strncpy(copy, replacedString, size);
        free(replacedString);
    }

    for (int i = 0; i < numberOfMetCodons; i++)
    {
        replacedString = str_replace(copy, Met[i], "Met");
        strncpy(copy, replacedString, size);
        free(replacedString);
    }

    for (int i = 0; i < numberOfValCodons; i++)
    {
        replacedString = str_replace(copy, Val[i], "Val");
        strncpy(copy, replacedString, size);
        free(replacedString);
    }

    for (int i = 0; i < numberOfSerCodons; i++)
    {
        replacedString = str_replace(copy, Ser[i], "Ser");
        strncpy(copy, replacedString, size);
        free(replacedString);
    }

    for (int i = 0; i < numberOfProCodons; i++)
    {
        replacedString = str_replace(copy, Pro[i], "Pro");
        strncpy(copy, replacedString, size);
        free(replacedString);
    }

    for (int i = 0; i < numberOfThrCodons; i++)
    {
        replacedString = str_replace(copy, Thr[i], "Thr");
        strncpy(copy, replacedString, size);
        free(replacedString);
    }

    for (int i = 0; i < numberOfAlaCodons; i++)
    {
        replacedString = str_replace(copy, Ala[i], "Ala");
        strncpy(copy, replacedString, size);
        free(replacedString);
    }

    for (int i = 0; i < numberOfTyrCodons; i++)
    {
        replacedString = str_replace(copy, Tyr[i], "Tyr");
        strncpy(copy, replacedString, size);
        free(replacedString);
    }

    for (int i = 0; i < numberOfSTOPCodons; i++)
    {
        replacedString = str_replace(copy, STOP[i], "STO"); // STOP will be saved as STO temporarily, in order to avoid overthinking about memory issues in output string.
        strncpy(copy, replacedString, size);
        free(replacedString);
    }

    for (int i = 0; i < numberOfHisCodons; i++)
    {
        replacedString = str_replace(copy, His[i], "His");
        strncpy(copy, replacedString, size);
        free(replacedString);
    }

    for (int i = 0; i < numberOfGlnCodons; i++)
    {
        replacedString = str_replace(copy, Gln[i], "Gln");
        strncpy(copy, replacedString, size);
        free(replacedString);
    }

    for (int i = 0; i < numberOfAsnCodons; i++)
    {
        replacedString = str_replace(copy, Asn[i], "Asn");
        strncpy(copy, replacedString, size);
        free(replacedString);
    }

    for (int i = 0; i < numberOfLysCodons; i++)
    {
        replacedString = str_replace(copy, Lys[i], "Lys");
        strncpy(copy, replacedString, size);
        free(replacedString);
    }

    for (int i = 0; i < numberOfAspCodons; i++)
    {
        replacedString = str_replace(copy, Asp[i], "Asp");
        strncpy(copy, replacedString, size);
        free(replacedString);
    }

    for (int i = 0; i < numberOfGluCodons; i++)
    {
        replacedString = str_replace(copy, Glu[i], "Glu");
        strncpy(copy, replacedString, size);
        free(replacedString);
    }

    for (int i = 0; i < numberOfCysCodons; i++)
    {
        replacedString = str_replace(copy, Cys[i], "Cys");
        strncpy(copy, replacedString, size);
        free(replacedString);
    }

    for (int i = 0; i < numberOfTrpCodons; i++)
    {
        replacedString = str_replace(copy, Trp[i], "Trp");
        strncpy(copy, replacedString, size);
        free(replacedString);
    }

    for (int i = 0; i < numberOfArgCodons; i++)
    {
        replacedString = str_replace(copy, Arg[i], "Arg");
        strncpy(copy, replacedString, size);
        free(replacedString);
    }

    for (int i = 0; i < numberOfGlyCodons; i++)
    {
        replacedString = str_replace(copy, Gly[i], "Gly");
        strncpy(copy, replacedString, size);
        free(replacedString);
    }*/

    printf("%s\n", copy);
    strncpy(output, copy, size);
}

// Source: https://stackoverflow.com/questions/779875/what-function-is-to-replace-a-substring-from-a-string-in-c
// You must free the result if result is non-NULL.
char *str_replace(char *orig, char *rep, char *with)
{
    char *result;  // the return string
    char *ins;     // the next insert point
    char *tmp;     // varies
    int len_rep;   // length of rep (the string to remove)
    int len_with;  // length of with (the string to replace rep with)
    int len_front; // distance between rep and end of last rep
    int count;     // number of replacements

    // sanity checks and initialization
    if (!orig || !rep)
        return NULL;
    len_rep = strlen(rep);
    if (len_rep == 0)
        return NULL; // empty rep causes infinite loop during count
    if (!with)
        with = "";
    len_with = strlen(with);

    // count the number of replacements needed
    ins = orig;
    for (count = 0; (tmp = strstr(ins, rep)); ++count)
    {
        ins = tmp + len_rep;
    }

    tmp = result = malloc(strlen(orig) + (len_with - len_rep) * count + 1);

    if (!result)
        return NULL;

    // first time through the loop, all the variable are set correctly
    // from here on,
    //    tmp points to the end of the result string
    //    ins points to the next occurrence of rep in orig
    //    orig points to the remainder of orig after "end of rep"
    while (count--)
    {
        ins = strstr(orig, rep);
        len_front = ins - orig;
        tmp = strncpy(tmp, orig, len_front) + len_front;
        tmp = strcpy(tmp, with) + len_with;
        orig += len_front + len_rep; // move to next "end of rep"
    }
    strcpy(tmp, orig);
    return result;
}