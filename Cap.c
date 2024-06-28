#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MADMAX 100

void up ( char *s ) {
    char *p = s;
    int i = 0;
    while(p) {
        while ( *p == ' ' ) ++p;
        if ( *p )
            *p = toupper(*p);
        p = strchr(p++, ' ');
    }
}

int main()
{
    char *s = ( char* ) malloc (MADMAX);
    if ( (s == NULL) ) {
        puts(" s's memory allocation failed");
        exit(EXIT_FAILURE);
    }
    printf(" enter a string: ");
    gets(s);
    s = ( char* ) realloc (s, strlen(s));
    if ( (s == NULL) ) {
        puts(" s's memory re-allocation failed");
        exit(EXIT_FAILURE);
    }
    up(s);
    puts(s);
    
    free(s);
    s = NULL;
    
    return 0;
}
