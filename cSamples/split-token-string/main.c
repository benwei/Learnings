/*
 * sample from STRTOK(3) BSD Library Functions Manual
 * ben6: add my comments
 */
#include <string.h> /* strcpy, strtok_r */
#include <stdio.h> /* printf */

int main (int argc, char **argv)
{ 
    /* FIXME: local should be initialized */
    char test[80], blah[80];
    char *sep = "\\/:;=-";
    char *word, *phrase, *brkt, *brkb;

    /* FIXME: ben6: should use strncpy to avoid overflow */
    strcpy(test, "This;is.a:test:of=the/string\\tokenizer-function.");

    for (word = strtok_r(test, sep, &brkt);
            word;
            word = strtok_r(NULL, sep, &brkt))
    {
        /* FIXME: ben6: should use strncpy to avoid overflow */
        strcpy(blah, "blah:blat:blab:blag");

        for (phrase = strtok_r(blah, sep, &brkb);
                phrase;
                phrase = strtok_r(NULL, sep, &brkb))
        {
            printf("So far we're at %s:%s\n", word, phrase);
        }
    }
}
