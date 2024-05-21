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

void replaceInput(const char input[], char output[], size_t size)
{
    char copy[size];
    int index = 0;                           // Index used as iterator.
    char codon[] = {'\0', '\0', '\0', '\0'}; // String that we will use to iterate each codon. The last char is reserved for \0.
    bool match = false;                      // When the codon is matched to any aminoacid, match equals true. While there's no match, equals false.

    strncpy(copy, input, size); // We copy the contents of input in copy string.

    // We iterate each codom and we substitute it with its correct aminoacid abbreviation:

    while (index < size - 1) // We don' iterate over the last character.
    {
        // I should replace this with strncpy.
        // We copy char by char the codon from the input string:
        codon[0] = copy[index];
        codon[1] = copy[index + 1];
        codon[2] = copy[index + 2];

        replaceCodon(codon); // We replace the codon string with the aminoacid abbreviation.

        // We copy char by char the aminoacid abbreviation in the input string:
        copy[index] = codon[0];
        copy[index + 1] = codon[1];
        copy[index + 2] = codon[2];

        index += 3; // We go to the next codon, so we need to jump three characters.
    }

    printf("%s\n", copy);
    strncpy(output, copy, size);
}

void replaceCodon(char codon[])
{
    size_t size = strlen(codon) + 1; // With strlen we get the number of characters (not including the last char, '\0') and we add 1 for the last char.
    bool replaced = false;           // Equals true when some aminoacid has matched with the codon.
    char *aminoacidAbbreviation[] = {"Phe", "Leu", "Ile", "Met", "Val", "Ser", "Pro", "Thr", "Ala",
                                     "Tyr", "STO", "His", "Gln", "Asn", "Lys", "Asp", "Glu", "Cys",
                                     "Trp", "Arg", "Gly"};
    // As the codon string has three characters and we're replacing it with the aminoacid abbreviation, STOP becomes STO.
    int i = 0;                         // Iterator used in while search.
    const int numberOfAminoacids = 21; // Number of aminoacids.

    // If the codon is some aminoacid, we copy the aminoacid abbreviation in the codon string.
    // For that, we iterate the aminoacidAbbreviation array, and if the codon matches with the i aminoacid, isAminoacid returns true and we replace it.
    while (!replaced && i < numberOfAminoacids)
    {
        if (isAminoacid(codon, aminoacidAbbreviation[i]))
        {
            replaced = true;
            strncpy(codon, aminoacidAbbreviation[i], size);
        }
        else
        {
            i++;
        }
    }
}

bool isAminoacid(const char codon[], const char aminoacid[])
{
    bool found = false;
    size_t size = strlen(codon); // We get the number of characters (not including the last char, '\0').
    int i = 0;                   // Iterator used for while search.
    // We should create a data structure so that we don't have to create 20 else-if...
    if (strncmp(aminoacid, "Phe", size) == 0)
    {
        while (i < numberOfPheCodons && !found)
        {
            if (strncmp(codon, Phe[i], size) == 0)
            {
                found = true;
            }
            else
            {
                i++;
            }
        }
    }
    return found;
}