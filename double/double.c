#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <ctype.h>
#include <string.h>


int linenum;


int getword(FILE *, char *, int);
void doubleword(char *, FILE *);


/**
 * @brief double, detects adjacent identical words in the input
 */
int main(int argc, char *argv[]) {
    int i;

    for (i = 1; i < argc; i++) {
        FILE *fp = fopen(argv[i], "r");
        if (fp == NULL) {
            fprintf(stderr, "%s: can't open '%s' (%s)\n", argv[0], argv[i], strerror(errno));
            return EXIT_FAILURE;
        } else {
            doubleword(argv[i], fp);
            fclose(fp);
        }
    }
    if (argc == 1)
        doubleword(NULL, stdin);
    return EXIT_SUCCESS;
}


/**
 * @brief getword, reads the next word from an opened file into buf[0..size-1]
 * @return: 0 when it reaches the end of file, otherwise 1
 */
int getword(FILE *fp, char *buf, int size) {
    int c, i;

    c = getc(fp);
    // scan forward to a nonspace character or EOF
    for ( ; c != EOF && isspace(c); c = getc(fp))
        if (c == '\n')  // exercise 1.1: checking here to detect '\n' following by spaces or other '\n'
            linenum++;

    // copy the word into buf[0..size-1]
    i = 0;
    for ( ; c != EOF && !isspace(c); c = getc(fp))
        if (i < size - 1)
            buf[i++] = tolower(c);
    if (i < size)
        buf[i] = '\0';
    
    if (c != EOF)
        ungetc(c, fp);
    return buf[0] != '\0';
}


void doubleword(char *name, FILE *fp) {
    char prev[128], word[128];
    linenum = 1;
    prev[0] = '\0';
    while (getword(fp, word, sizeof(word))) {
        if (isalpha(word[0]) && strcmp(prev, word) == 0) {
            if (name)
                printf("%s:", name);
            printf("%d: %s\n", linenum, word);

            // exercise 1.2: scan forward to three or more identical words
            while (getword(fp, word, sizeof(word)) && isalpha(word[0]) && strcmp(prev, word) == 0) {}
        }
        strcpy(prev, word);
    }
}
