#include <stdio.h>
#include <string.h>
#include "lines.h"

int readlines(char *lineptr[], int maxlines) {
    int len, nlines;
    char line[MAXLEN];
    nlines = 0;
    while ((len = _getline(line, MAXLEN)) > 0) 
        if (nlines >= maxlines)
            return -1;
        else {
            line[len - 1] = '\0';
            strcpy(lineptr[nlines++], line);
        }
    return nlines;
}

void writelines(char *lineptr[], int nlines) {
    while (nlines-- > 0)
        printf("%s\n", *lineptr++);
}

int _getline(char s[], int lim) {
    int c, i;
    for (i = 0; i < lim - 1 && (c = getchar()) != EOF && c != '\n'; ++i) 
        s[i] = c;
    if (c == '\n') {
        s[i] = c;
        ++i;
    }
    s[i] = '\0';
    return i;
}

